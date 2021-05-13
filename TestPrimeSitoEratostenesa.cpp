// TestPrimeSitoEratostenesa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//unsigned long long -> od 0 do 18446744073709551615

#include <iostream>
#include <time.h>
using namespace std;
const unsigned int rozmiar = 200000;
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
bool testPrime1(unsigned int n, bool tabPrimeNumber[]) {
    if (tabPrimeNumber[n]) return true;
    else return false;
}
bool testPrime2(unsigned long long n, bool tabPrimeNumber[], int rozmiar) {
    bool p = true;
    if (n < 2) p = false;
    if ((n != 2) && (n % 2 == 0)) p = false;
    if (n != 2) {
        unsigned long long x = ceil(sqrt(n));
        for (int i = 3; i <= rozmiar; i++) {
            if (tabPrimeNumber[i])
                if (n % tabPrimeNumber[i] == 0) {
                    p = false;
                    break;
                }
            if (i > x) break;
        }
    }
    return p;
}
bool testPrime3(unsigned long long n, unsigned int tabPrimeNumber[], int rozmiar) {
    bool p = true;
    if (n < 2) p = false;
    if ((n != 2) && (n % 2 == 0)) p = false;
    if (n != 2) {
        unsigned long long x = ceil(sqrt(n));
        for (int i = 3; i <= rozmiar; i++) {
            if (n % tabPrimeNumber[i] == 0) {
                p = false;
                break;
            }
            if (i > x) break;
        }
    }
    return p;
}
void sito2(unsigned int tabPrimeNumber[]) {
    unsigned int n = 3;
    unsigned int i = 2;
    tabPrimeNumber[0] = 2;
    tabPrimeNumber[1] = 3;
    while (i < rozmiar) {
        if (testPrime(n)) {
            tabPrimeNumber[i] = n;
            i++;
        }
        n += 2;
    }
}

int main()
{
    bool tabPrimeNumber[rozmiar];
    unsigned int tab[rozmiar];
    unsigned long long n = 741345314801;
    //4999879
    //61698999949
    //98765432167
    //997799999199999971
    sito2(tab); //2746151 -> x^2 = 7541345314801
    //cout<<tab[rozmiar - 1] << endl;
    cout << sito(tabPrimeNumber, rozmiar) << endl;;//wygenerowanie sita
    clock_t start = clock();
    //cout << testPrime(n) << endl;
    //cout << testPrime2(n, tabPrimeNumber, rozmiar) << endl;
    cout << testPrime3(n, tab, rozmiar) << endl;
    
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << elapsed << end;
}

