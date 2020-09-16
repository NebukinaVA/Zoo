#ifndef PCH_H
#define PCH_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Animal // класс животные
{
protected:
	std::string name;
	static int id_; // вспомогательная
	int id;
public:
	Animal(std::string n = { "Who am I?" })
	{
		id = ++id_;
		name = n;
	}
	virtual void Say() = 0;
	int ReturnId()
	{
		return id;
	}
	~Animal()
	{
	}
};

int Animal::id_ = 0;

class Mammal : protected Animal // класс млекопитающие
{
public:
	Mammal(std::string n) : Animal(n)
	{
	}
	~Mammal()
	{
	}
};

class Bird : protected Animal // клкасс птицы
{
public:
	Bird(std::string n) : Animal(n)
	{
	}
	~Bird()
	{
	}
};

class Cat : protected Mammal // класс коты
{
	std::string sound = { "Meow!" };
public:
	Cat(std::string n = { "Who am I?" }) : Mammal(n)
	{
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
	~Cat()
	{
	}
};

class Dog : protected Mammal // класс собаки
{
	std::string sound = { "Woof!" };
public:
	Dog(std::string n = { "Who am I?" }) : Mammal(n)
	{
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
	~Dog()
	{
	}
};

class Fox : protected Mammal // класс лиса
{
	std::string sound = { "?????" };
public:
	Fox(std::string n = { "Who am I?" }) : Mammal(n)
	{
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
	~Fox()
	{
	}
};

class Sparrow : protected Bird // класс воробей
{
	std::string sound = { "Tweet-tweet" };
public:
	Sparrow(std::string n = { "Who am I?" }) : Bird(n)
	{
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
	~Sparrow()
	{
	}
};

class Cockerel : protected Bird // класс петух
{
	std::string sound = { "Cock-A-Doodle-Do!" };
public:
	Cockerel(std::string n = { "Who am I?" }) : Bird(n)
	{
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
	~Cockerel()
	{
	}
};

class Zoo // класс зоопарк
{
	std::vector <Animal*> animals;
public:
	Zoo()
	{
		Animal* a;
		animals.push_back(a);
	}
	void Append(Animal* a)
	{
		animals.push_back(a);
	}
	void Remove(int ident) //id
	{
		std::vector <Animal*> temp(animals);
		if (animals.empty()) throw "There are no animals to remove :(";
		for (int i = 0;i < animals.size(); i++)
		{
			if (animals[i]->ReturnId() == ident)
			{
				temp.erase(animals.begin() + i);
				animals.resize(animals.size() - 1);
				animals.swap(temp);
			}
		}
	}
	void Listen() 
	{
		for (int i = 0; i < 5;i++)
			animals[i]->Say();
	}
	~Zoo()
	{
	}
};

int main()
{
	Cat cat("Sprinkles");
	cat.Say();
	Zoo zoo;
	Animal* pet;
	zoo.Append(pet);
	//zoo.Listen();
	zoo.Remove(1);
}
#endif //PCH_H