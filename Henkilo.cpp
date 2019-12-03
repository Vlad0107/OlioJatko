#include "Henkilo.h"
#include<iostream>
using namespace std;

Henkilo::Henkilo() : ika( 0 ), nimi( "" )
{
	cout << "Henkilon rakentaja" << endl;
}

Henkilo::Henkilo(const string& aNimi, int aIka) : ika( aIka ), nimi( aNimi )
{
	cout << "Henkilon 2 parametrinen rakentaja" << endl;
}

Henkilo::Henkilo(const string & aNimi, int aIka, const Osoite & aOsoite) 
	: ika ( aIka ), nimi( aNimi ), osoite( new Osoite( aOsoite )) 
	// luodaan heapiin osoite, johon kopioidaan tiedot
{ 
	cout << "Henkilon 3 parametrinen rakentaja" << endl;
}

Henkilo::Henkilo(const Henkilo& aHlo) : ika( aHlo.ika), nimi( aHlo.nimi ), osoite( aHlo.osoite )
{
	cout << "Henkilon kopiorakentaja" << endl;
}

Henkilo::~Henkilo()
{
	// Vapautetaan olion varaama dynaaminen muisti ja muut resurssit
	cout << "Henkilon " << nimi << " purkaja" << endl;
	//delete osoite;
}

string Henkilo::getNimi() const
{
	return nimi;
}

void Henkilo::setNimi(const string& aNimi)
{
	nimi = aNimi;
}

int Henkilo::getIka() const
{
	return ika;
}

void Henkilo::setIka(int aIka)
{
	if (ika >= 0) {
		ika = aIka;
	}
}

shared_ptr<Osoite> Henkilo::getOsoite() const
{
	return osoite;
}

shared_ptr<Osoite>Henkilo::getOsoitePtr() const
{
	return osoite;
}

/*void Henkilo::setOsoite(const shared_ptr<Osoite> & aOsoite)
{
	if (osoite) { // osoite on luotu ja olemassa => päivitetään osoite
		*osoite = aOsoite; // kopioidaan uudet arvot vanhaan osoitteeseen
	}
	else { // osoite == nullptr
		osoite = new shared_ptr<Osoite>(aOsoite);	// luodaan henkilölle osoite, johon kopioidaan							// aOsoite -olion arvot (kopiorakentaja)
	}
}*/

void Henkilo::setOsoitePtr(shared_ptr<Osoite> aOsoite)
{ 
	//delete osoite;  // tuhotaan vanha osoite (tai nullptr)
	osoite = aOsoite; // asetetaan uusi
}

void Henkilo::tulostaTiedot() const
{

	cout << "Henkilo osoitteessa" << this << endl;
	cout << "Nimi: " << nimi << endl;
	cout << "Ika: " << ika << endl;
	// tulostetaan myös osoite, jos sellainen henkilöllä on
	if (osoite) {
		cout << "Katuosoite: " << osoite->getKatuosoite() << endl;
		cout << "Kunta " << osoite->getKunta() << endl;
	}
	if (tulostusPolicy) {		//policy objekti määritelty
		tulostusPolicy(10);
	}

}
