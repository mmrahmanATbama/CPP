/*
 * Chapter 4, Exercise 4
 * Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than seven questions. Hint: Use the < and <= operators and the if-else construct.
 */

/* Algorithm 
 * Upper and lower number is known, since lower is 1 and upper is 100. so ask the user half of the upper and lower number, so the first time half is (1 + 100 ) / 2 == 50 (truncated value is ok).
 * ask the user if the number is less then half the number found using the above method.
 * if the user answer yes, lower number remains the same but upper number becomes half of the prev number, ask the user again for similar question using method from step 1. Continue until lower and upper number is the same.
 * If the user answers no, then lower number becomes half of the number and upper number stays the same. Then follow the same pattern as described in step two.
 * Do until lower and upper number is the same, that would ensure all the number has been accounted for.+
 * THIS ALGORITM did not work. 
 * https://everythingcomputerscience.com/DivideandConquerAlgorithm.html has the algorithm with explanation
 * Divide and Conquer Algorithm (Guessing Game) Steps:

Here is the actual Steps (Algorithm) we just used:

    Add the Highest Range + Lowest range - 1 = Possible Guesses 
    Divide Possible Guesses by 2 Round Up (your guess), ask is this your number ?
    If your guess is to low:
        the Lowest Range = your guess +1 // this is where I went wrong, Agile -- accept responsibility
    If your guess is to high:
        the Highest Range = your guess - 1 // this is where I went wrong
    If your guess isn't to low or to high:
        You are done don't go to next step.
    Repeat
 * 
 * NOT A VERY GOOD SOLUTION, even though it does work, need a better solution.

 */

#include <iostream>
// This function will truncate the value, for example 25 / 2 will become 12 instead of 12.5

int half(int low, int high)
{
    return (low + high) / 2;
}

int main(int argc, char** argv)
{
    char answer = ' ';
    int lowNumber = 1; // lowest number  
    int highNumber = 100; // highest number, this is the range
    int guessNumber = highNumber + lowNumber - 1; // in this case it becomes 100. 
    int tempGuess = 0;
    int questionCount = 0;


    std::cout << "Ask the user to guess a number between 1 and 100.\n";

    // truncated values are expected, for example 25/2 becomes 12 and not 12.5
    while (answer != 'c') // seven question at most
    {
        guessNumber = highNumber + lowNumber - 1;
        tempGuess = guessNumber / 2;
        std::cout << "Question no: " << ++questionCount << ".  Is the number less then " << tempGuess << "? \n";
        std::cin >> answer;
        if (answer == 'y')
        {
            highNumber = tempGuess + 1;
            std::cout << lowNumber << std::endl;
            std::cout << highNumber << std::endl;
        }
        else if (answer == 'n')
        {
            lowNumber = tempGuess + 1;
            std::cout << lowNumber << std::endl;
            std::cout << highNumber << std::endl;
        }
        else if (answer == 'c')
        {
            std::cout << "The number is: " << tempGuess << std::endl;
            break;
        }
        else
        {
            std::cout << "Wrong answer, please enter 'y or 'n' \n";
            continue;
        }
    }
    
    std::cout << "Question count: " << questionCount << std::endl;

    return 0;
}

