#include"Solist.h"

solist::solist(string nume_sol, string tip_voce)
{
	nume_solist = nume_sol;
	voce = tip_voce;

}

solist::solist(const solist& s)
{
	this->nume_solist = s.nume_solist;
	this->voce = s.voce;
}

void solist::citire(istream& i){
	cout << "Nume solist: "; getchar(); getline(i, this->nume_solist);
	cout << "Voce solist: ";  getchar();  getline(i, this->voce);
	
}

void solist::afisare(ostream& o) const
{
	o << "Nume Solist: " << nume_solist << endl;
	o << "Voce: " << voce << endl;
}

istream& operator>>(istream& i, solist& sol)
{
	sol.citire(i);
	return i;
}

ostream& operator<<(ostream& o, solist& sol)
{
	sol.afisare(o);
	return o;
}
