#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void fillVec(vector<int> &progVec, string file) {
    ifstream input(file);
    if (!input.is_open()) {
        cout << "file not opened" << endl;
        return;
    }
    string contents;
    getline(input, contents);
    stringstream prog(contents);
    while (prog.good()) {
        string item;
        getline(prog, item, ',');
        int itemInt = stoi(item);
        progVec.push_back(itemInt);
    }
}

void printVec(vector<int> &vec) {
    for(int item:vec) {
        cout << item << ' ';
    }
    cout << endl;
}

int process(vector<int> &progVec, int codeIndex) {
    int code = progVec.at(codeIndex);
    int a = progVec.at(codeIndex+1);
    int b = progVec.at(codeIndex+2);
    int result = progVec.at(codeIndex+3);
    switch (code){
        case 1:
            progVec.at(result) = progVec.at(a) + progVec.at(b);
            
        break;

        case 2:
            progVec.at(result) = progVec.at(a) * progVec.at(b);

        break;

        case 99:
            return -1;
        break;

    }

    return codeIndex + 4;

}

int main() {


    for(int noun = 0; noun < 100; noun++){
        for(int verb = 0; verb < 100; verb++) {
            
            vector<int> program;
            string filename = "input.txt";
            fillVec(program, filename);

            program.at(1) = noun;
            program.at(2) = verb;

            int codeindex = 0;

            while (codeindex != -1)
            {
                codeindex = process(program, codeindex);
            }
            // cout << program.at(0) << endl;
            if(program.at(0) == 19690720){
                cout << (100 * noun) + verb << endl;
                exit(0);
            }
        }
    }

    return 0;
}