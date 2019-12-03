#pragma once
#include<string>
#include<iostream>

using namespace std;
class Osoite
{
public:
	Osoite() : Osoite( "", "" ){
	}
	Osoite(const string& aKatu, const string& aKunta) : katuosoite(aKatu), kunta(aKunta) {
		cout << "osoite -luokan rakentaja" << endl;
	};
	~Osoite() {
		cout << "osoite -luokan purkaja" << endl;
	}
	string getKatuosoite() const { return katuosoite; }
	string getKunta() const { return kunta; }

	void setKatuosoite(const string& aKatuosoite) { katuosoite = aKatuosoite; }
	void setKunta(const string& aKunta) { kunta = aKunta; };

private:
	string katuosoite;
	string kunta;
};

