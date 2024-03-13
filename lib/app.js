'use strict'
const readline = require('readline');
const {red,green,cyan,yellow,bgBlue,bgCyan} = require('kleur');
const  rl = readline.createInterface({input:process.stdin,output:process.stdout});              
let timer = 3;
let query;
// iimport ------ lib/model.js
const Mysql = require('./model').connection;
const DefineModels = require('./model').Models[0];
////////////



class Progress
{

constructor(nowCount,dispCount,dispChar,per,interval,maxcount,Progresslength)
{
        this.nowCount = 0;
        this.dispCount = 0;
        this.dispChar = ["|", "/", "—", "＼"];
        this.per = per;
        this.interval = interval;
        this.maxcount = maxcount;
        this.Progresslength = Progresslength;
        this.ProgressBerRotate(this.maxcount,this.Progresslength); //プログレスバー
}

ProgressBerRotate = function(MaxCount, ProgressLength)  
{        
        this.interval = setInterval(() => 
        {
            this.nowCount+=1;
            this.per = this.nowCount / this.dispChar.length;
            // プロンプトサーバーが起動される間queryプロンプトを消す
            process.stdout.clearLine();
            process.stdout.cursorTo(1);
            // プログレスバーを表示する
            process.stdout.write
            ( 
                red(`\t ${this.dispChar[this.dispCount]}...${Math.floor(this.per * 100)}%\r`));
                this.dispCount = ++this.dispCount >= this.dispChar.length ? 0 : this.dispCount; //先にインクリメントして代入
                this.per >=1 ?this.nowCount =0:null;
                this.per==100? this.per =0:null; //100%まで来たらリセット
        },timer*200)   
}

}
  


class Branch
{
    constructor(LeadArg,OpenCliMessagenowCount,RunServer)
    {
    [,,this.LeadArg] = process.argv;
    this.RunServer = require('../view/server').runserver;
    this.apiData = require('../imagedata/collection').runserver;

    this.OpenCliMessage = cyan(`
    branch:🪴 >>>>>Welecome\b to \b${this.LeadArg}!!!\n
    \t-- Let me tell you first,\n
    People who  have don't  have  an acount don't give you any  
    authority-- ,🪴 \n
    \b---\bI'm glad that this app will help you develop `)
    };
    
Open()
{
    if(!this.LeadArg)
    {
        console.error('Prease pass on  argment!!!'); 
         process.exit(1);
    }else
    {
        console.log(this.OpenCliMessage);
    }
}

ParseMarkDown(filePath)
{
        const fs = require('node:fs/promises');
        const path = require('path');
        const marked = require('marked');

    fs.readFile(filePath,{encoding:"utf-8"}).then(file =>
    {
            const [html] = marked.parse(file,{
                // gfm:this.Op.options.gfmp
            });
    
    console.log(cyan(`OK 🪴: String >>> %s`), bgBlue(yellow(html)));
        }).catch(function(err)
            {
                if(err)
                {
                    err = new Error('faile undefined Error');
                    console.error(red(err));
                    console.error(red(`\n--Failed to read file at ${filePath}. Please make sure the file path is correct.`));     
                }
            });
}

CreateUser()
{
    rl.question(cyan(`please username🪴\nUserName:`),(Name)=>
    {
        rl.question(cyan(`next password🪴\nLoginPassward:`),(PassWord)=>
    {
             rl.question(cyan(`last enail_adress🪴\nadress:`),(MailAdress)=>
             {
                const now = new Date().toLocaleString('ja-jp');
                     //  data type object from String  
                     /*
                      now = new Date().toLocaleString('ja-jp'); 
                      test = new Date();
                     console.log(typeof(now),typeof(test));
                     ----string object
                     */
                DefineModels.findOrCreate
                ({
                      where:{username: Name,password:PassWord,email:MailAdress},                  
                      defaults:{username:Name,password:PassWord,email:MailAdress,createdAt:now,updatedAt:now}
                
                }).then(function([result, created])
                       { 
                          if(created)
                          {
                            console.log(red(`Sucsessfully!! --create newuser`));
                            this.InitializationPrompt();
                          }

                       }).catch(function(err)
                        {
                            console.error(err);

                            rl.question(cyan(`last enail_adress🪴\n onemore?🪴`),(result)=>
                            {
                            result === 'y'? this.CreateUser():this.InitializationPrompt();
                            });
                        }); 
               }); 
            });
        }); 
    }

    //ファイルパスを標準入力で受け取れるようにする
MainPrompt(query)
{
        // queryに標準入力を受け付ける
rl.question(cyan(`branch:🪴  >>:`), query => 
{
            const [command, ...filePathParts] = query.split(' ');
            const filePath = filePathParts.join(' ');
    
    command === 'parse'?this.ParseMarkDown(filePath):null;
    command === 'reload'?this.InitializationPrompt():null;
    
    if (command === 'runserver')
    {

        console.log(yellow(`---run server now🪴  CONTROl-BREAK  http://127.0.0.1:4000/`));
        const RunserverWhile = new Progress(100,10); //プログレスバー
  //サーバー先立てとく      
        ()=> { return this.runserver;}
        ()=>{ return this.apiData;}
    
    }
    
    if(command === 'createuser')
    {
        try
        {
            this.CreateUser();
        }
        catch(err)   
        {
            throw Error(err);
        }
    }

    this.MainPrompt(query);

    if(command === 'close')
    { //ここまだ使えない
        //server.close();
        console.log(bgCyan(red(`closed server  Please Enterkeys 🪴`)));
        this.InitializationPrompt();
    } 
    
    if(query === 'exit')
    {
        console.log(yellow(bgBlue(`branch:🪴 >>>Seeyou`)));

        rl.close();
    }
});  
}
  
async InitializationPrompt() 
{
    await rl.question(cyan(`branch:End or Start the session? 🪴 (y/n)`),result =>
    { 

        if(result === 'y')
        {
            this.MainPrompt(query);//実際に標準入力受付に入れる
        }
        else if(result === 'n')
        {
            console.log(red(`\nseeyou ..again🪴 `));     
            rl.close();
        } 
    })}

};   

//ここに処理呼び出す ここからは別モジュールに移動する
class Main
{
    Flow()
{
        const StratBranch = new Branch(this.LeadArg,this.OpenCliMessage); 
        //const BranchOf = new Branch();//プロンプトで呼び出される処理
        StratBranch.Open();
    rl.question(cyan('doyou want to create an acount?🪴  (y/n)'),result =>
        {
            if(result==='y')
            {
    
                rl.question(cyan(' username 🪴\nusername'),Name=>
                {
                    rl.question(cyan('password 🪴\npassword'),PassWord=>
                    {
                        const now = new Date().toLocaleString('ja-jp');
                       
                        DefineModels.findOne
                        ({
                            where:{username:Name,password:PassWord},
                            defaults:{ username:Name,password:PassWord,createdAt:now,updatedAt:now}
 
                        }).then(function(result)
                        {
                            
                if(result)
                        {
                            Mysql.query
                            (
                                'insert into  Loginhistory(id,username,password,email,createdAt,updatedAt) VALUES(?,?,?,?,?,?)',
                                {type:Mysql.QueryTypes.INSERT,replacements:[null,Name,PassWord,null,now,now]})}
                                console.log(red(`hello my friend 🪴`))
                                const  start =new Branch().MainPrompt();
                            }).catch(
                                function(err)
                                {
                                    console.error(err);
                                    rl.close()
                            })
                        })
                    })
                }
                else if (result==='n')
                {
                    const rollback = new Branch().InitializationPrompt();
                }
        })
      
    
    }
};
const main = new Main().Flow();

//アプリケーションを閉じるとききれいに落ちない