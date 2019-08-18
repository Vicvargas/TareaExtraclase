//
// Created by victoria on 16/8/19.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main() {

    //se crea un socket

    int listening =socket(AF_INET, SOCK_STREAM,0);
    if(listening== -1){
        cerr<<"No se puede crear un socket" << endl;
        return -1;
    }

    //se conecta a un IP/Puerto

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET,"O.O.O.O",&hint.sin_addr);


    if (bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1)
    {   cerr<< "no se puede conectar al puerto ";
        return -2;

    }
    //marcar el socket en el que estamos escuchando

    if(listen(listening,SOMAXCONN)==-1)
    {
        cerr<< "no se puede escuchar";
        return -3;
    }


    //se acepta la llamada

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host(NI_MAXHOST);
    char svc(NI_MAXSERV);

    int clientSocket = accept(listening,(sockaddr*)&client,&clientSize);

    if(clientSocket == -1)
    {
        cerr<< "Problema con la conexion del cliente";
        return -4;
    }

    //se cierra el socket que esta escuchando

    close(listening);


    memset(reinterpret_cast<void *>(host), 0, NI_MAXHOST);
    memset(reinterpret_cast<void *>(svc), 0, NI_MAXSERV);


    int result = getnameinfo((sockaddr*) &client, sizeof(client), reinterpret_cast<char *>(host), NI_MAXHOST,
                             reinterpret_cast<char *>(svc), NI_MAXSERV, 0);


    if(result)
    {
        cout << host<< "conectado en " <<svc << endl;
    }

    else
    {
        inet_ntop(AF_INET, &client.sin_addr, reinterpret_cast<char *>(host), NI_MAXHOST);
        cout << host << "Conectado en " << ntohs(client.sin_port)<< endl;
    }


    //mientras reciba un mensaje, que haga algo

    char buf[4096];

    while(true)
    {
        //int clientSocket = accept(listening,(sockaddr*)&client,&clientSize);
        //limpiar el buffer

        memset(reinterpret_cast<wchar_t *>(buf), 0, 4096);

        //esperar el mensaje

        int bytesRecv = recv(clientSocket,buf,4096,0);
        if (bytesRecv == -1)
        {
            cerr<< "Problema de conexion"<<endl;
            break;
        }

        if(bytesRecv == 0)
        {
            cout << "EL cliente se desconecto" << endl;
            break;
        }

        //Mostrar mensaje
        cout << "Recibido: " <<string(buf,0,bytesRecv)<< endl;

        //Reenviar mensaje
        send(clientSocket,buf,bytesRecv+1,0);

    }

    //Cerrar el socket
    close(clientSocket);

    return 0;

    }