CC = gcc
OBJ_P = prodcon.o

prodcon: $(OBJ_P)
	$(CC) -o prodcon $(OBJ_P)
	
$(OBJ_P): prodcon.c
	$(CC) -c prodcon.c
	
clear:
	$(RM) prodcon *.o *~
