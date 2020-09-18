#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

int Animal::id_ = 0;

int Animal::ReturnId()
{
	return id;
}

void Cat::Say()
{
	std::cout << sound << std::endl;
}

void Dog::Say()
{
	std::cout << sound << std::endl;
}

void Fox::Say()
{
	std::cout << sound << std::endl;
}

void Sparrow::Say()
{
	std::cout << sound << std::endl;
}


void Cockerel::Say()
{
	std::cout << sound << std::endl;
}

Zoo::Zoo()
{
}
void Zoo::Append(Animal* a)
{
	animals.push_back(a);
}
void Zoo::Remove(int ident) //id
{
	if (animals.empty()) throw "There are no animals to remove :(";
	for (int i = 0;i < animals.size(); i++)
	{
		if (animals[i]->ReturnId() == ident)
		{
			std::swap(animals[i], animals[animals.size() - 1]);
			animals.resize(animals.size() - 1);
			i--;
		}
	}
}
void Zoo::Listen()
{
	if (animals.empty()) throw "Sorry, our zoo is closed! :(";
	for (int i = 0; i < animals.size();i++)
		animals[i]->Say();
}