#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "MQTTClient.h"

#define ADDRESS     "dev.rightech.io:1883"
#define CLIENTID    "sita_mcs"
#define TOPIC       "base/relay/led1"
#define QOS         1
#define TIMEOUT     10000L

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: %.*s\n", message->payloadlen, (char*)message->payload);

    char*  my_payload= message->payload;	
	printf("my payload is %s\n",my_payload);

// Open LED device
    int led_fd = open("/sys/class/leds/user/brightness", O_WRONLY);
    if (led_fd < 0)
    {
        perror("Failed to open LED brightness file");
    }
   else
   {
	if (!strcmp(my_payload,"1"))
        {

            write(led_fd, "1", 1);
            printf("LED turned ON\n");
        }
        else if (!strcmp(my_payload, "0"))
        {
            write(led_fd, "0", 1);
            printf("LED turned OFF\n");
        }
        else
        {
            printf("Unknown command\n");
        }
        close(led_fd);
    }

		



    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    if (cause)
        printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[])
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    const char* uri = (argc > 1) ? argv[1] : ADDRESS;
    printf("Using server at %s\n", uri);

    if ((rc = MQTTClient_create(&client, uri, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to create client, return code %d\n", rc);
        return EXIT_FAILURE;
    }

    if ((rc = MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to set callbacks, return code %d\n", rc);
        goto destroy_exit;
    }

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        goto destroy_exit;
    }

    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);

    if ((rc = MQTTClient_subscribe(client, TOPIC, QOS)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to subscribe, return code %d\n", rc);
    }
    else
    {
        int ch;
        do {
            ch = getchar();
        } while (ch != 'Q' && ch != 'q');

        MQTTClient_unsubscribe(client, TOPIC);
    }

    MQTTClient_disconnect(client, 10000);
destroy_exit:
    MQTTClient_destroy(&client);
    return rc;
}

