CREATE DATABASE IF NOT EXISTS epytodo;
USE epytodo;

CREATE TABLE user (
    id INT AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    firstname VARCHAR(100) NOT NULL,
    name VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


CREATE TABLE todo (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    description TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    due_time DATETIME NOT NULL,
    user_id INT,
    status ENUM('not started', 'todo', 'in progress', 'done') DEFAULT 'not started',
    FOREIGN KEY (user_id) REFERENCES user(id)
);