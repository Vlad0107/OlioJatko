#include"Henkilo.h"
#include"Opiskelija.h"
using namespace std;

void doSomething() {
   // Heap (dynaaminen muisti)
	Henkilo* p = new Henkilo();
	p->setIka(10);
	p->setNimi("Pekka");
	p->tulostaTiedot();

	delete p; // vapautetaan dynaaminen muisti
	
	// Stack (automaattinen pinomuisti)
	Henkilo k("Kalle", 10);
	k.tulostaTiedot();

	Henkilo v(k);
	v.tulostaTiedot();

	Henkilo s = k;
	s.tulostaTiedot();
}

void foo(const Henkilo& x) {
	x.tulostaTiedot();
}



int main() {
	{
		Osoite os1("Teiskontie1", "Tampere");
		Henkilo ville("Ville", 25, os1);
		ville.tulostaTiedot();

		cout << "Kopioidaan ville henkiloon x" << endl;

		Henkilo x(ville);
		x.tulostaTiedot();

		system("pause");
	}

	system("pause");
	return EXIT_SUCCESS;
}