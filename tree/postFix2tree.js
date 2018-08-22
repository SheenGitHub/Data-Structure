function Node(element){
    this.element = element;
    this.left    = null;
    this.right   = null;
}
var input = "a b c * + d e * f + g * +";

var input2 = 'a b + c d e + * *';

function createTree(input){
    var stack = [], i, node, left , right;
    var operator = ['+', '*'];
    for( i = 0; i < input.length; i++ ) {
        var el = input[i];
        if( operator.indexOf(el) > -1 ){
            node = new Node(el);
            node.right = stack.pop();
            node.left = stack.pop();
            stack.push(node);
        }else if ( el !== ' '){
            stack.push( new Node( el ) );
        }
    }
    return stack.pop();
}

function inOrder(node){
    if(node !== null){
        inOrder(node.left);
        if(!inOrder.result){
            inOrder.result = [];
        }
        inOrder.result.push(node.element);
        inOrder(node.right);
    }
}

var tree = createTree(input2);
delete inOrder.result;
inOrder(tree);
var inResult = inOrder.result.join(" ");
console.log('InOrder traverse result of tree from postFix:',input2);
console.log(inResult)

