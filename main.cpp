
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "lista.h"
#include "abb.h"
#include <sstream>

#define PORT 8080

/**
 * Código basado en https://www.geeksforgeeks.org/socket-programming-cc/
 * @param argc
 * @param argv
 * @return
 */



int main(int argc, char const *argv[])
/**
 * Aquí empieza a correr el servidor
 */
{

    Lista *list_1 = new Lista;

    ABB *t = new ABB;


    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = " ";


    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("El socket falló");
        exit(EXIT_FAILURE);
    }


    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );


    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("Conexión fallida");
        exit(EXIT_FAILURE);
    }

    while(true){
        memset(buffer,0,0);

        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read( new_socket , buffer, 1024);
        if(buffer[0] =='q'){
            string s = buffer;
            string scut = s.substr(1,strlen(buffer)-1);
            stringstream num(scut);
            int x = 0;
            num >> x;
            list_1->add_head(x);
            list_1->print();
        }

        send(new_socket , hello , strlen(hello) , 0 );
        printf("Mensaje enviado");




    }


}
