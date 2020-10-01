import java.util.*;

class Main {
  public static void main(String[] args) {

    System.out.print("Parcel weight (kg): ");

    // your work here
    Scanner scan = new Scanner(System.in);
    float n = scan.nextFloat();
    int fee = 15;
    
    for(float i = 1; i < n;) {
      if(i < 3.0) {
        fee += 5;
        i += 0.5;
      } else if(i < 53.0) {
        fee += 8;
        i += 1.0;
      } else if(i >= 53.0) {
        fee += 15;
        i += 2.0;
      }
    }
    
    System.out.printf("Fee is HK$%d\n", fee);
    System.out.print("Please buy");
    
    int[] face = {50, 10, 2, 1};
    for(int i = 0; i <= 3; i++) {
      int num = fee / face[i];
      fee %= face[i];
      if(num != 0) System.out.printf(", %dx$%d", num, face[i]);
    }
  }
}
