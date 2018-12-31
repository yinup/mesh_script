#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 1234
#define CLIENT_PORT 5678
#define SERVER_IP "127.0.0.1"

#define BUFFER_LEN 512
#define WINDOW_SIZE_N 3

char recv_pkt_buff[WINDOW_SIZE_N][BUFFER_LEN];

typedef struct pkt_s {
	uint16_t win;
	uint16_t size;
	char data[BUFFER_LEN - (sizeof(uint16_t)*2)];
}
pkt_t;

int recv_data_layer(char *data, uint16_t data_len);
int send_data_layer(char *data, uint16_t data_len);
