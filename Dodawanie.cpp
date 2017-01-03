/*Dodawanie*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie: http://pl.spoj.com/problems/JSUMDUZE/ */
/*Kategoria: Sredni, ID: 1293*/

#include <iostream>

unsigned int stringLenght(char* str)
{
	char* temp = str;

	while (*str)
		++str;

	return str - temp;
}

int main()
{
	int pakiety = 0;

	std::cin >> pakiety;

	char** wynikKoncowy = new char*[pakiety];
	char** liczbaA = new char*[pakiety];
	char** liczbaB = new char*[pakiety];

	for (unsigned int i = 0; i < pakiety; i++)
	{
		wynikKoncowy[i] = new char[100];
		liczbaA[i] = new char[100];
		liczbaB[i] = new char[100];

		std::cin >> liczbaA[i] >> liczbaB[i];

		int WynikJednosci = 0;
		int WynikDziesiatek = 0;
		int Wynik = 0;

		unsigned int dlugA = stringLenght(liczbaA[i]);
		unsigned int dlugB = stringLenght(liczbaB[i]);
		unsigned int dlugosc = 0;

		if (dlugA == dlugB)
		{
			dlugosc = dlugA;
		}
		else if (dlugA < dlugB)
		{
			dlugosc = dlugB;

			for (unsigned int j = 0; j < dlugA; j++) 
				liczbaA[i][dlugosc - j - 1] = liczbaA[i][dlugA - j - 1];

			for (unsigned int j = 0; j < dlugosc - dlugA; j++) 
				liczbaA[i][j] = 48;
		}
		else if (dlugA > dlugB)
		{
			dlugosc = dlugA;

			for (unsigned int j = 0; j < dlugB; j++)
				liczbaB[i][dlugosc - j - 1] = liczbaB[i][dlugB - j - 1];

			for (unsigned int j = 0; j < dlugosc - dlugB; j++)
				liczbaB[i][j] = 48;
		}


		for (unsigned int j = dlugosc; j > 0; j--)
		{
			Wynik = (liczbaA[i][j - 1] - 48) + (liczbaB[i][j - 1] - 48) + WynikDziesiatek;

			if (Wynik > 9)
			{
				WynikJednosci = Wynik % 10;
				WynikDziesiatek = (Wynik / 10) % 10;
			}
			else
			{
				WynikJednosci = Wynik;
				WynikDziesiatek = 0;
			}

			wynikKoncowy[i][j - 1] = WynikJednosci + 48;
		}

		if (WynikDziesiatek > 0)
		{
			for (unsigned int j = dlugosc; j > 0; j--)
				wynikKoncowy[i][j] = wynikKoncowy[i][j - 1];
			
			wynikKoncowy[i][0] = WynikDziesiatek + 48;
			wynikKoncowy[i][dlugosc + 1] = '\0';
		}
		else
			wynikKoncowy[i][dlugosc] = '\0';
	}
	
	for (unsigned int i = 0; i < pakiety; i++)
	{
		std::cout << wynikKoncowy[i] << "\n";
	}

	return 0;
}