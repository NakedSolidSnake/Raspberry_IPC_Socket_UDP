#ifndef UDP_CLIENT_H_
#define UDP_CLIENT_H_

#include <stdbool.h>

typedef struct 
{
    int socket;
} UDP_Client;

bool UDP_Client_Init(UDP_Client *client);
bool UDP_Client_Send(UDP_Client *client);




#endif /* UDP_CLIENT_H_ */
