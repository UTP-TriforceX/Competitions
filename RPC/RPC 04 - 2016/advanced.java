import java.math.BigInteger;
import java.util.Scanner;

public class advanced {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x;
        while (true) {
            x = sc.nextLine();
            if (x.equals("0")) break;
      
            else {
                BigInteger n = new BigInteger(x);
                BigInteger sum = n.add(BigInteger.ONE);
                BigInteger two = new BigInteger("2");
                BigInteger ans = n.multiply(sum);
                ans = ans.divide(two);
                ans = ans.pow(2);
                if (ans.toString().length() > 10) {
                    String s = ans.toString().substring(ans.toString().length()-10);
                    long l = Long.valueOf(s);
                    System.out.println(l);
                }
                else System.out.println(ans);
           }
        }
    }
}
