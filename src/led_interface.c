#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <led_interface.h>


#define _1ms    1000

bool LED_Run(UDP_Server *server, LED_Data *led)
{

	if(led->interface->Init(led->object) == false)
		return false;

	if(UDP_Server_Init(server) == false) 
		return false;


	while(true)
	{
		UDP_Server_Run(server, led);
	}

	return false;	
}
