#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


int main()
{
	int caseNum;
	cin >> caseNum;
	while(caseNum-- > 0)
	{
		int size = 25;

	

		//set up value table
		int value[size+1][size+1];
		memset(value, 0, sizeof(value));
		
		bool case_finish = false;
		char c;
		int i = 1, j = 1;
		//skip whitespace
		c = getchar();
		while(isspace(c))
		{
			c = getchar();
		}
		while(case_finish != true)
		{
			if(c == -1)
				break;
			if(c != '\n')
			{
				if(i > size || j > size)
				{
					int ii;
					ii = 0;
					ii++;
				}
				else{
				value[i][j] = c - '0';
				j++;
				c = getchar();
				}
			}
			else
			{
				c = getchar();
				if(c == '\n')
				{
					case_finish == true;
					break;
				}
				else
				{
					i++;
					j = 1;
				}
			}
		}

		//set up dp table
		int dp[size+1][size+1]; //the number of element in the submatrix endpoint at this position.
		int startPoint[size+1][size+1][2];
		int maxH[size+1][size+1];
		memset(dp, 0, sizeof(dp));
		memset(startPoint, 0, sizeof(startPoint));

		//calculate highest size of 1 column "1" rect.
		for(int i = 0; i < size+1; i++)
			for(int j = 0; j < size+1; j++)
			{	
				if(value[i][j] == 0)
					maxH[i][j] = 0;
				else
					maxH[i][j] = maxH[i-1][j] + 1;
			}

		//calculate table
		for(int i = 0; i < size+1; i++)
		{
			for(int j = 0; j < size+1; j++)
			{
				if(value[i][j] == 0)
					dp[i][j] = 0;
				else // value[i][j] == 1
				{
					int height = 0x0fff;
					int start_j = j;
					int sum = 0;
					while(maxH[i][start_j] != 0)
					{
						if(maxH[i][start_j] < height)
						{
							height = maxH[i][start_j];
						}
						int candidate = (j - start_j + 1)* height;
						if(candidate > sum)
							sum = candidate;
						start_j--;
					}
					dp[i][j] = sum;
				}
			}
		}
		
		//get result
		int max_num = 0;
		for(int i = 1; i < size+1; i++)
		{
			for(int j = 1; j < size+1; j++)
				if(dp[i][j] > max_num)
					max_num = dp[i][j];
		}
		cout << max_num << "\n";
		if(caseNum != 0)
			cout << "\n";

	}
	return 0;
}
