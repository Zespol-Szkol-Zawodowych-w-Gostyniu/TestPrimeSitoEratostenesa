// TestPrimeSitoEratostenesa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//unsigned long long -> od 0 do 18446744073709551615

#include <iostream>
#include <time.h>
using namespace std;

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
int main()
{
    const unsigned int rozmiar = 1000001;
    bool tabPrimeNumber[rozmiar];
    unsigned long long n = 991999999717;
    //4999879
    //61698999949
    //98765432167
    //997799999199999971
    sito(tabPrimeNumber, rozmiar);//wygenerowanie sita
    clock_t start = clock();
    cout << testPrime(n) << endl;
    //cout << testPrime2(n, tabPrimeNumber, rozmiar) << endl;
    
    
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << elapsed << end;
}

