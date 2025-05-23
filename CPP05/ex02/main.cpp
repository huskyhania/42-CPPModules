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

int main ()
{
    {
        std::cout << "--test one--" << std::endl;
        Bureaucrat b1;
        Bureaucrat b2("test", 50);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        ShrubberyCreationForm s1;
        ShrubberyCreationForm s2("home");
        ShrubberyCreationForm s3("unsigned");
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
        b1.signForm(s1);
        b2.signForm(s2);
        b2.signForm(s2);
        b2.executeForm(s1);
        b2.executeForm(s2);
        b2.executeForm(s3);
        std::cout << std::endl;
    }
    {
        std::cout << "--test two--" << std::endl;
        Bureaucrat b1;
        Bureaucrat b2("robot", 40);
        Bureaucrat b3("slabeusz", 150);
        RobotomyRequestForm r1;
        RobotomyRequestForm r2("home");
        RobotomyRequestForm r3("unsigned");
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;
        std::cout << r3 << std::endl;
        b1.signForm(r1);
        b2.signForm(r2);
        b2.signForm(r2);
        b3.signForm(r3);
        b2.executeForm(r1);
        b2.executeForm(r2);
        b3.executeForm(r3);
        std::cout << std::endl;
    }
    {
        std::cout << std::endl << "--test three--" << std::endl;
        Bureaucrat b1;
        Bureaucrat b2("robot", 40);
        Bureaucrat b3("slabeusz", 150);
        Bureaucrat b4("prezes", 2);
        PresidentialPardonForm r1;
        PresidentialPardonForm r2("home");
        PresidentialPardonForm r3("unsigned");
        PresidentialPardonForm r4("toBeSigned");
        b1.signForm(r1);
        b2.signForm(r2);
        b2.signForm(r2);
        b3.signForm(r3);
        b4.signForm(r4);
        b2.executeForm(r1);
        b2.executeForm(r2);
        b3.executeForm(r3);
        b4.executeForm(r3);
        b4.executeForm(r4);
        std::cout << std::endl;
    }


    return 0;
}
