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

int main ()
{
    {
        Intern szarak;
        Bureaucrat bigBoss("BigBoss", 1);
        AForm *what;
        what = szarak.makeForm("robotomy", "Bender");
        AForm *problem;
        problem = szarak.makeForm("da fcuk is this", "STH");
        delete what;
        delete problem;
    }
    return 0;
}
