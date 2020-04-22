#include"Teatru.h"
#pragma once

teatru::teatru(int dur, bool interact, string nume_sp, string g, string data, int locuri, int locuri_adulti): spectacol(nume_sp, g, data, locuri)
{
	durata = dur;
	interactiune = interact;
	if (interact == true) {
		this->durata_in_plus.push_back(locuri_adulti + (locuri - locuri_adulti) * 2);
	}
	else
		this-> durata_in_plus.push_back(-1);
}

teatru::teatru(teatru& ttru): spectacol(ttru)
{
	this->interactiune = ttru.interactiune;
	this->loc_adulti = ttru.loc_adulti;
	this->loc_copii = ttru.loc_copii;
}

int teatru::adaugare_data(string data, int nr_locuri, int loc_ad)
{
	int i = spectacol::adaugare_data(data, nr_locuri);
	if (this->interactiune == true) {

		int loc_tot = spectacol::get_locuri(i - 1);

		this->loc_adulti = loc_ad;
		this->loc_copii = loc_tot - loc_ad;
		this->durata_in_plus.push_back(loc_ad + loc_copii * 2);
	}
	else
		this->durata_in_plus.push_back(-1);
	return -1;
	
}

void teatru::citire(istream& i)
{
	cout << "Daca spectacolul este interactiv apasati 1. Altfel apasati 0. "; i >> interactiune;
	cout << "Durata: "; i >> durata;
	spectacol::citire(i);
}

void teatru::afisare(ostream& o, int teat) const
{
	
	if (interactiune == true) {
		spectacol::afisare(o, 1);
		o << "Acest spectacol este interactiv. " << endl ;

	}
	else
		spectacol::afisare(o);

	
}


bool teatru::get_interact()
{
	return this->interactiune;
}

string teatru::get_tip()
{
	return "teatru";
}


