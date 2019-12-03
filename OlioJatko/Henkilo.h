#pragma once
#include<string>
#include"Osoite.h"
using namespace std;

class Henkilo
{
public:
	Henkilo(); // Oletusrakentaja ei luo osoitetta, vaan osoite on nullptr
	Henkilo(const string& aNimi, int aIka);
	Henkilo(const string& aNimi, int aIka, const Osoite& aOsoite); // luodaan osoite new:lla 
	Henkilo(const Henkilo& aHlo);
	// Muistetaan vapauttaa resurssit, jos sellaisia on varattuna
	virtual ~Henkilo(); 

	string getNimi() const;
	void setNimi(const string& aNimi);
	int getIka() const;
	void setIka(int aIka);
	Osoite getOsoite() const;
	Osoite* getOsoitePtr() const;
	// Osoite p‰ivitet‰‰n, jos oliolla on jo osoite
	// Muuten luodaan osoite dynaamisesti nullptr:n tilalle
	void setOsoite(const Osoite& aOsoite); 
	void setOsoitePtr(Osoite* aOsoite);
	virtual void tulostaTiedot() const;

private:
	int ika = 0;
	string nimi = "";
	Osoite* osoite = nullptr;
};

