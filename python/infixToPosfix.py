from collections import deque
from exp import expressoes, gabarito

def prior(x: str) -> int:
    
    priority = 0
    match x:
        case 'π' : priority = 0; 
        case 'λ' : priority = 1; 
        case '(' | ')': priority = 2; 
        case '+' | '-': priority = 3; 
        case '*' | '/': priority = 4; 
        case _: priority = 5; 
    
    return priority
    

def toPosfix(expression: str) -> str:
    infix = deque()
    posfix = deque()
    trab = ['π']
    x = ''
    y = ''
    
    for x in expression:
        if(not x.isspace()): infix.append(x)
    
    infix.append('λ')

    while True:
        x = infix.popleft()
        
        if(x == 'λ'): 
            while len(trab) > 1:
                posfix.append(trab.pop())
            break
        if(prior(x) == 5): posfix.append(x); continue
        if(x == '('): trab.append(x); continue
        if(x == ')'):
            y = trab.pop()
            while(y != '('):
                posfix.append(y)
                y = trab.pop()
            continue
        while(prior(x) <= prior(trab[-1])):
            y = trab.pop()
            posfix.append(y)
        trab.append(x)
    
    return "".join([f for f in posfix])

def main():
    
    for exp in expressoes:
        posfix = toPosfix(exp).strip()
        print("Infix: " + exp + "\nPosfix: " + posfix + "\n")
main()