test: main.o list.o polyList.o
	gcc -o $@ $^ -g

%.o: %.c list.h polyList.h
	gcc -c -o $@ $< -g

clean:
	del *.exe *.o