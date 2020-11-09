#include <iostream>
#include <time.h>
#include <cstring>
#include <string>
#include <locale.h>
#include <Windows.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;
class People {
public:
	virtual void printPeople() = 0;
	virtual void setPeople() = 0;
};


class Player : public People {
protected:
	string name; // имя
	int startpos; // стартовая позиция

public:

	Player() {
		name = "-";
		this->startpos = 0;
	}

	Player(int Startpos) {
		this->startpos = Startpos;
	}
	void setPeople() {
		bool a = true;
		int i, t;
		string temp;
		cout << "Класс: Player " << endl;
		cout << "Введите имя: " << endl;

		getline(cin, name);


		do
		{
			cout << "Введите стартовую позицию: " << endl;

			getline(cin, temp);
			t = 0;
			for (i = 0; i < temp.length(); i++) {
				if ((int)temp[i]< (int) '0' || (int)temp[i] > (int)'9') {
					cout << "Ошибка!" << endl;
					a = true;
					break;
				}
				else {
					t++;
					a = false;
				}
			}
			if (a == false && t == temp.length()) { startpos = atoi(temp.c_str()); }
			else {
				a = true;
			}
		} while (a);
	}



	~Player()
	{

	}

	void printPeople() {
		cout << "Класс: Player " << endl;
		cout << "Имя: " << name << endl;
		cout << "Стартовая позиция: " << startpos << endl;
	}

};

class reservePlayer : public Player {
protected:
	string teamName;
	int timeonbench; // время на скамейке

public:

	reservePlayer() {
		this->timeonbench = 0;
	}

	reservePlayer(int Timeonbench) {
		this->timeonbench = Timeonbench;
	}
	void setPeople() {
		int t,i;
		bool a = true;
		string temp;

		cout << "Класс: reservePlayer " << endl;
		cout << "Введите название команды" << endl;
		getline(cin, teamName);	
		do
		{
			cout << "Введите время на скамейке(минут): " << endl;

			getline(cin, temp);
			t = 0;
			for (i = 0; i < temp.length(); i++) {
				if ((int)temp[i]< (int) '0' || (int)temp[i] > (int)'9') {
					cout << "Ошибка!" << endl;
					a = true;
					break;
				}
				else {
					t++;
					a = false;
				}
			}
			if (a == false && t == temp.length()) { timeonbench = atoi(temp.c_str()); }
			else {
				a = true;
			}
		} while (a);
	}


	~reservePlayer()
	{

	}

	void printPeople() {
		cout << "Класс: reservePlayer " << endl;
		cout << "Название команды: " << teamName << endl;
		cout << "Время на скамейке(минут): " << timeonbench << endl;
	}

};


class Judge : public People { // судья
protected:
	string nameJudge;
	string shapecolor; // цвет формы

public:

	Judge() {
		this->shapecolor = "-";
	}

	Judge(string shapecolor) {
		this->shapecolor = shapecolor;
	}
	void setPeople() {
		cout << "Класс: Judge " << endl;
		cout << "Введите имя судьи:" << endl;
		getline(cin, nameJudge);
		cout << "Введите цвет формы:" << endl;
		getline(cin, shapecolor);

	}


	~Judge()
	{

	}

	void printPeople() {
		cout << "Класс: Judge " << endl;
		cout << "Имя судьи: " << nameJudge << endl;
		cout << "Цвет формы: " << shapecolor << endl;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	int i;
	Player pl1;
	reservePlayer rpl1;
	Judge j1;
	pl1.setPeople();

	rpl1.setPeople();
	j1.setPeople();

	People** peop = new People * [3];
	peop[0] = &pl1;
	peop[1] = &rpl1;
	peop[2] = &j1;
	for (i = 0; i < 3; i++) {
		peop[i]->printPeople();
	}

	return 0;
}