#include <iostream>
#include "Set.h"
using namespace std;

Set::Set() {												//Constructor fara parametri
	n = 0;
	m = 10;
	p = new int[m];
}

Set::Set(int dim, int val) {								//Constructor cu parametri
	n = dim;
	m = val;
	p = new int[m];
	for (int i = 0; i<n; i++) {
		p[i] = val;
	}
}

void Set::Insert(int val) {
	int j, x;
	int s = 1;
	int d = n;
	int mij;
	if (n == 0){
		p[n] = val;
		n++;
		return;
	}else
		while (s <= d) {
			mij = (s + d) / 2;
			if (val == p[mij]) return;
			if (val>p[mij] && val<p[mij + 1]) {
				x = mij;
				break;
			}
			else if (val<p[mij]) d = mij;
			else if (val>p[mij + 1]) s = mij + 1;
		}

	if (n == m) {
		m++;
		int *aux, i;
		aux = new int[m];
		for (i = 0; i<n; i++)
			aux[i] = p[i];
		delete[]p;
		p = aux;
	}
	n = n + 1;
	for (j = n; j>x; j--)
		p[j] = p[j - 1];
	p[x + 1] = val;
}

void Set::Delete(int val) {									//Functie pentru stergerea unei valori
	int s = 1;
	int d = n;
	int poz = 0;
	int mij, i;
	while (s <= d) {										//Cautarea valorii cu ajutorul Cautarii Binare
		mij = (s + d) / 2;
		if (val == p[mij]) { poz = mij; break; }
		else if (val<p[mij]) s = mij + 1;
		else d = mij - 1;
	}
	for (i = poz; i<n; i++)
		p[i] = p[i + 1];									//Stergerea valorii
	n = n - 1;
}

bool Set::Cautare(int val) {								//Functie care cauta o valoare cu ajutorul Cautarii Binare
	int s = 1;
	int d = n;
	int poz = 0;
	int mij;
	while (s <= d) {
		mij = (s + d) / 2;
		if (val == p[mij]) { poz = mij; break; }
		else if (val<p[mij]) s = mij + 1;
		else d = mij - 1;
	}
	if (poz>0) return true;
	return false;
}

int Set::Nr_elem() {										//Functie care returneaza numarul de elemente al multimii
	return n;
}

int Set::Suma() {											//Functie care returneaza Suma elementelor multimii
	int S = 0;
	int i;
	for (i = 0; i<n; i++)
		S = S + p[i];
	return S;
}

Set Set::pare() {											//Obtinerea numerelor pare din multime
	Set pare;
	int i;
	for (i = 0; i<n; i++)
		if (p[i] % 2 == 0)
			pare.Insert(p[i]);
	return pare;
}

Set Set::impare() {											//Obtinerea numerelor impare din multime
	int i;
	Set impare;
	for (i = 0; i<n; i++)
		if (p[i] % 2 != 0)
			impare.Insert(p[i]);
	return impare;
}

int Set::operator [](int i) {								//Supraincarcarea operatorului [] pentru returnarea elementului de pe pozitia i
		return p[i];
}

bool Set::operator >( Set & b) {							//Supraincarcarea operatorului > cu compararea card. a doua multimi
	if (Nr_elem() > b.Nr_elem() )return true;
	return false;
}

bool Set::operator <(Set & b) {								//Supraincarcarea operatorului < cu compararea card. a doua multimi
	if (Nr_elem() < b.Nr_elem())return true;
	return false;
}

int* Set::operator *(int scalar) {							//Supraincarcarea operatorului * pentru inmultirea elementelor cu un scalar
	int i;
	int *aux = new int;
	for (i = 0; i < n; i++)
		aux[i] = p[i] * scalar;
	return aux;
}

Set Set::operator +(Set & b) {								//Supraincarcarea operatorului + care sa efectueze reuniunea a doua multimi fara duplicate
	Set x;
	int i, q;
	if (Nr_elem() > b.Nr_elem()) q = Nr_elem();
	else q = b.Nr_elem();
	for (i = 0; i < q; i++)
		x.p[i] = p[i];
	for (i = 0; i < q; i++)
		x.Insert(b[i]);
	return x;
}


Set	Set::operator =(Set & b) {								//Supraincarcarea operatorului = pentru copierea elementelor dintr-o multime in alta
	int i, q;
	if (Nr_elem() > b.Nr_elem()) q = Nr_elem();
	else q = b.Nr_elem();
	for (i = 0; i < q; i++)
		p[i] = b.p[i];
	return *this;
}

istream & operator >>(istream &ci, Set &a) {				//Supraincarcarea operatorului de citire
	int i;
	for (i = 0; i < a.Nr_elem(); i++)
		ci >> a.p[i];
	return ci;
}

ostream & operator <<(ostream &co, Set &a) {				//Supraincarcarea operatorului de afisare
	int i;
	for (i = 0; i < a.Nr_elem(); i++)
		co << a.p[i] << " ";
	return co;
}


Set::Set(Set & a) {											//Constructorul de copiere
	*this = a;
}


Set::~Set() {												//Destructor
	delete[]p;
}
