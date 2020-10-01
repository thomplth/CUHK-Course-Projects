import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner keyboard = new Scanner(System.in);
    long factorial = 1L;
    int n;
    System.out.print("Input: ");
    n = keyboard.nextInt();
    
    // code here ...
    for(int i = 1; i <= n; i++ )
      factorial *= i;
    
    System.out.print("The factorial is " + factorial);
  }
}
