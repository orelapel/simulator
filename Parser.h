//
// Created by noa on 26/12/2019.
//

#ifndef SIMULATOR_PARSER_H
#define SIMULATOR_PARSER_H
#include <string>
#include <bits/unordered_map.h>
#include "vector"
#include "Command.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "ChangeCommand.h"
#include "Print.h"
#include "Sleep.h"
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "unordered_map"
#include <iostream>
#include <algorithm>
#include "IfCommand.h"
#include "LoopCommand.h"



class Parser {
    vector<string> lexer;
    unordered_map<string, Command*> commandMap;
public:
    ~Parser(){
        unordered_map<string, Command*>::iterator it;
        for ( it = commandMap.begin(); it != commandMap.end(); it++ ) {
            delete (*it).second;
        }
    }
    Parser(vector<string> lex);
    void makeMap();
};

#endif //SIMULATOR_PARSER_H