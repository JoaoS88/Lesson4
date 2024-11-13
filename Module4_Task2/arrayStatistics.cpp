#include <iostream>
//Task2:

// function to get input from the user and populate the array
void getArray(int myArray[], int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter number " << (i + 1) << std::endl;
        std::cin >> myArray[i];
    }
}
// function to output the contents of the array
void outputArray(int myArray[], int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << myArray[i];
        if (i < count - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}
// function to calculate and output various statistics of the array
void calcArrayStatistics(int myArray[], int count)
{
    int sumOfArrayValues = 0;
    int maxValue = myArray[0];
    int minValue = myArray[0];
    int numOddValues = 0;
    int numEvenValues = 0;

    for (int i = 0; i < count; i++)
    {
        sumOfArrayValues += myArray[i];

        if (myArray[i] > maxValue)
        {
            maxValue = myArray[i];
        }
        if (myArray[i] < minValue)
        {
            minValue = myArray[i];
        }
        if (myArray[i] % 2 == 0)
        {
            numEvenValues++;
        }
        else
        {
            numOddValues++;
        }
    }

    std::cout << "Sum of all values is: " << sumOfArrayValues << std::endl;
    std::cout << "Average of all values is: " << (sumOfArrayValues / static_cast<double>(count)) << std::endl;
    std::cout << "Largest value is: " << maxValue << std::endl;
    std::cout << "Smallest value is: " << minValue << std::endl;
    std::cout << "Number of Odd Numbers is: " << numOddValues << std::endl;
    std::cout << "Number of Even Numbers is: " << numEvenValues << std::endl;

}
int main()
{
    // for array size 10
    const int count10 = 10;
    const int count20 = 20;
    std::cout << "For size of array = 10:" << std::endl;
    int myArray[count10];
    getArray(myArray, count10);
    outputArray(myArray, count10);
    calcArrayStatistics(myArray, count10);

    // for array size 20
    std::cout << std::endl;
    std::cout << "For size of array = 20:" << std::endl;
    int myArray2[count20];
    getArray(myArray2, count20);
    outputArray(myArray2, count20);
    calcArrayStatistics(myArray2, count20);

    return 0;
}
