/* 中缀表达式转后缀表达式 */
function inFix2postFix(inFix){
    var stack = [], i;
    var output = [];
    var operator = {'+':1,'*':2, '(':3}
    /* 在以下的while循环中保持top()是最新的栈顶 */
    function top(){ return stack[stack.length-1]; }

    for( i = 0; i < inFix.length; i++){
        var cur = inFix[i];
        if (cur === ')'){
            /* 当前为')'时，弹出栈顶元素，直到'(' */
            while(stack.length > 0 && top() !== '('){
                output.push(stack.pop());
            }
            /* '('直接弹出，不放入输出 */
            stack.pop();
        }else if (cur in operator){
            /* 当输入是操作符'+','*','('时，弹出栈顶元素直到遇到优先级更低的元素 */
            /* 相同优先级的元素也弹出,'('例外，遇到')'才会弹出 */
            while(stack.length > 0 && operator[top()] >= operator[cur] && top() !== '('){
                output.push(stack.pop());
            }
            /* 操作符入栈 */
            stack.push(cur);
        }else if(cur !== ' ' ){
            /* 立刻输出操作数,空字符省略 */
            output.push(cur);
        }
    }
    /* 清空输出栈内元素 */
    while(stack.length > 0){
        output.push(stack.pop());
    }

    return output.join(' ');

}
var input = "a + b * c + ( d * e + f ) * g"
var result = inFix2postFix(input);
console.log(input," 的后缀表达式是:");
console.log(result);
