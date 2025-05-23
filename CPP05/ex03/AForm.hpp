/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:39:09 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/22 18:39:15 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		AForm(std::string name, bool isSigned, const int signGrade, const int execGrade);
		AForm(const AForm &original);
		AForm &operator=(const AForm &original);
		~AForm();
		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};
		class AlreadySignedException: public std::exception{
			public:
				const char* what() const throw();
		};
		class NotSignedException: public std::exception{
			public:
				const char* what() const throw();
		};
		//getters for every param
		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(Bureaucrat &clerk);
		virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &outstream, AForm &f1);

#endif
