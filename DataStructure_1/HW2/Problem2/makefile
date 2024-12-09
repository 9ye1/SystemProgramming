queueTest: main_queue.o l_cQueue.o dlist.o
	gcc -o $@ $^ -g

%.o: %.c l_cQueue.h dlist.h
	gcc -o $@ -c $< -g

clean:
	del *.exe *.o