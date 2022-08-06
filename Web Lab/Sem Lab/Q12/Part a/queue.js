function Queue(){
    this.queue = [];
}

Queue.prototype.enqueue = function(ele){
    this.queue.push(ele);
}

Queue.prototype.dequeue = function(){
    return this.queue.shift();
}

Queue.prototype.clear = function(){
    this.queue = [];
}

Queue.prototype.print = function(){
    if(! this.queue){
        consosle.log("empty");
    }
    else{
        for(var i=0;i<this.queue.length; i++)
        console.log(" "+ this.queue[i]);
    }
}
module.exports = Queue;