CC = gcc
OBJ_C = client.o
OBJ_S = server.o

all: client server

client: $(OBJ_C)
	$(CC) -o client $(OBJ_C)

$(OBJ_C): client.c
	$(CC) -c client.c

server: $(OBJ_S)
	$(CC) -o server $(OBJ_S)
  
$(OBJ_S): server.c
	$(CC) -c server.c

clear:
	$(RM) client server *.o *~
