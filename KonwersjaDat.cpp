/*Konwersja Dat*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie:http://pl.spoj.com/problems/WI_DATY/ */
/*Kategoria: Sredni, ID 4801*/
#include <iostream>
#include <string>
#include <cstdio>

void wyrownaj(std::string& ciag, int ile)
{
	std::string wynik(ile - ciag.length(), '0');
	wynik += ciag;
	ciag = wynik;
}

int int2str(std::string ciag)
{
	int a = 1;
	int wynik = 0;
	for (int i = ciag.length() - 1; i >= 0; i--)
	{
		wynik += (ciag.at(i) - '0') * a;
		a *= 10;
	}

	return wynik;
}


std::string intToBin(int liczba)
{
	int i = 31;
	std::string wynik = "";
	bool ok = false;
	while (i--)
	{
		if (liczba >> i & 1 & !ok)
			ok = true;

		if (ok) wynik.push_back(((liczba >> i) & 1) + 48);
	}

	return wynik;
}

int power(int liczba, int potega)
{
	int wynik = 1;

	while (potega != 0)
	{
		if (potega % 2 == 1)
			wynik = wynik*liczba;

		potega = potega / 2;
		liczba *= liczba;
	}

	return wynik;
}

int bin2dec(std::string input)
{
	int output = 0;
	for (int i = 0; i<input.size(); i++)
		output += (input[i] - '0')*power(2, input.size() - i - 1);
	return output;
}

int main()
{
	std::string ciag = "";
	std::cin >> ciag;

	if (ciag.empty())
		printf("ERROR\n");

	if (ciag.length() > 7 && ciag.length() < 11 && 
		ciag.at(4) == '-' && ciag.at(6) == '-' || ciag.at(7) == '-') //data ISO
	{
		std::string rok = "";
		std::string miesiac = "";
		std::string dzien = "";
		int i = 0;
		for (; i < 4; i++) rok += ciag.at(i);
		i++;
		for (; i < 7; i++) miesiac += ciag.at(i);
		i++;
		for (; i < 10; i++)dzien += ciag.at(i);

		std::string rokBin = intToBin(int2str(rok) - 1980);
		std::string miesiacBin = intToBin(int2str(miesiac));
		std::string dzienBin = intToBin(int2str(dzien));

		wyrownaj(rokBin, 7);
		wyrownaj(miesiacBin, 4);
		wyrownaj(dzienBin, 5);

		printf("%s%s%s", rokBin.c_str(), miesiacBin.c_str(), dzienBin.c_str());//std::cout << rokBin << miesiacBin << dzienBin << "\n";
	}
	else if (ciag.length() == 16) //data binarna
	{
		std::string rok = "";
		std::string miesiac = "";
		std::string dzien = "";
		int i = 0;
		for (; i < 7; i++) rok += ciag.at(i);
		for (; i < 11; i++) miesiac += ciag.at(i);
		for (; i < 16; i++)dzien += ciag.at(i);
		int rokI = bin2dec(rok) + 1980;
		int miesiacI = bin2dec(miesiac);
		int dzienI = bin2dec(dzien);
		printf("%i", rokI);//std::cout << rokI;
		
		if (miesiacI < 10)
			printf("-0%i", miesiacI);//std::cout << "-0" << miesiacI;
		else
			printf("-%i", miesiacI);//std::cout << "-" << miesiacI;
		
		if (dzienI < 10)
			printf("-0%i\n", dzienI); //std::cout << "-0" << dzienI << "\n";
		else
			printf("-%i\n", dzienI);//  std::cout << "-" << dzienI << "\n";
	}
	else
	{
		printf("ERROR\n");
	}

	return 0;
}