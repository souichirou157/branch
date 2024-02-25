const readline = require('readline');
const {red,green,cyan,yellow,bgBlue,bgCyan} = require('kleur');
function print(x) {
    // xを標準出力に書き込む
    process.stdout.write(`${x}`); // 改行を付ける
  }
  
function loop(){
 // 標準入力に質問を表示する
 rl.question('branch:🪴  >>:', query => {
    // queryに入力された文字列を評価する
    eval(query); // print関数が実行される
    // readlineインターフェイスを閉じる
  });
 loop(); 
}  
 
loop();

/*
branch () {
        // 標準入力に質問を表示する
        rl.question('branch:🪴  >>:', query => {
          // queryに入力された文字列を評価する
        eval(query); // print関数が実行される
          // readlineインターフェイスを閉じる
        if(query === 'exit ') {
            rl.close();
            this.InitializationPrompt();
          }
        });
        branch();
    }
*/