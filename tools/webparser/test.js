var fs = require('fs');
var array = fs.readFileSync('raw/unfinished').toString().split("\r");
for(i in array) {
    console.log(array[i]);
}