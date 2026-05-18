#include "AForm.hpp"


AForm::AForm() : name("default"), isSigned(false), gradeToSign(75), gradeToExecute(75) {}

AForm::AForm(const std::string& newName, int newGradeToSign, int newGradeToExecute)
    : name(newName), isSigned(false), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
    if (newGradeToSign < 1 || newGradeToExecute < 1)
        throw GradeTooHighException();
    if (newGradeToSign > 150 || newGradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form: " << f.getName()
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Sign Grade: " << f.getGradeToSign()
       << " | Exec Grade: " << f.getGradeToExecute();
    return os;
}
