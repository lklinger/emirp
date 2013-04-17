/*
     File Name:   emirp.cpp
     Created by:  Liz Klinger on 7/7/12.
     Description: Validates whether numbers are emirps and prints the first
                  100 emirps (aligned right and formatted 10 per row).
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int x); // Inputs an int and determines whether its divisible by any number less than itself
int reverseNum(int y); // Inputs an int and outputs an int with reversed digits

int main() // Uses isPrime and reverseNum to determine whether number is an emirp. Prints first 100 emirps and formats 10 per row
{
    int testNum = 2, countToTen = 1, limit = 0;
    
    cout << endl << "These are the first 100 emirps (i.e. prime numbers that result" << endl << "in a different prime when their digits are reversed)" << endl << endl;
    
    while (limit < 100) // print the first 100 emirps
    {
        if(isPrime(testNum)) // if int is a prime
        {
            if(isPrime(reverseNum(testNum))) // and also if int with reversed digits is also a prime
            {
                if (countToTen <= 10) // print number
                {
                    cout << setw(6) << testNum << " ";
                    countToTen++;
                    limit++;
                }
                else // if number would be 11th in current row, then create a new row and print number. reset countToTen
                {
                    cout << endl;
                    cout << setw(6) << testNum << " ";
                    countToTen = 2;
                    limit++;
                }
            }
        }
        
        testNum++; // if number is not prime or reverse digits number is not prime, then increment testNum
    }
    cout << endl << endl;
    
    return 0;
}

bool isPrime(int testNum)
{
    int divideBy = 2, loopExit = 0;
    
    while (loopExit == 0)
    {
        if (testNum % divideBy == 0)
        {
            if (divideBy == testNum) // if number is divisible by itself, then it is a prime
            {
                loopExit = 1;
                return true;
            }
            else if (divideBy != testNum) // if number is divisible by a number less than itself, then it is not a prime
            {
                loopExit = 1;
                return false;
            }
        }
        else if (testNum % divideBy > 0) // number is not divisible, try another number increment higher
        {
            divideBy++;
            loopExit = 0;
        }        
    }
    
    return false;
}

int reverseNum(int num)
{
    int modifiedNum = 0;
    
    while (num > 0)
    {
        modifiedNum = modifiedNum * 10; // moves up digits already stored in int, if applicable
        modifiedNum = modifiedNum + (num % 10); // stores next number available from the ones place of num
        num = num / 10; // divide num by 10 to get rid of the current ones place
    }
    
    return modifiedNum;
}
