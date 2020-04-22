#include"Spectactor.h"

void spectator::adauga_pofte()
{
	int nr_pofte;
	cout << "Cate pofte doriti sa adaugati? "; cin >> nr_pofte; cout << endl;
	cout << "0-gen; 1-tip; 2-durata minima 3-animal specific 4-interactiv 5-voce" << endl;
	for (int i = 0; i < nr_pofte; i++) {
		int tip_pofta;
		cout << "Tip pofta: "; cin >> tip_pofta;
		
		if (tip_pofta == 0) {
			string pofta;
			cout << endl << "Pofta: "; cin >> pofta;
			adauga_pofta_gen(pofta);
		}
		else if (tip_pofta == 1) {
			string pofta;
			cout<< endl << "Pofta: "; cin >> pofta;
			adauga_pofta_tip(pofta);
		}
		else if (tip_pofta == 2) {
			int pofta;
			cout << endl << "Pofta: "; cin >> pofta;
			adauga_pofta_dur_min(pofta);
		}
		else if (tip_pofta == 3) {
			string pofta;
			cout << endl << "Pofta: "; cin >> pofta;
			adauga_pofta_circ_animal(pofta);
		}
		else if (tip_pofta == 4) {
			bool pofta;
			cout << endl << "Daca doriti un spectacol interactiv apasati 1. Altfel, apasati 0 "; cin >> pofta;
			adauga_pofta_teatru_inter(pofta);
		}
		else if (tip_pofta == 5) {
			string pofta;
			cout << endl << "Pofta: "; cin >> pofta;
			adauga_pofta_opera_voce(pofta);
		}
	}
}

void spectator::adauga_pofta_gen(string gen)
{
	this->p_gen.push_back(gen);
}

void spectator::adauga_pofta_tip(string tip)
{
	this->p_tip.push_back(tip);
}

void spectator::adauga_pofta_dur_min(int dur)
{
	this->p_dur_min.push_back(dur);
}

void spectator::adauga_pofta_circ_animal(string animal)
{
	this->p_circ_animal.push_back(animal);
}

void spectator::adauga_pofta_teatru_inter(bool inter)
{
	if (this->p_teatru_inter.size() < 2)
	{
		this->p_teatru_inter.push_back(inter);
	}
}

void spectator::adauga_pofta_opera_voce(string voce)
{
	this->p_opera_voce.push_back(voce);
}

void spectator::adauga_exigente()
{
	int nr_ex;
	cout << "Cate exigente doriti sa adaugati? "; cin >> nr_ex; cout << endl;
	cout << "0-gen+tip; 1-durata maxima; 2-animal specific 4-nr max spectatori" << endl;
	for (int i = 0; i < nr_ex; i++) {
		int tip_exigenta;
		cout << "Tip Exigenta: "; cin >> tip_exigenta;

		if (tip_exigenta == 0) {
			string gen, tip;
			cout << endl << "Gen: "; cin >> gen;
			cout << endl << "Tip: "; cin >> tip;
			adauga_exigenta_gen_tip(gen, tip);
		}
		else if (tip_exigenta == 1) {
			int exigenta;
			cout << endl << "Exigenta: "; cin >> exigenta;
			adauga_exigenta_dur_max(exigenta);
		}
		else if (tip_exigenta == 2) {
			string exigenta;
			cout << endl << "Exigenta: "; cin >> exigenta;
			adauga_exigenta_animale(exigenta);
		}
		else if (tip_exigenta == 3) {
			int exigenta;
			cout << endl << "Exigenta: "; cin >> exigenta;
			adauga_exigenta_max_spect(exigenta);
		}

	}
}

void spectator::adauga_exigenta_gen_tip(string gen, string tip)
{
	pair<string, string> comb;
	comb= make_pair(gen, tip);
	this->e_gen_tip.push_back(comb);
}

void spectator::adauga_exigenta_dur_max(int dur)
{
	this->e_dur_max.push_back(dur);
}

void spectator::adauga_exigenta_animale(string animal)
{
	this->e_animale.push_back(animal);
}

void spectator::adauga_exigenta_max_spect(int nr_spect)
{
	if (nr_spect > this->e_max_spect) {
		this->e_max_spect = nr_spect;
	}
}






vector<spectacol*>& spectator::alegere_spectacole(vector <spectacol*>& spect)
{
	vector <spectacol*> spect_app;

	for (int i = 0; i < spect.size(); i++) {
		int okp = 0, oke = 1;

		if ((spect[i]->get_doar_adulti() == false) || (spect[i]->get_doar_adulti() == true && this->varsta > 16))
		{
			for (int j = 0; j < p_gen.size(); j++) {
				if (spect[i]->get_gen() == p_gen[j]) {
					okp = 1;
					break;
				}
			}
			if (okp == 0) {
				for (int j = 0; j < p_tip.size(); j++) {
					if (spect[i]->get_tip() == p_tip[j]) {
						okp = 1;
						break;
					}
				}
			}
			if (okp == 0) {
				for (int j = 0; j < p_dur_min.size(); j++) {
					if (spect[i]->get_durata() >= p_dur_min[j]) {
						okp = 1;
						break;
					}
				}
			}
			if (okp == 0 && spect[i]->get_tip() == "circ") {
				for (int j = 0; j < p_circ_animal.size(); j++) {
					for (int k = 0; k < (spect[i]->get_animale()).size(); k++) {
						if ((spect[i]->get_animale())[k] == p_circ_animal[j]) {
							okp = 1;
							break;
						}
					}
				}
			}
			if (okp == 0 && spect[i]->get_tip() == "teatru") {
				for (int j = 0; j < p_teatru_inter.size(); j++) {
					if (spect[i]->get_interact() == p_teatru_inter[j]) {
						okp = 1;
						break;
					}
				}
			}
			if (okp == 0 && spect[i]->get_tip() == "opera") {
				for (int j = 0; j < p_opera_voce.size(); j++) {
					if (spect[i]->get_voce() == p_opera_voce[j]) {
						okp = 1;
						break;
					}
				}
			}

			for (int j = 0; j < e_gen_tip.size(); j++) {
				if (e_gen_tip[j].first == spect[i]->get_gen() && e_gen_tip[j].second == spect[i]->get_tip()) {
					oke = 0;
					break;
				}
			}
			if (oke == 1) {
				for (int j = 0; j < e_dur_max.size(); j++) {
					if (e_dur_max[j] < spect[i]->get_durata()) {
						oke = 0;
						break;
					}
				}
			}
			if (oke == 1 && spect[i]->get_tip() == "circ") {
				for (int j = 0; j < e_animale.size(); j++) {
					for (int k = 0; k < (spect[i]->get_animale()).size(); k++)
						if (e_animale[j] == (spect[i]->get_animale())[k]) {
							oke = 0;
							break;
						}
				}
			}
			int n = spect[i]->spectacol::get_nr_date();
			if (oke == 1) {


				for (int k = 0; k < n; k++)
					if (e_max_spect < spect[i]->get_locuri(k) && e_max_spect != -1) {
						oke++;
					}

			}

			if (okp == 1 && oke < n + 1 && oke != 0) {
				spect_app.push_back(spect[i]);
				for (int k = 0; k < n; k++)
					if (e_max_spect < spect_app[spect_app.size() - 1]->get_locuri(k) && e_max_spect != -1) {
						spect_app[spect_app.size() - 1]->sterge_data(k);
						n--;
					}
			}


		}
	}

	if (spect_app.size() == 0) {
		cout << "Niciun spectacol care sa indeplineasca cerintele nu este disponibil."<<endl;
	}
	else {

		cout << "Spectacole potrivite pentru " << this->nume << endl << endl;
		for (int j = 0; j < spect_app.size(); j++) {
			cout << "Spectacolul " << j + 1 << " : " << spect_app[j]->get_tip() << endl << *spect_app[j] << endl << endl;
		}
	}

	return spect_app;
	
}
