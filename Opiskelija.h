#include"Henkilo.h"
#include<iostream>
using namespace std;

class Opiskelija : public Henkilo {
public:
	Opiskelija(const string& aNimi, int aIka, int aOpintopisteet) 
		: Henkilo (aNimi, aIka), opintopisteet( aOpintopisteet )   {
		a = new double(2.22);
	}
	~Opiskelija() {
		cout << "Opiskelijan purkaja. Vapautetaan opiskelijan omistamat resussit " << endl;
		delete a; // vapautetaan resurssi
	}
	void tulostaTiedot() const {
		cout << "Opiskelijan tulosta tiedot -metodi" << endl;
		Henkilo::tulostaTiedot();
		cout << "Opintopisteet " << opintopisteet << endl;
	}
	int getOpintopisteet() const  
	{ 
		return opintopisteet;  
	}
	void setOpintopisteet(int aOpintopisteet) {
		opintopisteet = aOpintopisteet;
	}

private:
	int opintopisteet;
	double* a;
};