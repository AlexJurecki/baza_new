// baza.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "baza_new.h"
#include "pojazdy.hpp"
#include "randomgen.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <cstring>


class Data {
public:
	Data() { cout << "Welcome to the Data!" << endl; }
	void dodaj_random(char  type) {
		switch (type) {
		case 'M':
			Katalog.push_back(make_shared<Motocykl>());
			
			break;
		case 'O':
			Katalog.push_back(make_shared<Osobowy>());
			break;
		case 'L':
			Katalog.push_back(make_shared<LKW>());
			break;

		}
		Katalog.back()->setTyp(type);
		Katalog.back()->setId(numer);
		numer += 1;
	}
	void dodaj(char type)
	{
		//string	a="BMW";
		//string b="K1200";
		//int c=2010;
		//double d=110;
		//double e=35.5;
		//bool	f=true;
		// 
		//Vehicles.push_back(Motocykl(a, b, c, d, e, f));
		cout << "Would you like to randomize? yes/no" << endl;
		string question;
		cin >> question;
		if ((question == "yes") || (question == "y")) {
			Katalog.push_back(make_shared<Motocykl>());

		}
		else {
			string a, b;
			int c;
			double d, e;
			
			cout << endl << "Podaj marke:\t";
			cin >> a;
			cout << "Podaj model:\t";
			cin >> b;
			cout << endl << "Podaj Date produkcji:\t";
			cin >> c;
			cout << endl << "Podaj pojemnosc:\t";
			cin >> d;
			cout << endl << "Podaj moc:\t";
			cin >> e;
			
			switch (type) {
			case 'M':
				cout << endl << "Podaj bool Boxer:\t";
				bool f;
				cin >> f;
				Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
				
				break;
			case 'O':
				cout << endl << "Podaj int pasazerowie:\t";
				int ff;
				cin >> ff;
				Katalog.push_back(make_shared<Osobowy>(a, b, c, d, e, ff));
				
				break;
			case 'L':
				cout << endl << "Podaj double ladunek:\t";
				double fff;
				cin >> fff;
				Katalog.push_back(make_shared<LKW>(a, b, c, d, e, fff));
				
				break;

			}
			

			//Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
		}
		Katalog.back()->setTyp(type);
		Katalog.back()->setId(numer);
		numer += 1;
		//Vehicles.push_back(make_unique<Motocykl>(a, b, c, d, e, f));
		//Vehicles.push_back(Motocykl(a, b, c, d, e, f));
		// 
		//dum(new Motocykl(a, b, c, d, e, f));
	}

	void timeflow() {
		//for (int i = 0; i < size(Katalog);++i) {

		//	Katalog[i]++;
		//}
		//Pojazd&++(Katalog[0]);
		for (auto& it : Katalog) {

			++(*it);
			it->print();
		}
	}
	/*
	template <typename T>
	//void maxi(const T (*func)()){
	T maxi(const string& str){

		//auto it = max(Katalog.begin(), Katalog.end(), [&](shared_ptr<Pojazd>& arg1, shared_ptr<Pojazd>& arg2) {return arg1->func() > arg2->func(); });
		if (str=="power")
		auto it = max(Katalog.begin(), Katalog.end(), [](shared_ptr<Pojazd>& arg1, shared_ptr<Pojazd>& arg2) {return (arg1->getPower() > (arg2->getPower(); });
		//poj maximal_obj = Katalog[it];
		//maximal_obj.print();
		//cout <<"MAX cecha"<<  maximal_obj.t();
		cout << "ITITIT"<<it;
		return
	}*/


	void dodaj_cechy() {

		cout << "Gimme cecha" << endl;
		Katalog.back()->setCechy();
	}

	const void drukuj() {
		for (int i = 0; i < size(Katalog); ++i) {
			//Vehicles[i].print();
			cout << Katalog[i]->getId();
			cout <<" ( "<< Katalog[i]->getTyp()<<" )"<< "\t";
			Katalog[i]->print();
			//	cout << "\tCechy:";
				//list<string>::iterator it = Katalog[i]->getCechy().begin();
				//for (it; it != Katalog[i]->getCechy().end(); *it++)
				//	cout << *it <<", "<< endl;


				//dynamic_pointer_cast<Motocykl>(Katalog[i])->print();
				//dynamic_pointer_cast<Pojazd>(Katalog[i])->print();
			switch (Katalog[i]->getTyp()) {
			case 'M':

				static_pointer_cast<Motocykl>(Katalog[i])->print();
				break;
			case 'O':

				static_pointer_cast<Osobowy>(Katalog[i])->print();
				break;
			case 'L':

				static_pointer_cast<LKW>(Katalog[i])->print();
				break;

			}


			//static_pointer_cast<Motocykl>(Katalog[i])->print();
			//static_pointer_cast<Pojazd>(Katalog[i])->print();
			//static_cast<Pojazd>(Vehicles[i]).print();
			//cout << Katalog[i].getBool()<<
			//stat_cast_ptr<Motocykl>(Vehicles[i]);
			//auto derived=stat_cast_ptr<Motocykl>(Vehicles[i]);
		}
	}

	const void sortuj() {
		sort(Katalog.begin(), Katalog.end());

	}

	void sortby() {
		cout << "m - moc, i - id, d- data, w-wiek" << endl;
		string input;
		cin >> input;
		sort(Katalog.begin(), Katalog.end(), [input](shared_ptr<Pojazd>& arg1, shared_ptr<Pojazd>& arg2) {
			//////return (arg1->data < arg2->data);
			// 
			//std::cout << arg.isMonster() << std::endl;
			//if (arg.isMonster() == true) {

				//return arg1->data>arg2->data; //bullshit afterawrds


			if (input == "m" || input == "moc") {
				return (arg1->getPower() < arg2->getPower());
			}

			if (input == "d" || input == "data") {
				return (arg1->getData() < arg2->getData());
			}

			if (input == "w" || input == "wiek") {
				return (arg1->getWiek() < arg2->getWiek());
			}
			else {
				return (arg1->getId() < arg2->getId());
			}
			//}
		//	else {
			//	return 'y';
		//	}/**/
			});
		//

	}

	void eraser(const int& wanted_id) {
		//int i = 0;

		//int wanted_id = 1;
		//vector  <shared_ptr<Pojazd>>::iterator it = find(Katalog.begin(), Katalog.end(), wanted_id);
		//auto it = find(Katalog.begin(), Katalog.end(), [](shared_ptr<Pojazd>& arg) {});
		//
	//	if (it != end(Katalog)) {
		//	cout << "Element o id=" << wanted_id << " zajmuje pozycje "<< distance(Katalog.begin(), it) << endl;
		//	Katalog.erase(it);		}
	//	else {	cout << "Element is not present in the given baza danych";	}

		auto it = find_if(Katalog.begin(), Katalog.end(), [wanted_id](const shared_ptr<Pojazd>& arg) {return arg->getId() == wanted_id; });
		//cout << *it;
		Katalog.erase(it);

	}

	void Write() {
		ofstream File("baza_binar.bin", ios::out | ios::binary, ofstream::trunc);
		if (File.is_open())
		{
			int size_of_database = size(Katalog);
			File.write((char*)&size_of_database, sizeof(size_of_database));
			cout << size_of_database << endl;
			for (int i = 0; i < size(Katalog); ++i) {
				//Vehicles[i].print();
				//cout << Katalog[i]->getId() << "\t";
				//Katalog[i]->print();
				int id = Katalog[i]->getId();
				File.write((char*)&id, sizeof(id));

				size_t len = Katalog[i]->getMarka().size();
				File.write((char*)&len, sizeof(len));
				File.write((char*)&Katalog[i]->getMarka()[0], len);

				len = Katalog[i]->getModel().size();
				File.write((char*)&len, sizeof(len));
				File.write((char*)&Katalog[i]->getModel()[0], len);

				int dat = Katalog[i]->getData();
				double poj = Katalog[i]->getPojemnosc();
				double pow = Katalog[i]->getPower();

				//File.write((char*)&dat, sizeof(dat));
				//	File.write((char*)&poj, sizeof(poj));
				//	File.write((char*)&pow, sizeof(pow));
				File.write((char*)&dat, sizeof(dat));
				File.write((char*)&poj, sizeof(poj));
				File.write((char*)&pow, sizeof(pow));


				//dynamic_pointer_cast<Pojazd>(Katalog[i])->print();
				if ((Katalog[i])->getTyp() == 'M') {
					char typ = 'M';
					File.write((char*)&typ, sizeof(typ));
					bool box = static_pointer_cast<Motocykl>(Katalog[i])->getBool();
					File.write((char*)&box, sizeof(box));
				}
				else if ((Katalog[i])->getTyp()== 'O') {
					char typ = 'O';
					File.write((char*)&typ, sizeof(typ));
					int pas = static_pointer_cast<Osobowy>(Katalog[i])->getPasazerowie();
					File.write((char*)&pas, sizeof(pas));
				}
				else if ((Katalog[i])->getTyp() == 'L') {
					char typ = 'L';
					File.write((char*)&typ, sizeof(typ));
					double lad = static_pointer_cast<LKW>(Katalog[i])->getLadunek();
					File.write((char*)&lad, sizeof(lad));
				}


			}
			// No need. The file will be closed when the function returns.
			// binFile.close();
		}
	}


	void Read() {

		ifstream File("baza_binar.bin", ios::in | ios::binary);
		if (File.is_open())
		{
			int size_of_database;
			File.read((char*)&size_of_database, sizeof(size_of_database));
			cout << endl << "Size of databse " << size_of_database<<endl;
			for (int i = 0; i < size_of_database; i++) {

				int id, da; double pow, poj; char typ; string mod, mar;

				File.read((char*)&id, sizeof(id));

				size_t len = 0;
				File.read((char*)&len, sizeof(len));
				mar.resize(len);
				File.read((char*)&mar[0], len);
				//cout << mar;

				len = 0;
				File.read((char*)&len, sizeof(len));
				mod.resize(len);
				File.read((char*)&mod[0], len);

				File.read((char*)&da, sizeof(da));
				File.read((char*)&poj, sizeof(poj));
				File.read((char*)&pow, sizeof(pow));

				File.read((char*)&typ, sizeof(typ));
				if (typ == 'M') {
					bool box;
					File.read((char*)&box, sizeof(box));
					Katalog.push_back(make_shared<Motocykl>(mar, mod, da, poj, pow, box));
					//string mar, string mod, int dat, double poj, double pow, bool b
					//Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
				}
				else if (typ == 'O') {
					int pas;
					File.read((char*)&pas, sizeof(pas));
					Katalog.push_back(make_shared<Osobowy>(mar, mod, da, poj, pow, pas));
					//string mar, string mod, int dat, double poj, double pow, bool b
					//Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
				}
				else if (typ == 'L') {
					double lad;
					File.read((char*)&lad, sizeof(lad));
					Katalog.push_back(make_shared<LKW>(mar, mod, da, poj, pow, lad));
					//string mar, string mod, int dat, double poj, double pow, bool b
					//Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
				}
				Katalog.back()->setTyp(typ);
				Katalog.back()->setId(numer);
				numer += 1;



			}

		}

	}

	~Data() {}

	//friend void sortby();


private:
	//vector < unique_ptr<Pojazd>> Vehicles;
	//vector <Pojazd> Vehicles;
	unique_ptr<Pojazd>* Veh;
	unique_ptr<Pojazd> dum;
	vector  <shared_ptr<Pojazd>> Katalog;
	int numer = 1;
};
//

//
bool operator<(const Pojazd& P1, const Pojazd& P2) {
	return (P1.power < P2.power);
	/*cout << "m - moc, p - pojemnosc, d- data, w-wiek" << endl;
	string input;
	cin >> input;
	if (input == "m" || input == "moc") {

	}
	 input == "p" || input == "pojemnosc") {
		return (P1.pojemnosc < P2.pojemnosc);
	}
	if (input == "d" || input == "data") {
		return (P1.data < P2.data);
	}
	if (input == "w" || input == "wiek") {
		return (P1.wiek < P2.wiek);
	}
	else {
		return (P1.id < P2.id);
	}*/

	//	return (P1.power < P2.power);
}

/*void sortby(vector  <shared_ptr<Pojazd>> Katalog) {
		sort(Katalog.begin(), Katalog.end(),
		[](const Pojazd& a, const Pojazd& b) -> bool
		{
			return a.data < b.data;
		});
}*/


class Konsola {
public:
	//friend Firma;
	Data A;

	Konsola() {}

	void akcja() {
		int stan = 1;
		string akcje;
		cout << "Welcome to Bjarne Inc." << endl;

		for (int turn = 1; turn <= 50; turn++) {

			cout << "Choose wisely: lp,m,rm,break,cech,sortby" << endl;
			cout << "Ruch numer: " << turn << endl << endl;
			cin >> akcje;
			if (akcje == "lp") {
				A.drukuj();
				cout << endl;
			}
			if (akcje == "m") {
				A.dodaj('M');
				cout << endl;
			}
			if (akcje == "rm") {
				A.dodaj_random('M');
				cout << endl;
			}
			if (akcje == "o") {
				A.dodaj('O');
				cout << endl;
			}
			if (akcje == "ro") {
				A.dodaj_random('O');
				cout << endl;
			}
			if (akcje == "l") {
				A.dodaj('L');
				cout << endl;
			}
			if (akcje == "rl") {
				A.dodaj_random('L');
				cout << endl;
			}
			if (akcje == "time") {
				A.timeflow();
				cout << endl;
			}
			if (akcje == "sort") {
				A.sortuj();
				A.drukuj();
				cout << endl;
			}
			if (akcje == "sortby") {
				A.sortby();
				A.drukuj();
				cout << endl;
			}
			if (akcje == "cech") {
				A.dodaj_cechy();
				cout << endl;
			}
			if (akcje == "er") {
				cout << "Gimme a id that you would like to erase\t";
				int nr;
				cin >> nr;
				A.eraser(nr);
				cout << endl;
			}
			if (akcje == "max") {
				cout << "Which maximum?" << endl;
				string aux;
				cin >> aux;
				//A.maxi(Pojazd::getPower());

				cout << endl;
			}
			if (akcje == "write") {
				A.Write();
				cout << "write" << endl;

			}
			if (akcje == "read") {
				A.Read();
				cout << "read" << endl;

			}
			if (akcje == "break") {

				cout << "SEEYA" << endl;
				break;
			}

		}cout << "Koniec gry!" << endl;


	}
	~Konsola() {}
private:

};

int main()
{
	ofstream myfile;
	myfile.open("dane.txt");
	myfile << "Boo.\n";
	myfile.close();

	//Motocykl A();
	//Data D;
	//D.dodaj();
	//D.drukuj();
	// 
	// 
	// 
	//unique_ptr<Pojazd> poj(new Motocykl("M","M",1,1,1,false));
	/*
	unique_ptr<Pojazd> poj(new Motocykl("M","M", 1, 1, 1,true));
	poj->print();
	//static_cast_ptr<Pojazd>(poj)->print();
	auto derived_ptr = static_cast_ptr<Pojazd>(poj);
	derived_ptr->print();
	//poj->print();
	Pojazd* f = new Motocykl("M", "M", 1, 1, 1, true);
	f->print();
	static_cast<Pojazd*>(f)->print();
	*/
	vector <Pojazd> VVV;
	VVV.push_back(Pojazd());
	VVV.push_back(Pojazd());
	for (auto& it : VVV) {
		it.print();
		++(it);
		it.print();
	}//alternative

	/* //trial trial
	cout << "Hello CMake. POJAZD" << endl;
	Pojazd AAA;
	AAA.print();
	cout << "MOTO" << endl;
	Motocykl MMM;
	static_cast<Pojazd>(MMM).print();
	MMM.print();
	cout << "OSOBISTY "<< endl;
	Osobowy OOO;
	static_cast<Pojazd>(OOO).print();
	OOO.print();
	cout << "LORRY" << endl;
	LKW LLL;
	static_cast<Pojazd>(LLL).print();
	LLL.print();
	*/
	Konsola K;
	K.akcja();
	return 0;
}

