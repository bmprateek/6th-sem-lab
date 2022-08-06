var express = require('express');
var app = express();

app.get('/', function(req, res) {
 res.send('Welcome to the Engineering College!');
});

app.get('/branches', function(req, res) {
 res.send('The different branches offered in our college are:<br>1.CivilEngineering<br>2.Mechanical Engineering<br>3.Electrical and Electronics Engineering<br>4.Computer Science');
});

app.get('/branches/civil', function(req, res) {
res.send('<p style="background-color:lightblue;font-family:verdana;">Civil Engineering </p>');
});

app.get('/branches/mechanical', function(req, res) {
  res.send('<p style="background-color:lightgreen;">Mechanical engineering.</p>');
});

app.get('/branches/electrical', function(req, res) {
  res.send('<p style="background-color:red;">Electrical engineering.</p>');
});
app.get('/branches/computers',function(req,res){
 res.send('<p style="background-color:black;">Computer science.</p>');
});
 app.listen(3000, function() {
  console.log("Example app listening at ", port)
});