#pragma once
#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;


class spectacol {
	string nume_spectacol;
	string gen;
	vector<pair<string, int>> data_loc;

protected:
	bool doar_adulti=false;
	int durata=0;
	

public:
	
	spectacol(string nume_sp = "", string g = "", string data="", int locuri=0);
	spectacol(const spectacol& spec);
	virtual ~spectacol() { cout << "obiect distrus"; }
	
	virtual int adaugare_data(string data="", int nr_locuri=0, int adul=-1);
	int get_locuri(int i=0); //i=data spctacolului dorit
	string get_gen();
	int get_durata();
	bool get_doar_adulti();
	virtual string get_tip() = 0;
	virtual vector<string> get_animale() = 0;
	virtual bool get_interact() = 0;
	virtual string get_voce() = 0;

	friend istream& operator >>(istream& i, spectacol& sp);
	friend ostream& operator <<(ostream& o, const spectacol& sp);
	virtual void citire(istream& i);
	virtual void afisare(ostream& o, int teat=-1)const;
	
	void sterge_data(int k);
	virtual void adauga_show(int dur, bool adulti = false, string animale = "")=0;
	virtual int get_durata_plus(int k)const { return -1; }
	int get_nr_date() { return data_loc.size(); }
	

};