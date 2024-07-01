const fs = require("fs");

const stdin = fs.readFileSync(0);
const [A, B, C] = stdin.toString().split("\n");

console.log(parseInt(A) + parseInt(B) - parseInt(C))
console.log(A + B - C)
