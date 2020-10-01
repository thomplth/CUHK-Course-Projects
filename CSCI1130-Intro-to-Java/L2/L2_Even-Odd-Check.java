import java.util.*;

class Main {
  public static void main(String[] args) {

    Scanner keyboard = new Scanner(System.in);
    int i, j, sol;
    System.out.print("Input first number: ");
    i = keyboard.nextInt();
    System.out.print("Input second number: ");
    j = keyboard.nextInt();
    
    sol = i + j;
    sol %= 2;
    
    // code here...
    // Student should change this line.
    if(sol == 0)
      System.out.println("Sum is even.");
    else
      System.out.println("Sum is odd.");
  }
}
