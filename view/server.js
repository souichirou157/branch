const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const path = require('path');
const port = 4000;


app.use(express.static(path.join(__dirname)));



app.get("/main",(req,res)=>
{
    res.sendFile(path.join(__dirname, "index.html"));
});
    console.log(`${__dirname}`);
  





module.exports =
{
    runserver:app.listen(port,console.log(`🪴 ok`)),
}









