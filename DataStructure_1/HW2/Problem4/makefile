DEPS = listP4.h l_stackP4.h

in2post: in2post.o l_stackP4.o listP4.o
	gcc -o $@ $^ -g

%.o: %.c $(DEPS)
	gcc -o $@ -c $< -g

clean:
	del *.exe *.o