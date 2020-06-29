
/**
 * Bleep out words you do not like. Cin words, Cout the word, unless it is in the disliked word list
 */

#include<iostream>
#include<vector>


int main(int argc, char** argv)
{
    std::string dislikedWord = "Broccolli";
    std::vector <std::string> words;
    std::cout << "Enter words, ctrl z to close: ";
    
    for (std::string temp; std::cin >> temp;)
    {
        if (temp == "-1")
        {
            break;
        }
        else
        {
        words.push_back(temp);
        }
    }
    for (int i=0; i < words.size(); i++)
    {
       if (words[i] != dislikedWord)
        {
            std::cout << words[i] << " ";
        }
    }   
    std::cout << std::endl;     

    return 0;
}

