//
// Created by noa on 29/12/2019.
//

#include "unordered_map"
#include "Parser.h"

Parser::Parser(vector<string> lex) {
    lexer = lex;
}

void Parser::makeMap() {
    commandMap.insert(pair<string, Command *>("openDataServer", new OpenServerCommand()));
    commandMap.insert(pair<string, Command *>("connectControlClient", new ConnectCommand()));
    commandMap.insert(pair<string, Command *>("var", new DefineVarCommand()));
    commandMap.insert(pair<string, Command *>("=", new ChangeCommand()));
    commandMap.insert(pair<string, Command *>("Print", new Print()));
    commandMap.insert(pair<string, Command *>("Sleep", new Sleep()));
    commandMap.insert(pair<string, Command *>("if", new IfCommand()));
    commandMap.insert(pair<string, Command *>("while", new LoopCommand()));

    // initilize
    SimbolTable *st = new SimbolTable();
    st->createMapForSimulatorInfo();
    st->createNumberedMapForSim();
    int index = 0;

    // play the commands
    while (index < lexer.size()) {
        if (lexer[index + 1] == "=") {
            Command *c = commandMap.find(lexer[index + 1])->second;
            if (c != NULL) {
                index += 1;
                index = index + c->execute(lexer, index, st);
            }
        } else {
            Command *c = commandMap.find(lexer[index])->second;
            if (c != NULL) {
                index += c->execute(lexer, index, st);
            }

        }
    }
    // stop the threads
    st->dontstop = false;

    delete st;
    unordered_map<string, Command*>::iterator it;
    for ( it = commandMap.begin(); it != commandMap.end(); it++ ) {
        delete (*it).second;
    }
}