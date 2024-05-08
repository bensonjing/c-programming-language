#include <stdio.h>
#include "calculator.h"

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
