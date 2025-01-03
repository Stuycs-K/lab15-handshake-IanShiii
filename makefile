.PHONY: compile server client clean

compile: client_ex server_ex

server: server_ex
	@./server_ex

client: client_ex
	@./client_ex

client_ex: basic_client.o pipe_networking.o
	@gcc -o client_ex basic_client.o pipe_networking.o

server_ex: persistent_server.o pipe_networking.o
	@gcc -o server_ex persistent_server.o pipe_networking.o

basic_client.o: basic_client.c pipe_networking.h
	@gcc -c basic_client.c

persistent_server.o: persistent_server.c pipe_networking.h
	@gcc -c persistent_server.c

basic_server.o: basic_server.c pipe_networking.h
	@gcc -c basic_server.c

pipe_networking.o: pipe_networking.c pipe_networking.h
	@gcc -c pipe_networking.c

clean:
	@rm client_ex server_ex *.o *~
