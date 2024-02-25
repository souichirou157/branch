const express = require("express");
const app = express();
const port = 4400;



const user = [

    {name:"saru",id:1},
    {name:"unpo",id:2},
    {name:"tinpo",id:3},

]





app.get("/api/user",(req,res)=>
{
    res.send(user);
})


module.export ={
    showdata:app.listen(port,console.log('api data 🪴')),
}