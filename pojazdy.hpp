

#include "baza_new.h"
#include "randomgen.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>



using namespace std;

/*
template<typename D, typename B>
unique_ptr<D> static_cast_ptr(unique_ptr<B>& base) {
	return unique_ptr<D>(static_cast<D*>(base.release()));
}
template<typename D, typename B>
unique_ptr<D> static_cast_ptr(unique_ptr<B>&& base) {
	return unique_ptr<D>(static_cast<D*>(base.release()));
}*/

class Pojazd {
public:
	Pojazd() : marka(Random_MarkaG()), model(Random_ModelG()), data(Random_Data()), pojemnosc(Random_Poj()), power(Random_Power()) { } //konstruktor domyslny, wykorzystuje randomizowane param
	Pojazd(string mar, string mod, int dat, double poj, double pow) :marka(mar), model(mod), data(dat), pojemnosc(poj), power(pow) {} //konstruktor param, przyjmuje nasze dane/ dane z pliku
	const int getId() const { return id; }//gettery i settery...
	const int getWiek() const { return wiek; }
	const double getData() const { return data; }//int
	const double getPower() const { return power; }//double
	const double getPojemnosc() const { return pojemnosc; }//double
	//list<string> getCechy() const { return cechy; }////
	const string getModel() const { return model; }//string
	const string getMarka() const { return marka; }//string
	const char getTyp()  const { return typ; }
	void setId(int ID) { id = ID; }
	void setTyp(char t) { typ = t; }

	/*void setCechy() {

		cout << "Max 3 cechy!" << endl;
		for (int i = 0; i < 3; ++i) {

			string auxiliary;
			cout << "Waiting for new cecha:" << endl;
			cin >> auxiliary;
			cechy.push_front(auxiliary);
			cout << endl << "You want more? y/n" << endl;

			cin >> auxiliary;

			if (i != 2 && auxiliary == "n")
			{
				break;
			}

		}

	}
	*/
	
	//friend bool operator<(const Pojazd& P1, const Pojazd& P2);//sama deklaracja

	void print() { cout << "Marka:" << marka << ", model:" << model << ", data:" << data << ", wiek:" << wiek << ", poj:" << pojemnosc << ", moc:" << power << endl; }
	virtual ~Pojazd() { cout << "Bye Pojazd" << endl; }


	friend Pojazd& operator++(Pojazd& L); //sama deklaracja
private:
	string marka;
	string model;
	int data;
	double power;
	double pojemnosc;
	int liczba_cech;
	int wiek = 2022 - data;
	char typ;
	int id;

};

Pojazd& operator++(Pojazd& L) {//oeprator ++ dla pojazdow, wykorzystamy go do funkcji void timeline
	++L.wiek;
	return L;
}

/*
bool operator<(const Pojazd& P1, const Pojazd& P2) {
	return (P1.power < P2.power);
}*/


class Motocykl :public Pojazd {
public:
	//const char typ = 'M';//static
	Motocykl() :Pojazd((Random_MarkaM()), (Random_ModelM()), (Random_Data()), (Random_Poj()), (Random_Power())), boxer(Random_Boxer()) {} //domyslny -randomizacja
	Motocykl(string mar, string mod, int dat, double poj, double pow, bool b) :Pojazd(mar, mod, dat, poj, pow), boxer(b) {} //param
	virtual void print() { cout << "\tBoxer?:\t" << boxer << endl; }
	virtual ~Motocykl() { cout << "Bye motocykl" << endl; }
	const bool getBool() const{ return boxer; }
private:
	bool boxer;//unikalny atrybut motocyklu
};


class Osobowy :public Pojazd {
public:
//	const char typ = 'O';//static
	Osobowy() :Pojazd((Random_MarkaO()), (Random_ModelO()), (Random_Data()), (Random_Poj()), (Random_Power())), pasazerowie(Random_Pasazerowie()) {}//domyslny -randomizacja
	Osobowy(string mar, string mod, int dat, double poj, double pow, int p) :Pojazd(mar, mod, dat, poj, pow), pasazerowie(p) {} //param
	virtual void print() { cout << "\tPasazerowie?:\t" << pasazerowie << endl; }
	virtual~Osobowy() { cout << "Bye osobowy" << endl; }
	const int getPasazerowie() const { return pasazerowie; }
private:
	int pasazerowie; //unikalny dla osobowy

};


class LKW :public Pojazd {
public:
	//const char typ = 'P';//static
	LKW() :Pojazd((Random_MarkaL()), (Random_ModelL()), (Random_Data()), (Random_Poj()), (Random_Power())), ladunek(Random_Ladunek()) {}//default - randomizacja
	LKW(string mar, string mod, int dat, double poj, double pow, double l) :Pojazd(mar, mod, dat, poj, pow), ladunek(l) {}//param
	virtual void  print() { cout << "\tLadunek?:\t" << ladunek << endl; }
	virtual ~LKW() { cout << "Bye lkw" << endl; }
	const double getLadunek() const { return ladunek; }
private:
	double ladunek;//unikalny dla lkw

};
