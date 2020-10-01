import java.util.*;

class Main {
  public static void main(String[] args) {
    System.out.println("Input Your Month Salary: ");
    Scanner keyboard = new Scanner(System.in);
    int mc = keyboard.nextInt();
    int sol = 0;
    if(mc <= 30000 && mc >= 7100)
      sol = (int) Math.round(mc * 0.05);
    else if(mc > 30000)
      sol = 1500;
    else if(mc < 7000)
      sol = 0;
    System.out.println("Monthly Mandatory Contribution: \n" + sol);
  }
}
