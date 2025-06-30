const express = require('express');
const cors = require('cors');
const fs = require('fs');
const app = express();
app.use(cors());

app.get('/api/route', (req, res) => {
    fs.readFile('../../routes_output.json', 'utf8', (err, data) => {
        if (err) return res.status(500).send('Error reading file');
        res.json(JSON.parse(data));
    });
});

app.listen(3001, () => console.log("API listening on http://localhost:3001"));
