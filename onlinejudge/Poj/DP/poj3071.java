import java.util.Scanner;

class Main{
	public static void main(String argv[]){
		Scanner scan = new Scanner(System.in);
		int n;
		n = scan.nextInt();
		scan.nextLine();
		while(n != -1){
			/*content*/
			
			//scan table p
			double[][] p = new double[(1<<n)+1][(1<<n)+1];
			for(int i = 1; i < (1<<n)+1; i++){
				for(int j = 1; j < (1<<n)+1; j++){
					p[i][j] = scan.nextDouble();
				}
				scan.nextLine();
			}
			
			
			
			double[][] dp = new double[n+1][(1 << n) + 1];
			
			for(int i = 0; i < (1<<n)+1; i++){
				p[i][0] = 1;
				if(i < n+1)
					dp[i][0] = 1;
				p[0][i] = 1;
				dp[0][i] = 1;
			}

			
			//calculate dp
			for(int i = 1; i < n + 1; i++){
				for(int j = 1; j < (1 << n) + 1; j++){
					if(i == 1){
						if(j % 2 == 1){	//first team
							dp[i][j] = p[j][j+1];
						}else{ //second team
							dp[i][j] = p[j][j-1];
						}
					}
					else{
						/*calculate sum*/
						int sec_num = (j - 1) / (1 << i);
						int sec_len = 1 << i;
						int position = (j - 1) % (1 << i);
						double sum = 0;
						if(position + 1 <= (1 << (i-1))){
							//in the first half
							for(int index = 1; index < (1 << (i-1))+1; index++){
								int secondTeam = sec_num * sec_len + index + sec_len/2;
								sum += dp[i-1][secondTeam] * p[j][secondTeam];
							}
						}else{
							//in the second half
							for(int index = 1; index < (1 << (i-1))+1; index++){
								int secondTeam = sec_num * sec_len + index;
								sum += dp[i-1][secondTeam] * p[j][secondTeam];
							}
						}
						
						
						/*calculate dp*/
						dp[i][j] = dp[i-1][j] * sum;
					}
					/*
					if(j <= (1 << (n-1))){
						double sum = 0;
						
						for(int k = 1 + (1<<(n-1)); k < 1 + (1<<n); k++){
							sum += p[i-1][k];
						}
						dp[i][j] = dp[i-1][j] * sum;
					}else{
						double sum = 0;
						for(int k = 1; k < 1 + (1<<(n-1)); k++){
							sum += p[i-1][k];
						}
						dp[i][j] = dp[i-1][j] * sum;
					}*/
				}
			}
			
//			printMatrix(dp, 1+n, 1+(1<<n));
			
			
			//find solution
			int maxIndex = 0; 
			double maxValue = 0;
			for(int i = 1; i < (1 << n) + 1; i++){
				if(dp[n][i] > maxValue){
					maxIndex = i;
					maxValue = dp[n][i];
				}
			}
			System.out.println(maxIndex);
			
			/*content finish*/
			n = scan.nextInt();
			scan.nextLine();
		}
	}

/*
	public static void printMatrix(double[][] matrix, int rowNum, int colNum){
		for(int i = 0; i < rowNum; i++){
			for(int j = 0; j < colNum; j++){
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
*/
}
