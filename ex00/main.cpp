#include "Bureaucrat.hpp"

int main() {
    try 
    {
        Bureaucrat alice("Alice", 5);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.decrementGrade();
        std::cout << alice << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat bob("Bob", 0);
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat carol("Carol", 1);
        carol.incrementGrade();
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat dave("Dave", 150);
        dave.decrementGrade();
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}