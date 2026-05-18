#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) : name(newName) {
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    }
    catch (std::exception& e) {
        std::cout << *this << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}