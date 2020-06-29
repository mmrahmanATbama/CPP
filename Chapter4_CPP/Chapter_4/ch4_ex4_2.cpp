/*
 * Chapter 4, Exercise 4
 * Write a program to play a tempNumbers guessing game. The user thinks of a tempNumber between 1 and 100 and your program asks questionNumbers to figure out what the tempNumber is (e.g., “Is the tempNumber you are thinking of less than 50?”). Your program should be able to identify the tempNumber after asking no more than seven questionNumbers. Hint: Use the < and <= operators and the if-else construct.
 * 
 * This solution may work: this is from https://programming-principles-and-pratice-using-c.readthedocs.io/en/latest/ch4-computation.html
 */

#include<iostream>

int main(int argc, char** argv)
{
    int highNumber = 100;
    int lowNumber = 1;
    int range = highNumber - lowNumber;
    int tempNumber = highNumber / 2;
    int questionNumber = 0;
    char answer = ' ';

    std::cout << "Pick a tempNumber from " << lowNumber << " to " << highNumber << std::endl;

    while (lowNumber != highNumber)
    {
        range = highNumber - lowNumber;
        if (range == 1)
        {
            tempNumber = highNumber;
        }
        else
        {
            tempNumber = lowNumber + range / 2;
        }
        if (questionNumber % 2 == 0)
        {
            std::cout << questionNumber + 1 << ". Is the Number you are thinking of less than " << tempNumber << "? (Enter 'y' or 'n') \n";

            std::cin >> answer;
            if ('y' == answer)
            {
                highNumber = tempNumber - 1;
                questionNumber++;

            }
            else if ('n' == answer)
            {
                lowNumber = tempNumber;
                questionNumber++;

            }
            else
            {
                std::cout << "Please enter 'y' or 'n' ...\n";
            }
        }
        else
        {

            std::cout << questionNumber + 1 << ". Is the pNumber you are thinking of greater than " << tempNumber << "? (Enter 'y' or 'n') \n";
            std::cin >> answer;
            if ('y' == answer)
            {
                lowNumber = tempNumber + 1;
                questionNumber++;

            }
            else if ('n' == answer)
            {
                highNumber = tempNumber;
                questionNumber++;

            }
            else
            {
                std::cout << "Please enter 'y' or 'n' ...\n";
            }

        }
    }
    std::cout << "The number you are thinking of is " << lowNumber << "\n";
    std::cout << "I needed " << questionNumber << " guesses.\n";

    return 0;
}

