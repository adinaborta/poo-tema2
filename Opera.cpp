#pragma once
#include "Opera.h"

opera::opera(int pauza, string nume_sp, string g, string nume_sol, string tip_voce, string data, int locuri) : spectacol(nume_sp, g, data, locuri),solist_principal(nume_sol, tip_voce)
{
	pauza_fixa = pauza;
}

opera::opera(const opera& op) : spectacol(op), solist_principal(op.solist_principal)
{
	this->pauza_fixa = op.pauza_fixa;
}

void opera::adaugare_act(int dur = 0) {
	if (dur != 0)
	{
		this->durata_act.push_back(dur);
		this->durata = this->durata + dur + this->pauza_fixa;
	}
	
}

void opera::adauga_show(int dur, bool adulti, string animale)
{
	this->adaugare_act(dur);
}

void opera::citire(istream& i)
{
	int ok = 0, n = 0, durata;
	spectacol::citire(i);
	this->solist_principal.citire(i);
	cout << "Pauza: "; i >> this->pauza_fixa;
	cout << "Daca doriti sa adaugati acte acum apasati 1: "; i >> ok;
	if (ok == 1) {
		cout << "Cate acte doriti sa introduceti? "; i >> n;
	}
	for (int j = 0; j < n; j++) {
		cout << "Durata actului " << j + 1 << " : "; i >> durata;
		adaugare_act(durata);
	}
}

void opera::afisare(ostream& o, int teat) const {
	spectacol::afisare(o);
	solist_principal.afisare(o);

	o << "Pauza: " << pauza_fixa << endl;
	for (int i = 0; i < durata_act.size() ; i++) {
		o << "Durata actului " << i + 1 <<" : " << durata_act[i]<<" "<<endl;
	}
}

string opera::get_voce()
{
	return this->solist_principal.get_voce();
}

string opera::get_tip()
{
	return "opera";
}



