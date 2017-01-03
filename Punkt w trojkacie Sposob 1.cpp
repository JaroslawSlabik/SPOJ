/*Punkty w trójk¹cie (Sposob 2)*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie: http://pl.spoj.com/problems/T_PINTR/
/*Kategoria: Sredni, ID: 541*/


/*
	Dla odcinka AB
	macierz 3X3
	[ A.x  A.y  1 ]
D = [ B.x  B.y  1 ] -> det(D) = det(AB) = d_AB
	[ p.x  p.y  1 ]
   ------------------
	| A.x  A.y  1 |
	| B.x  B.y  1 |
	d_AB == 0 - punkt p jest na lini
	d_AB < 0 - punkt p jest po lewej stronie
	d_AB > 0 - punkt p jest po prawej stronie

	Powtorzyæ operacjê na 2 kolejnych odcinków
*/

#include<iostream>

#define wTroj 'I'
#define pozaTroj 'O'
#define naBrzeguTroj 'E'

struct punkt
{
	int x, y;

	punkt(int X, int Y)
	{
		x = X;
		y = Y;
	}

	bool operator==(punkt a)
	{
		return x == a.x && y == a.y;
	}
};

int main()
{
	punkt A(0, 0), B(0, 0), C(0, 0); // Wierzcho³ki trójk¹ta
	punkt p(0,0); //punkt 

	while (std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> p.x >> p.y)
	{
		if (A == punkt(0, 0) && B == punkt(0, 0) && C == punkt(0, 0) && p == punkt(0, 0))
			break;

		//wyznacznik det(A B)
		int d_AB = A.x * B.y + B.x * p.y + p.x * A.y - B.y * p.x - p.y * A.x - A.y * B.x;

		//wyznacznik det(B C)
		int d_BC = B.x * C.y + C.x * p.y + p.x * B.y - C.y * p.x - p.y * B.x - B.y * C.x;

		//wyznacznik det(C A)
		int d_CA = C.x * A.y + A.x * p.y + p.x * C.y - A.y * p.x - p.y * C.x - C.y * A.x;

		if ((d_AB < 0 && d_BC < 0 && d_CA < 0) ||
			(d_AB > 0 && d_BC > 0 && d_CA > 0))
		{
			std::cout << wTroj << std::endl;
			continue;
		}

		if (d_AB == 0 || d_BC == 0 || d_CA == 0)
		{
			std::cout << naBrzeguTroj << std::endl;
			continue;
		}

		std::cout << pozaTroj << std::endl;
	}

	system("pause");
	return 0;
}


