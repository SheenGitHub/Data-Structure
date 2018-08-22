var cursor = (function(){

    function Node( element, next ){
        this.element = element;
        this.next    = next;
    }

    var CursorSpace;

    function InitializeCursorSpace() {
        var i;
        CursorSpace = Array(10);
        
        for( i = 0; i < CursorSpace.length; i++){
            CursorSpace[i] = new Node(undefined, i+1)
        }
        CursorSpace[i-1].next = 0;
    }

    function CursorAlloc() {
        var p;
        p = CursorSpace[0].next;
        CursorSpace[0].next = CursorSpace[p].next;
        CursorSpace[p].next = 0;
        return p;
    }

    function CursorFree( position ) {
        CursorSpace[position].next = CursorSpace[0].next;
        CursorSpace[0].next = position;
    }

    function IsEmpty( list ) {
        return CursorSpace[list].next === 0;
    }

    function IsLast( position, list ) {
        return CursorSpace[position].next === 0;
    }

    function Find( element, list ) {
        var p;
        p = CursorSpace[list].next;
        while( p && CursorSpace[p].element !== element )
            p = CursorSpace[p].next;
        return p;
    }

    function FindPrevious( element, list ) {
        var p;
        p = list;
        while( CursorSpace[p].next && CursorSpace[CursorSpace[p].next].element != element)
            p = CursorSpace[p].next;
        return p;
    }

    function Delete( element, list ) {
        var p, tmpCell;
        p = FindPrevious( element, list );

        if( !IsLast( p, list ) ){
            tmpCell = CursorSpace[p].next;
            CursorSpace[p].next = CursorSpace[tmpCell].next;
            CursorFree(tmpCell);
        }
    }

    function Insert( element, list, position ) {
        var tmpCell;
        tmpCell = CursorAlloc();
        if( tmpCell === 0 )
            throw new Error("out of space");
        CursorSpace[tmpCell].element = element;
        CursorSpace[tmpCell].next = CursorSpace[position].next;
        CursorSpace[position].next = tmpCell;
        return tmpCell;
    }

    return {
        InitializeCursorSpace, CursorAlloc, CursorFree,
        IsEmpty, IsLast, Find, FindPrevious, Delete, Insert

    }

}());

cursor.InitializeCursorSpace();

list1 = cursor.CursorAlloc();
console.log("Alloc list1 at:",list1);
var p1 = cursor.Insert('b',list1,list1);
console.log("insert 'b' at:",p1);
var p2 = cursor.Insert('f',list1,p1);
console.log("insert 'f' at:",p2);
var p3 = cursor.Insert('head',list1,p1);
console.log("insert 'head' after ",p1," at:",p3);
var f1 = cursor.Find('f',list1)
console.log("find 'f' at:",f1);
cursor.Delete('f',list1)
console.log("delete 'f' from list1");
list2 = cursor.CursorAlloc();
console.log("Alloc list2 at:",list2);
