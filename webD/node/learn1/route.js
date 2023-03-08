const http =require('http');

const server =http.createServer((req, res)=>{
    res.writeHead(200,{
        'Content-Type' : 'text/html'
    });

    var url =req.url;

    if (url==='/about')
    {
        res.write('Welcome to about us page\n');
        res.write(req.url)
        res.end();
    }
})

server.listen(8000, ()=>{
    console.log("Server started ...")
})

