var express = require('express'); 
var app = express();  
var MongoClient = require('mongodb').MongoClient;
var expressValidator = require('express-validator');
// var bodyParser = require("body-parser");
app.use(expressValidator());
// app.use(bodyParser.urlencoded({ extended: false }));
// app.use(bodyParser.json());
// app.use(express.static("public"));

app.get('/', function (req, res) {  
   res.sendFile( __dirname + "/" + "index.html" );  
    
})  
app.get('/process_get', function (req, res) {  
req.checkQuery('name' , 'only characters in name or shud not be empty').isAlpha().notEmpty();
req.checkQuery('usn' , 'Invalid usn or shud not be empty').matches(/1MS\d{2}CS\d{3}/).notEmpty();
req.checkQuery('sex' , 'shud not be empty').notEmpty();
req.checkQuery('sem' , 'shud not be empty').notEmpty();
req.checkQuery('branch' , 'shud not be empty').notEmpty();
req.checkQuery('college' , 'shud not be empty').notEmpty();
req.checkQuery('ac' , 'shud not be empty').notEmpty();
req.checkQuery('pn' , 'shud not be empty').notEmpty();
req.checkQuery('bn' , 'shud not be empty').notEmpty();

var errors = req.validationErrors()
if(errors){
    res.json(JSON.stringify(errors))
    return
}

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
    if(err) 
    console.log(err);
    // var db = client.db('db');
    var collection = db.collection('student');
    collection.insertMany(response);

    // Locate all the entries using find
    collection.find().toArray(function(err, results) {
        console.log(results);
        if(err) throw err
        res.render('disp1.ejs',{students:results})
        // Let's close the db
        // client.close();
        db.close();
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