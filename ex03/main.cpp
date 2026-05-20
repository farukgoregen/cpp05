#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someIntern;
    AForm* form;

    std::cout << "--- Test 1: Shrubbery Creation Form ---" << std::endl;
    form = someIntern.makeForm("shrubbery creation", "home");
    if (form) {
        Bureaucrat bob("Bob", 136);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    std::cout << std::endl << "--- Test 2: Robotomy Request Form ---" << std::endl;
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat alice("Alice", 45);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }

    std::cout << std::endl << "--- Test 3: Presidential Pardon Form ---" << std::endl;
    form = someIntern.makeForm("presidential pardon", "Faruk");
    if (form) {
        Bureaucrat president("President", 5);
        president.signForm(*form);
        president.executeForm(*form);
        delete form;
    }

    std::cout << std::endl << "--- Test 4: Unknown Form ---" << std::endl;
    form = someIntern.makeForm("unknown form", "target");
    if (form)
        delete form;

    return 0;
}