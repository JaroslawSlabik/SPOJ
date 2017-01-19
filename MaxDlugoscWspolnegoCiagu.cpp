/*Długość najdłuższego wspólnego podciągu*/
/*Autor: Jaroaław Słabik*/
/*Pochodzenie: http://pl.spoj.com/problems/LENLCS/ */
/*Kategoria: Sredni, ID: 498*/

#include <cstdio>
#include <algorithm>

int lcs[1001][1001];

int main() 
{
	int liczbaTestow = 0;
	char* ciagA;
	char* ciagB;

    scanf("%d\n", &liczbaTestow);

    for (int k = 0; k < liczbaTestow; ++k) 
    {
    	int dlugoscCiaguA = 0;
    	scanf("%d\n", &dlugoscCiaguA);
    	ciagA = new char[dlugoscCiaguA];
    	scanf("%s\n", ciagA);

		int dlugoscCiaguB = 0;
    	scanf("%d\n", &dlugoscCiaguB);
    	ciagB = new char[dlugoscCiaguB];
    	scanf("%s\n", ciagB);

		for (int i = 1; i <= dlugoscCiaguA; i++)
		{
			for (int j = 1; j <= dlugoscCiaguB; j++)
			{
				if ( ciagA[i-1] == ciagB[j-1] ) 
				{
					lcs[i][j] = lcs[i-1][j-1]+1;
				}
				else
				{
					lcs[i][j] = std::max( lcs[i-1][j] , lcs[i][j-1] );
				}
			}
		}
		printf("%d\n", lcs[dlugoscCiaguA][dlugoscCiaguB]);
    }

	return 0;
}