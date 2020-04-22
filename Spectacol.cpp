#pragma once
#include"Spectacol.h"
using namespace std;

spectacol::spectacol(string nume_sp, string g, string data, int locuri) {

	nume_spectacol = nume_sp;
	gen = g;

	pair<string, int> dataloc;
	dataloc = make_pair(data, locuri);
	this->data_loc.push_back(dataloc);
}

spectacol::spectacol(const spectacol& spec)
{
	this->durata = spec.durata;
	this->nume_spectacol = spec.nume_spectacol;
	this->gen = spec.gen;
	this->data_loc = spec.data_loc;
}

int spectacol::adaugare_data(string data, int nr_locuri, int adul) {
	pair<string, int> spect;
		spect = make_pair(data, nr_locuri);
		if (data_loc.size() == 1 && data_loc[0].first=="" && data_loc[0].second==0) {
			data_loc[0] = spect;
		}
		else
			data_loc.push_back(spect);

	return data_loc.size();
}



int spectacol::get_locuri(int i)
{
	return this->data_loc[i].second;
}


string spectacol::get_gen()
{
	return this->gen;
}

int spectacol::get_durata()
{
	return this->durata;
}

bool spectacol::get_doar_adulti()
{
	return this->doar_adulti;
}

void spectacol::citire(istream& i)
{
	int ok=0, n=0;
	cout << "Nume spectacol: "; getchar(); getline( i, this->nume_spectacol );
	if (this->get_tip() != "circ") {
		cout << "Gen: "; getchar(); getline(i , this->gen);
	}
	
	cout << "Daca doriti sa adaugati date acum apasati 1: ";  i >> ok;
	if (ok == 1)
	{
		cout << "Cate date doriti sa adaugati? "; i >> n;
	}
	int nr_locuri, loc_ad=-1;
	string data;
	for (int j = 0; j < n; j++) {
			cout << "Data " << j + 1 << " :"; getchar(); getline(i, data);
			cout << "Numar de locuri " << j + 1 << " :"; i >> nr_locuri;


		if (this->adaugare_data() == -1)
		{
			cout << "Cate locuri destinate adultilor exista? "; i >> loc_ad;
		}
		this->adaugare_data(data, nr_locuri, loc_ad);
	}
}

void spectacol::afisare(ostream& o, int teat) const
{
	if (teat==-1)
		o << "Durata: " << this->durata << " minute"<< endl;
	o << "Nume: " << this->nume_spectacol << endl;
	o << "Gen: " << this->gen << endl;
	

	if (this->doar_adulti == false) {
		o << "Spectacolul este destinat copiilor si adultilor." << endl;
	}
	else
		o << "Spectacolul este destinat numai adultilor." << endl;
	

	for (int i = 0; i < data_loc.size(); i++) {
		o << "Data " << i + 1 << " :" << data_loc[i].first << endl;
		o << "Numar de locuri: " << data_loc[i].second << endl;
		if (teat!=-1) {
			o << "Durata: " << get_durata_plus(i) << " minute" << endl;;
		}
	}

}

void spectacol::sterge_data(int k)
{
	for (int i = k; i < this->data_loc.size()-1; i++) {
		this->data_loc[i] = this->data_loc[i + 1];
	}
	data_loc.pop_back();
}

istream& operator>>(istream& i, spectacol& sp)
{
	sp.citire(i);
	return i;
}
ostream& operator <<(ostream& o, const spectacol& sp)
{
	sp.afisare(o);
	return o;
}
