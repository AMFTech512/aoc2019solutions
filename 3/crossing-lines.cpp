#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct segment {
    char dir;
    int length;
};

void fillVec(vector<segment> &vec1, vector<segment> &vec2, string file) {

    ifstream input(file);
    if (!input.is_open()) {
        cout << "file not opened" << endl;
        return;
    }

    string contents;
    getline(input, contents);
    stringstream wire1(contents);
    while (wire1.good()) {
        string item;
        segment next;
        getline(wire1, item, ',');
        next.dir = item[0];
        next.length = atoi(item.c_str()+1);
        vec1.push_back(next);
    }

    getline(input, contents);
    stringstream wire2(contents);
    while (wire2.good()) {
        string item;
        segment next;
        getline(wire2, item, ',');
        next.dir = item[0];
        next.length = atoi(item.c_str()+1);
        vec2.push_back(next);
    }
}

int addCoord(int hor, int ver, int **arr) {
    if (arr[hor][ver] == 0) {
                    arr[hor][ver] +=1;
                } else {

                    // TODO: finish this function

                    // dist = (abs(hor-5000) + abs(ver-5000));
                    // if (dist < min) {
                        
                    //     min = dist;
                    // }
                }
}

int followWire(vector<segment> &segs, int **arr) {
    int hor = 5000, ver = 5000, dist = 0, min = 100000, coord = 0;
    for (segment seg:segs) {
        if (seg.dir == 'R') {
            for (int i = 0; i < seg.length; i++) {
                hor = hor + 1;
                // TODO: integrate 'addCoord()' function somehow
            }

        }
}
}

int main() {

    vector<segment> line1, line2;

    fillVec(line1, line2, "./input.txt");

    // print segments
    // for(segment currentSeg:line1) {
    //     cout << currentSeg.dir << currentSeg.length << " ";
    // }
    // cout << endl << endl;

    // for(segment currentSeg:line2) {
    //     cout << currentSeg.dir << currentSeg.length << " ";
    // }
    // cout << endl;

    int space[10000][10000] = {0};

    
    return 0;
}