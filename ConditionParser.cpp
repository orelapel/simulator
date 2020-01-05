//
// Created by noa on 29/12/2019.
//

#include "ConditionParser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "ChangeCommand.h"
#include "Print.h"
#include "Sleep.h"
#include "IfCommand.h"
#include "LoopCommand.h"

using namespace std;

void ConditionParser::makeMap() {
    // make the map command
    commandMap.insert(pair<string, Command *>("openDataServer", new OpenServerCommand()));
    commandMap.insert(pair<string, Command *>("connectControlClient", new ConnectCommand()));
    commandMap.insert(pair<string, Command *>("var", new DefineVarCommand()));
    commandMap.insert(pair<string, Command *>("=", new ChangeCommand()));
    commandMap.insert(pair<string, Command *>("Print", new Print()));
    commandMap.insert(pair<string, Command *>("Sleep", new Sleep()));
    commandMap.insert(pair<string,Command*>("if",new IfCommand()));
    commandMap.insert(pair<string,Command*>("while",new LoopCommand()));
}
void ConditionParser::initCondition(vector<string> lexer, int index,SimbolTable *st) {
    string con;
    i = index + 1;

    // build the condition
    while (lexer[i] != "{") {
        con += lexer[i];
        i++;
    }

    vector<string> variables;
    int j=0;
    int flag;
    string wholeWord;

    // find the variables and push the m to the vector
    while (j<con.length()) {
        wholeWord ="";
        flag=0;
        while (j<con.length() && con[j]!='(' && con[j]!=')'&& con[j]!='+'&&con[j]!='-'&&con[j]!='*'&&con[j]!='/'&&con[j]!='='&&con[j]!='!'
                && con[j]!='<'&&con[j]!='<'){
            wholeWord =wholeWord+con[j];
            j++;
            flag=1;
        }
        if (isalpha(wholeWord[0])){
            variables.push_back(wholeWord);
        }
        if (flag==0){
            j++;
        }
    }

    // build the set variables string
    string setVar;
    if (!variables.empty()){
        for(std::vector<string>::iterator it = variables.begin() ; it != variables.end(); ++it){
            setVar += (*it)+ "=" +to_string(st->varMap[(*it)]->getVal());
            if((it+1)!=variables.end()){
                setVar=setVar+";";
            }
        }
    }

    // calculate the condition
    Interpreter *inter = new Interpreter();
    Expression *exp = nullptr;
    try {
        if (!variables.empty()){
            inter->setVariables(setVar);
        }
        exp = inter->interpret(con);
        condition = exp->calculate();
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
}