import java.util.*;

class Main {
 public static void main(String args[]){
   long a = 0L;
   long b = 1L;
   long temp = 0L;
   
   Scanner scan = new Scanner(System.in);
   System.out.println("Input:");
   int n = scan.nextInt();
   int m = scan.nextInt();
   System.out.println("Output:");
   
   if(n <= 0) System.out.print("0 ");
   if(n <= 1) System.out.print("1 ");
   
   for(int i = 2; i <= m; i++) {
     temp = a + b;
     a = b;
     b = temp;
     
     if(i >= n)
      System.out.print(b + " ");
   }
  
 }
 
}
