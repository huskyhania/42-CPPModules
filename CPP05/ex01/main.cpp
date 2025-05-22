/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:22 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/22 22:19:59 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    {
        Bureaucrat b1;
        Bureaucrat b2("Henryk", 100);
        Bureaucrat b3("Dyrektor", 1);

        Form f1;
        Form f2;
        Form lowest("podanie", 0, 150, 150);
        Form highest("decyzja", 0, 1, 1);
        std::cout << "--test one--" << std::endl;
        std::cout << lowest << std::endl;
        std::cout << highest << std::endl;

        lowest.beSigned(b2);
        b2.signForm(lowest);
        b3.signForm(highest);
    }
    {
        std::cout << std::endl << "--test two--" << std::endl;
        Bureaucrat b1("prezes", 1);
        Bureaucrat b2("normik", 150);
        Form f1("kartka", 0, 150, 150);
        Form f2("bardzo pilne bardzo wazne", 0, 1, 1);
        Form f3("podpisana kartka", 1, 149, 149);
        b2.signForm(f1);
        b2.signForm(f2);
        b2.signForm(f1);
        b2.signForm(f3);
        b1.signForm(f2);
        b1.signForm(f2);
    }
    {
        std::cout << std::endl << "--test three--" << std::endl;
        Bureaucrat c1;
        Bureaucrat c2 = c1;
        Form z1("test", 0, 20, 20);
        Form z2 = z1;
        c2.signForm(z2);
    }
    {
        std::cout << std::endl << "--fail form test--" << std::endl;
        try{
            Form failForm("fail", 1, 150, 0);
        }
        catch(std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    {
        Form seg("bardzo pilne bardzo wazne", 0, 1, 1);
        Bureaucrat b1("Henryk", 100);
        try
        {
            seg.beSigned(b1);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
