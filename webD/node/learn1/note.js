const http = require('http');
const fs = require('fs');
const url = require('url');
const querystring = require('querystring');

const portNumber = 8080;

const server = http.createServer((req, res) => {

    const method = req.method;
    const parsedUrl = url.parse(req.url, true);

    if (req.url === '/') {
        fs.readFile('note.html', (err, data) => {
            res.writeHead(200, { 'Content-Type': 'text/html' })
            res.write(data);
            return res.end();
        })
    }

    if (method === 'POST' && req.url === '/submit') {
        let body = '';
        req.on('data', chunk => {
            body += chunk.toString();
        });

        req.on('end', () => {
            // console.log(body);

            const formData = querystring.parse(body);
            const note = formData.note;

            // do something with the form data
            fs.writeFile('note.txt', note, function (err, file) {
                if (err) throw err;
                console.log('Saved!');
            });

            // send response
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Form submitted successfully!');
        });
    }
})

server.listen(portNumber, () => {
    console.log(`Server started on ${portNumber}...`)
});