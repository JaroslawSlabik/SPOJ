/*Dodawanie Rzymskie*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie: http://pl.spoj.com/problems/JSUMRZYM/ */
/*Kategoria: Sredni, ID 1311*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
 
 
class DodawanieRzymskie
{
private:
	std::vector<std::pair<unsigned int, char>> paryCyfr;//.first - arabskie, .second - rzymskie 
	void a2r(int arabska, char*rzymska); 
	void r2a(char *rzymska, int& arabska);
	int MAXrzymskie;
public:
	DodawanieRzymskie();
	void Dodaj(char* liczbaA, char* liczbaB, char* wynik);
	~DodawanieRzymskie();
};
 
void DodawanieRzymskie::a2r(int arabska, char *rzymska)
{
	int i = 0; //pozycja paryCyfr
	int j = 0; //pozycja rzymska
 
	if ((arabska > 2001) || (arabska <= 0))
	{
		return;
	}
 
	while ((arabska) && (i < MAXrzymskie))
	{
		if(arabska >= paryCyfr[i].first)
		{
			arabska -= paryCyfr[i].first;
			rzymska[j++] = paryCyfr[i].second;
		}
		else if ((i%2 == 0) && (i<MAXrzymskie-2) && (arabska >= paryCyfr[i].first - paryCyfr[i+2].first) && (paryCyfr[i+2].first != paryCyfr[i].first - paryCyfr[i+2].first))
		{
			arabska -= paryCyfr[i].first - paryCyfr[i+2].first;
			rzymska[j++] = paryCyfr[i+2].second;
			rzymska[j++] = paryCyfr[i].second;
			i++;
		}
		else if ((i%2 == 1) && (i<MAXrzymskie-1) && (arabska >= paryCyfr[i].first - paryCyfr[i+1].first) && (paryCyfr[i+1].first != paryCyfr[i].first - paryCyfr[i+1].first))
		{
			arabska -= paryCyfr[i].first - paryCyfr[i+1].first;
			rzymska[j++] = paryCyfr[i+1].second;
			rzymska[j++] = paryCyfr[i].second;
			i++;
		}
		else
		{
			i++;
		}
	}
	rzymska[j++] = 0;
}

void DodawanieRzymskie::r2a(char *rzymska, int& arabska)
{
	int i = 0; //pozycja paryCyfr
	int j = 0; //pozycja rzymska
	arabska = 0;
 
	int length = strlen(rzymska);
 
	while ((j<length) && (i<MAXrzymskie))
	{
		if(rzymska[j] == paryCyfr[i].second)
		{
			arabska += paryCyfr[i].first;
			j++;
		}
		else if ((i%2 == 0) && (i<MAXrzymskie-2) &&  (j<length-1) && (rzymska[j] == paryCyfr[i+2].second) && (rzymska[j+1] == paryCyfr[i].second))
		{
			arabska += paryCyfr[i].first - paryCyfr[i+2].first;
			j += 2;
			i++;
		}
		else if ((i%2 == 1) && (i<MAXrzymskie-1) && (j<length-1) && (rzymska[j] == paryCyfr[i+1].second) && (rzymska[j+1] == paryCyfr[i].second))
		{
			arabska += paryCyfr[i].first - paryCyfr[i+1].first;
			j += 2;
			i++;
		}
		else
		{
			i++;
		}
	}
}
 
DodawanieRzymskie::DodawanieRzymskie()
{
	paryCyfr.push_back(std::make_pair(1000, 'M'));
	paryCyfr.push_back(std::make_pair(500, 'D'));
	paryCyfr.push_back(std::make_pair(100, 'C'));
	paryCyfr.push_back(std::make_pair(50, 'L'));
	paryCyfr.push_back(std::make_pair(10, 'X'));
	paryCyfr.push_back(std::make_pair(5, 'V'));
	paryCyfr.push_back(std::make_pair(1, 'I'));
	
	MAXrzymskie = 7;
}

void DodawanieRzymskie::Dodaj(char* liczbaA, char* liczbaB, char* wynik)
{
	int a;
	r2a(liczbaA, a);
	int b;
	r2a(liczbaB, b);
	a2r(a + b, wynik);
}

DodawanieRzymskie::~DodawanieRzymskie()
{
	paryCyfr.clear();
}
 
int main()
{
	char rzymskaA[50];
	char rzymskaB[50];
	DodawanieRzymskie dodawanie;
	
	while(std::cin >> rzymskaA >> rzymskaB)
	{
		char wynik[50];
		dodawanie.Dodaj(rzymskaA, rzymskaB, wynik);
		
		printf("%s\n", wynik);
	}

	return 0;
}


