cc = gcc
server_prom = server
client_prom = client
server_obj = tcp_server.o
client_obj = tcp_client.o

$(server_prom): $(server_obj)
	$(cc) -o $(server_prom) $(server_obj) -lpthread

$(client_prom): $(client_obj)
	$(cc) -o $(client_prom) $(client_obj) -lpthread

%.o: %.c
	$(cc) -c $< -o $@

clean:
	rm -rf $(server_prom) $(client_prom) $(server_obj) $(client_obj)