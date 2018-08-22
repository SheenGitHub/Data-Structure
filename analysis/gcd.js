function gcd( M , N ){
    var R;
    while ( N > 0 ) {
        R = M % N;
        M = N;
        N = R;
    }
    return M;
}

var result = gcd( 1989, 1590 );
console.log( result );
