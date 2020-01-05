//
// Created by noa on 22/12/2019.
//

#ifndef SIMULATOR_PRINT_H
#define SIMULATOR_PRINT_H


#include "Command.h"
#include <vector>
#include <iostream>

class Print: public Command{
    ~Print(){

    }
    virtual int execute(vector<string>lexer, int index, SimbolTable *st) {
        // if the paramater is not expression
        if (lexer[index+1].find('+') == std::string::npos&& lexer[index+1].find('-') == std::string::npos&&
        lexer[index+1].find('*') == std::string::npos&& lexer[index+1].find('/') == std::string::npos) {
            //if it is var
            if  (st->varMap.find(lexer[index+1])!=st->varMap.end()){
                cout<<st->varMap.find(lexer[index+1])->second->getVal()<<endl;
            }
            else {
                // if it is string
                if (lexer[index+1][0] == '"') {
                    cout<<lexer[index+1].substr(1,lexer[index+1].length()-2)<<endl;
                }
                else {
                    //if we recieve var tant not found in our data
                    throw("we cant print variable that is not in our data");
                }
            }
        } else {
            //if it is expression
            vector<string> variables;
            int j = 0;
            int flag;
            string wholeWord;
            string assign = lexer[index+1];

            // find the variables in the assign
            while (j < assign.length()) {
                wholeWord = "";
                flag = 0;
                while (j < assign.length() && assign[j] != '(' && assign[j] != ')' && assign[j] != '+' &&
                       assign[j] != '-' && assign[j] != '*' && assign[j] != '/'){
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

            // build the set variables string
            string setVar;
            if (!variables.empty()) {
                for (std::vector<string>::iterator it = variables.begin(); it != variables.end(); ++it) {
                    setVar += (*it) + "=" + to_string(st->varMap[(*it)]->getVal());
                    if ((it + 1) != variables.end()) {
                        setVar = setVar + ";";
                    }
                }
            }

            // take care of the case -(-var)
            int flagVar=0;
            string newAssign = "";
            int k=0;
            int t=0;
            while (k<assign.length()) {
                if (assign[k]=='-' && isalpha(assign[k+1])){
                    newAssign = assign.substr(0, k+1)+ "("; //continue
                    t=k+1;
                    string var="";
                    while(assign[t]!='+'&&assign[t]!='-'&& assign[t]!='*'&&assign[t]!='/'&&t<assign.length()) {
                        var =var+assign[t];
                        t++;
                        flagVar=1;
                    }
                    newAssign = newAssign + var + ")" +  assign.substr(t, assign.length() - 1);
                }
                if (flagVar==1) {
                    k=t;
                    flagVar=0;
                }
                else {
                    k++;
                }
            }

            // calculate the exp
            Interpreter *inter = new Interpreter();
            Expression *exp = nullptr;
            try {
                if (!variables.empty()) {
                    inter->setVariables(setVar);
                }
                if (newAssign!=""){
                    assign =newAssign;
                }
                exp = inter->interpret(assign);
                cout<< exp->calculate()<<endl;
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
        return 2;
    }

};

#endif //SIMULATOR_PRINT_H
