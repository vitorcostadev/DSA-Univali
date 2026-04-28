/*
1. Elabore um programa que verifique, por meio da estrutura de dados pilha dinâmica genérica, se
uma expressão aritmética está sintaticamente correta em relação ao uso de parênteses, colchetes e
chaves. O programa deverá permitir que o usuário digite uma expressão aritmética qualquer e
apresente como resultado a avaliação corresponde aos corretos posicionamento e quantidade de
parênteses, colchetes e chaves da expressão lida. 
*/

#include <iostream>
#include <vector>
#include "../Stack.h"

using namespace std;

bool isValidExp(string expression, Stack<char> &stack){
    for(int i = 0; i < expression.length(); i++){
        char ch = expression.at(i);
        if(ch == '(' || ch == '[' || ch == '{'){
            push(stack, ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(isEmpty(stack)) return false;
            
            char opening = top(stack);
            if((ch == ')' && opening != '(') || 
               (ch == ']' && opening != '[') || 
               (ch == '}' && opening != '{')) {
                return false;
            }

            pop(stack);
        }
    }
    
    return isEmpty(stack);
}
int main(){
    string expressoes[] = {
        "[2 + 3 * (7 - 4)]",
        "{[(2+3]*5)}",
        "((()))",
        "[{(1+2)*(3+4)}]",
        "[{()}]",
        "[{(})]",
        "( [ { } ] )",
        "( [ { ] } )",
        "{[()()]}",
        "{[(])}",
        "((({[]})))",
        "((({[}])))",
        "[ ( ( ) ] )",
        "[ ( ( ) ) ]",
        "{ [ ( 1 + 2 ) * 3 ] }",
        "{ [ ( 1 + 2 ] * 3 ) }",
        "[[[[]]]]",
        "[[[[}]]]]",
        "()[]{}",
        "([)]"
    };

    for(int i = 0; i<20; i++){
        Stack<char> exp; create(exp);  
        bool isvalid = isValidExp(expressoes[i], exp);
        cout << expressoes[i] << " -> " << (isvalid ? "Valid!" : "Invalid!") << endl;
        destroy(exp);  
    }
}