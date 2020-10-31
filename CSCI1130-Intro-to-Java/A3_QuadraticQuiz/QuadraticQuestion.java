package quadraticquiz;

/**
 *
 * @author ***
 * @since 28 October 2020
 */
import java.util.Random;
import javax.swing.JOptionPane;

public class QuadraticQuestion {

    private String qTitle;
    private int numOfRoots;
    private int root1;
    private int root2;
    private int B;
    private int C;

    /**
     * Two real roots question constructor
     *
     * @param title is question tile
     * @param r1 is the first root
     * @param r2 is the second root
     */
    public QuadraticQuestion(String title, int r1, int r2) {
        // out-of-range verification
        if (r1 > 5 || r1 < -5 || r2 > 5 || r2 < -5) {
            root1 = 1;
            root2 = 2;
        } else {
            root1 = r1;
            root2 = r2;
        }

        // assign parameters
        qTitle = title;
        numOfRoots = 2;
        B = -root1 + -root2;
        C = root1 * root2;
    }

    /**
     * Single real root question constructor
     *
     * @param title is the question title
     * @param r is the single real root
     */
    public QuadraticQuestion(String title, int r) {
        // out-of-range verification
        if (r > 5 || r < -5) {
            root1 = 1;
            root2 = 1;
        } else {
            root1 = r;
            root2 = r;
        }

        // assign parameters
        qTitle = title;
        numOfRoots = 1;
        B = -2 * root1;
        C = root1 * root1;
    }

    /**
     * No real root question constructor
     *
     * @param title is the question title
     */
    public QuadraticQuestion(String title) {
        // set roots to out-of-range values
        root1 = -10;
        root2 = -10;

        // assign parameters
        qTitle = title;
        numOfRoots = 0;

        // assign random B and C that combine as a no real root quadratic equation
        do {
            B = nRandom(-10, 10);
            C = nRandom(1, 50);
        } while ((Math.pow(B, 2) - 4 * C) >= 0);
    }

    /**
     * Display input panel and ask for question answer
     *
     * @return answer that is 0, 1, or 2.
     */
    public String getUserInputAnswer() {
        // construct equation string
        String question = "x^2";
        if (B != 0) {
            if (B >= 0) {
                question += String.format("+%dx", B);
            } else {
                question += String.format("%dx", B);
            }
        }
        if (C != 0) {
            if (C >= 0) {
                question += String.format("+%d", C);
            } else {
                question += String.format("%d", C);
            }
        }
        question += " = 0";

        // terminal output
        switch (numOfRoots) {
            case 0:
                System.out.printf("%s, %s real roots.\n", question, numOfRoots);
                break;
            case 1:
                System.out.printf("%s, %s real root: %d\n", question, numOfRoots, root1);
                break;
            default:
                System.out.printf("%s, %s real roots: %d, %d\n", question, numOfRoots, root1, root2);
        }

        // show input panel
        String info = qTitle + ": " + question + ", how many real roots?\n";
        String ans;
        do {
            ans = JOptionPane.showInputDialog(info, "<type answer [0-2] here>");
        } while (ans == null);
        return ans;
    }

    /**
     * compare input string with predetermined number of roots
     *
     * @param ans is the user input
     * @return true if user input is correct, false if wrong
     */
    public boolean checkAnswer(String ans) {
        if (Integer.parseInt(ans) == numOfRoots) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * generate a random number of the range [a, b]
     *
     * @param a is the lower boundary
     * @param b is the upper boundary
     * @return random number
     */
    public int nRandom(int a, int b) {
        long seed = System.currentTimeMillis();
        Random rngObj = new Random(seed);
        return rngObj.nextInt(b - a + 1) + a;
    }
}
