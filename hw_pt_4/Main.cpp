#include <iostream>
#include <vector>
#include "Pizza.h"

using namespace std;

int  main() {
	setlocale(LC_ALL, "rus");
	DoughFactory* dough_factory = new DoughFactory;
	SauceFactory* sause_factory = new SauceFactory;
	CheesesFactory* cheeses_factory = new CheesesFactory;
	PepperoniFactory* pepperoni_factory = new PepperoniFactory;
	TomatoFactory* tomato_factory = new TomatoFactory;
	MeatFactory* meat_factory = new MeatFactory;
	ChickenFactory* chicken_factory = new ChickenFactory;
	PineapplesFactory* pineapples_factory = new PineapplesFactory;

	vector<Pizza*> village_pizza;
	village_pizza.push_back(dough_factory->createPizza());
	village_pizza.push_back(sause_factory->createPizza());
	village_pizza.push_back(meat_factory->createPizza());
	village_pizza.push_back(cheeses_factory->createPizza());
	village_pizza.push_back(pepperoni_factory->createPizza());
	village_pizza.push_back(tomato_factory->createPizza());
	village_pizza.push_back(chicken_factory->createPizza());

	vector<Pizza*> margo_pizza;
	margo_pizza.push_back(dough_factory->createPizza());
	margo_pizza.push_back(sause_factory->createPizza());
	margo_pizza.push_back(cheeses_factory->createPizza());
	margo_pizza.push_back(tomato_factory->createPizza());

	vector<Pizza*> peppi_pizza;
	peppi_pizza.push_back(dough_factory->createPizza());
	peppi_pizza.push_back(sause_factory->createPizza());
	peppi_pizza.push_back(cheeses_factory->createPizza());
	peppi_pizza.push_back(pepperoni_factory->createPizza());

	vector<Pizza*> hawaiian_pizza;
	hawaiian_pizza.push_back(dough_factory->createPizza());
	hawaiian_pizza.push_back(sause_factory->createPizza());
	hawaiian_pizza.push_back(cheeses_factory->createPizza());
	hawaiian_pizza.push_back(chicken_factory->createPizza());
	hawaiian_pizza.push_back(pineapples_factory->createPizza());

	vector<Pizza*> mushroom_pizza;
	mushroom_pizza.push_back(createBase());
	mushroom_pizza.push_back(new Mushrooms);

	vector<Pizza*> meat_pizza;
	meat_pizza.push_back(createBase());
	meat_pizza.push_back(createMeat());

	cout << "������ ����! �� ���� ������ ��� � ����� ��������!\n ����� ����� �� �������������?\n";
	while (true) {

		cout << "1. �����������;\n2. ���������;\n3. ���������;\n4. ���������.\n5. �������.\n6. ������.\n7. �������, �� � �� ���� �����.\n";
		int pos = 0;
		cin >> pos;
		Cheque* pCheque = Cheque::GetInstance();
		switch (pos) {
		case 1: {
			cout << "�������� �����!!!\n������ ����������� �����:\n";
			for (int i = 0; i < village_pizza.size(); i++)
				village_pizza[i]->info();

			pCheque->PutCheque("����������� ");
			break;
		}
		case 2: {
			cout << "�������� �����!!!\n������ ����� ���������:\n";
			for (int i = 0; i < margo_pizza.size(); i++)
				margo_pizza[i]->info();

			pCheque->PutCheque("��������� ");
			break;
		}
		case 3: {
			cout << "�������� �����!!!\n������ ����� ���������:\n";
			for (int i = 0; i < peppi_pizza.size(); i++)
				peppi_pizza[i]->info();

			pCheque->PutCheque("��������� ");
			break;
		}
		case 4: {
			cout << "�������� �����!!!\n������ ��������� �����:\n";
			for (int i = 0; i < hawaiian_pizza.size(); i++)
				hawaiian_pizza[i]->info();

			pCheque->PutCheque("��������� ");
			break;
		}
		case 5: {
			cout << "�������� �����!!!\n������ ������� �����:\n";
			for (int i = 0; i < mushroom_pizza.size(); i++)
				mushroom_pizza[i]->info();

			pCheque->PutCheque("������� ");
			break;
		}

		case 6: {
			cout << "�������� �����!!!\n������ ������ �����:\n";
			for (int i = 0; i < meat_pizza.size(); i++)
				meat_pizza[i]->info();

			pCheque->PutCheque("������ ");
			break;
		}

		case 7: {
			cout << "�� ��������!";
			return 0; 
		}

		default: {
			cout << "� ���������, ����� ����� � ��� ���. �������� �����.";
			continue;
		}
		}
	}
}


