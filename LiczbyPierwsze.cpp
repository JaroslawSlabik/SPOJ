/*Liczby Pierwsze*/
/*Autor: Jaroaław Słabik*/
/*Pochodzenie: http://pl.spoj.com/problems/PRIME_T/ */
/*Kategoria: Łatwy, ID: 438*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
 
bool czy_pierwsza(int n)
{
  if(n<2)
    return false;
 
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}
 
int main()
{
  int n;
  int liczba;

  scanf("%d", &n);

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &liczba);
    if(czy_pierwsza(liczba))
      printf("TAK\n");
    else
      printf("NIE\n");
  }

  return 0;
}
