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
	// проверяем порядок вызова дестукторов
	Dog* dog1 = new Dog("Rex");
	delete dog1; 
	Animal* dog2 = new Dog("Rex"); 
	delete dog2;
	// проверяем BirdCount
	Sparrow sparrow("Jack");
	Animal* psparrow = &sparrow;
	Cockerel cockerel("Petya");
	Animal* pcockerel = &cockerel;
	Dog dog;
	Animal* pdog = &dog;
	zoo.Append(psparrow);
	zoo.Append(pcockerel);
	zoo.Append(pdog);
	std::cout << zoo.BirdCounter() << std::endl;
}