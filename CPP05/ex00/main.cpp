/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:22 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/20 16:35:44 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << std::endl << "--first test--" << std::endl << std::endl;

		Bureaucrat Halinka;
		Bureaucrat Grazynka("Grazynka", 10);
		std::cout << Halinka << std::endl;
		std::cout << Grazynka << std::endl;
		Halinka.incrementGrade();
		std::cout << Halinka << std::endl;
		Halinka.incrementGrade();
		std::cout << Halinka << std::endl;
		for (int i = 0; i < 10; i++)
		{
			try{
				Grazynka.incrementGrade();
				std::cout << Grazynka << std::endl;
			}
			catch (std::exception & e){
				std::cerr << "Exception caught from incrementGrade: " << e.what() << std::endl;
			}
		}
		std::cout << Grazynka << std::endl;
	}
	{
		std::cout << std::endl << "--second test--" << std::endl << std::endl;
		try{
			Bureaucrat Krystynka("Krystynka", 151);
		}
		catch (std::exception & e){
			std::cerr << "Exception caught from constructor: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--third test--" << std::endl << std::endl;
		try{
			Bureaucrat Krystynka("Krystynka", -10);
		}
		catch (std::exception & e){
			std::cerr << "Exception caught from constructor: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "--fourth test--" << std::endl << std::endl;
		try{
			Bureaucrat Krystynka("Krystynka", 149);
			std::cout << "values from constructor " << Krystynka << std::endl;
			Krystynka.decrementGrade();
			std::cout << Krystynka << std::endl;
			Krystynka.decrementGrade();
			std::cout << Krystynka << std::endl;
		}
		catch (std::exception & e){
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
}

