import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        String X;
        Scanner sc = new Scanner(System.in);
        X = sc.nextLine();
        String str = X;
        int count = 0;
        while (true) {
            int num =0;
            for (int i = 0; i<str.length(); i++) {
                num += str.charAt(i)-48;
            }
            if (num <10) {
                if (X.length() ==1) {
                    System.out.println(0);
                } else {
                    System.out.println(count+1);
                }
                if (num%3 == 0) System.out.println("YES");
                else System.out.println("NO");
                break;
            }
            str = ""+num;
            count++;
        }
    }
}