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
    int obsticle;
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
        {{-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 2}, {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0},
        {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}},//[0][n]

        {{-50,-50,-50,-50, 0}, {0,0,0,0, 0}, {0,0,0,0, 0}, {0,0,0,0, 0},
        {0,0,0,0, 0}, {-1,-1,-1,-1, 1}, {-50,-50,-50,-50, 0}},//[1][n]

        {{-50,-50,-50,-50, 0}, {-1,-1,-1,-1, 1}, {0,0,0,0, 0}, {0,0,0,0, 0},
        {-1,-1,-1,-1, 1}, {0,0,0,0, 0}, {-50,-50,-50,-50, 0}},//[2][n]

        {{-50,-50,-50,-50, 0}, {-1,-1,-1,-1, 1}, {0,0,0,0, 0}, {100,100,100,100, 20},
        {-1,-1,-1,-1, 1}, {0,0,0,0, 0}, {-50,-50,-50,-50, 0}},//[3][n]

        {{-50,-50,-50,-50, 0}, {0,0,0,0, 0}, {0,0,0,0, 0}, {0,0,0,0, 0},
        {0,0,0,0, 0}, {0,0,0,0, 0}, {-50,-50,-50,-50, 0}},//[4][n]

        {{-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0},
        {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}, {-50,-50,-50,-50, 0}}//[5][n]
    };

public:
    void nScan(vector<int> trajectory)
    {
        if (NmazeTiles[trajectory[0]][trajectory[1]].west != -50 && NmazeTiles[trajectory[0]][trajectory[1]].west != 100 && NmazeTiles[trajectory[0]][trajectory[1]].west != -1)
        {
            if (trajectory[2] == 0)
            {
                NmazeTiles[trajectory[0]][trajectory[1]].west += 1;
            }
            else if (trajectory[2] == 1)
            {
                NmazeTiles[trajectory[0]][trajectory[1]].north += 1;
            }
            else if (trajectory[2] == 2)
            {
                NmazeTiles[trajectory[0]][trajectory[1]].east += 1;
            }
            else if (trajectory[2] == 3)
            {
                NmazeTiles[trajectory[0]][trajectory[1]].south += 1;
            }
        }
        
        
    }
    void qScan(vector<int> current, vector<int> next)
    {
        int west = -2;
        int north = -3;
        int east = -2;
        int south = -1;

        double Q = 0;
        double prevQ = 0;
        double nextQ = 0;
        int prevN = 0;
        int direction = current[2];
        int directionNext = next[2];
        int wind = 0;

        //find the previous N and previous Q value for calculation
        if (direction == 0)
        {
            prevQ = QmazeTiles[current[0]][current[1]].west;
            prevN = NmazeTiles[current[0]][current[1]].west;
            wind = west;
        }
        else if (direction == 1)
        {
            prevQ = QmazeTiles[current[0]][current[1]].north;
            prevN = NmazeTiles[current[0]][current[1]].north;
            wind = north;
        }
        else if (direction == 2)
        {
            prevQ = QmazeTiles[current[0]][current[1]].east;
            prevN = NmazeTiles[current[0]][current[1]].east;
            wind = east;
        }
        else if (direction == 3)
        {
            prevQ = QmazeTiles[current[0]][current[1]].south;
            prevN = NmazeTiles[current[0]][current[1]].south;
            wind = south;
        }
        
        //find the nest Q value for calculation
        if (directionNext == 0)
        {
            nextQ = QmazeTiles[next[0]][next[1]].west;
        }
        else if (directionNext == 1)
        {
            nextQ = QmazeTiles[next[0]][next[1]].north;
        }
        else if (directionNext == 2)
        {
            nextQ = QmazeTiles[next[0]][next[1]].east;
        }
        else if (directionNext == 3)
        {
            nextQ = QmazeTiles[next[0]][next[1]].south;
        }

        //testing to see values
        /*cout << "prevQ: " << prevQ << endl;
        cout << "prevN: " << prevN << endl;
        cout << "wind: " << wind << endl;*/
        
        Q = prevQ + (1 / prevN) * (wind + 1 * nextQ - prevQ);
        cout << "Q = " << prevQ << " + (1 / " << prevN << ") * (" << wind << " + 1 * " << nextQ << " - " << prevQ << ") = " << Q << endl;
        if (direction == 0)
        {
            QmazeTiles[current[0]][current[1]].west = Q;
        }
        else if (direction == 1)
        {
            QmazeTiles[current[0]][current[1]].north = Q;
        }
        else if (direction == 2)
        {
            QmazeTiles[current[0]][current[1]].east = Q;
        }
        else if (direction == 3)
        {
            QmazeTiles[current[0]][current[1]].south = Q;
        }
    }

    vector<vector<int>> trajectory(int Row, int col) //take the x and y of the start tile, return a vector with the trajectory
    {
        int random = rand() % 1;
        int direction;
        vector<vector<int>> path; //a vector of each trajectory in the path
        vector<int> next; //the new move we're going to be making add this to the path

        int curTileCol = col;
        int curTileRow = Row;

        bool end = false; // true when we hit the goal or terminal state
        int count = 0; //count to make sure we don't get stuck if >100 abort
        
        while (!end)
        {
            random = rand() % 10 + 1;
            if (random < 9)//.9 chance we chose max direction for movement 
            {
                //find max
                direction = max(curTileCol, curTileRow);
                direction = drift(direction);
                next = { curTileRow , curTileCol, direction };
                path.push_back(next);
            }
            else //.1 chance we choose a random direction 
            {
                direction = rand() % 3;
                direction = drift(direction);
                next = { curTileRow , curTileCol, direction };
                path.push_back(next);
            }

           
            if (direction == 0 && QmazeTiles[curTileRow][curTileCol - 1].obsticle != 1)//if direction west
            {
                curTileCol -= 1;
            }
            else if (direction == 1 && QmazeTiles[curTileRow - 1][curTileCol].obsticle != 1)//if direction north
            {
                curTileRow -= 1;
            }
            else if (direction == 2 && QmazeTiles[curTileRow][curTileCol + 1].obsticle != 1)//if direction east
            {
                curTileCol += 1;
            }
            else if (direction == 3 && QmazeTiles[curTileRow + 1][curTileCol].obsticle != 1)//if direction south
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
            count++;
            if (count >= 100)
            {
                break;
            }
        }
        count = 0;

        //cout << "exit trajectory " << endl;
        return path; //return our trajectory
        
    }

    int drift(int dir)
    {
        int random = rand() % 10 + 1;

        if (dir == 0) //west
        {

            if (random <= 1) // .1 chance drift left
            {
                dir = 3;
            }
            else if (random > 1 && random < 2) // .1 chance drift right
            {
                dir = 1;
            }
        }
        else if (dir == 1) //north
        {
            if (random <= 1) // .1 chance drift left
            {
                dir = 0;
            }
            else if (random > 1 && random < 2) // .1 chance drift right
            {
                dir = 2;
            }
        }
        else if (dir == 2)//east
        {
            if (random <= 1) // .1 chance drift left
            {
                dir = 1;
            }
            else if (random > 1 && random < 2) // .1 chance drift right
            {
                dir = 3;
            }
        }
        else if (dir == 3)//south
        {
            if (random <= 1) // .1 chance drift left
            {
                dir = 2;
            }
            else if (random > 1 && random < 2) // .1 chance drift right
            {
                dir = 0;
            }
        }
        return dir;
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

        //cout << "start tile: " << randRow  << " " << randCol << endl;
        vector<vector<int>>path = trajectory(randRow, randCol);
        
        //shows us the path
        cout << "path size =  " << path.size() << endl;
        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[i].size(); j++)
            {
                //cout << j << " " << j  << endl;
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        //cout << "finished" << endl;
        

        //now that we have our trajectory send each trajectory to N and then to q
        for (int i = 0; i < path.size() -  1; i++)
        {
            
            nScan(path[i]);
            if (path[i][2] != -50 && path[i][2] != 100)
            {
                qScan(path[i], path[i + 1]);
            }
        }
        path.clear();
    }

    void PrintProbabilitiesN() {

        for (int i = 0; i < 7; i++)
        {
            cout <<left << std::setw(12) << NmazeTiles[0][i].west;
        }
        cout << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "row " << i + 1 << ":" << endl;
                    for (int k = 0; k < 7; k++)
                    {
                        if (NmazeTiles[i + 1][k].west == -1)
                        {
                            cout << left << std::setw(12) << "####";
                        }
                        else
                        {
                            cout << left << std::setw(12) << NmazeTiles[i + 1][k].west;
                        }   
                    }
                    cout << endl;
                    for (int k = 0; k < 7; k++)
                    {
                        if (NmazeTiles[i + 1][k].north == -1)
                        {
                            cout << left << std::setw(12) << "####";
                        }
                        else
                        {
                            cout << left << std::setw(12) << NmazeTiles[i + 1][k].north;
                        }
                    }
                    cout << endl;
                    for (int k = 0; k < 7; k++)
                    {
                        if (NmazeTiles[i + 1][k].east == -1)
                        {
                            cout << left << std::setw(12) << "####";
                        }
                        else
                        {
                            cout << left << std::setw(12) << NmazeTiles[i + 1][k].east;
                        }
                    }
                    cout << endl;
                    for (int k = 0; k < 7; k++)
                    {
                        if (NmazeTiles[i + 1][k].south == -1)
                        {
                            cout << left << std::setw(12) << "####";
                        }
                        else
                        {
                            cout << left << std::setw(12) << NmazeTiles[i + 1][k].south;
                        }
                    }
                    cout << endl;
                    cout << endl;
            }
            cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << left << std::setw(12) << NmazeTiles[5][i].west;
        }

        /*for (int i = 0; i < 7; i++)
        {
            cout <<left << std::setw(12) << NmazeTiles[0][i].west;
        }
        cout << endl;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (NmazeTiles[i + 1][j].west != -50 && NmazeTiles[i + 1][j].west != 100 && NmazeTiles[i + 1][j].west != -1)
                {
                    cout << left << std::setw(12) << NmazeTiles[i+ 1][j].north;
                }
                else
                {
                    cout << left << std::setw(12) << "";
                }
            }
            cout << endl;
            for (int j = 0; j < 7; j++)
            {
                if (NmazeTiles[i + 1][j].west != -50 && NmazeTiles[i + 1][j].west != 100 && NmazeTiles[i + 1][j].west != -1)
                {
                    cout  << std::setw(9) << NmazeTiles[i + 1][j].west << std::setw(3) << NmazeTiles[i + 1][j].east;
                }
                else if (NmazeTiles[i + 1][j].west == -1)
                {
                    cout << std::setw(9) << "####";
                }
                else
                {
                    cout << std::setw(9) << NmazeTiles[i + 1][j].west;
                }
            }
            cout << endl;
            
        }*/
        
       
    }

    void PrintProbabilitiesQ()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << left << std::setw(12) << QmazeTiles[0][i].west;
        }
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "row " << i + 1 << ":" << endl;
            for (int k = 0; k < 7; k++)
            {
                if (QmazeTiles[i + 1][k].obsticle == 1)
                {
                    cout << left << std::setw(12) << "####";
                }
                else
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << QmazeTiles[i + 1][k].west;
                }
            }
            cout << endl;
            for (int k = 0; k < 7; k++)
            {
                if (QmazeTiles[i + 1][k].obsticle == 1)
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << "####";
                }
                else
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << QmazeTiles[i + 1][k].north;
                }
            }
            cout << endl;
            for (int k = 0; k < 7; k++)
            {
                if (QmazeTiles[i + 1][k].obsticle == 1)
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << "####";
                }
                else
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << QmazeTiles[i + 1][k].east;
                }
            }
            cout << endl;
            for (int k = 0; k < 7; k++)
            {
                if (QmazeTiles[i + 1][k].obsticle == 1)
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << "####";
                }
                else
                {
                    cout << setprecision(2) << fixed << left << std::setw(12) << QmazeTiles[i + 1][k].south;
                }
            }
            cout << endl;
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << left << std::setw(12) << QmazeTiles[5][i].west;
        }
    }
};

//test
int main()
{
    Maze robotMaze;
    

    //robotMaze.PrintProbabilitiesN();
    //robotMaze.PrintProbabilitiesQ();
    cout << endl;
    for (int i = 0; i < 50000; i++)
    {
        cout << "run: " << i << endl;
        robotMaze.solve();
    }
    //robotMaze.solve();
    cout << endl;
    cout << "N maze: " << endl;
    robotMaze.PrintProbabilitiesN();
    cout << endl;
    cout << "Q maze: " << endl;
    robotMaze.PrintProbabilitiesQ();
    cout << endl;
    

    /*for (int i = 0; i < 100; i++)
    {
        cout << "pass " << i << endl;
        robotMaze.solve();
        cout << endl;
    }*/
    
    
    
    
    


    system("pause");
    return 0;
}

