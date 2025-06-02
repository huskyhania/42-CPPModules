/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:52:03 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/02 21:08:16 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	int choice = std::rand()%3;
	if (choice == 1){
		std::cout << "choice: A\n";
		return new A;
	}
	else if (choice == 2){
		std::cout << "choice: B\n";
		return new B;
	}
	else{ 
		std::cout << "choice: C\n";
		return new C;
	}
}
//casting on pointers will return a valid pointer on success or nullpointer on failure
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer of type A was identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer of type B was identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer of type C was identified" << std::endl;
	else
		std::cout << "Casting error" << std::endl;
}

//casting is not enough of a use for a variable to silence "unused" warnings
//voiding could also be done like this: (void)dynamic_cast<A&>(p);

void	identify(Base& p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference type A was identified" << std::endl;
		return;
	}
	catch (std::bad_cast&){}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference type B was identified" << std::endl;
		return;
	}
	catch (std::bad_cast&){}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference type C was identified" << std::endl;
		return;
	}
	catch (std::bad_cast&){}
	std::cout << "Unable to identify by reference" << std::endl;	
}

int main(void)
{
	std::srand(time(NULL));
	try{
		Base *sth;
		sth = generate();
		identify(sth);
		identify(*sth);
		delete(sth);
	}
	catch (const std::bad_alloc& e)//catches exceptions of type std::bad_alloc an its derived types
	{
		std::cout << "memory alloc fail\n";
	}
	catch (...)
	{
		std::cout << std::endl << "something else went wrong...\n";
	}
	{
		std::cout << std::endl << "nullptr test" << std::endl;
		Base* ptr = nullptr;
		identify(ptr);
	}
	{
		std::cout << std::endl << "A small loop test" << std::endl;
		try{
			Base *multitest;
			for (int i = 0; i < 20; i++)
			{
				multitest = generate();
				identify(multitest);
				identify(*multitest);
				std::cout << std::endl;
				delete(multitest);
			}
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "memory alloc fail\n";
		}
		catch (...)
		{
			std::cout << "something else went wrong...\n";
		}
	}
	return 0;
}
