#include"Henkilo.h"
#include"Opiskelija.h"
#include<memory>			//unique_ptr,shared_ptr ja weak_ptr
#include<vector>
#include<algorithm>
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
void fooSmart() {
	unique_ptr<Henkilo> pekka{ new Henkilo{"pekka", 10} };
	pekka->tulostaTiedot();
}// OK!! unique_ptr pekka vapaututetaan automaattisesti resurssin vapautuessa...
//unique_ptr ei voida kopioida

void foo() {
	//heap objektin luominen
	Henkilo* pekka = new Henkilo("pekka", 20);
	//olion k‰ytt‰minen 
	pekka->tulostaTiedot();
	//return;	muistivuoto, ei ehditty deletoimaan!!
	delete pekka;
}

void fooSmartShared() {
	shared_ptr<Henkilo> pekka;
	{
		shared_ptr<Henkilo> x{ new Henkilo{"pekka",20} };
		pekka = x;
		pekka->tulostaTiedot();
		shared_ptr<Henkilo> y = x;
	}//x ja y vapautuvat
	





//VIIKKOTEHT 6 alkaa!!!
}//pekka vapautuu
/*1.funktorit:
esim. struct multi_x {
	multi_x(int x) :x(x) {}
	int operator ()(int y) const { return x + y }

private:
	int x;
};
-Funktorit ovat periaatteessa funktiota, joille voi antaa objekteja muistiin.
Esimerkiksi luodaan funktio, joka tarkoituksena on tehd‰ jotain, mutta ei haluta k‰ytt‰‰ globaalisia muuttujia.
Funktorit ovat luokan ja olion yhdistelm‰.*/
struct Object
{
	bool operator()( Henkilo* y,  Henkilo* x) 
	{
		return x->getIka() > y->getIka();
	}
};

struct Object_unique
{
	bool operator()(unique_ptr<Henkilo> &y, unique_ptr<Henkilo> &x)
	{
		return x->getIka() > y->getIka();
	}
};
#include<functional>

//Vaihtoehto 1: Yksi versio, johon k‰yv‰t kaikki lambdat, jotka return void ja ei parametreja
void funktioJokaKayttaaLambdaa(const function<void()>& f, int n)
{
	for (int i = 0; i < n; i++) f();
}

//Vaihtoehto 2: k‰‰nt‰j‰ generoi jokaielle lambdalle oman verionsa alla olevasta template
template<typename F>
void funktioJokaKayttaaLambdaa(F& lambda, int n) {
	for (int i = 0; i < n; i++)lambda();
}

//Esimerkki jossa lambda aa int -parametrin eik‰ palauta mit‰‰n (void)
template<typename F>
void foo(F& f) {
	f(10);
}

int main() {
	foo();

	Henkilo pekka("Pekka", 10);
	Henkilo kalle("Kalle", 25);

	//policy objektin pit‰‰ olla void(int)
	pekka.tulostusPolicy = [](int a) { cout << "hello" << a << endl; };
	pekka.tulostaTiedot();


	auto helloWorldLambda = []() {cout << "Hello World" << endl; };

	funktioJokaKayttaaLambdaa(helloWorldLambda,10);

	auto printHelloWorldMultipletimes= [](int n) {
		for (int a =  0  ; a < n; a++) {
			cout << "Hello world" << endl;
		}
	};
	
	foo(printHelloWorldMultipletimes);

	vector<Henkilo*> henkilot;
	henkilot.push_back((new Henkilo("pekka", 20)));
	henkilot.push_back((new Henkilo("konsta", 50)));
	henkilot.push_back((new Henkilo("anja", 30)));
	henkilot.push_back((new Henkilo("mika", 10)));
	henkilot.push_back((new Henkilo("aleksi", 5)));
	//sort(begin(henkilot), end(henkilot), Object());
	/*
	vector<unique_ptr<Henkilo>> henkilot;
	henkilot.push_back(unique_ptr<Henkilo>(new Henkilo("pekka", 20)));
	henkilot.push_back(unique_ptr<Henkilo>(new Henkilo("konsta", 10)));
	henkilot.push_back(unique_ptr<Henkilo>(new Henkilo("anja", 50)));
	sort(begin(henkilot), end(henkilot), Object_unique());
	*/
	int x = 6;
	auto func = [x]()
	{ 
		for(int a = 0; a < x; a++)
		{
			cout << "Hello world" << endl;
		}
	};
	func(); // now call the function

	sort(begin(henkilot), end(henkilot), [](Henkilo* x, Henkilo* y) 
	{
		return x->getIka() < y->getIka();
	});

	for_each(henkilot.begin(), henkilot.end(), [](Henkilo* x)
	{
		if (x->getIka() < 18) {
			x->setIka(18);
		}
	});

	

	int numAdults = 0;
	int Children = 0;

	auto countAdultChildren = [&](const auto& p) {//unique_ptr<Henkilo>
		if (p->getIka() > 18) {
			numAdults++;
		}
		else if(p->getIka() < 18) {
			Children++;
		}
	};
	// tai auto countAdultChildren = [&](const auto& p){ p->getIka() > 18 ? numAdults++ : Children++ };

	for_each(henkilot.begin(), henkilot.end(), countAdultChildren);

	cout << "ADults " << numAdults << endl;
	cout << "Children " << Children << endl;


	system("pause");
	return EXIT_SUCCESS;
}
