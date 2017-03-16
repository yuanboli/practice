import java.util.Scanner;

class Main{
	static void main(String argv[]){
		Scanner scan = new Scanner(System.in);
		int n;
		n = scan.nextInt();
		scan.nextLine();
		while(n != -1){
			/*content*/
			
			//scan table p
			double[][] p = new double[n+1][n+1];
			for(int i = 1; i < n+1; i++){
				for(int j = 1; j < n+1; j++){
					p[i][j] = scan.nextDouble();
				}
				scan.nextLine();
			}
			
			//calculate dp
			double[][] dp = new double[n+1][(1 << n) + 1];
			for(int i = 1; i < n + 1; i++){
				for(int j = 1; j < (1 << n) + 1; j++){
					if(j <= (1 << (n-1))){
						double sum = 0;
						for(int k = 1 + (1<<(n-1)); k < 1 + (1<<n); k++){
							sum += p[i-1][k];
						}
						dp[i][j] = dp[i-1][j] * sum;
					}else{
						double sum = 0;
						for(int k = 1; k < 1 + (1<<(n-1); k++){
							sum += p[i-1][k];
						}
						dp[i][j] = dp[i-1][j] * sum;
					}
				}
			}
			
			//find solution
			int maxIndex = 0, maxValue = 0;
			for(int i = 1; i < (1 << n) + 1; i++){
				if(p[n][i] > maxValue){
					maxIndex = i;
				}
			}
			System.out.println(maxIndex);
			
			/*content finish*/
			n = scan.nextInt();
			scan.nextLine();
		}
	}
}