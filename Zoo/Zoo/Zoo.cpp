#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>


int main()
{
	Fox fox;
	Cat cat("Sprinkles");
	fox.Say();
	Animal* pcat = &cat;
	Zoo zoo;
	zoo.Append(pcat);
	zoo.Listen();
	zoo.Remove(1);
	zoo.Remove(0);
	Dog* dog1 = new Dog("Rex"); // сначала вызывается деструктор наследника, потом базового класса
	delete dog1;
	Animal* dog2 = new Dog("Rex"); // вызывается только деструктор базового класса
	delete dog2;
	Sparrow sparrow("Jack");
	Animal* psparrow = &sparrow;
	Cockerel cockerel("Petya");
	Cockerel* pcockerel = &cockerel;
	zoo.Append(psparrow);
	zoo.Append(pcockerel);
	std::cout << zoo.BirdCounter() << std::endl;
}