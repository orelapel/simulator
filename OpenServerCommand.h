//
// Created by noa on 18/12/2019.
//
#include <unistd.h>
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <vector>
#include <netinet/in.h>
#include "Command.h"
#include "SimbolTable.h"
#include <stdio.h>
#include <string.h>
#include "Interpreter.h"
#include "Expression.h"
#include <semaphore.h>



#ifndef SIMULATOR_OPENSERVERCOMMAND_H
#define SIMULATOR_OPENSERVERCOMMAND_H

using namespace std;

class OpenServerCommand:public Command {
    int port;
    int client_socket;
public:
    ~OpenServerCommand(){

    }
    virtual int execute(vector<string>lexer, int index, SimbolTable *st) {
        // calculate the port
        Interpreter *inter = new Interpreter();
        Expression *exp = nullptr;
        try {
            exp = inter->interpret(lexer[index+1]);
            port = exp->calculate();
            delete exp;
            delete inter;
        } catch (const char *e) {
            if (exp != nullptr) {
                delete exp;
            }
            if (inter != nullptr) {
                delete inter;
            }
        }

        // create the socket
        int socketfd = socket (AF_INET,SOCK_STREAM,0);
        if (socketfd == -1){
            std::cerr<<"Could not create a socket"<<std::endl;
            return -1;
        }
        sockaddr_in address;
        address.sin_family=AF_INET;
        address.sin_addr.s_addr=INADDR_ANY;
        address.sin_port=htons(port);
        if (bind(socketfd,(struct sockaddr*) &address, sizeof(address))==-1){
            std::cerr<<"Could not bind the socket to an Ip"<<std::endl;
            return -2;
        }

        if (listen(socketfd,SOMAXCONN)==-1) {
            std::cerr<<"Error listen"<<std::endl;
            return -3;
        }

        client_socket=accept(socketfd,(struct sockaddr*)&address,(socklen_t*)&address);
        if (client_socket==-1){
            std::cerr<<"Error accepting client"<<std::endl;
            return -4;
        }
        close(socketfd);

        // waiting until we get yhe first line
        char buffer[1024] = {0};
        int valread=1;
        float param [36];
        valread = read(client_socket , buffer, 1);

        thread(&OpenServerCommand::OpenServerCommandFunc, this, st).detach();
      return 2;
    }

    int OpenServerCommandFunc(SimbolTable *st) {
        //reading from client
        char buffer[1] = {0};
        string line;
        float param [36];
        while (st->dontstop) {
            read(client_socket , buffer, 1);
            // read a line
            while(buffer[0]!='\n') {
                line += buffer[0];
                read(client_socket , buffer, 1);
            }

            char* value;
            int n = line.length();

            // declaring character array
            char lineToChar[n + 1];

            strcpy(lineToChar, line.c_str());
            // split the line by ,
            value= strtok (lineToChar,",");
            int j=0;
            while (value != NULL)
            {
                param[j] = stof(value);
                value = strtok (NULL, ",");
                j++;
            }
            // insert every value to the appropriate simulator path
            map<int, string>::iterator it;
            int k = 0;
            for ( it = st->numSimMap.begin(); it != st->numSimMap.end(); it++ ) {
                st->simMap[it->second]->setVal(param[k]);
                k++;
            }
            line = "";
        }
    }
};

#endif //SIMULATOR_OPENSERVERCOMMAND_H
