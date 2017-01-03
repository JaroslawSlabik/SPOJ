/*Prime Generator ENG*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie:http://www.spoj.com/problems/PRIME1/ */
/*Kategoria: classical, ID 2*/

#include <cstdio>
#include <list>
 
#define MAX 31684
#define LMT 178
#define LEN 3410
#define RNG 100032
 
unsigned base[MAX/64], primes[LEN];
 
#define sq(x) ((x)*(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
 
void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!chkC(base, i))
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				setC(base, j);
	for(i=3, j=0; i<MAX; i+=2)
		if(!chkC(base, i))
			primes[j++] = i;
}
 
void segmented_sieve(int a, int b, std::list<int>& listOfPrimes)
{
	unsigned i, j, k, is2 = (a<=2 && 2<=b)? 1 : 0;
	if(is2==1) listOfPrimes.push_back(2);
	if(b<2) return;
	if(a<3) a = 3;
	if(a%2==0) a++;
	unsigned segment[RNG/64] = {0};
	for(i=0;sq(primes[i])<=b;i++)
	{
		j = primes[i]*((a+primes[i]-1)/primes[i]);
		if(j%2==0) j += primes[i];
		for(k=primes[i]<<1;j<=b;j+=k)
			if(j!=primes[i])
				setC(segment,(j-a));
	}
	for(i=0;i<=b-a;i+=2)
		if(!chkC(segment,i))
			listOfPrimes.push_back(i+a);
}
 
int main()
{
	std::list<int> listOfPrimes;
	sieve();
	int testy;
	scanf("%d",&testy);
	for(int x=0; x<testy; x++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		segmented_sieve(a, b, listOfPrimes);
	}
	
	for(auto it = listOfPrimes.begin(); it != listOfPrimes.end(); ++it)
		 printf("%d\n", *it);//std::cout << *it << "\n";
	
	return 0;
} 