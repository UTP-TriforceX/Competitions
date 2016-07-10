import java.math.BigInteger;
import java.util.Scanner;

public class dividing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x;
        
        while (sc.hasNext()) {
            x = sc.nextLine();
            BigInteger bi = new BigInteger(x, 16);
            BigInteger a = new BigInteger("17");
        
            if (bi.mod(a) == BigInteger.ZERO) {
                System.out.println("yes");
            }
        
            else System.out.println("no");
        }
    }
}
