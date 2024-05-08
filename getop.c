#include <stdio.h>
#include <ctype.h> 
#include "calculator.h"

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
