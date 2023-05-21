CC = gcc
OBJ_B = barrier.o

barrier: $(OBJ_B)
	$(CC) -o barrier $(OBJ_B)
	
$(OBJ_B): barrier.c
	$(CC) -c barrier.c
	
clear:
	$(RM) barrier *.o *~
