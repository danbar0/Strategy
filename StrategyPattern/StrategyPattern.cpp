// StrategyPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "weapon_sword.h"
#include "concrete_blade.h"
#include "concrete_handle.h"

class Scimitar : public Sword {
public:
	Scimitar(void) {
		handleBehavior = new OpenHandle(); 
		bladeBehavior = new CurvedBlade(); 
	}
	~Scimitar(void) {
		delete handleBehavior;
		delete bladeBehavior; 
	}

private:
};

class Longsword : public Sword {
public:
	Longsword(void) {
		handleBehavior = new HiltedHandle(); 
		bladeBehavior = new LongBlade(); 
	}

	~Longsword(void) {
		delete handleBehavior; 
		delete bladeBehavior; 
	}
};

int main()
{
	Sword* scimitar = new Scimitar(); 
	Sword* longsword = new Longsword(); 

	std::cout << "Welcome to swordplay!\n";

	scimitar->attack(); 
	longsword->attack(); 

	scimitar->setHandleBehavior(new RapierHandle());

	std::cout << "Enemy changed sword handle!\n";

	scimitar->attack();
	longsword->attack();

	delete scimitar;

}
