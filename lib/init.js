












/** Package.json  npm run  model init :node  lib/init.js */
const DefineModels= require(`./model`).Models;


(async () => { //User
    await  DefineModels[0].sync({force:true});
})();


(async () => {// Loginhistory
    await  DefineModels[1].sync({force:true});
})();

// json scripts commands "branch": "node lib/app.js",
