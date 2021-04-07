#ifndef UDP_SERVER_H_
#define UDP_SERVER_H_

#include <stdbool.h>
#include <stdlib.h>

typedef void (*Event)(const char *buffer, size_t buffer_size, void *data);

typedef struct 
{
    int socket;
    int port;
    char *buffer;
    size_t buffer_size;
    Event on_receive_message;
} UDP_Server;


bool UDP_Server_Init(UDP_Server *server);
bool UDP_Server_Run(UDP_Server *server, void *user_data);


#endif /* UDP_SERVER_H_ */
