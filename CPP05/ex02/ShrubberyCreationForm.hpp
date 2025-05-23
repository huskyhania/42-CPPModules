/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:27:14 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 13:27:17 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm();

		const std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
		class FileOpenException: public std::exception{
			public:
				const char* what() const throw();
		};
};

#endif
