#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


int cal_dp(int start_i, int start_j, int i, int j)
{
	return (i - start_i + 1) * (j - start_j + 1);
}


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
			if(c != '\n')
			{
				value[i][j] = c - '0';
				j++;
				c = getchar();
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

/*		for(int i = 1; i < size+1; i++)
		{
			for(int j = 1; j < size+1; j++)
			{
				cin >> value[i][j];
			}
		}
*/
		//set up dp table
		int dp[size+1][size+1]; //the number of element in the submatrix endpoint at this position.
		int startPoint[size+1][size+1][2];
		memset(dp, 0, sizeof(dp));
		memset(startPoint, 0, sizeof(startPoint));

		//calculate table
		for(int i = 0; i < size+1; i++)
		{
			for(int j = 0; j < size+1; j++)
			{
				if(value[i][j] != 1)
					dp[i][j] = 0;
				else
				{
					if(dp[i-1][j] != 0) //left is 1;
					{
						int start_i, start_j;
						start_i = startPoint[i-1][j][0];
						
						//get startPoint col index
						for(start_j = j; value[i][start_j] == 1 && start_j >= startPoint[i-1][j][1]; start_j--){}
						start_j++;

						//update dp
						int new_dp = cal_dp(start_i, start_j, i, j);
						if(new_dp > dp[i][j])
						{
							dp[i][j] = new_dp;
							startPoint[i][j][0] = start_i;
							startPoint[i][j][1] = start_j;
						}
					}
					if(dp[i][j-1] != 0)
					{
						int start_i, start_j;
						start_j = startPoint[i][j-1][1];
						
						//get startPoint col index
						for(start_i = i; value[start_i][j] == 1 && start_i >= startPoint[i][j-1][0]; start_i--){}
						start_i++;

						//update dp
						int new_dp = cal_dp(start_i, start_j, i, j);
						if(new_dp > dp[i][j])
						{
							dp[i][j] = new_dp;
							startPoint[i][j][0] = start_i;
							startPoint[i][j][1] = start_j;
						}
					}
					if(dp[i-1][j] == 0 && dp[i][j-1] == 0)//up and left are all 0
					{
						startPoint[i][j][0] = i;
						startPoint[i][j][1] = j;
						dp[i][j] = 1;
					}
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
