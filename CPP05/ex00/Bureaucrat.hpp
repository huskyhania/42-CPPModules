#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &original);
		Bureaucrat &operator=(const Bureaucrat &original);
		~Bureaucrat();
		const std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream &outstream, Bureaucrat &buro);

class Bureaucrat::GradeTooHighException::public std::exception{}

class Bureaucrat::GradeTooLowException::public std::exception{}

#endif
