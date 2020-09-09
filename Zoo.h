// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H
#include <string>
#include <iostream>
//#include <vector>

class Animal // класс животные
{
protected:
	std::string name;
	int id = 0;
public:
	Animal()
	{
	}
	Animal(std::string n = {"Who am I?"})
	{
		name = n;
	}
	virtual void Say()
	{
	}
	void Listen()
	{

	}
	~Animal()
	{
	}
};

class Mammal : protected Animal // класс млекопитающие
{
public: 
	Mammal(std::string name) : Animal(name)
	{
	}
};

class Bird : protected Animal // клкасс птицы
{
public:
	Bird(std::string name) : Animal(name)
	{
	}
};

class Cat: protected Mammal // класс коты
{
	std::string sound = { "Meow!" };
public:
	Cat(std::string name): Mammal (name)
	{
		id = id + 1;
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
};

class Dog: protected Mammal // класс собаки
{
	std::string sound = { "Woof!" };
public:
	Dog(std::string name) : Mammal(name)
	{
		id = id + 1;
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
};

class Fox : protected Mammal // класс лиса
{
	std::string sound = { "?????" };
public:
	Fox(std::string name) : Mammal(name)
	{
		id = id + 1;
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
};

class Sparrow : protected Bird // класс воробей
{
	std::string sound = { "Tweet-tweet" };
public:
	Sparrow(std::string name) : Bird(name)
	{
		id = id + 1;
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
};

class Cockerel : protected Bird // класс петух
{
	std::string sound = { "Cock-A-Doodle-Do!" };
public:
	Cockerel(std::string name) : Bird(name)
	{
		id = id + 1;
	}
	void Say()
	{
		std::cout << sound << std::endl;
	}
};

int main()
{
	Cat cat("Sprinkles");
	cat.Say();
}
#endif //PCH_H
