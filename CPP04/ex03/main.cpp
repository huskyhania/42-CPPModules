#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "--school test--" << std::endl << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << std::endl << "--end school test--" << std::endl;
	}
	{
		std::cout << "--my tests--" << std::endl;
		Character who("Hania");
		AMateria* cold = new Ice();
		AMateria* medicine = new Cure();
		who.equip(cold);
		who.equip(medicine);
		Character whothis("Ala");
		std::cout << "Character 2 Name: " << whothis.getName() << std::endl;
		Character whothat("Maria");
		whothat = who;		
		std::cout << "Character 3 Name: " << whothat.getName() << std::endl;
		std::cout << "Equipments in " << whothat.getName() << std::endl;

    	whothis.use(0, who);
		whothat.use(1, who);
		std::cout << std::endl << std::endl;
	}
	{
		Character Char1("Player1");
		AMateria* brr = new Ice();
		AMateria* pomoc = new Cure();
		Char1.equip(brr);
		Char1.equip(pomoc);
		AMateria* fire = new Ice();
    	AMateria* lightning = new Cure();
    	Char1.equip(fire);
    	Char1.equip(lightning);
    	AMateria* iceToEquip = new Ice();
    	Char1.equip(iceToEquip); 
	
		Char1.use(0, Char1);
		Char1.use(1, Char1);
		Char1.unequip(0);
		std::cout << "Using unequipped Materia (should not work): " << std::endl;
		Char1.use(0, Char1);
		delete brr;
		//ONCE A CHARACTER IS EQUIPPED WITH A MATERIA, IT'S RESPONSIBLE FOR DELETING IT, OTHERWISE MATERIA HAS TO BE DELETED MANUALLY
		//delete pomoc;
		//delete fire;
		//delete lightning;
		delete iceToEquip;
		std::cout << "--test end--" << std::endl << std::endl;
	}
	{
		std::cout << "--learn and create materia--" << std::endl;
    	IMateriaSource* src = new MateriaSource();
    	src->learnMateria(new Ice());
    	src->learnMateria(new Cure());

    	AMateria* iceClone = src->createMateria("ice");
    	AMateria* cureClone = src->createMateria("cure");

		if (iceClone != nullptr && cureClone != nullptr) {
        	std::cout << "cloned materia types: " << iceClone->getType() << ", " << cureClone->getType() << std::endl;
    	}
    	delete iceClone;
    	delete cureClone;
    	delete src;

    	std::cout << "--memory fails--" << std::endl;
    	AMateria* failingMateria = new Ice();
    	AMateria* clonedMateria = failingMateria->clone();

    	delete failingMateria;
    	delete clonedMateria;
		std::cout << std::endl;
	}
	return 0;
}
