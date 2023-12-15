#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

enum Color {
    WHITE = 0,
    GREEN = 1,
    RED = 2,
    YELLOW = 3,
    BLUE = 4,
    ORANGE = 5
};

class RubicsCube {
public:
    RubicsCube();
    ~RubicsCube();

    void initializeRandom();
    void loadFromFile(const char* filename);
    bool isSolved();
    void rotateFace(int face, bool clockRotate);
    void rotateAdjacentFace(int face, bool clockRotate);
    void printCube();
private:
    Color cube[6][3][3];
protected:

};