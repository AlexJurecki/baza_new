
#include "data.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
//#include <memory>
#include <cstring>

class Konsola {
public:
	Data A;

	Konsola() {}

	void akcja() {
		
		string akcje;
		cout << "Welcome to Bjarne Inc." << endl;

		for (int turn = 1; turn <= 100; turn++) {//100 ruchow, dowolna liczba

			cout << "Choose wisely: lp (listuj pojazdy) ,m (moto) ,rm (random moto), l (lorry), rl (random lorry) o (osobowy), ro (randmo osobowy),time (wiek+1),more (liczba wpisow o x>limit),sortby (sortuj po), er (wymaz pojazd), write (zapisz do pliku .bin), read(wczytaj ze pliku .bin),break (koniec)" << endl;
			cout << "Ruch numer: " << turn << endl << endl;
			cin >> akcje;
			if (akcje == "lp") {//listuj pojazdy
				A.drukuj();
				cout << endl;
			}
			if (akcje == "m") {//wstaw motocykl (random/custom)
				A.dodaj('M');
				cout << endl;
			}
			if (akcje == "rm") {//wstaw random motocykl
				A.dodaj_random('M');
				cout << endl;
			}
			if (akcje == "o") {//wstaw osobowy (random/custom)
				A.dodaj('O');
				cout << endl;
			}
			if (akcje == "ro") { //wstaw random osobowy
				A.dodaj_random('O');
				cout << endl;
			}
			if (akcje == "l") { //wstaw lorry (custom/random)
				A.dodaj('L');
				cout << endl;
			}
			if (akcje == "rl") { //wstaw random lorry
				A.dodaj_random('L');
				cout << endl;
			}
			if (akcje == "time") {//mija rok, wiek rosnie o 1
				A.timeflow();
				cout << endl;
			}

			if (akcje == "sortby") { //sortowanie po zmiennej + drukowanie
				A.sortby();
				A.drukuj();
				cout << endl;
			}

			if (akcje == "er") { //usuwanie wiersza
				cout << "Gimme a id that you would like to erase\t";
				int nr;
				cin >> nr;
				A.eraser(nr);
				cout << endl;
			}
			/*if (akcje == "max") {
				cout << "Which maximum?" << endl;
				string aux;
				cin >> aux;
				//A.maxi(Pojazd::getPower());
				cout << endl;
			}*/

			if (akcje == "more") {//sprawdz, ile pojazdow ma wiekszy rok/moc
				cout << "Which variable? Data (d)or Power(p)?\t" << endl;
				char type;
				cin >> type;
				if (type == 'p') {
					cout << endl << "Power bigger than...? Gimme double\t";
					double limit; //limit to nasz podzial, chcemy dostac wiecej niz limit
					cin >> limit;
					cout << " There are more than " << A.more(limit) << " vehciles that meet the criteria" << endl; ;
				}
				else {
					cout << endl << "Data bigger than...? Gimme int\t";
					int limit;
					cin >> limit;
					cout << " There are " << A.more(limit) << " vehicles that meet the criteria >" <<limit << endl;
				}
			}

			if (akcje == "write") { //zapiasz do pliku bin.
				A.Write();
				cout << "write" << endl;

			}
			if (akcje == "read") { //odczytaj z pliku bin
				A.Read();
				cout << "read" << endl;

			}
			if (akcje == "break") { //zakoncz

				cout << "SEEYA" << endl;
				break;
			}

		}cout << "Koniec gry!" << endl;


	}
	~Konsola() {}
private:

};