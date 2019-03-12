#include <iostream>
#ifndef SET_H
#define SET_H
using namespace std;

class Set {
public:
	Set();															//Constructor fara parametri
	Set(int, int);													//Constructor cu parametri
	void Insert(int val);											//Functie pentru inserarea unei valori in multime
	void Delete(int val);											//Functie pentru stergerea unei valori
	bool Cautare(int val);											//Functie care cauta o valoare cu ajutorul Cautarii Binare
	int Nr_elem();													//Functie care returneaza numarul de elemente al multimii
	int Suma();														//Functie care returneaza Suma elementelor multimii1
	Set pare();														//Obtinerea numerelor pare din multime
	Set impare();													//Obtinerea numerelor impare din multime
	int operator [](int i);											//Supraincarcarea operatorului [] pentru returnarea elementului de pe pozitia i
	bool operator >(Set & b);										//Supraincarcarea operatorului > cu compararea card. a doua multimi
	bool operator <(Set & b);										//Supraincarcarea operatorului < cu compararea card. a doua multimi
	int* operator *(int scalar);									//Supraincarcarea operatorului * pentru inmultirea elementelor cu un scalar
	Set operator +(Set & b);										//Supraincarcarea operatorului + care sa efectueze reuniunea a doua multimi fara duplicate
	Set operator =(Set & b);										//Supraincarcarea operatorului = pentru copierea elementelor dintr-o multime in alta
	friend istream & operator >>(istream & ci, Set & a);			//Supraincarcarea operatorului de citire
	friend ostream & operator <<(ostream & co, Set & a);			//Supraincarcarea operatorului de afisare
	Set(Set & a);													//Constructorul de copiere
	~Set();															//Destructor
private:
	int n, m;
	int *p;
};

#endif // SET_H
