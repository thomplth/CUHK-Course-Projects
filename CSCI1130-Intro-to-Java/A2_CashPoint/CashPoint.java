package exercise;

import javax.swing.*;

/**
 * CashPoint Introduction to Computing: Java Assignment 2
 *
 * @author ***
 * @since 14 October 2020
 */
public class CashPoint {

    private static double balance = 109700.0;

    /**
     * Show a menu of choices and get user's input, given method
     *
     * @return a String of user input: "1","2","3","4", null means Cancel/Close
     */
    public static String showMainMenu() {
        return JOptionPane.showInputDialog("Cash Point: Input your task\n" + "1. Check Balance\n"
                + "2. Cash Deposit\n"
                + "3. Cash Withdrawal\n"
                + "4. Exit\n",
                "<type [1 - 4] here>");
    }

    /**
     * Show the deposit menu for choices and get user's input
     *
     * @return a String of user input in range of "1" to "20" (expected), null
     * means Cancel/Close
     */
    public static String showDepositMenu() {
        return JOptionPane.showInputDialog("Cash Deposit (HKD):\nInput # of $100 banknotes [20 max]\n", "<type [1 - 20] here>");
    }

    /**
     * Show the withdrawal menue for currency check and get user's input
     *
     * @return a String of user input: "1" or "2", null means Cancel/Close
     */
    public static String showWithdrawalMenu() {
        return JOptionPane.showInputDialog("Cash Withdrawal: Choose your currency\n1. Hong Kong Dollar (HKD)\n2. Korean Won (KRW)\n", "<type [1 or 2] here>");
    }

    /**
     * Show a dialog displaying the balance, given method
     */
    public static void checkBalance() {
        // format String before pop up message dialog
        String balance_str = String.format("Balance (HKD): %.2f\n", balance);
        JOptionPane.showMessageDialog(null, balance_str);
    }

    /**
     * Perform deposit function
     */
    public static void deposit() {
        // loop untill valid input or cancel button is pressed
        while (true) {
            String response = showDepositMenu();
            if (response == null) {
                System.out.println("User closed or cancelled deposit dialog box");
                break;
            }
            try {
                int n = Integer.parseInt(response);
                // input check
                if (n >= 1 && n <= 20) {
                    balance += 100 * n;
                    JOptionPane.showMessageDialog(null, "HKD " + 100 * n + " deposited");
                    break;
                } else {
                    invalid();
                }
            } catch (Exception e) {
                // input check (optional)
                invalid();
            }
        }
    }

    /**
     * Perform withdrawal functions
     */
    public static void withdraw() {
        String choice = null;

        // first loop for currency selection
        while (true) {
            String response = showWithdrawalMenu();
            if (response == null) {
                System.out.println("User closed or cancelled withdrawal dialog box");
                break;
            } else if ("1".equals(response)) {
                System.out.println("User choosed HKD");
                choice = "HKD";
            } else if ("2".equals(response)) {
                System.out.println("User choosed KRW");
                choice = "KRW";
            } else {
                invalid();
            }

            // second loop for withdrawal amount input
            while (choice != null) {

                // case (1) withdrawing HKD
                if ("HKD".equals(choice)) {
                    String value = JOptionPane.showInputDialog("Cash Withdrawal (HKD):\n100 min, 10000 max", "<type [amount] here>");
                    if (value == null) {
                        System.out.println("User closed or cancelled input dialog box");
                        break;
                    }
                    try {
                        int n = Integer.parseInt(value);
                        n = n / 100 * 100;
                        if (balance < n) {
                            JOptionPane.showMessageDialog(null, "Not enough balance, input again");
                        } else if (n >= 100 && n <= 10000) {
                            // withdrawal confirmation (HKD)
                            int reply = JOptionPane.showConfirmDialog(null, "Banknotes provided for HKD are 500 & 100\nWithdraw HKD " + n + " or not?", null, JOptionPane.YES_NO_OPTION);
                            if (reply == JOptionPane.YES_OPTION) {
                                int n500 = n / 500;
                                int n100 = n % 500 / 100;
                                String message = String.format("HKD %d withdrawn\n", n);
                                if (n500 != 0) {
                                    message += "HKD 500 x " + n500 + "\n";
                                }
                                if (n100 != 0) {
                                    message += "HKD 100 x " + n100 + "\n";
                                }
                                JOptionPane.showMessageDialog(null, message);
                                balance -= n;
                                return;
                            }
                        } else {
                            invalid();
                        }
                    } catch (Exception e) {
                        // input check (optional)
                        invalid();
                    }
                } // case (2) withdrawing KRW
                else if ("KRW".equals(choice)) {
                    String value = JOptionPane.showInputDialog("Cash Withdrawal (KRW):\n1000 min, 200000 max", "<type [amount] here>");
                    if (value == null) {
                        System.out.println("User closed or cancelled input dialog box");
                        break;
                    }
                    try {
                        int n = Integer.parseInt(value);
                        n = n / 1000 * 1000;
                        if (balance < n / 150.0) {
                            JOptionPane.showMessageDialog(null, "Not enough balance, input again");
                        } else if (n >= 1000 && n <= 200000) {
                            // withdrawal confirmation (KRW)
                            String info = String.format("Banknotes provided for KRW are 10000 & 1000\nWithdraw KRW %d (HKD %.2f) or not?", n, n / 150.0);
                            int reply = JOptionPane.showConfirmDialog(null, info, null, JOptionPane.YES_NO_OPTION);
                            if (reply == JOptionPane.YES_OPTION) {
                                int n10000 = n / 10000;
                                int n1000 = n % 10000 / 1000;
                                String message = String.format("KRW %d withdrawn\n", n);
                                if (n10000 != 0) {
                                    message += "KRW 10000 x " + n10000 + "\n";
                                }
                                if (n1000 != 0) {
                                    message += "KRW 1000 x " + n1000 + "\n";
                                }
                                JOptionPane.showMessageDialog(null, message);
                                balance -= n / 150.0;
                                return;
                            }
                        } else {
                            invalid();
                        }
                    } catch (Exception e) {
                        // input check (optional)
                        invalid();
                    }
                }
            }
        }
    }

    /**
     * Show message dialog to indicate invalid input
     */
    public static void invalid() {
        JOptionPane.showMessageDialog(null, "Invalid input");
    }

    /**
     * main() method, starting point of the Java application
     *
     * @param args are command line arguments in a string array
     */
    public static void main(String[] args) {
        String choice;
        // repeatedly call showMainMenu() and process user requests
        while (true) {
            choice = showMainMenu();
            if (choice == null) // end (1) if cancel button is clicked
            {
                System.out.println("User cancelled dialog box");
                break;
            } else if ("1".equals(choice)) // check balance option
            {
                System.out.println("User picked 1");
                checkBalance();
            } else if ("2".equals(choice)) // deposit option
            {
                System.out.println("User picked 2");
                deposit();
            } else if ("3".equals(choice)) // withdrawal option
            {
                System.out.println("User picked 3");
                withdraw();
            } else if ("4".equals(choice)) // end (2) if user input 4
            {
                System.out.println("User closed dialog box");
                JOptionPane.showMessageDialog(null, "Hope to serve you again");
                break;
            } else // other inputs are treated as invalid
            {
                invalid();
            }
        }
    }
}
