const express = require("express");
const app = express();
const port = 4400;
const axios = require('axios'); //httpリクエストを行いHTMLを取得、文字列として返す
const cheerio = require('cheerio'); //HTMLの解析DOM操作を行う
const { runserver } = require("../view/server");
let jsondata = {};


app.get("/api/user",(req,res)=>
{
  let imgdata;

    //variable url the last url you want to use
    axios.get(url).then(response =>
    {
        const html = response.data;
        const $loadData = cheerio.load(html); //
        
        return $loadData;
    }).then($loadData=>{

        const imgTags = $loadData('img');
        imgdata =  $loadData('img').attr('src');
        for(let i =0; i < imgTags.length; i++) jsondata[`url${i}`] = JSON.stringify(imgdata);
        res.send(jsondata);
        console.log(jsondata);
   
   
    }).catch(console.error);   
});



module.export =
{
    runserver:app.listen(port,console.log('api data 🪴')),

}