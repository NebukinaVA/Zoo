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
	~Animal() { std::cout << "An animal died :(((" << std::endl; }
};

class Mammal : public Animal // класс млекопитающие
{
public:
	Mammal(std::string n) : Animal(n) {}
	~Mammal() { std::cout << "A mammal died :(((" << std::endl; }
};

class Bird : public Animal // клкасс птицы
{
public:
	Bird(std::string n) : Animal(n) {}
	~Bird() { std::cout << "A bird died :(((" << std::endl; }
};

class Cat : public Mammal // класс коты
{
	std::string sound = { "Meow!" };
public:
	Cat(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Cat() { std::cout << "A cat died :(((" << std::endl; }
};

class Dog : public Mammal // класс собаки
{
	std::string sound = { "Woof!" };
public:
	Dog(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Dog() { std::cout << "A dog died :(((" << std::endl; }
};

class Fox : public Mammal // класс лиса
{
	std::string sound = { "?????" };
public:
	Fox(std::string n = { "Who am I?" }) : Mammal(n) {}
	void Say();
	~Fox() { std::cout << "A fox died :(((" << std::endl; }
};

class Sparrow : public Bird // класс воробей
{
	std::string sound = { "Tweet-tweet" };
public:
	Sparrow(std::string n = { "Who am I?" }) : Bird(n) {}
	void Say();
	~Sparrow() { std::cout << "A sparrow died :(((" << std::endl; }
};

class Cockerel : public Bird // класс петух
{
	std::string sound = { "Cock-A-Doodle-Do!" };
public:
	Cockerel(std::string n = { "Who am I?" }) : Bird(n) {}
	void Say();
	~Cockerel() { std::cout << "A cockerel died :(((" << std::endl; }
};

class Zoo // класс зоопарк
{
	std::vector <Animal*> animals;
public:
	Zoo();
	void Append(Animal* a);
	void Remove(int ident); //id
	void Listen();
	int BirdCounter(); //
	~Zoo() {}
};

#endif