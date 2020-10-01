import java.util.Scanner;

/**
 * Perimeter of Circle, in the only, Main class.
 */
class Main {
  // main method with standard properties
  public static void main(String[] args) {
    // declare a keyboard variable of type Scanner
    Scanner keyboard;
    // create a new Scanner object, named keyboard
    keyboard = new Scanner(System.in);
    
    // declare an integer variable named radius
    int radius;
    
    System.out.print("Input: ");
    // read from the user an integer through the keyboard, store the value in radius
    radius = keyboard.nextInt();
    
    // TO DO: student's work here...
    double perimeter = 2 * Math.PI * radius;
    
    System.out.printf("The perimeter is %.3f\nBye", perimeter);
  }
}

