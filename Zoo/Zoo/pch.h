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
	int ReturnId();
	~Animal() {}
};

class Mammal : public Animal // класс млекопитающие
{
public:
	Mammal(std::string n) : Animal(n) {}
	~Mammal() {}
};

class Bird : public Animal // клкасс птицы
{
public:
	Bird(std::string n) : Animal(n) {}
	~Bird() {}
};

class Cat : public Mammal // класс коты
{
	std::string sound = { "Meow!" };
public:
	Cat(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Cat() {}
};

class Dog : public Mammal // класс собаки
{
	std::string sound = { "Woof!" };
public:
	Dog(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Dog() {}
};

class Fox : public Mammal // класс лиса
{
	std::string sound = { "?????" };
public:
	Fox(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Fox() {}
};

class Sparrow : public Bird // класс воробей
{
	std::string sound = { "Tweet-tweet" };
public:
	Sparrow(std::string n = { "Who am I?" }) : Bird(n) {}
	void Say();
	~Sparrow() {}
};

class Cockerel : public Bird // класс петух
{
	std::string sound = { "Cock-A-Doodle-Do!" };
public:
	Cockerel(std::string n = { "Who am I?" }) : Bird(n) {}
	void Say();
	~Cockerel() {}
};

class Zoo // класс зоопарк
{
	std::vector <Animal*> animals;
public:
	Zoo();
	void Append(Animal* a);
	void Remove(int ident); //id
	void Listen();
	~Zoo() {}
};

#endif