import java.util.Scanner;
import java.math.BigInteger;
public class Main{
    public static void main(String[] args) {
        Scanner scr=new Scanner(System.in);
        while(true){
            int n=scr.nextInt();
            int d=scr.nextInt();
            if(n+d==0)
                break;
            BigInteger x=BigInteger.valueOf(n);
            x=x.pow(d);
            System.out.println(x);
            }
        }
    }
