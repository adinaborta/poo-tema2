#pragma once
#include"Spectacol.h"

class circ : public spectacol {
	vector <string> animale_vii;
	bool fol_animale = false;
	int nr_repr=0;
	
public:
	circ(string nume_sp = "", string data = "", int locuri = 0, string g = "COMEDIE");
	circ(const circ& cir);
	~circ() { cout << "distruge circ"; }

	void adauga_reprezentatie (int dur, bool adulti=false, string animale="");

	void citire(istream& i);
	void afisare(ostream& o, int teat = -1)const;

	string get_tip();
	vector <string> get_animale();
	bool get_interact() { return false; }
	string get_voce() { return ""; }
	void adauga_show(int dur, bool adulti = false, string animale = "");
};
