/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:04:15 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 00:04:16 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		~RobotomyRequestForm();

		const std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
