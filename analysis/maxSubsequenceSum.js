
function maxsubSum1(a){
    var thissum, maxsum, i, j, k, N = a.length;
    maxsum = 0;
    for( i = 0; i < N; i++ ) {
        thissum = 0;
        for( j = i; j < N; j++ ){
            thissum += a[j];
            if(thissum > maxsum)
                maxsum = thissum;
            
        }
    }
    return maxsum;
}

var arr = [ -2, 11, -4, 1, 3, -5, -2, 5, -2, 3, -6, 3, 4, -3, 5, 6 , -5, 9, -5, -10, 2, 3, -7, 5, 3, -5, 12, -3, -2,-1, 3, -10, 6, 7 ];
console.time("exhaustion");
console.log(maxsubSum1(arr));
console.timeEnd("exhaustion");

function maxsubDC(a,left,right){
    var 
        maxLeft, maxRight,
        maxLeftBorderSum, maxRightBorderSum,
        leftBorderSum, rightBorderSum,
        center, i;
    if(left === right){
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    center = parseInt((left+right)/2,10);
    maxLeft = maxsubDC(a, left, center);
    maxRight = maxsubDC(a, center+1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for( i = center; i >= left; i--){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0;
    rightBorderSum = 0;

    for( i = center+1; i <= right; i++){
        rightBorderSum += a[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max3(maxLeft, maxRight, maxLeftBorderSum+maxRightBorderSum);

}

function max3(a,b,c){
    return (a > b)?( a > c ? a : c):( b > c ? b : c);
}

console.time("Divided and Conque");
console.log(maxsubDC(arr,0, arr.length - 1));
console.timeEnd("Divided and Conque");
