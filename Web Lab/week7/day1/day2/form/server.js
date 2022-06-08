var http = require('http'),fs = require('fs'),
	url = require('url'), qs = require('querystring');
var server = http.createServer(function(req,res)
	{
	var url_parts = url.parse(req.url,true);
		var body = '';
		if(url_parts.pathname == '/')
			fs.readFile('./form.html',function(error,data)
				{
				if(error){
				res.writeHead(404);
				res.write("Not found");
				}
				else{
				res.writeHead(200,{'Content-type':"text/html"});				console.log('serving the page form.html');
				res.write(data);
				}
					res.end();
				}
			);
		if(req.method==='GET')
		{
		if(url_parts.pathname == '/getData')
			{
			console.log("serving");
			console.log("data sent are :"+ url_parts.query.name+" and age :"+ url_parts.query.age);
			res.end("data sent are :"+ url_parts.query.name+" and age :"+ url_parts.query.age);
			}
		}
		else{
		if(req.method==='POST')
                {
                if(url_parts.pathname == 'getData')
                        console.log("serving");
			req.on('data', function(data){
				body += data;
			});
		req.on('end',function(){
		var POST = qs.parse(body);
			console.log("sent data are "+POST.name +" and "+ POST.age);
			res.end("sent data are "+POST.name +" and "+ POST.age);
		});
		}
	}
}
);
server.listen(5000);
console.log('server listening at localhost 5000');