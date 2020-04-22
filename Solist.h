#pragma once
#include <iostream>
#include <string>
using namespace std;
class solist {
	string nume_solist;
	string voce;

public:
	solist(){}
	solist(string nume_sol="", string tip_voce="");
	solist(const solist& s);
	~solist() { cout << "distruge solist";}

	virtual void citire(istream& i);
	virtual void afisare(ostream& o) const ;
	friend istream& operator>>(istream& i, solist& sol);
	friend ostream& operator<<(ostream& o, solist& sol);

	string get_voce() {
		return this->voce;
	}
};