/* Example of if else in C++, converts yen, pounds, kroner into dollars.
 */

#include <iostream>

int main(int argc, char** argv)
{
    constexpr double dollarPound = .80;
    constexpr double dollarKroner = 9.58;
    constexpr double dollarYen = 107.26;
    char option = ' ';
    char currency = ' ';
    double amount = 1.0;
    double convertedAmount = 1.0;
    // user chooses conversion, Dollar to other or other to Dollar
    std::cout << "Enter A to convert from Dollar to another currency, B to convert another currency to Dollar\n";
    std::cin >> option;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << "Enter your currency (Y for Yen, D for Dollar, K for Kroner, P for Pound: ";
    std::cin >> currency;

    if (option == 'a' || option == 'A')
    {
        switch (currency)
        {
            case 'Y': case 'y':
                convertedAmount = amount * dollarYen;
                break;

            case 'p': case 'P':
                convertedAmount = amount * dollarPound;
                break;

            case 'k': case 'K':
                convertedAmount = amount * dollarKroner;
                break;

            default:
                std::cout << "Bad input.\n";
                exit(1);
        }
        std::cout << amount << " dollars equals to " << convertedAmount << " " << currency << std::endl;
    } else if (option == 'b' || option == 'B')
    {
        switch (currency)
        {
            case 'Y': case 'y':
                convertedAmount = amount / dollarYen;
                break;

            case 'p': case 'P':
                convertedAmount = amount / dollarPound;
                break;

            case 'k': case 'K':
                convertedAmount = amount / dollarKroner;
                break;

            default:
                std::cout << "Bad input.\n";
                exit(1);
        }
        std::cout << amount << " " << currency << " equals to " << convertedAmount << " dollars " << std::endl;
    } else
    {
        std::cout << "User exit.\n";
        exit(1);
    }
    return 0;
}

