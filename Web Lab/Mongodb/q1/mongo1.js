var express = require('express'); 
var app = express();  
var MongoClient = require('mongodb').MongoClient;
// var expressValidator = require('express-validator');

// app.use(expressValidator())

app.get('/', function (req, res) {  
   res.sendFile( __dirname + "/" + "index.html" );  
    
})  
app.get('/process_get', function (req, res) { 

// req.checkBody('name',"Name should not be blank").notEmpty()
// req.checkBody('name',"Invalid name").isAlpha().notEmpty()
// var errors = req.validationErrors()
// if(errors){
//     res.json(JSON.stringify(errors))
//     return
// }

response = {  
    usn: req.query.usn,
    name: req.query.name,
    sex: req.query.sex,
    sem: req.query.sem,
    branch: req.query.branch,
    college: req.query.college,
    ac: req.query.ac,
    pn: req.query.pn,
    bn: req.query.bn,

   };  
   console.log(response);
   MongoClient.connect('mongodb://127.0.0.1:27017/', function(err, db) {
    if(err) throw err;
    // var db = client.db('db');
    var collection = db.collection('student');
    collection.insertMany(response);

    // Locate all the entries using find
    collection.find().toArray(function(err, results) {
        console.log(results);
        if(err) throw err
        res.render('disp1.ejs',{students:results})
        // Let's close the db
        db.close();
        // client.close()
    });
}); 
   //console.log("Sent data are (GET): first name :"+req.query.first_name+" and last name :"+req.query.last_name);   
   //res.end(JSON.stringify(response));  
    //res.end("Sent data are (GET): first name :"+req.query.first_name+" and last name :"+req.query.last_name);
})  
var server = app.listen(5000, function () {  
 
  var host = server.address().address  
  var port = server.address().port  
  console.log("Example app listening at http://%s:%s", host, port)  
  
})  