var a = ['A','B','C','D','E','F'];
var stack = [];
var count = 0;

function AllRank(array, start, end){
    var i;
    if( start === end )
    {
        console.log((++count)+':'+array.join(''));
        
    }
    for( i = start + 1; i <= end; i++){
        swap( array, start, i);
        AllRank( array, start + 1, end);
        swap( array, start, i);

    }
}

function swap( array, i, j ) {
    var tmp    = array[ i ];
    array[ i ] = array[ j ];
    array[ j ] = tmp;
}

AllRank( a, 0, 6 );
