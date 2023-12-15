#include <iostream>
#include "RubicsCube.h"

using namespace std;

int main() {
    RubicsCube cube1;
    cube1.printCube();
    cout << cube1.isSolved() << endl;
    cout << "-----------------------------" << endl;
    cube1.rotateFace(0, true);
    cube1.printCube();
    cout << cube1.isSolved() << endl;
    cout << "-----------------------------" << endl;
    cube1.loadFromFile("fileColors.txt");
    cube1.printCube();
    cout << cube1.isSolved() << endl;
    cout << "-----------------------------" << endl;
    cube1.rotateFace(0, false);
    cube1.printCube();
    cout << cube1.isSolved() << endl;
    return 0;
}