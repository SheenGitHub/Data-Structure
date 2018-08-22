function pow( X, N ){
    if ( N == 0 ) return 1;
    if ( N == 1 ) return X;
    if ( N % 2 == 0) {
        return pow( X * X, N/2 );
    }else{
        return X * pow( X * X, (N/2)|0 );
    }
}

var result = pow( 3 , 5 );
console.log( result );
