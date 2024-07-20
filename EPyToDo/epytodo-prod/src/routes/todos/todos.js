const express = require('express');
const router = express.Router();
const db = require('../../config/db');
const authenticateToken = require('../../middleware/auth');

router.get('/', authenticateToken, async (req, res) => {
    try {
        const userId = req.user.user_id;
        const [todos] = await db.query('SELECT * FROM todo WHERE user_id = ?', [userId]);
        res.json(todos);
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error });
    }
});

router.get('/:id', authenticateToken, async (req, res) => {
    const { id } = req.params;
    try {
        const [results] = await db.query('SELECT * FROM todo WHERE id = ?', [id]);
        if (results.length > 0) {
            res.json(results[0]);
        } else {
            res.status(404).json({ msg: "Todo not found" });
        }
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error });
    }
});

router.post('/', authenticateToken, async (req, res) => {
    const { title, description, due_time, status } = req.body;
    if (!title || !description || !due_time || !status) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    const user_id = req.user.user_id;
    if (!user_id) {
        return res.status(401).json({ msg: "Unauthorized" });
    }
    try {
        const result = await db.query(
            'INSERT INTO todo (title, description, due_time, status, user_id) VALUES (?, ?, ?, ?, ?)',
            [title, description, due_time, status, user_id]
        );
        if (result[0].affectedRows > 0) {
            const [newTodo] = await db.query('SELECT * FROM todo WHERE id = ?', [result[0].insertId]);
            res.status(201).json(newTodo[0]);
        } else {
            res.status(400).json({ msg: "Failed to create todo" });
        }
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error });
    }
});

router.put('/:id', authenticateToken, async (req, res) => {
    const { id } = req.params;
    if (!id) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    const { title, description, due_time, status } = req.body;
    if (!title || !description || !due_time || !status) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    const userId = req.user.user_id;
    if (!userId) {
        return res.status(401).json({ msg: "Unauthorized" });
    }
    try {
        const [result] = await db.query(
            'UPDATE todo SET title = ?, description = ?, due_time = ?, status = ? WHERE id = ? AND user_id = ?',
            [title, description, due_time, status, id, userId]
        );
        if (result.affectedRows > 0) {
            const [updatedTodo] = await db.query('SELECT * FROM todo WHERE id = ?', [id]);
            res.json(updatedTodo[0]);
        } else {
            res.status(404).json({ msg: "No todo found to update" });
        }
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error });
    }
});


router.delete('/:id', authenticateToken, async (req, res) => {
    const { id } = req.params;
    if (!id) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    const userId = req.user.user_id;
    if (!userId) {
        return res.status(401).json({ msg: "Unauthorized" });
    }
    try {
        const [todos] = await db.query('SELECT * FROM todo WHERE id = ? AND user_id = ?', [id, userId]);
        if (todos.length === 0) {
            return res.status(404).json({ msg: "No todo found to delete" });
        }
        const [result] = await db.query('DELETE FROM todo WHERE id = ? AND user_id = ?', [id, userId]);
        if (result.affectedRows > 0) {
            res.json({ msg: `Successfully deleted record number : ${id}` });
        } else {
            res.status(404).json({ msg: "No todo found to delete" });
        }
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error });
    }
});

module.exports = router;
