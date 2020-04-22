#pragma once
#include"Spectacol.h"
#include"Solist.h"

class opera : public spectacol{
	solist solist_principal;
	int pauza_fixa;
	vector <int> durata_act;

public:
	opera(int pauza=0, string nume_sp="", string g="", string nume_sol="", string tip_voce="", string data = "", int locuri = 0);
	opera(const opera& op);
	~opera() { cout << "distruge opera"; }

	void adaugare_act(int);
	void adauga_show(int dur, bool adulti = false, string animale = "");

	void citire(istream& i);
	void afisare(ostream& o, int teat = -1)const;

	string get_voce();
	string get_tip();
	vector <string> get_animale() { vector <string> f; return f; }
	bool get_interact() { return false; }

};