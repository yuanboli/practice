import java.util.*;
class Solution{
	public static void main(String[] argv){
		int testNum;
		Scanner scan = new Scanner(System.in);
		testNum = scan.nextInt();
		scan.nextLine();
		while(testNum > 0){
		
		/*content*/
		//get string
		String str = scan.nextLine();
		
		//init
		int strLen = str.length();
		int dp[][] = new int[strLen+1][strLen+1];
		for(int i = 0; i < strLen + 1; i++)
			for(int j = 0; j < strLen + 1; j++)
				dp[i][j] = -1;

		//calculate dp
		for(int i = 1; i < strLen + 1; i++){
			for(int j = 1; j < strLen + 1; j++){
				getDp(i, j, str, dp);
			}
		}

		//print result
		System.out.println(dp[1][strLen]);
		/*content finish*/

		//loop counter update.
		testNum--;
		}
		scan.close();
	}


	private static int getDp(int i, int j, String str, int[][] dp){
		
		//have not calculated before
		if(i > j)
			return 0;
		if(dp[i][j] == -1){
			if(i == j){
				dp[i][j] = 1;
			}else if(str.charAt(i-1) == str.charAt(j-1)){
				dp[i][j] = 1 + getDp(i+1, j, str, dp) + getDp(i, j-1, str, dp);
			}else{
				dp[i][j] = getDp(i+1, j, str, dp) + getDp(i, j-1, str, dp) - getDp(i+1, j-1, str, dp);
			}
		}
		return dp[i][j];
	}
}
