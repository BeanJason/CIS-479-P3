// CIS-479-P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "string"

using namespace std;

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
    void nScan(int x, int y)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {

            }
        }
    }
    void qScan(int x, int y)
    {
        int west = -2;
        int north = -3;
        int east = -2;
        int south = -1;

    }

    vector<vector<int>> trajectory(int x, int y) //take the x and y of the start tile, return a vector with the trajectory
    {
        float random = rand() % 1;
        int direction;
        vector<vector<int>> path;
        vector<int> next;

        int curTileX = x;
        int curTileY = y;

        bool end = false;

        
        while (!end)
        {
            random = rand() % 1;
            if (random < .9)//.9 chance we chose max direction for movement 
            {
                //find max
                direction = max(curTileX, curTileY);
                next = { curTileX, curTileY, direction };
                path.push_back(next);
            }
            else //.1 chance we choose a random direction 
            {
                direction = rand() % 3;
                next = { curTileX, curTileY, direction };
                path.push_back(next);
            }

            //move to the current tile in the direction chosen, unless it is a obstacle (if obstacle we bounce back so stay the same tile so don't change)
            //
            //
            //
            //Code for that here 

            if (direction == 0)//if direction west
            {
                curTileX += 1;
            }
            else if (direction == 1)//if direction north
            {
                curTileY += 1;
            }
            else if (direction == 2)//if direction east
            {
                curTileX -= 1;
            }
            else if (direction == 3)//if direction south
            {
                curTileY -= 1;
            }
            //check if the next tile is -50 / 100 in that case add it to the path and set end to true
            if (QmazeTiles[curTileX][curTileY].west == -50 || QmazeTiles[curTileX][curTileY].west == 100)
            {
                int reason = QmazeTiles[curTileX][curTileY].west;
                next = { curTileX, curTileY, reason };//used -1 for direction bc it's not going to be moving anymore
                path.push_back(next);
                end = true;
            }

        }

       
        return path; //return our trajectory
        
    }

    int max(int x, int y)
    {
        int maxDir = QmazeTiles[x][y].west;//hold the value that's in this direction
        int direction = 0;//what will be returned indicating max direction
        if (QmazeTiles[x][y].north > maxDir)//do this for all directions if value in this direction > prev replace
        {
            maxDir = QmazeTiles[x][y].north;
            direction = 1;
        }
        if (QmazeTiles[x][y].east > maxDir)
        {
            maxDir = QmazeTiles[x][y].east;
            direction = 2;
        }
        if (QmazeTiles[x][y].south > maxDir)
        {
            maxDir = QmazeTiles[x][y].south;
            direction = 3;
        }

        //if each direction is equal return a random direction
        if (QmazeTiles[x][y].west == QmazeTiles[x][y].north && QmazeTiles[x][y].west == QmazeTiles[x][y].east && QmazeTiles[x][y].west == QmazeTiles[x][y].south)
        {
            direction = rand() % 3;
        }

        return direction;
    }

    void solve()
    {
        //pick random initial tile, need a tile between [1][1]/[6][6] that's not -50,100,or-1
        int random = rand() % 14;
        int goodTiles[14][2] = { {1,1}, {1,2},
            {1,3}, {1,4},
            {2,3}, {2,4}, {2,6},
            {3, 2}, {3,5},
            {4, 1}, {4, 2}, {4,3}, {4,4},{4,5}
        }; //all posible tiles
     
        int randX = goodTiles[random][1];
        int randY = goodTiles[random][0];

        cout << randX << randY << endl;

        vector<vector<int>>path = trajectory(randX, randY);
        
        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
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
    Maze robotMaze;
    

    //robotMaze.PrintProbabilities();



    robotMaze.solve();
    
    
    
    


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
