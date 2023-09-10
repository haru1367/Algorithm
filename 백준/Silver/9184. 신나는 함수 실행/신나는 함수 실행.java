import java.util.Scanner;
public class Main {
    static long[][][] dp = new long[21][21][21];

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       for (int i = 0; i<= 20; i++) {
           for (int j = 0; j<=20; j++) {
               for (int k = 0; k<=20; k++) {
                   if (i<=0 || j<=0 || k <= 0) {
                       dp[i][j][k]= 1;
                   } else if (i<j && j<k) {
                       dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                   } else {
                       dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                   }
               }
           }
       }
        while (true) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c= sc.nextInt();
            if (a == b && b == c && a == -1) {
                break;
            }
            System.out.print(String.format("w(%d, %d, %d) = ",a,b,c));
            if (a<= 0 || b<=0 || c<=0) {
                a = 0;
                b =0;
                c = 0;
            }
            if (a>20 || b>20 || c>20) {
                a = 20;
                b= 20;
                c= 20;
            }
            System.out.print(dp[a][b][c]);
            System.out.println();
        }
    }
}