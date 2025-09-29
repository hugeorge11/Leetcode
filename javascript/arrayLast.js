// George Hu 9/26
// arrayLast.js
// N: Js pract

/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if(this.length == 0){
        return -1;
    }
    //for(let i = 0; i < this.length; i++){
        
    //}
    return this[this.length-1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
