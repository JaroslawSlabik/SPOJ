/*Transform the Expression ENG*/
/*Autor: Jaroa³aw S³abik*/
/*Pochodzenie:http://www.spoj.com/problems/ONP/ */
/*Kategoria: classical, ID 4*/
/*Przydatny link: https://pl.wikipedia.org/wiki/Odwrotna_notacja_polska*/

#include <cstdio>
#include <stack>
#include <map>
#include <cctype>

//ONP - Odwrotna notacja polska
//TNM - Tradycyjna notacja matematyczna
 
int main()
{
	char TNM[500], ONP[500];
	std::map<char,int> Priorytet;
	Priorytet.insert(std::pair<char,int>('+',1));
	Priorytet.insert(std::pair<char,int>('-',2));
	Priorytet.insert(std::pair<char,int>('*',3));
	Priorytet.insert(std::pair<char,int>('/',4));
	Priorytet.insert(std::pair<char,int>('^',5));
	std::stack<char> Stos;
	
	
	int liczbaTestow = 0;
	scanf("%d",&liczbaTestow);
	
	for( ; liczbaTestow ; liczbaTestow--)
	{
		int pozONP = 0;
		scanf("%s",TNM);
		for(int i = 0; TNM[i]; i++)
		{
			if(isalpha(TNM[i])) ONP[pozONP++] = TNM[i];
			else if(TNM[i]=='(') Stos.push(TNM[i]);
			else if(TNM[i]==')')
			{
				while(!Stos.empty() && Stos.top()!='(')
				{
					ONP[pozONP++] = Stos.top();
					Stos.pop();
				}
				Stos.pop();
			}
			else
			{
				while(!Stos.empty() && Stos.top()!='(' && Priorytet[Stos.top()] > Priorytet[TNM[i]])
				{
					ONP[pozONP++] = Stos.top();
					Stos.pop();
				}
				Stos.push(TNM[i]);
			}
		}
		while(!Stos.empty())
		{
			ONP[pozONP++] = Stos.top();
			Stos.pop();
		}
		ONP[pozONP] = 0;
		printf("%s\n",ONP);
	}
	return 0;
} 