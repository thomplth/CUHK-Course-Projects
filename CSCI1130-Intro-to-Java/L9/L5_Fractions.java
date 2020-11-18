import java.util.Scanner;
// let's complete the class Fraction here
class Fraction {
    // define your fields, constructor and more instance methods here
    private int numerator;
    private int denominator;

    // YOUR CODE HERE
    public Fraction(int n, int d) {
      numerator = n;
      denominator = d;
    }

    public String printString() {
      simplify(this);
      return this.numerator + "/" + this.denominator;
    }
    
    public Fraction multiplyBy(Fraction f) {
      this.numerator *= f.numerator;
      this.denominator *= f.denominator;
      simplify(this);
      return this;
    }
    
    private void simplify(Fraction f) {
      int g = gcd(f.numerator, f.denominator);
      f.numerator /= g;
      f.denominator /= g;
    }
    
    public static int gcd(int x, int y) {
    // The following implements the Euclidean Algorithm for finding GCD
    // See: https://en.wikipedia.org/wiki/Euclidean_algorithm
      while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
      }
    return x;
    }
}

class Main {
    public static void main(String[] args) {
      
    // Do not touch the following lines
    //
    Scanner keyin = new Scanner(System.in);
    System.out.println("a? b? c? d?");
    int a, b, c, d;
    a = keyin.nextInt();
    b = keyin.nextInt();
    c = keyin.nextInt();
    d = keyin.nextInt();

    Fraction r, q, result;
    r = new Fraction(a, b);
    q = new Fraction(c, d);
    
    System.out.print(r.printString() + " x " + q.printString() + " = ");
    result = r.multiplyBy(q);
    System.out.println( result.printString() );
    // The End
  }
}

/*
 import java.util.Scanner;

 // let's complete the class Fraction here
 class Fraction {
     // define your fields, constructor and more instance methods here
     private int a, b;
     public Fraction() {
       a = 1; b = 2;
     }
     
     public Fraction(int x, int y) {
       a = x;
       b = y;
       simplify();
     }
     
     public String printString() {
       return (a+"/"+b);
     }
     
     public Fraction multiplyBy(Fraction second) {
       Fraction result = new Fraction();
       result.a = this.a * second.a;
       result.b = this.b * second.b;
       Fraction.simplify(result);
  //     result.simplify();
       return result;
     }

     // requirement in the question to make this a class method
     private static void simplify(Fraction q) {
       int gcf = Fraction.gcd(q.a, q.b);
       q.a /= gcf;
       q.b /= gcf;
     }
     
     // usual OO way using instance method
     private void simplify() {
       int gcf = Fraction.gcd(this.a, this.b);
       this.a /= gcf;
       this.b /= gcf;
     }
     
     // The following implements the Euclidean Algorithm for finding GCD
     // See: https://en.wikipedia.org/wiki/Euclidean_algorithm
     private static int gcd(int x, int y) {
       while (y != 0) {
         int tmp = y;
         y = x % y;
         x = tmp;
       }
       return x;
     }
 }

 class Main {
     public static void main(String[] args) {
       
     // Do not touch the following lines
     //
     Scanner keyin = new Scanner(System.in);
     System.out.println("a? b? c? d?");
     int a, b, c, d;
     a = keyin.nextInt();
     b = keyin.nextInt();
     c = keyin.nextInt();
     d = keyin.nextInt();

     Fraction r, q, result;
     r = new Fraction(a, b);
     q = new Fraction(c, d);
     
     System.out.print(r.printString() + " x " + q.printString() + " = ");
     result = r.multiplyBy(q);
     System.out.println( result.printString() );
     // The End
   }
 }
 */
