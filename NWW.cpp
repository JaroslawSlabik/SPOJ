/*NWW 2*/
/*Autor: Jaroaław Słabik*/
/*Pochodzenie: http://pl.spoj.com/problems/NWW/ */
/*Kategoria: Sredni, ID: 747*/

#include <iostream>
#include <algorithm>

typedef unsigned long long DUZA;

/*Rozwiazaniem może byc jedna z ponizszych funkcji obliczajaca NWD*/

/*DUZA nwd(DUZA a, DUZA b) 
{
  DUZA pom;
 
    while(b!=0)
  {
      pom = b;
      b = a%b;
      a = pom;  
    }
    return a;
}*/

DUZA nwd(DUZA a, DUZA b) // dziala szybciej o 0.01s
{
    if (a<b)
       std::swap (a,b);
    DUZA p;
    while(true)
    {
        p = b % a;
        if (p==0)
           return a;
        std::swap(b,a);
        std::swap(p,a);
    }
}


int main()
{
  DUZA liczbaTestow = 0;
  DUZA ileLiczbN = 0;
  DUZA pierwszaLiczbaN = 0;
  DUZA kolejneLiczbyN = 0;

  std::cin >>liczbaTestow;

  for(DUZA i = 0; i < liczbaTestow; i++)
  {
    std::cin >>ileLiczbN; 
    if (ileLiczbN != 0)
    {
      std::cin >>pierwszaLiczbaN;
      for (DUZA j = 1; j < ileLiczbN; j++)
      {
        std::cin>>kolejneLiczbyN;
        pierwszaLiczbaN = pierwszaLiczbaN / nwd(pierwszaLiczbaN, kolejneLiczbyN) * kolejneLiczbyN;
      }
      std::cout <<pierwszaLiczbaN << "\n";
    }
  }

  return 0;
}