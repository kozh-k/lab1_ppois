#pragma once
#include "RubicsCube.h"

    RubicsCube::RubicsCube() {
        initializeRandom();
    };
    RubicsCube::~RubicsCube() {};

    void RubicsCube::initializeRandom() {
        srand(static_cast<unsigned int>(time(nullptr)));
        int colorCount[6] = { 0 };
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    Color randomColor;
                    do {
                        randomColor = static_cast<Color>(rand() % 6);
                    } while (colorCount[randomColor] >= 9);
                    cube[i][j][k] = randomColor;
                    colorCount[randomColor]++;
                }
            }
        }
    }

    void RubicsCube::loadFromFile(const char* filename) {
        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        int colorCount[6] = { 0 };

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int color;
                    inputFile >> color;

                    if (inputFile.fail()) {
                        cerr << "Error: Failed to read color from file." << endl;
                        inputFile.close();
                        return;
                    }

                    if (color < 0 || color >= 6) {
                        cerr << "Error: Invalid color code in file." << endl;
                        inputFile.close();
                        return;
                    }

                    if (colorCount[color] >= 9) {
                        cerr << "Error: Too many instances of color " << color << " in file." << endl;
                        inputFile.close();
                        return;
                    }

                    cube[i][j][k] = static_cast<Color>(color);
                    colorCount[color]++;
                }
            }
        }
        inputFile.close();
    }

    bool RubicsCube::isSolved() {
        for (int i = 0; i < 6; ++i) {
            Color currentColor = cube[i][0][0];
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (cube[i][j][k] != currentColor)
                        return false;
                }
            }
        }
        return true;
    }

    void RubicsCube::rotateFace(int face, bool clockRotate) {
        Color temp_color[3][3]{};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp_color[i][j] = cube[face][i][j];
            }
        }

        if (clockRotate) {
            cube[face][0][0] = temp_color[2][0];
            cube[face][0][1] = temp_color[1][0];
            cube[face][0][2] = temp_color[0][0];
            cube[face][1][0] = temp_color[2][1];
            cube[face][1][1] = temp_color[1][1];
            cube[face][1][2] = temp_color[0][1];
            cube[face][2][0] = temp_color[2][2];
            cube[face][2][1] = temp_color[1][2];
            cube[face][2][2] = temp_color[0][2];

            if (face == 0) {
                rotateAdjacentFace(1, true);
                rotateAdjacentFace(2, true);
                rotateAdjacentFace(4, true);
                rotateAdjacentFace(5, true);
            }
            else if (face == 1) {
                rotateAdjacentFace(0, true);
                rotateAdjacentFace(2, true);
                rotateAdjacentFace(3, true);
                rotateAdjacentFace(5, true);
            }
            else if (face == 2) {
                rotateAdjacentFace(0, true);
                rotateAdjacentFace(1, true);
                rotateAdjacentFace(3, true);
                rotateAdjacentFace(4, true);
            }
            else if (face == 3) {
                rotateAdjacentFace(1, true);
                rotateAdjacentFace(2, true);
                rotateAdjacentFace(4, true);
                rotateAdjacentFace(5, true);
            }
            else if (face == 4) {
                rotateAdjacentFace(0, true);
                rotateAdjacentFace(2, true);
                rotateAdjacentFace(3, true);
                rotateAdjacentFace(5, true);
            }
            else if (face == 5) {
                rotateAdjacentFace(0, true);
                rotateAdjacentFace(1, true);
                rotateAdjacentFace(3, true);
                rotateAdjacentFace(4, true);
            }
        }
        else {
            cube[face][0][0] = temp_color[0][2];
            cube[face][0][1] = temp_color[1][2];
            cube[face][0][2] = temp_color[2][2];
            cube[face][1][0] = temp_color[0][1];
            cube[face][1][1] = temp_color[1][1];
            cube[face][1][2] = temp_color[2][1];
            cube[face][2][0] = temp_color[0][0];
            cube[face][2][1] = temp_color[1][0];
            cube[face][2][2] = temp_color[2][0];

            if (face == 0) {
                rotateAdjacentFace(1, false);
                rotateAdjacentFace(2, false);
                rotateAdjacentFace(4, false);
                rotateAdjacentFace(5, false);
            }
            else if (face == 1) {
                rotateAdjacentFace(0, false);
                rotateAdjacentFace(2, false);
                rotateAdjacentFace(3, false);
                rotateAdjacentFace(5, false);
            }
            else if (face == 2) {
                rotateAdjacentFace(0, false);
                rotateAdjacentFace(1, false);
                rotateAdjacentFace(3, false);
                rotateAdjacentFace(4, false);
            }
            else if (face == 3) {
                rotateAdjacentFace(1, false);
                rotateAdjacentFace(2, false);
                rotateAdjacentFace(4, false);
                rotateAdjacentFace(5, false);
            }
            else if (face == 4) {
                rotateAdjacentFace(0, false);
                rotateAdjacentFace(2, false);
                rotateAdjacentFace(3, false);
                rotateAdjacentFace(5, false);
            }
            else if (face == 5) {
                rotateAdjacentFace(0, false);
                rotateAdjacentFace(1, false);
                rotateAdjacentFace(3, false);
                rotateAdjacentFace(4, false);
            }
        }
    }

    void RubicsCube::rotateAdjacentFace(int face, bool clockRotate) {
        Color temp_color[3];

        for (int i = 0; i < 3; ++i) {
            temp_color[i] = cube[face][i][(clockRotate) ? 2 : 0];
        }

        if (clockRotate) {
            cube[face][0][2] = cube[face][0][0];
            cube[face][1][2] = cube[face][0][1];
            cube[face][2][2] = cube[face][1][1];

            cube[face][0][0] = cube[face][2][0];
            cube[face][0][1] = cube[face][1][0];
            cube[face][1][1] = cube[face][2][1];

            cube[face][2][0] = cube[face][2][2];
            cube[face][1][0] = cube[face][2][1];
            cube[face][2][1] = temp_color[0];
        }
        else {
            cube[face][0][0] = cube[face][2][0];
            cube[face][0][1] = cube[face][1][0];
            cube[face][1][1] = cube[face][2][1];

            cube[face][2][0] = cube[face][2][2];
            cube[face][1][0] = cube[face][2][1];
            cube[face][2][1] = temp_color[2];

            cube[face][0][2] = cube[face][0][0];
            cube[face][1][2] = cube[face][0][1];
            cube[face][2][2] = cube[face][1][1];
        }
    }

    void RubicsCube::printCube() {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    char colorCode;
                    switch (cube[i][j][k]) {
                    case RED:
                        colorCode = 'R';
                        break;
                    case GREEN:
                        colorCode = 'G';
                        break;
                    case BLUE:
                        colorCode = 'B';
                        break;
                    case WHITE:
                        colorCode = 'W';
                        break;
                    case YELLOW:
                        colorCode = 'Y';
                        break;
                    case ORANGE:
                        colorCode = 'O';
                        break;
                    default:
                        colorCode = '?';
                    }
                    cout << colorCode << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
    }