/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:22 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 15:23:54 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <memory>

int main ()
{
	Intern i1;
	Bureaucrat b1("Prezes", 1);
	Bureaucrat b2("normik", 150);
	{
		std::cout << "--test one--" << std::endl;
		try{
			AForm *test = i1.makeForm("bye", "test");
			if (test)
			{
				b2.signForm(*test);
				b2.executeForm(*test);
				b1.signForm(*test);
				b1.executeForm(*test);
				delete test;
			}
		}
		catch (std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--test two--" << std::endl;
		try{
			AForm *form = i1.makeForm("pardon", "Luigi");
			if (form)
			{
				b1.signForm(*form);
				b1.executeForm(*form);
				delete form;
			}
		}
		catch (std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--test three--" << std::endl;
		try{
			AForm *what = i1.makeForm("robotomy", "here");
			if (what)
			{
				b1.signForm(*what);
				b2.executeForm(*what);
				delete what;
			}
		}
		catch(std::exception &e){
			std::cout << "couldn't execute because " << e.what() << std::endl;
		}
		std::cout << std::endl << "--one more--" << std::endl;
		try {
			AForm *problem = i1.makeForm("da fcuk is this", "STH");
			if (problem)
			{
				b2.signForm(*problem);
				b2.executeForm(*problem);
				delete problem;
			}
		} 
		catch (const std::exception &e) {
			std::cout << "couldn't execute because of " << e.what() << std::endl;
		}
	}
	return 0;
}
