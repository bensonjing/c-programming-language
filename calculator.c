#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */ 

int getop(char[]); 
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() 
{
    int type; 
    double op2; 
    char s[MAXOP]; 

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: 
            push(atof(s)); 
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
        case '\n': 
            printf("\t%.8g\n", pop()); 
            break; 
        default: 
            printf("error: unknown operation %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of stack */ 

int sp = 0;        /* next free stack position */ 
double val[100];   /* value stack */ 

void push(double f) 
{
    if (sp < MAXVAL)
        val[sp++] = f; 
    else 
        printf("error: stack pull, can't push %g\n", f); 
}

double pop(void) 
{
    if (sp > 0) 
        return val[--sp]; 
    else 
        printf("error: stack empty\n"); 
        return 0.0;
}

#include <ctype.h> 

int getch(void); 
void ungetch(int); 

/* getop: get the next operator or operand */ 
int getop(char s[])
{
    int i, c; 

    while ((s[0] = c = getch()) == ' ' || c == '\t');  
    s[1] = '\0'; 
    if (!isdigit(c) && c != '.') /* not a number */
        return c;	   
	i = 0; 
	if (isdigit(c))				 /* collect integer part */ 
		while (isdigit(s[++i] = c = getch())); 
	if (c == '.')				 /* collect fraction part */ 
		while (isdigit(s[++i] = c = getch())); 
	s[i] = '\0'; 
	if (c != EOF)
		ungetch(c); 
	return NUMBER;
}

#define BUFSIZE 100 

char buf[BUFSIZE]; 
int bufp = 0; 

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) 
{
	if (bufp >= BUFSIZE)
		printf("error: too many character in buffer");
	else 
		buf[bufp++] = c;
}
