#include <iostream>
#include "Set.h"
using namespace std;

void afisare(Set v) {							//Functia de afisare a elementelor din vector
	int i, n;
	n = v.Nr_elem();
	for (i = 0; i<n; i++)
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	Set v;
	v.Insert(1);
	v.Insert(5);
	v.Insert(9);
	v.Insert(8);
	afisare(v);
	v.Delete(5);
	afisare(v);
	return 0;
}
