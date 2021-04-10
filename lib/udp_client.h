#ifndef UDP_CLIENT_H_
#define UDP_CLIENT_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int socket;
    const char *hostname;
    const char *port;
} UDP_Client;

/**
 * @brief 
 * 
 * @param client 
 * @return true 
 * @return false 
 */
bool UDP_Client_Init(UDP_Client *client);

/**
 * @brief 
 * 
 * @param client 
 * @param message 
 * @param message_size 
 * @return true 
 * @return false 
 */
bool UDP_Client_Send(UDP_Client *client, const char *message, size_t message_size);




#endif /* UDP_CLIENT_H_ */
