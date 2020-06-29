/* This is a Drill 7 on Chapter 4, continuation from other drills.
 * Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. 
 * Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit indicator into a string. You may consider 12 m 
 * (with a space between the number and the unit) equivalent to 12m (without a space).
 * Drill 8 : reject values without units or "illegal" units. 
 */

#include <iostream>

int main(int argc, char* argv[])
{
    constexpr double cm = 1;
    constexpr double m = 100 * cm;
    constexpr double in = 2.54 * cm;
    constexpr double ft = 12 * in;
    std::string unit = " ";
    double value = 0.0;
    
    std::cout << "Enter a value and unit to convert: ie 12m: \n";    
    while (std::cin >> value >> unit)
    {
        if (!(unit == "cm" || unit == "m" || unit == "in" || unit == "ft"))
        {
            std::cout << "Invalid or no unit provided. \n";
            std::cout << "Please enter unit. \n";
            continue;
            //exit(0);
        }
        if (unit == "cm")
        {
            std::cout << "The converted value is: " << value * cm << " cm" << std::endl;
        }
        else if (unit == "m")
        {
            std::cout << "The converted value is: " << value * m << " cm" << std::endl;
        }
        
        else if (unit == "in")
        {
            std::cout << "The converted value is: " << value * in << " cm" << std::endl;
        }
        else if (unit == "ft")
        {
            std::cout << "The converted value is: " << value * ft << " cm" << std::endl;
        }
    }
    return 0;
}

