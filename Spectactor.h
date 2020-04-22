#pragma once
#include"Opera.h"
#include"Circ.h"
#include"Teatru.h"

class spectator {
	string nume;
	int varsta;

	vector <string> p_gen;
	vector <string> p_tip;
	vector <int> p_dur_min;
	vector <string> p_circ_animal;
	vector <bool> p_teatru_inter;
	vector <string> p_opera_voce;

	vector <pair<string, string>> e_gen_tip;
	vector <int> e_dur_max;
	vector <string> e_animale;
	int e_max_spect=-1;

public:
	spectator(string n = "", int v = 0) { this->nume = n; this->varsta = v; };
	~spectator() { cout << "distruge spectactor";}

	void adauga_pofte();
	void adauga_pofta_gen(string);
	void adauga_pofta_tip(string);
	void adauga_pofta_dur_min(int); 
	void adauga_pofta_circ_animal(string);
	void adauga_pofta_teatru_inter(bool);
	void adauga_pofta_opera_voce(string);

	void adauga_exigente();
	void adauga_exigenta_gen_tip(string, string);
	void adauga_exigenta_dur_max(int);
	void adauga_exigenta_animale(string);
	void adauga_exigenta_max_spect(int);
	

	vector<spectacol*>& alegere_spectacole(vector <spectacol*>& spect);

	


};