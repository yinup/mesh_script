#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "shared.h"

/*
 * gcc -I. -o client client.c socket.c
 */
int main(int argc, char **argv)
{
	int sockfd = 0;
	struct sockaddr_in client_addr;
	struct sockaddr_in server_addr;
	const socklen_t slen = sizeof(struct sockaddr_in);

	char recv_buff[BUFFER_LEN] = { 0 };
	int recv_len = 0;
	char send_buff[BUFFER_LEN] = { 0 };
	
	unsigned int server_port_num = SERVER_PORT;
	unsigned int client_port_num = CLIENT_PORT;

	char *server_ip = argv[1];
	if(argc < 2)
	{
		printf("Usage: client server_id\n");
		
		return 1;
	}
	else
	{
		printf("server ip: %s\n", server_ip);
	}

	printf("CLIENT\n");

	/// Setup socket
	if (setup_socket(&sockfd) < 0) {
		return (-1);
	}
	/// Setup server addr struct
	if (setup_sockaddr_in(&server_addr, &server_port_num, server_ip) == NULL) {
		return (-1);
	}
	/// Setup client addr struct
	if (setup_sockaddr_in(&client_addr, &client_port_num, NULL) == NULL) {
		return (-1);
	}
	/// Bind CLIENT_PORT to address structure on sockfd
	if (bind_socket(sockfd, &client_addr) < 0) {
		return (-1);
	}

	for (;;) {

		printf("Enter message: ");
		gets(send_buff);
		send_data_raw(sockfd, &send_buff, BUFFER_LEN, &server_addr, slen);
		recv_data_raw(sockfd, &recv_buff, &recv_len, BUFFER_LEN, &server_addr, slen);

		printf("Reply:\n %s\n", recv_buff);

	}

	return 0;
}
