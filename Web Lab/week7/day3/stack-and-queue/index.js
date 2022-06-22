var mod1 = require('./stack');
var mod2 = require('./queue');
const st = new mod1();
const qu = new mod2();
console.log("queue");
qu.enqueue(1);
qu.enqueue(2);
qu.enqueue(3);
qu.enqueue(4);
qu.enqueue(5);
qu.print();
qu.dequeue();
qu.print();
qu.clear();
qu.print();
console.log("stack");
st.push(1)
st.push(2)
st.push(3);
st.push(4);
st.push(5);
st.print();
st.pop();
st.print();
st.clear();
st.print();
