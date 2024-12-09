test: funcTest.o polyArray.o
	gcc -o $@ $^ -g

%.o: %.c polyArray.h
	gcc -o $@ -c $< -g

clean:
	del *.exe *.o

	