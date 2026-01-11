lab2: lab2.o symtab.o optab.o
	gcc lab2.o symtab.o optab.o -o lab2

lab2.o: lab2.c symtab.h optab.h
	gcc -c lab2.c

symtab.o: symtab.c symtab.h
	gcc -c symtab.c

optab.o: optab.c optab.h
	gcc -c optab.c

clean:
	rm *.o lab2