import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String input = scan.nextLine();
    int len = input.length();
    boolean isPalindrome = true;
    for(int i = 0; i < len/2; i++) {
      if(input.charAt(i) != input.charAt(len-1-i))
        isPalindrome = false;
    }
    if(isPalindrome)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
