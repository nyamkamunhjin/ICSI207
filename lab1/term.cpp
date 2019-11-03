#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;
int main() {
    system("clear");
    while (true) {
        vector<string> tokens;
        string command;

        
        cout << "$ ";
        getline(cin, command);

        istringstream iss(command);

        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));

        if (tokens.size() != 0 && tokens[0].compare("ls") == 0) {
            system("ls");
        }

        if (tokens.size() != 0 && tokens[0].compare("exit") == 0) {
            exit(1);
        }

        if (tokens.size() == 2 && tokens[0].compare("create") == 0) {
            string temp = "touch " + tokens[1];  
            system(temp.c_str());
        }

        if (tokens.size() > 2 && tokens[0].compare("input") == 0) {
            ofstream file;
            file.open(tokens[1]);

            for(int i = 2; i < tokens.size(); i++) {
                file << tokens[i] << " ";
            }
            file.close();
        }

        if (tokens.size() == 3 && tokens[0].compare("rename") == 0) {
            string temp = "mv " + tokens[1] + " " + tokens[2];
            system(temp.c_str());
        }

        if(tokens.size() == 2 && tokens[0].compare("del") == 0) {
            string temp = "rm " + tokens[1];
            system(temp.c_str());
        }
    }

    return 0;
}