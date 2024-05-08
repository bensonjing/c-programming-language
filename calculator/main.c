#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calculator.h"

#define MAXOP 100  

int main() 
{
    int type; 
    double op2; 
    char input[MAXOP];

    while ((type = getop(input)) != EOF) {
        switch (type) {
        case NUMBER: 
            push(atof(input)); 
            break;

        case MATHOP: 
            if (!strcmp(input, "sin"))
                push(sin(pop()));
            else if (!strcmp(input, "cos")) 
                push(cos(pop()));
            else if (!strcmp(input, "pow")) {
                op2 = pop(); 
                push(pow(pop(), op2));
            } else {
                printf("error: unknown operation %s\n", input);
            }
            break;

        case '+': 
            push(pop() + pop());
            break; 

        case '*': 
            push(pop() * pop()); 
            break; 

        case '-': 
            op2 = pop(); 
            push(pop() - op2); 
            break; 

        case '/': 
            op2 = pop(); 
            if (op2 != 0.0) 
                push(pop() / op2); 
            else 
                printf("error: zero divisor\n");
            break; 

		case '%': 
            op2 = pop(); 
            if (op2 != 0.0) 
                push(fmod(pop(), op2)); 
            else 
                printf("error: zero divisor\n");
            break; 

        case '\n':
            printf("\t%.8g\n", pop()); 
            break; 

        default: 
            printf("error: unknown operation %s\n", input);
            break;
        }
    }
    return 0;
}
