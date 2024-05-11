objects = main.o stack.o getop.o getch.o

output : $(objects)
	cc -o output $(objects) -lm

$(objects) : calculator.h

clean : 
	rm output $(objects)
