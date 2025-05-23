/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:06:41 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 00:06:54 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
		~PresidentialPardonForm();

		const std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
