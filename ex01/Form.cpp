#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(75), gradeToExecute(75) {}

Form::Form(const std::string& newName, int newGradeToSign, int newGradeToExecute)
    : name(newName), isSigned(false), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
    if (newGradeToSign < 1 || newGradeToExecute < 1)
        throw GradeTooHighException();
    if (newGradeToSign > 150 || newGradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName()
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Sign Grade: " << f.getGradeToSign()
       << " | Exec Grade: " << f.getGradeToExecute();
    return os;
}
