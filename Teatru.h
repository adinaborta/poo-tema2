#pragma once
#include "Spectacol.h"

class teatru : public spectacol
{
	bool interactiune;
	int loc_adulti=0;
	int loc_copii = 0;
	vector <int> durata_in_plus;

public:
	teatru(int dur=0, bool interact=false, string nume_sp = "", string g = "", string data = "", int locuri = 0, int locuri_adulti=0);
	teatru(teatru& ttru);
	~teatru() { cout << "distruge teatru"; }

	int adaugare_data(string data="", int nr_locuri=0, int loc_ad=-1);


	void citire(istream& i);
	void afisare(ostream& o, int teat = -1)const;

	void adauga_show(int dur, bool adulti = false, string animale = "") {}


	bool get_interact();
	vector <string> get_animale() { vector <string> f; return f; }
	string get_voce() { return ""; }
	string get_tip();
	int get_durata_plus(int k)const { return this->durata_in_plus[k]; }
};


