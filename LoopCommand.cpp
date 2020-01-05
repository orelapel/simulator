//
// Created by noa on 29/12/2019.
//

#include "LoopCommand.h"

LoopCommand::LoopCommand() {}

int LoopCommand::execute(vector<string> lexer, int index, SimbolTable *st) {
    makeMap();
    initCondition(lexer, index, st);
    i += 1;
    vector<string> subLexer;
    // build sub lexer that contains the actions inside the while
    while ((lexer[i] != "}") && (i < lexer.size())) {
        subLexer.push_back(lexer[i]);
        i++;
    }
    // while the condition is true
    while (condition == 1) {
        int j = 0;
        // play the commands
        while (j < subLexer.size()) {
            if (subLexer[j + 1] == "=") {
                Command *c = commandMap.find(subLexer[j + 1])->second;
                if (c != NULL) {
                    j += 1;
                    j = j + c->execute(subLexer, j, st);
                }
            } else {
                Command *c = commandMap.find(subLexer[j])->second;
                if (c != NULL) {
                    j += c->execute(subLexer, j, st);
                }
            }

        }
        initCondition(lexer, index, st);
    }
    return subLexer.size() + 6;

}