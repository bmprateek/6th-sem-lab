function CheckAutomorphicNumber(num){
    const s = num.toString();  
     
    const square = num * num;
      
    const last = square % Math.pow(10, s.length);
     
    console.log(num + " square = " + square);
      
    return last == num;
}
module.exports.CheckAutomorphicNumber = CheckAutomorphicNumber;