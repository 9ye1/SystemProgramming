DEPS = listP3.h l_stackP3.h

parenthesis: parenthesis.o l_stackP3.o listP3.o
	gcc -o $@ $^ -g

%.o: %.c $(DEPS)
	gcc -o $@ -c $< -g

clean:
	del *.exe *.o