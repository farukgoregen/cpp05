#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

// if/else kullanmamak için fonksiyon pointer'lı struct array kullanıyoruz
static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // her satır: form adı, o formu oluşturan fonksiyon
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string&);
    };

    FormEntry forms[] = {
        {"shrubbery creation",  makeShrubbery},
        {"robotomy request",    makeRobotomy},
        {"presidential pardon", makePardon}
    };

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Intern: unknown form name: " << formName << std::endl;
    return NULL;
}