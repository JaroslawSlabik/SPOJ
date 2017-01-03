/*Dyzio ENG*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie:http://www.spoj.com/problems/DYZIO/ */
/*Kategoria: classical, ID 56*/

#include <cstdio>
 
char string[20002];
int liczba , AktualnaPozycja, MAXliczbaCiec, pozycja;
 
void Przeciecie(int p) 
{
	if(string[pozycja] == '1') 
		liczba++;
	if(p > AktualnaPozycja) 
	{
		AktualnaPozycja = p;
		MAXliczbaCiec = liczba ;
	}
	if(string[pozycja++] == '1') 
	{
		Przeciecie(p+1);
		Przeciecie(p+1);
	}
}
 
int main() 
{
	int dlugosc = 0;
	
	while(scanf("%d", &dlugosc) == true) 
	{
		scanf("%s", string);
		pozycja = liczba  = AktualnaPozycja = MAXliczbaCiec = 0;
		Przeciecie(1);
		printf("%d\n", MAXliczbaCiec);
	}
	
	return 0;
} 