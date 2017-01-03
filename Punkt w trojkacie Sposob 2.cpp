/*Punkty w trójk¹cie (Sposob 1)*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie: http://pl.spoj.com/problems/T_PINTR/
/*Kategoria: Sredni, ID: 541*/

/* Mno¿enie wektorów */

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

struct vector 
{
	int x, y;

	vector(const punkt &p1, const punkt &p2) {
		x = p2.x - p1.x;
		y = p2.y - p1.y;
	}

	void revers() {
		x = -x;
		y = -y;
	}
};

int iloczynV(const vector &a, const vector &b) {
	return a.x*b.y - a.y*b.x;
}

int main()
{
	punkt A(0, 0), B(0, 0), C(0, 0);
	punkt p(0, 0);

	while (std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> p.x >> p.y) 
	{
		if (A == punkt(0, 0) && B == punkt(0, 0) && C == punkt(0, 0) && p == punkt(0, 0))
			break;

		vector AB(A, B), BC(B, C), CA(C, A);

		if (iloczynV(AB, BC) < 0)
		{
			AB.revers();
			BC.revers();
			CA.revers();
		}

		int ax = iloczynV(AB, vector(A, p));
		int bx = iloczynV(BC, vector(B, p));
		int cx = iloczynV(CA, vector(C, p));

		if (ax < 0 || bx < 0 || cx < 0) {
			std::cout << pozaTroj << std::endl;
			continue;
		}

		if (ax == 0 || bx == 0 || cx == 0) {
			std::cout << naBrzeguTroj << std::endl;
			continue;
		}
		std::cout << wTroj << std::endl;
	}

	system("pause");
	return 0;
}