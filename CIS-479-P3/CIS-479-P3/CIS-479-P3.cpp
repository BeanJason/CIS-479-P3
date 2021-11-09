// CIS-479-P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

struct tile {
    float west;
    float north;
    float east;
    float south;
};

class Maze {
private:
    tile NmazeTiles[6][7] = {
        {{-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50},
        {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}},//[0][n]

        {{-50,-50,-50,-50}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0},
        {0,0,0,0}, {-1,-1,-1,-1}, {-50,-50,-50,-50}},//[1][n]

        {{-50,-50,-50,-50}, {-1,-1,-1,-1}, {0,0,0,0}, {0,0,0,0},
        {-1,-1,-1,-1}, {0,0,0,0}, {-50,-50,-50,-50}},//[2][n]

        {{-50,-50,-50,-50}, {-1,-1,-1,-1}, {0,0,0,0}, {100,100,100,100},
        {-1,-1,-1,-1}, {0,0,0,0}, {-50,-50,-50,-50}},//[3][n]

        {{-50,-50,-50,-50}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0},
        {0,0,0,0}, {0,0,0,0}, {-50,-50,-50,-50}},//[4][n]

        {{-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50},
        {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}}//[5][n]
    };

    tile QmazeTiles[6][7] = {
        {{-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50},
        {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}},//[0][n]

        {{-50,-50,-50,-50}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0},
        {0,0,0,0}, {-1,-1,-1,-1}, {-50,-50,-50,-50}},//[1][n]

        {{-50,-50,-50,-50}, {-1,-1,-1,-1}, {0,0,0,0}, {0,0,0,0},
        {-1,-1,-1,-1}, {0,0,0,0}, {-50,-50,-50,-50}},//[2][n]

        {{-50,-50,-50,-50}, {-1,-1,-1,-1}, {0,0,0,0}, {100,100,100,100},
        {-1,-1,-1,-1}, {0,0,0,0}, {-50,-50,-50,-50}},//[3][n]

        {{-50,-50,-50,-50}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0},
        {0,0,0,0}, {0,0,0,0}, {-50,-50,-50,-50}},//[4][n]

        {{-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50},
        {-50,-50,-50,-50}, {-50,-50,-50,-50}, {-50,-50,-50,-50}}//[5][n]
    };

public:
    void nScan()
    {

    }
    void qScan()
    {

    }

    void PrintProbabilities() {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (NmazeTiles[i][j].west == -1) {
                    std::cout << std::setw(5) << "####";
                    std::cout << "   ";
                }
                else {
                    std::cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[i][j].west;
                    std::cout << "   ";
                }
            }
            std::cout << '\n';
        }
    }
};

//test
int main()
{
    Maze Ngrid;

    Ngrid.PrintProbabilities();

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
