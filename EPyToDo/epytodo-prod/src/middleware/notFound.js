function notFound(req, res, next) {
    res.status(404).json({
        status: 404,
        error: 'Not Found',
        message: 'The requested resource was not found on this server.'
    });
}

module.exports = notFound;