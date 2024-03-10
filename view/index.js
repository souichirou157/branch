
const app = Vue.createApp({

    data()
    {
        return {
            username: '投稿待ち',
            text:'メッセージを送信',
            jsonData:'',
            move:'データを見に行く',
            count:0,
        }
    }
    ,
    methods:
    {
        sendMessage() 
        {
            //http://localhost:4400/api/user

            const obj = document.querySelector('#obj');
            const li = document.createElement('li');

            

            if(this.sendMessage)
            {
                this.count++;
                this.username = '読み込み中....';
                setTimeout(()=>{
                    li.innerText = this.jsonData;
                    obj.appendChild(li);
                    this.jsonData = '';
                 this.username = '投稿待ち';},6000);
            }
        }
        ,
      
    }

});

app.mount('#main');

