const express = require("express");
const app = express();
const port = 4400;
const axios = require('axios'); //httpリクエストを行いHTMLを取得、文字列として返す
const cheerio = require('cheerio'); //HTMLの解析DOM操作を行う
let tagSrc = [{}];




app.get("/api/user",(req,res)=>
{
    let tag;

    axios.get(url).then(response =>
    {
    const html = response.data;
    const $loadData = cheerio.load(html);
    tag=  $loadData('img').attr('src');
    tagSrc = [{url:tag}];res.send(tagSrc);
    }).catch(console.error);
    
});


module.export ={
    showdata:app.listen(port,console.log('api data 🪴')),
}