var my_http = require("http");

my_http.createServer(function(request , response)
{
    response.writeHeader(200 , {"Content-Type":"text/plain"});
    response.write("Hello dudeman");
    response.end();

}).listen(5000);
console.log("server running on 5000");