CC = gcc
OBJ_T = timeout.o

timeout: $(OBJ_T)
	$(CC) -o timeout $(OBJ_T)
	
$(OBJ_T): timeout.c
	$(CC) -c timeout.c
	
clear:
	$(RM) timeout *.o *~
