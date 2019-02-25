import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Main {
    public static  long gcd(long x,long y){
        if(y==0)return  x;
        return  gcd(y,x%y);
    }
    public static void main(String[] args) throws FileNotFoundException {
            int cas=1;
            File file=new File("C:\\Users\\Nuhash\\Desktop\\untitled1\\src");
            //File file1=new File("out.txt");
            Scanner scanner=new Scanner(System.in);
            while (true){
                int n=scanner.nextInt();
                if(n==-1)break;
                String tmp=scanner.nextLine();
                //String tmp=x.toString();
                double x=Double.valueOf(tmp);
                String tmp1=tmp.substring(3);
                int k=tmp1.length()-n;
                if(n>0){
                    double xx= Math.pow(10,tmp1.length())-Math.pow(10,k);
                    double yy= Math.pow(10,tmp1.length())*x-Math.pow(10,k)*x;
                    long t1=(long)Math.ceil(xx);
                    long t2=(long)Math.ceil(yy);
                    long gg=gcd(t1,t2);
                    t1/=gg;
                    t2/=gg;
                    System.out.println("Case "+cas+": "+t2+"/"+t1);
                }
                else{
                    double xx=(Math.pow(10,tmp1.length()));
                    long yy=Integer.valueOf(tmp1);
                    long t=(long)xx;
                    long gg=gcd(t,yy);
                    t/=gg;
                    yy/=gg;
                    System.out.println("Case "+cas+": "+yy+"/"+t);
                }
                cas++;
            }
        }

}
