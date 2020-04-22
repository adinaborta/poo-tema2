#include "Circ.h"

circ::circ(string nume_sp, string data, int locuri, string g) : spectacol(nume_sp, g, data, locuri) {}


circ::circ(const circ& cir) : spectacol(cir) {
	this->nr_repr=cir.nr_repr;
	this->fol_animale = cir.fol_animale;
	this->doar_adulti = cir.doar_adulti;
}


void circ::adauga_reprezentatie(int dur, bool adulti, string animale)
{
	this->durata += dur;

	if (adulti != false) {
		this->doar_adulti = true;
	}

	animale_vii.push_back(animale);
	if (animale != "") {
		fol_animale = true;
	}

	nr_repr++;
}

void circ::citire(istream& i)
{
	int ok = 0, n = 0, dur=0;
	string animale;
	bool adulti;
	spectacol::citire(i);
	cout << "Daca doriti sa introduceti numere acum apasati tasta 1: "; i >> ok;
	if (ok == 1)
	{
		cout << "Cate numere doriti sa introduceti? "; i >> n;
		for (int j = 0; j < n; j++) {
			cout << "Durata in minute a numarului: "; i >> dur;
			cout << "Daca spectacolul foloseste animale, introduceti denumirile animalelor. Alfel, apasati 0: "; getchar(); getline(i, animale);
			cout << "Daca spectacolul este dedicat numai adultilor, apasati 1. In caz contrar, apasati 0. " ;  i >> adulti;
			if (animale == "0") {
				adauga_reprezentatie(dur, adulti);
			}
			else
				adauga_reprezentatie(dur, adulti, animale);
		}
		
	}
	
}

void circ::afisare(ostream& o, int teat) const {
	spectacol::afisare(o);
	o << "Numere artistice: " << nr_repr << endl;

	for (int i = 0; i < animale_vii.size(); i++) {
		if (animale_vii[i] != "")
			o << "Numarul " << i + 1 << " foloseste urmatoarele animale: " << animale_vii[i] << endl;
	}

}


string circ::get_tip()
{
	return "circ";
}

vector<string> circ::get_animale()
{
	return this->animale_vii;
}

void circ::adauga_show(int dur, bool adulti, string animale)
{
	this->adauga_reprezentatie(dur, adulti, animale);
}
