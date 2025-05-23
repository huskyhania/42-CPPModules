/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:03:50 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 00:03:51 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char* touch_grass = R"(
              * *    
           *    *  *
      *  *    *     *  *
     *     *    *  *    *
 * *   *    *    *    *   *
 *     *  *    * * .#  *   *
 *   *     * #.  .# *   *
  *     "#.  #: #" * *    *
 *   * * "#. ##"       *
   *       "###
             "##
              ##.
              .##:
              :###
              ;###
            ,####.
/\/\/\/\/\/.######.\/\/\/\/\
)";

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 0, 145, 137), _target("Shrubbery"){
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 0, 145, 137), _target(target){
	std::cout << "Shrubbery parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original):
	AForm("ShrubberyCreationForm", 0, 145, 137), _target(original.getTarget())
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &original){
	if (this != &original)
	{
		this->_target = original.getTarget();
		AForm::operator=(original);
	}
	std::cout << "Shr assignement operator" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubbery destructor" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget() const{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	std::cout << "Shrubbery execute called" << std::endl;
	if (!this->getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::ofstream out;
	out.open(this->_target + "_shrubbery");
	if (out.fail()){
		throw ShrubberyCreationForm::FileOpenException();
	}
	out << touch_grass;
	out.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw(){
	return "file could not be opened";
}
