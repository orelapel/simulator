//
// Created by noa on 21/12/2019.
//

#ifndef SIMULATOR_DEFINEVARCOMMAND_H
#define SIMULATOR_DEFINEVARCOMMAND_H

#include "Command.h"
#include "InformationVar.h"
#include <string>
#include <map>
#include "SimbolTable.h"

using namespace std;

class DefineVarCommand: public Command{
public:
    ~DefineVarCommand() {

    }
    virtual int execute (vector<string>lexer, int index, SimbolTable *st) {
        double valueVarInfo;
        string pathVarInfo;
        string directionVarInfo;
        map<string, InformationVar*>::iterator it;
        // take the path in the sim without the "
        string path = lexer[index+4].substr(1, lexer[index+4].size()-2);
        // check the direction
        if (lexer[index+2] == "<-") {
            // make the var and the path point to the same information
            for ( it = st->simMap.begin(); it != st->simMap.end(); it++ ) {
                if (it->first == path) {
                    st->varMap.insert(pair<string, InformationVar *>(lexer[index + 1], it->second));
                    st->varMap[lexer[index + 1]]->setDir("<-");
                    break;
                }
            }
            return 5;
        } else if(lexer[index+2]=="->") {
            // create new information and point to it
            InformationVar *iv= new InformationVar(0, lexer[index+2], path);
            st->varMap.insert(pair<string, InformationVar*>(lexer[index+1], iv));
            st->simMap[path]->setDir("->");
            return 5;
        } else if(lexer[index+2]=="=") {
            // calculate the assign
            string assign = lexer[index + 3];
            vector<string> variables;
            int j = 0;
            int flag;
            string wholeWord;
            while (j < assign.length()) {
                wholeWord = "";
                flag = 0;
                while (j < assign.length() && assign[j] != '(' && assign[j] != ')' && assign[j] != '+' &&
                       assign[j] != '-' && assign[j] != '*' && assign[j] != '/') {
                    wholeWord = wholeWord + assign[j];
                    j++;
                    flag = 1;
                }
                if (isalpha(wholeWord[0])) {
                    variables.push_back(wholeWord);
                }
                if (flag == 0) {
                    j++;
                }
            }
            // make the set variables string
            string setVar;
            if (!variables.empty()) {
                for (std::vector<string>::iterator it = variables.begin(); it != variables.end(); ++it) {
                    setVar += (*it) + "=" + to_string(st->varMap[(*it)]->getVal());
                    if ((it + 1) != variables.end()) {
                        setVar = setVar + ";";
                    }
                }
            }
            // calculate
            Interpreter *inter = new Interpreter();
            Expression *exp = nullptr;
            try {
                if (!variables.empty()) {
                    inter->setVariables(setVar);
                }
                exp = inter->interpret(assign);
                valueVarInfo = exp->calculate();
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
            InformationVar *iv = new InformationVar(valueVarInfo, "", "");
            st->varMap.insert(pair<string, InformationVar *>(lexer[index + 1], iv));
            return 4;
        }
        return 5;
    }
};

#endif //SIMULATOR_DEFINEVARCOMMAND_H