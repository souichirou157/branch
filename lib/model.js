const env = require('dotenv').config();
const {Sequelize ,DataTypes, QueryTypes}= require('sequelize');


const SequelizeConfig = new Sequelize(process.env.DATABASE_NAME,process.env.DATABASE_USER,process.env.DATABASE_PASSWORD,
    {host:process.env.DATABASE_HOST,dialect:process.env.DATABASE_ENGINE}); 


//データベーススキーマ別テーブル作成、もしくは正規化する時に必要絡むだけ抜き出して定義
class DbSchema{
   constructor(id,username,password,email){
        
        this.id ={
            type:DataTypes.INTEGER,
            allowNull:false,
            primaryKey:true,
            autoIncrement:true,
            comment:'主キー',
        },
        this.username = {
            type:DataTypes.STRING(this.length),
            allowNull:false
        },
        this.password = {
            type:DataTypes.STRING(this.length)||DataTypes.Number(this.length),
            allowNull:false
        },
        this.email ={ // カラム名を変更
            type:DataTypes.STRING(30)||DataTypes.Number(this.length), // データ型を変更
            allowNull:true,   
        }
    }

}
const option = {
    freezeTableName:true,    
    timestamps:true, 
    createdAt:true,
    updatedAt:true            
  };
//テーブルのスキーマ
const UserColumn = new DbSchema(); //ユーザ情報テーブル
const LoginColumn = new DbSchema(); //ログイン履歴テーブル


const LoginHistory = new Sequelize(process.env.DATABASE_NAME,process.env.DATABASE_USER,process.env.DATABASE_PASSWORD,{host:process.env.DATABASE_HOST,dialect:process.env.DATABASE_ENGINE}).define('Loginhistory',LoginColumn, option);
const UserModel =  new Sequelize(process.env.DATABASE_NAME,process.env.DATABASE_USER,process.env.DATABASE_PASSWORD,
    {host:process.env.DATABASE_HOST,dialect:process.env.DATABASE_ENGINE}).define('User', UserColumn, option);

module.exports={
    connection:SequelizeConfig, //DB接続情報
    Models:[UserModel,LoginHistory],//ユーザーテーブル情報
    

    branch:function(x){
        process.stdout.write(`${x}`); 
    }
}





