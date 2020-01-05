
#include "string"
#include <fstream>
#include <string.h>
#include <deque>
#include <vector>
#include <algorithm>
#include "OpenServerCommand.h"
#include "unordered_map"
#include "Parser.h"


using namespace std;

vector<string> lexer(ifstream &fp) {
    int count = 0;
    string line;
    vector<string> lineArray;
    vector<string> splitLine;

    // insert each line to line array
    while (!fp.eof()) {
        getline(fp, line);
        lineArray.push_back(line);
        count++;
    }

    // go over the lines and saparate them
    for (std::vector<string>::iterator it = lineArray.begin(); it != lineArray.end(); ++it) {
        char *key;
        int n = (*it).length();

        // declaring character array
        char stringToChar[n + 1];

        // copying the contents of the
        // string to char array
        strcpy(stringToChar, (*it).c_str());

        // read the first key in the line
        key = strtok(stringToChar, " (,\t");
        int flag = 0;
        int flagExp = 0;
        string wholeWord = "";
        string wholeExp = "";
        while (key != NULL) {
            string keyString = key;
            // count the appearance of "
            size_t countMarks = std::count(keyString.begin(), keyString.end(), '"');
            // if we have only one " and its the first time
            if ((countMarks == 1) && flag == 0) {
                flag = 1;
                wholeWord = key;
            // if its not the first time (so its the end of the string)
            } else if ((countMarks == 1) && flag == 1) {
                flag = 0;
                wholeWord = wholeWord + " " + key;
                splitLine.push_back(wholeWord);
                wholeWord = "";
            // if its mathematic expression
            } else if ((!splitLine.empty() && splitLine[splitLine.size() - 1] == "=") ||
                    ((countMarks <= 0 && flag == 0) &&
                       (isdigit(keyString[0]) || keyString[0] == '(' || keyString.find('+') != std::string::npos ||
                        (keyString.find('-') != std::string::npos && (keyString.find("->") == std::string::npos
                                                                      && keyString.find("<-") == std::string::npos))
                        || keyString.find('*') != std::string::npos ||
                        keyString.find('/') != std::string::npos))) {
                flagExp = 1;
                wholeExp += keyString;
            // not mathematic expression and not string
            } else if (flag == 0 && flagExp == 0) {
                splitLine.push_back(key);
            // if we in the middle of string
            } else if (flag == 1 && (keyString.find('"') == std::string::npos)) {
                wholeWord = wholeWord + " " + key;
            // if we in the middle of expression
            } else if (flagExp == 1) {
                // if the key is {
                if (keyString == "{") {
                    splitLine.push_back(wholeExp);
                    splitLine.push_back(key);
                    flagExp = 0;
                } else {
                    wholeExp += keyString;
                }
            }
            if ((*it).find("sim") != std::string::npos) {
                key = strtok(NULL, " ,(\t");
            } else {
                key = strtok(NULL, " ,\t");
            }
        }
        // insert the expression
        if (flagExp == 1) {
            splitLine.push_back(wholeExp);
        }
        int m = splitLine[splitLine.size() - 1].size();
        // if the end of the line contain ) we want to remove it
        if (splitLine[splitLine.size() - 1][m - 1] == ')') {
            splitLine[splitLine.size() - 1] = splitLine[splitLine.size() - 1].substr(0, m - 1);
        }
    }
    return splitLine;
}

int main(int argc, char *argv[]) {
    try {
        ifstream flyFile;
        flyFile.open(argv[1]);
        vector<string> lexing = lexer(flyFile);
        Parser *p = new Parser(lexing);
        p->makeMap();
        flyFile.close();
        delete p;
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }
    return 0;
}