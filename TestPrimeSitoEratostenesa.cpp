// TestPrimeSitoEratostenesa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//unsigned long long -> od 0 do 18446744073709551615

#include <iostream>
#include <time.h>
using namespace std;


bool testPrime(unsigned long long n) {
	bool p = true;
	if (n < 2) p = false;
	if ((n != 2) && (n % 2 == 0)) p = false;
	if (n != 2) {//wszystkie i>2
		for (unsigned long long dzielnik = 3; dzielnik < ceil(sqrt(n)); dzielnik += 2) {
			if (n % dzielnik == 0) {
				p = false;
				break;
			}
		}
	}
	if (p) return true;
	else false;
}
int sito(bool tabPrimeNumber[], int size) {
    for (int i = 0; i < size; i++) {
        tabPrimeNumber[i] = 1;
    }
    tabPrimeNumber[0] = 0;
    tabPrimeNumber[1] = 0;
    for (int i = 2; i * i < size; i++) {
        if (tabPrimeNumber[i])
            for (int j = 2; i * j < size; j++) {
                tabPrimeNumber[i * j] = 0;
            }
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (tabPrimeNumber[i]) count++;
    }
    return count;
}

int main()
{
    const unsigned int rozmiar = 1000001;
    bool tabPrimeNumber[rozmiar];
    //4999879
    //61698999949
    //98765432167
    clock_t start = clock();
    cout << testPrime(997799999199999971) << endl;
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << elapsed << end;
}

