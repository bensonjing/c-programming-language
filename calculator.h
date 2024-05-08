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

#define NUMBER '0'
#define MATHOP '1'

int getop(char[]); 
void push(double);
double pop(void);
void printTop(void); 
void duplicate(void);
void swap(void); 
void clear(void);
