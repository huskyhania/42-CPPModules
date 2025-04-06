#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &original);
		Brain &operator=(const Brain &original);
		~Brain();
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif
