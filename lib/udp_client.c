#include <udp_client.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

bool UDP_Client_Init(UDP_Client *client)
{
    bool status = false;
    do 
    {
        if(!client)
            break;

        client->socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(client->socket < 0)
            break;

        status = true;        
    }while(false);
    
    return status;
}

bool UDP_Client_Send(UDP_Client *client, const char *message, size_t message_size)
{
    bool status = false;
    struct sockaddr_in server;
    ssize_t send_len;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(client->hostname);
    server.sin_port = htons(atoi(client->port));

    send_len = sendto(client->socket, message, message_size, 0, (struct sockaddr *)&server, sizeof(server));
    if(send_len == message_size)
        status = true;

    return status;
}