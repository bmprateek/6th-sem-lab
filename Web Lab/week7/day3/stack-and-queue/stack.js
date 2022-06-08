
function stack(){ this.stack = [];
}

stack.prototype.push = function(element){
	this.stack.push(element);
}

stack.prototype.pop = function(){
	let ele = this.stack.pop();
	return ele;
}

stack.prototype.print = function(){
	if(!this.stack.length){
	console.log("empty");
	}
	else{
	for(var i=0; i< this.stack.length; i++)
		console.log(" "+ this.stack[i]);
	}
}

stack.prototype.topp = function(){
return this.stack[this.stack.length - 1];
}

stack.prototype.clear=function(){
this.stack = [];
}

module.exports = stack