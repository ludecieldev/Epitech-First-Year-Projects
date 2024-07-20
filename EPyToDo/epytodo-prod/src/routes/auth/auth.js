const express = require('express');
const router = express.Router();
const db = require('../../config/db');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

router.post('/register', async (req, res) => {
    const { email, name, firstname, password } = req.body;
    if (!email || !name || !firstname || !password) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    try {
        const [user] = await db.query('SELECT id FROM user WHERE email = ?', [email]);
        if (user.length > 0) {
            return res.status(409).json({ msg: "User already exists" });
        }

        const hashedPassword = await bcrypt.hash(password, 10);

        const result = await db.query('INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)', [email, name, firstname, hashedPassword]);

        const token = jwt.sign({ user_id: result.insertId, email }, process.env.SECRET, { expiresIn: '1h' });

        res.status(201).json({ token });
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error: error });
    }
});

router.post('/login', async (req, res) => {
    const { email, password } = req.body;
    if (!email || !password) {
        return res.status(400).json({ msg: "Bad parameter" });
    }
    try {
        const [users] = await db.query('SELECT * FROM user WHERE email = ?', [email]);
        if (users.length === 0) {
            return res.status(404).json({ msg: "User not found" });
        }

        const user = users[0];

        const validPassword = await bcrypt.compare(password, user.password);
        if (!validPassword) {
            return res.status(401).json({ msg: "Invalid password" });
        }

        const token = jwt.sign({ user_id: user.id, email: user.email }, process.env.SECRET, { expiresIn: '1h' });

        res.json({ token });
    } catch (error) {
        res.status(500).json({ msg: "Internal server error", error: error });
    }
});

module.exports = router;