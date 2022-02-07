#include "baza_new.h"
#include "pojazdy.hpp"
#include "randomgen.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
//#include <memory>
#include <cstring>


class Data {
public:

	Data() { cout << "Welcome to the Data!" << endl; }//domyslny



	void dodaj_random(char  type) { //funkcja dodaje pojazd o randomwych param
		switch (type) { // rodzaj zalezy od typu
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
		Katalog.back()->setTyp(type);//kwestia ulatiwajaca wizualizacje i pozniejszy odczyt z pliku
		Katalog.back()->setId(numer);//numerator ID
		numer += 1;
	}




	template<typename tname>
	void getcin(tname& arg) {//dosc prosty template, wykonuje cin dla roznych typow
			cin >> arg;
				}



	void dodaj(char type)
	{

		cout << "Would you like to randomize? yes/no" << endl;
		string question;
		//cin >> question;
		getcin(question);
		if ((question == "yes") || (question == "y")) { //randomizownie param jest mozliwe rowniez na tym etapie
			switch (type) {
			case 'M': Katalog.push_back(make_shared<Motocykl>()); //pushback - dodwanie klasy dziedziczacej po poejdzie jako ostatni element wektora
				break;

			case 'O': Katalog.push_back(make_shared<Osobowy>());
				break;

			case 'L': Katalog.push_back(make_shared<LKW>());
				break;
			}
		}
		else { //customow wpisywane dane do parametrow pojazdow
			string a, b;
			int c;
			double d, e;

			cout << endl << "Podaj marke:\t";
			cin >> a;
			cout << "Podaj model:\t";
			cin >> b;
			cout << endl << "Podaj Date produkcji:\t";
			cin >> c;
			try { //exception - rok nie moze byc zbyt maly, wiemy kiedy powstal pierwszy automobile
				if (c < 1886) {
					throw c;
				}
			}
			catch (int ex) {
				cout << "Exception - the first car  " << endl << " the Benz Patent-Motorwagen was built in 1886" << endl;
				c = 1886;
			}


			cout << endl << "Podaj pojemnosc:\t";

			cin >> d;
			try { //exception -  pojemnosc nie moze byc niedodatnia
				if (d <= 0) {
					throw d;
				}
			}
			catch (double ex) {
				cout << "Exception - pojemnosc is not  " << d << " you're wrong!" << endl;
				d = 100;
			}
			cout << endl << "Podaj moc:\t";

			cin >> e;
			try {//exception-  moc nie moze byc niedodatnia
				if (e <= 0) {
					throw e;
				}
			}
			catch (double ex) {
				cout << "Exception - power is not  " << e << " you're wrong!" << endl;
				e = 50;
			}
			switch (type) { //czesc parametrow nalezy do dziedziczacych klas, ponizej wpisywane sa ich param zaleznie od zadanego typu
			case 'M':
				cout << endl << "Podaj bool Boxer:\t"; //motocykl ma atrybut bool
				bool f;
				getcin(f);
				//	cin >> f;
				Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));

				break;
			case 'O':
				cout << endl << "Podaj int pasazerowie:\t";//osobowy ma atrybut int
				int ff;
				getcin(ff);
				Katalog.push_back(make_shared<Osobowy>(a, b, c, d, e, ff));

				break;
			case 'L':
				cout << endl << "Podaj double ladunek:\t";//LKW ma atrybut  double
				double fff;
				getcin(fff);
				Katalog.push_back(make_shared<LKW>(a, b, c, d, e, fff));

				break;

			}

		}
		Katalog.back()->setTyp(type); //kwestia ulatiwajaca wizualizacje i pozniejszy odczyt z pliku
		Katalog.back()->setId(numer);//numerator dla nadawnia ID z sensem
		numer += 1;
	}



	void timeflow() { //funkcja wplywajaca na atrybut wiek - zwieksza go o jeden

		for (auto& it : Katalog) {

			++(*it);
			it->print();
		}
	}


	/*
	template <typename T> //to sie akurat nie udalo
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



	template <typename T>
	T more(T x) { //template pozwala na porownanie mocy lub daty, zalezne od wyboru zastosujemy int lub double
		
		auto it = count_if(
				Katalog.begin(),
				Katalog.end(),
				[x](shared_ptr<Pojazd>& arg) {if (is_same<T, double>::value) return (arg->getPower() > x); else if (is_same<T, int>::value) return (arg->getData()>x); });
				return it; //zliczamy liczbe pojazdow, ktore posiadaja parametr wiekszy od zadanej wartosci
			
	}



	const void drukuj() {//funkcja drukujaca
		for (int i = 0; i < size(Katalog); ++i) {
			cout << Katalog[i]->getId();
			cout <<" ( "<< Katalog[i]->getTyp()<<" )"<< "\t";
			Katalog[i]->print(); //korzystamy z metody print wewnatrz klas

			switch (Katalog[i]->getTyp()) { //zaleznie od getTyp - motocykl/LKW/osobowy
			case 'M':

				static_pointer_cast<Motocykl>(Katalog[i])->print(); //static_ptr_cast do dostania sie do atrybutow nienalezacych bezposrednio do pojazdu
				break;
			case 'O':

				static_pointer_cast<Osobowy>(Katalog[i])->print();
				break;
			case 'L':

				static_pointer_cast<LKW>(Katalog[i])->print();
				break;

			}
		}
	}



	const void sortuj() {
		//sort(Katalog.begin(), Katalog.end());
		sort(Katalog.begin(), Katalog.end());
	}



	void sortby() {
		cout << "m - moc, i - id, d- data, w-wiek" << endl;
		string input;
		cin >> input;
		sort(Katalog.begin(), Katalog.end(), [input](shared_ptr<Pojazd>& arg1, shared_ptr<Pojazd>& arg2) {//sortujemy po wybranej wartosci


			//dosc skomplikowane lambda, zwracajaca sort wymaganych wartosci przez odczyt z konsoli
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

			});
	}



	void eraser(const int& wanted_id) {

		auto it = find_if(Katalog.begin(), Katalog.end(), [wanted_id](const shared_ptr<Pojazd>& arg) {return arg->getId() == wanted_id; });

		//usuwanie danego pojazdu z listy, wzywane sa dwa destruktory
		
		Katalog.erase(it);
	}



	void Write() { //zapis do pliku
		ofstream File("baza_binar.bin", ios::out | ios::binary, ofstream::trunc); //otwieranie pliku, usuwnanie z niego poprzednich danych
		if (File.is_open())
		{
			int size_of_database = size(Katalog); //rozmiar listy w VS
			File.write((char*)&size_of_database, sizeof(size_of_database));
			cout << size_of_database << endl;
			for (int i = 0; i < size(Katalog); ++i) { //petla po liczbie pojazdow
	
				int id = Katalog[i]->getId();
				File.write((char*)&id, sizeof(id)); //zapis id (de facto juz zbedne)

				size_t len = Katalog[i]->getMarka().size(); //zapis stringow
				File.write((char*)&len, sizeof(len));
				File.write((char*)&Katalog[i]->getMarka()[0], len);

				len = Katalog[i]->getModel().size();
				File.write((char*)&len, sizeof(len));
				File.write((char*)&Katalog[i]->getModel()[0], len);

				int dat = Katalog[i]->getData(); //zapis int/double
				double poj = Katalog[i]->getPojemnosc();
				double pow = Katalog[i]->getPower();


				File.write((char*)&dat, sizeof(dat));
				File.write((char*)&poj, sizeof(poj));
				File.write((char*)&pow, sizeof(pow));


				if ((Katalog[i])->getTyp() == 'M') {//zaleznie od Typu, zapis odpowiedniej wartosci : bool/int/double
					char typ = 'M';
					File.write((char*)&typ, sizeof(typ));
					bool box = static_pointer_cast<Motocykl>(Katalog[i])->getBool();
					File.write((char*)&box, sizeof(box));
				}
				else if ((Katalog[i])->getTyp()== 'O') {//zaleznie od Typu, zapis odpowiedniej wartosci : bool/int/double
					char typ = 'O';
					File.write((char*)&typ, sizeof(typ));
					int pas = static_pointer_cast<Osobowy>(Katalog[i])->getPasazerowie();
					File.write((char*)&pas, sizeof(pas));
				}
				else if ((Katalog[i])->getTyp() == 'L') {//zaleznie od Typu, zapis odpowiedniej wartosci : bool/int/double
					char typ = 'L';
					File.write((char*)&typ, sizeof(typ));
					double lad = static_pointer_cast<LKW>(Katalog[i])->getLadunek();
					File.write((char*)&lad, sizeof(lad));
				}
			}
		}
	}




	void Read() {//odczyt z pliku binarnego

		ifstream File("baza_binar.bin", ios::in | ios::binary); //otwieramy plik
		if (File.is_open())
		{
			int size_of_database; //zczytujemy rozmiar databse w pliku
			File.read((char*)&size_of_database, sizeof(size_of_database));
			cout << endl << "Size of databse " << size_of_database<<endl;
			for (int i = 0; i < size_of_database; i++) { //petla - zczytywawnie wszystkich pojazdow

				int id, da; double pow, poj; char typ; string mod, mar;

				File.read((char*)&id, sizeof(id));

				size_t len = 0;
				File.read((char*)&len, sizeof(len)); //w ten sposob zczytujemy string
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

				File.read((char*)&typ, sizeof(typ)); //determinacja jakiego typu jest pojazd w pliku
				if (typ == 'M') {
					bool box; //zaleznie od typu -> rozne atrybuty (bool, int, double)
					File.read((char*)&box, sizeof(box));
					Katalog.push_back(make_shared<Motocykl>(mar, mod, da, poj, pow, box));

				}
				else if (typ == 'O') {
					int pas;//zaleznie od typu -> rozne atrybuty (bool, int, double)
					File.read((char*)&pas, sizeof(pas));
					Katalog.push_back(make_shared<Osobowy>(mar, mod, da, poj, pow, pas));

				}
				else if (typ == 'L') {
					double lad;//zaleznie od typu -> rozne atrybuty (bool, int, double)
					File.read((char*)&lad, sizeof(lad));
					Katalog.push_back(make_shared<LKW>(mar, mod, da, poj, pow, lad));

				}
				Katalog.back()->setTyp(typ); 
				Katalog.back()->setId(numer); //nadanie nowych id
				numer += 1;
			}
		}
	}


	~Data() {} //destruktor


private:

	vector  <shared_ptr<Pojazd>> Katalog; //glowny wektor do trzymania pojazdow
	int numer = 1; //pomocniczy numerator do nadawnia ID
};










class Konsola {
public:
	Data A;

	Konsola() {}

	void akcja() {
		//int stan = 1;
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
			if (akcje == "sort") {
				A.sortuj();
				A.drukuj();
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
			if (akcje == "max") {
				cout << "Which maximum?" << endl;
				string aux;
				cin >> aux;
				//A.maxi(Pojazd::getPower());
				cout << endl;
			}

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
					cout << " There are more than " << A.more(limit) << " vehciles that meet the criteria" << endl;
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

int main()
{


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

