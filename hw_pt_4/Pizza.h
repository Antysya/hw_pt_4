#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class Cheque {
private:
	static Cheque* pObj;
	Cheque() {
		pObj = NULL;
	}
	~Cheque() {
		if (pObj) {
			delete pObj;
		};
	}
	
public:	
	static Cheque* GetInstance(){
		if (!pObj) {
			pObj = new Cheque();
		}
		return pObj;
	}

	void PutCheque(string message) {

		SYSTEMTIME timer;
		GetLocalTime(&timer);
		ofstream fObj("cheque.txt", ios::app);
		if (!fObj) {
			cout << "\nError with file\n";
			exit(EXIT_FAILURE);
		}
		fObj << message.c_str() << "\t" << timer.wDay << ':' << setfill('0') << setw(2) << timer.wMonth << ':' << timer.wYear << endl;
	};
};

Cheque* Cheque::pObj;

class Pizza {
	vector<Pizza*> pizza;
public:
	virtual void info() = 0;
	virtual void addPizza(Pizza* p) {
		pizza.push_back(p);;
	}
	virtual ~Pizza() {}
};

class Dough : public Pizza {
public:
	void info() {
		cout << "Тесто" << endl;
	};
};

class Sauce : public Pizza
{
public:
	void info() {
		cout << "Соус" << endl;
	};
};

class Cheeses : public Pizza
{
public:
	void info() {
		cout << "Сыр" << endl;
	};
};

class Pepperoni : public Pizza
{
public:
	void info() {
		cout << "Пепперони" << endl;
	};
};

class Tomato : public Pizza
{
public:
	void info() {
		cout << "Помидор" << endl;
	};
};

class Meat : public Pizza {
public:
	void info() {
		cout << "Мясо" << endl;
	};
};

class Chicken : public Pizza {
public:
	void info() {
		cout << "Курица" << endl;
	}
};

class Pineapples : public Pizza {
public:
	void info() {
		cout << "Ананас" << endl;
	}
};

class Mushrooms : public Pizza {
public:
	void info() {
		cout << "Грибы" << endl;
	}
};

// Фабрики объектов
class Factory
{
public:
	virtual Pizza* createPizza() = 0;
	virtual ~Factory() {}
};

class DoughFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Dough;
	};
};

class SauceFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Sauce;
	}
};

class CheesesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Cheeses;
	}
};

class PepperoniFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pepperoni;
	}
};

class TomatoFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Tomato;
	}
};

class MeatFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Meat;
	}
};

class ChickenFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Chicken;
	}
};

class PineapplesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pineapples;
	}
};

//паттерн Composite 
class CompositeBase : public Pizza {
private:
	vector<Pizza*> base;
public:
	void info() {		
		for (int i = 0; i < base.size(); i++)
			base[i]->info();
	};
	void addPizza(Pizza* p) {
		base.push_back(p);
	}
	~CompositeBase() {}
};

CompositeBase* createBase() {
	CompositeBase* base = new CompositeBase;
	base->addPizza(new Dough);
	base->addPizza(new Sauce);
	base->addPizza(new Cheeses);
	return base;
}

CompositeBase* createMeat() {
	CompositeBase* base = new CompositeBase;
	base->addPizza(new Pepperoni);
	base->addPizza(new Tomato);
	base->addPizza(new Meat);
	base->addPizza(new Chicken);
	base->addPizza(new Mushrooms);
	return base;
}