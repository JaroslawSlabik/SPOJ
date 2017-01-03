/*Kod GRAY'a*/
/*Autor: Jaroaław Słabik*/
/*Pochodzenie: http://pl.spoj.com/problems/WI_GRAY/ */
/*Kategoria: Sredni, ID 4800*/

#include <iostream>

void KonwersjaDecDoBin(int liczba, int iloscBitow, bool* lancuchBitow)
{
	int i = iloscBitow - 1;

	//dopóki liczba będzie różna od zera
	while (liczba) 
	{
		lancuchBitow[i--] = (liczba % 2 == 1)? true : false;
		liczba /= 2;
	}

	//dopełnienie pustych miejsc w lancuchu zerami
	for (; i >= 0; i--)
	{
		lancuchBitow[i] = false;
	}
}

void KonwersjaBinDoGRAY(bool* lancuchBitow, int iloscBitow)
{
	//przepuszczenie lancucha przez bramkę XOR
	for (unsigned int i = iloscBitow - 1; i > 0; i--)
	{
		lancuchBitow[i] = lancuchBitow[i] ^ lancuchBitow[i - 1];
	}
}

int main()
{
	int liczbaBitow = 0;
	int liczbaDoKonwersji = 0;

	std::cin >> liczbaBitow >> liczbaDoKonwersji;

	bool *tab = new bool[liczbaBitow];

	KonwersjaDecDoBin(liczbaDoKonwersji, liczbaBitow, tab);

	KonwersjaBinDoGRAY(tab, liczbaBitow);

	for (int i = 0; i < liczbaBitow; i++)
		std::cout << tab[i];

	delete[] tab;

	return 0;
}