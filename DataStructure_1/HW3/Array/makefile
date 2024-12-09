test: main.o polyArray.o
	gcc -o $@ $^ -g

%.o: %.c polyArray.h
	gcc -c -o $@ $< -g

clean:
	del *.exe *.o