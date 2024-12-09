all: in2post

in2post: stack.o in2post.o
	gcc -o $@ $^

%.o: %.c stack.h
	gcc -c -o $@ $< -g