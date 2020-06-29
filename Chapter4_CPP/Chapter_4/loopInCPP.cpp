/*
 * Example of loops in C++ try this section of the book
 * ASCII value
 * char ('a' + 1 ) equals to b 
 */

#include <iostream>


int main(int argc, char* argv[])
{
    char inputChar = 'A';
    inputChar = char(inputChar + 1);
    //std::cout << "Enter a character :" << std::endl;
    //std::cin >> inputChar;
    std::cout << "Value of the character " << inputChar << " is : " << int(inputChar) << std::endl;
    int temp = 0;
//    while (int(inputChar +temp) <= int('z')) 
//    {
//        std::cout << char(inputChar + temp) << " " << int(inputChar) + temp << std::endl;
//        ++temp;
//    }
    
//    std::cout << "************************************************************** \n";
//    inputChar = 'A';
//    temp = 0;
//    for (int i = int('A'); i <= int('z'); ++i)
//    {
//       if (inputChar >='A' && inputChar <= 'Z' || inputChar >= 'a' && inputChar <= 'z')
//       {
//           std::cout << inputChar << " " << int(inputChar) << std::endl;
//       }
//       inputChar = char(i + 1);
//       
//    }
    
    std::cout << "************************************************************** \n";
    inputChar = 'A';
    temp = 0;
    for (int i = 0; i <= int('z'); ++i)
    {
        inputChar = char('A'+ i);
       if (inputChar >='A' && inputChar <= 'Z' || inputChar >= 'a' && inputChar <= 'z')
       {
           std::cout << inputChar << " " << int(inputChar) << std::endl;
       }
       
       
    }
   
    
    return 0;
}