BINARY = executavel

all1:
	gcc -Wall -g 1.c -o $(BINARY)

all2:
	gcc -Wall -g 2.c -o $(BINARY)

all3:
	gcc -Wall -g 3.c -o $(BINARY)

all4:
	gcc -Wall -g 4.c -o $(BINARY)

all5:
	gcc -Wall -g 5.c -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o