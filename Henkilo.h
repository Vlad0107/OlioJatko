#pragma once
#include<memory>
#include<functional>
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
	shared_ptr<Osoite> getOsoite() const;
	shared_ptr<Osoite> getOsoitePtr() const;
	// Osoite p‰ivitet‰‰n, jos oliolla on jo osoite
	// Muuten luodaan osoite dynaamisesti nullptr:n tilalle
	//void setOsoite(const Osoite& aOsoite); 
	void setOsoitePtr(shared_ptr<Osoite> aOsoite);
	virtual void tulostaTiedot() const;

	//m‰‰ritell‰‰n luokalle Policy Object -tietoj‰sen (lambda)
	//jokaisella oliolla on oma uniikki toiminnallisuutensa
	function<void(int)> tulostusPolicy = [](int a) {cout << "Tulostus Policy" << endl; };

private:
	int ika = 0;
	string nimi = "";
	//unique_ptr<Osoite> osoite;		//vain minun osoite. Ei jaettu = aggregaatio
	shared_ptr<Osoite> osoite;		//osoitteen voi jakaa useampi henkilˆ

};

