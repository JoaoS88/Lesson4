#include <iostream>
#include <fstream>
#include <string>
//Task4:

// method to get the size of the maze from the text file
// would work if using vector instead of array
//void getMazeSizeFromFile(int& rows, int& cols)
//{
//    rows = 0;
//    cols = 0;
//    std::string line;
//
//    std::ifstream inFile("maze.txt");
//    if (inFile.is_open())
//    {
//        // read the first line to get the number of columns
//        if (std::getline(inFile, line))
//        {
//            cols = line.length();
//            rows = 1;  // Counting the first row
//        }
//        // now, read the rest of the lines to get the number of rows
//        while (std::getline(inFile, line))
//        {
//            rows++;
//        }
//        inFile.close();
//    }
//    else
//    {
//        std::cout << "Error opening file....";
//    }
//}

// method to output the array
inline void outputArray(char myArray[][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << myArray[i][j];
        }
        std::cout << std::endl;
    }
}
// method to load text from text file and places it into a char array myArray
void loadTextFileToArray(char myArray[][5], int rows, int cols)
{
    std::ifstream inFile("maze.txt");
    std::string line;

    if (inFile.is_open())
    {
        for (int i = 0; i < rows; i++)
        {
            if (std::getline(inFile, line))
            {
                for (int j = 0; j < cols; j++)
                {
                    myArray[i][j] = line[j]; // populate the array
                }
            }
        }
        inFile.close();
    }
    else
    {
        std::cout << "Error opening file....";
    }

    std::cout << "Successfully read from file: " << std::endl;
    outputArray(myArray, rows, cols);
    std::cout << std::endl;
}

// pathfinding function 
bool findPath(char myArray[][5], int x, int y, int rows, int cols)
{
    // boundary checks and wall check
    if (x < 0 || x >= rows || y < 0 || y >= cols || myArray[x][y] == '#' || myArray[x][y] == '*')
    {
        return false;
    }
    // check if reached the end
    if (myArray[x][y] == 'E')
    {
        return true;
    }
    // mark cell as part of the path
    myArray[x][y] = '*';

    // recursive search in each direction (up, down, left, right)
    if (findPath(myArray, x - 1, y, rows, cols) || // up
        findPath(myArray, x + 1, y, rows, cols) || // down
        findPath(myArray, x, y - 1, rows, cols) || // left
        findPath(myArray, x, y + 1, rows, cols))   // right
    {
        return true;
    }
    // unmark cell if it’s not part of the solution path
    myArray[x][y] = ' ';
    return false;
}
// method to draw correct path
void findAndDrawCorrectPath(char myArray[][5], int rows, int cols)
{
    int startcoordinateX = -1;
    int startcoordinateY = -1;

    // find the starting coordinates (S)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (myArray[i][j] == 'S')
            {
                startcoordinateX = i;
                startcoordinateY = j;
                break;
            }
        }
        // break outer loop if start is found
        if (startcoordinateX != -1)
        {
            break;
        }
    }

    // start pathfinding from the start position
    if (startcoordinateX != -1 && startcoordinateY != -1)
    {
        if (!findPath(myArray, startcoordinateX, startcoordinateY, rows, cols))
        {
            std::cout << "No path found from S to E" << std::endl;
        }
    }
    else
    {
        std::cout << "Start point 'S' not found in the maze" << std::endl;
    }

    std::cout << "The correct path to solve the maze is: " << std::endl;
    // output the maze with the path drawn
    outputArray(myArray, rows, cols);
}
int main()
{
    const int rows = 5, cols = 5;
    //getMazeSizeFromFile(rows, cols); could be done if using vector instead of array

    // define array based on the size of the maze
    char myArray[rows][5];
    loadTextFileToArray(myArray, rows, cols);
    // find and draw the path
    findAndDrawCorrectPath(myArray, rows, cols);

    return 0;
}
