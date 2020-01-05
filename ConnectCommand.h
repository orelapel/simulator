//
// Created by noa on 21/12/2019.
//
#ifndef SIMULATOR_CONNECTCOMMAND_H
#define SIMULATOR_CONNECTCOMMAND_H
#include <unistd.h>
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <vector>
#include <netinet/in.h>
#include "Command.h"
#include <arpa/inet.h>
#include "SimbolTable.h"

using namespace std;

class ConnectCommand:public Command {
    int port;
    int client_socket;
public:
    ~ConnectCommand() {

    }
    virtual int execute(vector<string>lexer, int index, SimbolTable *st) {
        // calculate the port
        Interpreter *inter = new Interpreter();
        Expression *exp = nullptr;
        try {
            exp = inter->interpret(lexer[index+2]);
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

        // create socket
        client_socket = socket (AF_INET,SOCK_STREAM,0);
        if (client_socket == -1){
            std::cerr<<"Could not create a socket"<<std::endl;
            return -1;
        }
        sockaddr_in address;
        address.sin_family=AF_INET;
        // take the address without the "
        string ad = lexer[index+1].substr(1,lexer[index+1].length()-2);
        int n = ad.length();

        // declaring character array
        char stringToChar[n + 1];

        // copying the contents of the
        // string to char array
        strcpy(stringToChar, ad.c_str());

        address.sin_addr.s_addr=inet_addr(stringToChar);
        address.sin_port=htons(port);

        int is_connect = connect(client_socket, (struct sockaddr*)&address, sizeof(address));
        if(is_connect==-1){
            std::cerr<<"Could not connect to host server"<<endl;
            return -2;
        }

        thread(&ConnectCommand::connectCommandFunc, this, st).detach();
        return 3;
    }

    int connectCommandFunc(SimbolTable *st) {
        //if here we made a connection send all the set command which in the queue
        while (st->dontstop) {
            while (!st->sets.empty()) {
                int n = st->sets.front().length();
                char set[n + 1];
                strcpy(set, st->sets.front().c_str());

                int is_sent = write(client_socket, set, strlen(set));
                if (is_sent == -1) {
                    std::cout << "Error sending message" << std::endl;
                }

                st->sets.pop();
            }
        }
        close(client_socket);
    }
};

#endif //SIMULATOR_CONNECTCOMMAND_H
