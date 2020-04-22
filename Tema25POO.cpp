#include"Opera.h"
#include"Spectacol.h"
#include"Circ.h"
#include"Teatru.h"
#include <fstream>
#include "Spectactor.h"
#pragma once

int main(){

	ofstream out("spectacoleout.txt");

	vector <spectacol*> spect;

	spect.push_back(new teatru(50, true, "FRUMOASA SI BESCIA", "DRAMA", "08.12.2020", 50));
	spect[0]->adaugare_data("07.03.2020", 40);
	spect[0]->adaugare_data("07.04.2020", 60);

	spect.push_back(new teatru(60, false, "FAT FRUMOS SI MERELE DE AUR", "TEATRU DE COPII", "08.12.2020", 70));
	spect[1]->adaugare_data("05.09.2020", 40);

	spect.push_back(new teatru(90, false, "SIRENA CEA MICA", "TEATRU DE COPII", "23.12.2020", 80));
	spect[2]->adaugare_data("08.10.2020", 50);

	spect.push_back(new teatru(70, true, "VANATOAREA-DE-UMBRE", "DRAMA", "11.12.2020", 60));
	spect[3]->adaugare_data("05.09.2020", 90);

	spect.push_back(new teatru(60, false, "VANATOAREA-DE-UMBRE-2", "TRAGEDIE", "11.12.2021", 80));
	spect[4]->adaugare_data("05.09.2021", 50);

	spect.push_back(new circ("VAREKAI", "04.08.2020", 270));
	spect[5]->adauga_show(30, true, "PAPAGAL"); 
	spect[5]->adauga_show(40, true, "GASCA");

	spect.push_back(new circ("CIRCUS", "06.09.2020", 170));
	spect[6]->adauga_show(40, false, "PANDA");
	spect[6]->adauga_show(50, false, "BABUIN");

	spect.push_back(new circ("LE CROIX", "06.09.2021", 300));
	spect[7]->adauga_show(30, false);
	spect[7]->adauga_show(60, false); 
	
	spect.push_back(new circ("LE CIRC", "06.10.2020", 170));
	spect[8]->adauga_show(40, true, "CARCALETE");
	spect[8]->adauga_show(50, false, "MAIMUTA");

	spect.push_back(new circ("SPIDER-MAN SI FURNICA", "06.11.2020", 170));
	spect[9]->adauga_show(20, false);
	spect[9]->adauga_show(70, false, "LEU");


	spect.push_back(new opera(10, "BEETH AND FRIENDS", "TRAGEDIE", "FUEGO", "TENOR", "05.06.2020", 200));
	spect[10]->adauga_show(30);
	spect[10]->adauga_show(60);
	spect[10]->adauga_show(50);

	spect.push_back(new opera(15, "INIMA ARSA", "DRAMA", "FLORIN SALAMANDRA", "PORTAVOCE", "06.34.2020", 300));
	spect[11]->adauga_show(50);
	spect[11]->adauga_show(30);
	spect[11]->adauga_show(40);

	spect.push_back(new opera(15, "OOP(era)", "DRAMA", "GORDON", "BARITON", "20.10.2010", 150));
	spect[12]->adauga_show(80);
	spect[12]->adauga_show(30);
	spect[12]->adauga_show(30);

	spect.push_back(new opera(15, "TERRARIAN", "TRAGEDIE", "MIGUEL CASS", "BASS", "45.34.2020", 260));
	spect[13]->adauga_show(40);
	spect[13]->adauga_show(30);
	spect[13]->adauga_show(40);

	spect.push_back(new opera(15, "DUMM", "COMEDIE", "MIGUEL CASS", "BASS", "03.64.2020", 270));
	spect[14]->adauga_show(50);
	spect[14]->adauga_show(30);
	spect[14]->adauga_show(40);


	int t = spect.size();

	/*for (int i = 0; i < spect.size(); i++) {

		cout <<"Spectacolul "<<i+1<< " : "<< spect[i]->get_tip()<<endl<< *spect[i]<<endl<<endl;
	}*/

	spectator s1("Marioara", 45);	
	s1.adauga_pofta_teatru_inter(true);
	s1.adauga_pofta_gen("COMEDIE");
	s1.adauga_exigenta_animale("CARCALETE");
	s1.alegere_spectacole(spect);


	spectator s2("Patricia", 7);
	s2.adauga_pofta_tip("circ");
	s2.alegere_spectacole(spect);

	spectator s3("Marian", 20);
	s3.adauga_exigenta_max_spect(50);
	s3.adauga_pofta_tip("teatru");
	s3.alegere_spectacole(spect);

	spectator s4("Doru", 70);
	s4.adauga_pofta_opera_voce("BASS");
	s4.adauga_pofta_opera_voce("TENOR");
	s4.alegere_spectacole(spect);

	spectator s5("Andrei", 19);
	s5.adauga_pofta_circ_animal("BABUIN");
	s5.adauga_pofta_circ_animal("LEU");
	s5.alegere_spectacole(spect);





	for (int i = 0; i < spect.size(); i++) {
		delete spect[i];
	}




	
	











	

	

	



	return 0;
}