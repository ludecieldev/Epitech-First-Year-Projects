const express = require('express');
const app = express();
require('dotenv').config();
const port = process.env.PORT;

app.use(express.json());

const userRoutes = require('./routes/user/user');
const todoRoutes = require('./routes/todos/todos');
const authRoutes = require('./routes/auth/auth');

app.use('/', authRoutes);
app.use('/users', userRoutes);
app.use('/user', userRoutes);
app.use('/todos', todoRoutes);

app.get('/', (req, res) => {
    res.status(200).send('Welcome to the API!');
});

app.use((req, res, next) => {
    res.status(404).json({
        msg: 'Not found'
    });
});

app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).json({
        msg: 'Internal server error'
    });
});

app.listen(port, () => {
    console.log(`Server started on http://localhost:${port}`);
});
