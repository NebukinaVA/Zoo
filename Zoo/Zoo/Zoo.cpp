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
}