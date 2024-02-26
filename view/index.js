


const app = Vue.createApp({

    data()
    {
        return {
            username: '投稿待ち',
            text:'メッセージを送信',
            message:'',
            move:'データを見に行く',
            outputMessage:[],
            count:0,
        }
    }
    ,
    methods:
    {
        sendMessage() 
        {

            this.outputMessage.push(this.message);
            this.message = '';
            if(this.sendMessage)
            {
                this.count++;
                this.username = '投稿されました....';
                setTimeout(()=>{
                 this.username = '投稿待ち';},6000);
            }
        }
        ,
      
    }

});

app.mount('#main');


