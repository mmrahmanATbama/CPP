/*
 * Chapter 4 drill 1
 * While loop reads in two ints and then print them, exits when a terminating '|' is entered.
 */
#include<iostream>
#include<cmath>

int main(int argc, char** argv)
{
    double input1, input2 = 0;
    char terminate = ' ';

    //std::cout <<"Enter two numbers, enter '|' to terminate.\n";

//    while (std::cin >> input1 >> input2)
//    {
//        //std::cout <<input1 << " " << input2 << std::endl;
//        if (input1 <= input2)
//        {
//            std::cout << "The smaller number is: " << input1 << std::endl;
//            std::cout << "The larger number is: " << input2 << std::endl;
//        }
//        else if (input1 > input2)
//        {
//            std::cout << "The smaller number is: " << input2 << std::endl;
//            std::cout << "The larger number is: " << input1 << std::endl;
//        }
//        if (input1 == input2)
//        {
//            std::cout << "The numbers are equal.\n";
//        }
//        else if ((fabs(input1 - input2)) <= .001)
//        {
//            std::cout << "The numbers are almost equal.\n";
//        }
//        std::cout << (fabs(input1 - input2)) << std::endl;
//    }
    // Chapter 4 Drill 6

    double smallest = 0.0, largest = 0.0, temp = 0.0;
    int count = 0; // this is one solution to initialize largest and smallest first time.
    std::cout << "Enter a double, | to end" << std::endl;
    while (std::cin >> temp)
    {
        // smallest and largest are  equal the first time, so both the variables will get the same value
        if (count == 0)
        {
            smallest = temp;
            largest = temp;
            ++count; // count will not be 0 again in this while loop, so no need to keep track.
        }
        
        // second and next, temp will be assigned other values.
        if (temp <= smallest)
        {
            smallest = temp;
        }
        else if (temp >= largest)
        {
            largest = temp;
        }
        else 
        {
         // number is not within range, not smallest or largest
            std::cout << "Number is neither smallest nor largest, continue. \n";
        }
        std::cout << "Smallest number so far: " << smallest << std::endl;
        std::cout << "Largest number so far: " << largest << std::endl;
    }
    
   
        
    return 0;
} // end program

