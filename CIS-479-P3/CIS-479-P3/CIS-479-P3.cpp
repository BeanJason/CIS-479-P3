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
    void nScan(vector<int> trajectory)
    {
        if (trajectory[2] == 0)
        {
            NmazeTiles[trajectory[0], trajectory[1]]->west += 1;
        }
        else if (trajectory[2] == 1)
        {
            NmazeTiles[trajectory[0], trajectory[1]]->north += 1;
        }
        else if (trajectory[2] == 2)
        {
            NmazeTiles[trajectory[0], trajectory[1]]->east += 1;
        }
        else if (trajectory[2] == 3)
        {
            NmazeTiles[trajectory[0], trajectory[1]]->south += 1;
        }
        
    }
    void qScan(int row, int col)
    {
        int west = -2;
        int north = -3;
        int east = -2;
        int south = -1;

    }

    vector<vector<int>> trajectory(int Row, int col) //take the x and y of the start tile, return a vector with the trajectory
    {
        float random = rand() % 1;
        int direction;
        vector<vector<int>> path;
        vector<int> next;

        int curTileCol = col;
        int curTileRow = Row;

        bool end = false;

        
        while (!end)
        {
            random = rand() % 1;
            if (random < .9)//.9 chance we chose max direction for movement 
            {
                //find max
                direction = max(curTileCol, curTileRow);
                next = { curTileRow , curTileCol, direction };
                path.push_back(next);
            }
            else //.1 chance we choose a random direction 
            {
                direction = rand() % 3;
                next = { curTileRow , curTileCol, direction };
                path.push_back(next);
            }

           
            if (direction == 0 && QmazeTiles[curTileRow][curTileCol - 1].west != -1)//if direction west
            {
                curTileCol -= 1;
            }
            else if (direction == 1 && QmazeTiles[curTileRow - 1][curTileCol].west != -1)//if direction north
            {
                curTileRow -= 1;
            }
            else if (direction == 2 && QmazeTiles[curTileRow][curTileCol + 1].west != -1)//if direction east
            {
                curTileCol += 1;
            }
            else if (direction == 3 && QmazeTiles[curTileRow + 1][curTileCol].west != -1)//if direction south
            {
                curTileRow += 1;
            }
            //check if the next tile is -50 / 100 in that case add it to the path and set end to true
            if (QmazeTiles[curTileRow][curTileCol].west == -50 || QmazeTiles[curTileRow][curTileCol].west == 100)
            {
                int reason = QmazeTiles[curTileRow][curTileCol].west;
                next = { curTileRow, curTileCol, reason };//used -1 for direction bc it's not going to be moving anymore
                path.push_back(next);
                end = true;
            }

        }

       
        return path; //return our trajectory
        
    }

    int max(int row, int  col)
    {
        //directinos key
        //0 = west
        //1 = north
        //2 = east
        //3 = south

        int maxDir = QmazeTiles[row][col].west;//hold the value that's in this direction
        int direction = 0;//what will be returned indicating max direction
        if (QmazeTiles[row][col].north > maxDir)//do this for all directions if value in this direction > prev replace
        {
            maxDir = QmazeTiles[row][col].north;
            direction = 1; 
        }
        if (QmazeTiles[row][col].east > maxDir) 
        {
            maxDir = QmazeTiles[row][col].east;
            direction = 2;
        }
        if (QmazeTiles[row][col].south > maxDir) 
        {
            maxDir = QmazeTiles[row][col].south;
            direction = 3;
        }

        //if each direction is equal return a random direction
        if (QmazeTiles[row][col].west == QmazeTiles[row][col].north && QmazeTiles[row][col].west == QmazeTiles[row][col].east && QmazeTiles[row][col].west == QmazeTiles[row][col].south)
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
            {2,2}, {2,4}, {2,6},
            {3, 2}, {3,5},
            {4, 1}, {4, 2}, {4,3}, {4,4},{4,5}
        }; //all posible tiles
     
        int randCol = goodTiles[random][1];
        int randRow = goodTiles[random][0];

        cout << "start tile: " << randRow  << " " << randCol << endl;
        vector<vector<int>>path = trajectory(randRow, randCol);
        
        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        //now that we have our trajectory send each trajectory to N and then to q
        for (int i = 0; i < path.size(); i++)
        {
            nScan(path[i]);
        }

    }

    void PrintProbabilitiesN() {

        for (int i = 0; i < 6; i++)
        {
            std::cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[0][i].west;
        }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (NmazeTiles[i][j].west != -50 || NmazeTiles[i][j].west != 100 || NmazeTiles[i][j].west != -1)
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[i][j].north;
                    }
                    else
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << " ";
                    }
                }
                cout << endl;
                for (int k = 0; k < 6; k++)
                {
                    if (NmazeTiles[i][j].west != -50 || NmazeTiles[i][j].west != 100 || NmazeTiles[i][j].west != -1)
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[i][j].west << std::setprecision(2) << std::fixed << std::setw(3) << NmazeTiles[i][j].east;
                    }
                    else if (NmazeTiles[i][j].west != -1)
                    {
                        std::cout << std::setw(7) << "####";
                    }
                    else
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[i][j].west;
                    }
                }
                cout << endl;
                for (int k = 0; k < 6; k++)
                {
                    if (NmazeTiles[i][j].west != -50 || NmazeTiles[i][j].west != 100 || NmazeTiles[i][j].west != -1)
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[i][j].south;
                    }
                    else
                    {
                        cout << std::setprecision(2) << std::fixed << std::setw(7) << " ";
                    }
                }
                cout << endl;
            }
        }
            
            cout << endl;

            for (int i = 0; i < 7; i++)
            {
                std::cout << std::setprecision(2) << std::fixed << std::setw(7) << NmazeTiles[5][i].west;
            }
        /*for (int i = 0; i < 6; ++i) {
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
        }*/
    }
};

//test
int main()
{
    Maze robotMaze;
    

    robotMaze.PrintProbabilitiesN();


    /*for (int i = 0; i < 100; i++)
    {
        cout << "pass " << i << endl;
        robotMaze.solve();
        cout << endl;
    }*/
    
    
    
    
    


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
