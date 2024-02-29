const express = require("express");
const app = express();
const port = 4400;
const axios = require('axios'); //httpリクエストを行いHTMLを取得、文字列として返す
const cheerio = require('cheerio'); //HTMLの解析DOM操作を行う
let tagSrc = {};



//自分のサイトにアクセス
app.get("/api/user",(req,res)=>
{
    let tag;

    //ほしいデータのある場所にアクセス そのまま取得するためにthenでつないで処理
    axios.get(url).then(response =>
    {
    const html = response.data;
    const $loadData = cheerio.load(html);
    const imgTags = $loadData('img');
    tag=  $loadData('img').attr('src');
    
    for(let i =0; i < imgTags.length; i++) tagSrc[`url${i}`] = tag;
    
    res.send(tagSrc);
    console.log(tagSrc);
    }).catch(console.error);
    
});


module.export ={
    showdata:app.listen(port,console.log('api data 🪴')),
}