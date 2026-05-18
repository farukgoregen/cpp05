#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- Test 1: Invalid Form Creation ---" << std::endl;
    try
    {
        Form badForm("Bad Form", 200, 1);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 2: Successful Signing ---" << std::endl;
    try
    {
        Bureaucrat omer("Omer", 10);
        Form highPriority("High Priority Form", 20, 45);
        std::cout << omer << std::endl;
        std::cout << highPriority << std::endl;
        omer.signForm(highPriority);
        std::cout << highPriority << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3: Failed Signing (Low Grade) ---" << std::endl;
    try
    {
        Bureaucrat stajyer("Stajyer", 150);
        Form secretDoc("Secret Document", 1, 1);
        std::cout << stajyer << std::endl;
        std::cout << secretDoc << std::endl;
        stajyer.signForm(secretDoc);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}