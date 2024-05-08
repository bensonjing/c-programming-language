/* Reverse Polish calculator 
 *
 * The calculator reads arithmetic operations in postfix order and outputs the 
 * result. The calculator handles operations inlcuding: addition, subtraction,
 * multiplication, division, modulus, sine, cosine, and power
 * 
 * Examples 
 * ========
 * > 1 2 + 4 3 - * 
 * 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100  
#define NUMBER '0'
#define MATHOP '1'

int getop(char[]); 
void push(double);
double pop(void);
void printTop(void); 
void duplicate(void);
void swap(void); 
void clear(void);

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

#define MAXDEPTH 100 

int stackPointer = 0;        
double stack[MAXDEPTH];   

void push(double oprand) 
{
    if (stackPointer < MAXDEPTH)
        stack[stackPointer++] = oprand; 
    else 
        printf("error: stack pull, can't push %g\n", oprand); 
}

double pop(void) 
{
    if (stackPointer > 0) 
        return stack[--stackPointer]; 
    else 
        printf("error: stack empty\n"); 
        return 0.0;
}

void printTop(void) 
{
    if (stackPointer > 0)
        printf("top stack element: %g\n", stack[stackPointer-1]);
    else 
        printf("error: stack empty\n");
}

void duplicate(void)
{
    double top = pop(); 
    push(top); 
    push(top);
}

void swap(void)
{
    double top1 = pop(); 
    double top2 = pop(); 
    push(top1); 
    push(top2);
}

void clear(void) 
{
    stackPointer = 0;
}

#include <ctype.h> 

int getChar(void); 
void ungetChar(int); 

int getop(char input[])
{
    int index, current;

    while ((input[0] = current = getChar()) == ' ' || current == '\t');  
    input[1] = '\0'; 
	index = 0; 

    if (isalpha(current)) {
        while (isalpha(input[++index] = current = getChar())); 
        input[index] = '\0'; 
        if (current != EOF) ungetChar(current);
        return MATHOP; 
    }

    if (!isdigit(current) && current != '.' && current != '-') 
        return current;	   


	if (current == '-') {
		int next;
		if (!isdigit(next = getChar())) {
			ungetChar(next); 
			return current;            
		} else {
			input[++index] = next;
			while (isdigit(input[++index] = current = getChar())); 
		}
	}

	if (isdigit(current))
		while (isdigit(input[++index] = current = getChar())); 

	if (current == '.')
		while (isdigit(input[++index] = current = getChar())); 

	input[index] = '\0'; 
	if (current != EOF)
		ungetChar(current); 

	return NUMBER;
}

#define BUFSIZE 100 

char buffer[BUFSIZE]; 
int bufferPointer = 0; 

int getChar(void)
{
	return (bufferPointer > 0) ? buffer[--bufferPointer] : getchar(); 
}

void ungetChar(int c) 
{
	if (bufferPointer >= BUFSIZE)
		printf("error: too many character in buffer");
	else 
		buffer[bufferPointer++] = c;
}
