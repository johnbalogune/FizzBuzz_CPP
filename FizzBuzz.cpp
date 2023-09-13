#include <iostream>
#include <string>

class Replacement
{
public:
    Replacement(int number, std::string name1, std::string name2) : number(number), name1(name1), name2(name2) {};

    int number = 0;
    std::string name1 = "";
    std::string name2 = "";

    void operator== (Replacement const & other)
    {
        if (number % 3 == 0)
            std::cout << name1 << ", ";
        if (number % 5 == 0)
            std::cout << name2 << ", ";
        if (number % 3 != 0 && number % 5 != 0)
            std::cout << number << ", ";
    }

    friend std::ostream& operator<<(std::ostream& os, const Replacement& replacement)
    {
        os << replacement.number << ". ";
        return os;
    }
};

int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            Replacement replacement = Replacement(i, "Fizz", "Buzz");
            replacement == replacement;  // Use the overloaded operator
        }
        else
        {
            std::cout << i << ", "; // End numbers with a full stop and space
        }
    }

    return 0;
}
