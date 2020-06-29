
#include <iostream>

// function declaration

int sq(int x)
{
    int temp = 0;
    if (x <= 0)
    {
        std::cout << "Invalid number.\n";
        exit(1);
    } else
    {
        for (int i = x; i > 0; --i)
        {
            temp +=x;
            //std::cout << "Temp: " << temp << std::endl;
        }
     }
    return temp;
}

int main(int argc, char** argv)
{

    std::cout << sq(5) << std::endl;
    return 0;
}

