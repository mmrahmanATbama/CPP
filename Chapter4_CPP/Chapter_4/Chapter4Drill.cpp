/**
 * This is drill from Chapter 4, the program bellow encompasses all the drills 1 -11 in chapter 4.
 * 
 * 1. Write a program that consists of a while-loop that (each time around the loop) reads in two ints and then prints them. Exit the program when a terminating '|' is entered.
 * 2. Change the program to write out the smaller value is: followed by the smaller of the numbers and the larger value is: followed by the larger value.
 * 3. Change the program so that it writes the line the numbers are equal (only) if they are equal.
 * 4. Change the program so that it uses doubles instead of ints.
 * 5. Change the program so that it writes out the numbers are almost equal after writing out which is the larger and the smaller if the two numbers differ by less than 1.0/100.
 * 6. Now change the body of the loop so that it reads just one double each time around. Define two variables to keep track of which is the smallest and which is the largest value you have seen so far. Each time through the loop write out the value entered. If it’s the smallest so far, write the smallest so far after the number. If it is the largest so far, write the largest so far after the number.
 * 7. Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit indicator into a string. You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space).
 * 8. Reject values without units or with “illegal” representations of units, such as y, yard, meter, km, and gallons.
 * 9. Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values entered. When the loop ends, print the smallest, the largest, the number of values, and the sum of values. Note that to keep the sum, you have to decide on a unit to use for that sum; use meters.
 * 10. Keep all the values entered (converted into meters) in a vector. At the end, write out those values.
 * 11. Before writing out the values from the vector, sort them (that’ll make them come out in increasing order).  
 */

// **************************************************************************************************************************************

#include<iostream>
#include<ios> // for stream size, did not work ... need to clear cin buffer
#include<limits> // for limits, did not work ... 
#include <vector>
#include <algorithm>

constexpr double m = 1; // drill 9 asks for meter
constexpr double cm = 0.01 * m;
constexpr double inch = 2.54 * cm;
constexpr double ft = 12 * inch;

// Drill 2: write a function for drill 2. This would make it versatile for later drills
// mundane function, implemented for practice.

int smallerBetweenTwoNumbers(int num1, int num2)
{
    if (num1 <= num2)
    {
        return num1;
    }
    else
        return num2;
}

int largerBetweenTwoNumbers(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
        return num2;
}

bool twoNumbersEqual(int value1, int value2)
{
    if (value1 == value2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool almostEqual(double number1, double number2)
{
    double diff = number1 - number2;
    // if diff is a negative number make it positive, could use absolute value as well.
    // or could use -- ((diff < 0 && diff <= .001) || (diff > 0 && diff is > -.001))
    if (diff < 0)
    {
        diff = -1 * diff;
    }

    if (diff < .001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double convertToMeter(double value, std::string unit)
{
    if (unit == "cm")
        return value * cm;
    else if (unit == "m")
        return value * m;
    else if (unit == "inch")
        return value * inch;
    else if (unit == "ft")
        return value * ft;
    else
        return 0.0;
}


// --------------------- MAIN ------------------------------------------------------

int main(int argc, char** argv)
{
    // Drill 1
    //    int value1 = 0, value2 = 0;
    //
    //    std::cout << "Enter two integers, | to exit.\n";
    //    while (std::cin >> value1 >> value2) // this will take out if user enters any character other than integer.
    //    {
    //        std::cout << value1 << " " << value2 << std::endl;
    //        // Drill 2
    //        std::cout << "The smaller value is: " << smallerBetweenTwoNumbers(value1, value2) << std::endl;
    //        std::cout << "The larger value is: " << largerBetweenTwoNumbers(value1, value2) << std::endl;
    //
    //        // Drill 3
    //        if (twoNumbersEqual(value1, value2))
    //        {
    //            std::cout << "The numbers are equal. \n";
    //        }
    //    }

    // Drill 4
    //std::cin.seekg(0,ios::end);
    //std::cin.clear();
    //std::cin.ignore();
    //std::cin.clear();
    //fflush(stdin);
    //std::cin.ignore(200,'\n');
    //std::cin.ignore(limits::numeric_limits<ios::streamsize>::max(),'\n'); did not clear

    //   double number1 = 0.0, number2 = 0.0;
    //
    //    std::cout << "Enter two doubles, | to end. \n";
    //    while (std::cin >> number1 >> number2)
    //    {
    //        if (number1 <= number2)
    //        {
    //            std::cout << "The smaller value is: " << number1 << std::endl;
    //            std::cout << "The larger value is: " << number2 << std::endl;
    //        } else if (number1 > number2)
    //        {
    //            std::cout << "The smaller value is: " << number2 << std::endl;
    //            std::cout << "The larger value is: " << number1 << std::endl;
    //        } else
    //        {
    //            std::cout << "Number 1 and number two are equals.\n";
    //        }
    //
    //        // Drill 5
    //        if (almostEqual(number1, number2))
    //        {
    //            std::cout << "The numbers are almost equal. \n";
    //        }
    //    }

    // Drill 6
    // Drill 7
    // Drill 10, use vector, // convert all the values entered, keep them in the vector.

    double num1 = 0.0, smallest = 0.0, largest = 0.0;
    bool firstTime = true;
    std::string unit = " ";
    int valueCount = 0;
    double sumOfValues = 0;
    std::vector <double> valuesVector;

    std::cout << "Enter a number: \n";
    while (std::cin >> num1 >> unit)
    {
        // check if unit is valid
        // Drill 8
        if (!(unit == "cm" || unit == "m" || unit == "inch" || unit == "ft"))
        {
            std::cout << "Enter a valid unit.\n";
            continue;
        }
        //first time both smallest and largest will be the same
        if (firstTime)
        {
            smallest = num1;
            largest = num1;
            firstTime = false;
        }
        else if (num1 <= smallest)
        {
            smallest = num1;
        }
        else if (num1 > largest)
        {
            largest = num1;
        }
        else
        {
            std::cout << "Entered number is neither largest nor smallest.\n";
        }
        std::cout << "Smallest number so far: " << smallest << unit << std::endl;
        std::cout << "Largest number so far: " << largest << unit << std::endl;
        ++valueCount;
        num1 = convertToMeter(num1, unit);
        sumOfValues += num1;
        valuesVector.push_back(num1); // Drill 10
    }
    std::cout << std::endl;
    std::cout << "*************************************************\n";
    std::cout << "Number of Values: " << valueCount << std::endl;
    std::cout << "Sum of values: " << sumOfValues << " m" << std::endl;
    std::cout << "Smallest number: " << smallest << unit << std::endl;
    std::cout << "Largest number: " << largest << unit << std::endl;
    
    // Drill 10
    std::cout << "Values entered, converted to meter: \n";
    std::sort(valuesVector.begin(), valuesVector.end()); // Drill 11
    for (int i = 0; i < valuesVector.size(); i++)
    {
        std::cout << "   " << valuesVector[i] << std::endl;
    }

    return 0;
}

