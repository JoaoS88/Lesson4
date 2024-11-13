#include <iostream>
#include <fstream>
#include <cctype> 
//Task3:

// loads text from text file and places it into a char array myArray
void loadTextFileToArray(char myArray[])
{
    int i = 0;
    char letter;

    std::ifstream inFile("alphabet.txt");
    if (inFile.is_open())
    {

        while (inFile >> letter && i < 26)
        {
            myArray[i] = letter;
            i++;
        }
        inFile.close();
    }
    else
    {
        std::cout << "Error opening file....";
    }
}
// method to convert each element of the array myArray to uppercase
inline void alphabetToUpper(char myArray[])
{
    for (int i = 0; i < 26; i++)
    {
        myArray[i] = toupper(myArray[i]);
    }

}
// method to output the array
inline void outputArray(char myArray[])
{
    for (int i = 0; i < 26; i++)
    {
        std::cout << myArray[i] << ", ";
    }
}
int main()
{
    char myArray[26];
    // array should look like a,b,c,d,e, ... ,x,y,z
    // takes characters from text file, reads them using ifstream and places them in a char array
    loadTextFileToArray(myArray);
    std::cout << "The array after reading characters from the text file is:" << std::endl;
    outputArray(myArray);
    std::cout << std::endl;

    // array should look like A,B,C,D,E, ... ,X,Y,Z
    // takes characters from array and converts them to uppercase from lowercase couterpart
    alphabetToUpper(myArray);
    std::cout << "The array after converting characters to upper:" << std::endl;
    outputArray(myArray);
    std::cout << std::endl;

    return 0;
}
