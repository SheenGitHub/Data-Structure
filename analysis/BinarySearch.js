function BinarySearch(arr, x){
    var left = 0, right = arr.length-1,
        center;
    while( left <= right ){
        center =(( left + right ) / 2) | 0;
        if( a[center] === x ) return center;
        else if ( x < a[center] ) right = center - 1;
        else left = center + 1;
    }
    return -1;
}

var a = [ 2,3,4,6,8,9,11,13,15,37,45,66,78,95];
var result = BinarySearch(a, 78);
console.log(result);
