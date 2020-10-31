package quadraticquiz;

import java.util.Random;

/**
 * QuadraticQuiz Introduction to Computing: Java Assignment 3
 *
 * @author ***
 * @since 28 October 2020
 */
public class QuadraticQuiz {

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

    /**
     * main() method, starting point of the Java application
     *
     * @param args are command line arguments
     */
    public static void main(String[] args) {

        // Trial Questions
        // create and store new objects
        PanelDisplay panel = new PanelDisplay();
        QuadraticQuestion T1 = new QuadraticQuestion("Trial 1", -2, 2);
        QuadraticQuestion T2 = new QuadraticQuestion("Trial 2", -1);
        QuadraticQuestion T3 = new QuadraticQuestion("Trial 3", 5, 0);

        // send messages to objects
        T1.getUserInputAnswer();
        T2.getUserInputAnswer();
        T3.getUserInputAnswer();

        // Actual Questions
        // create and store new objects
        QuadraticQuestion question;
        String answer;
        
        // random number generator
        long seed = System.currentTimeMillis();
        Random rngObj = new Random(seed);

        for (int i = 1; i <= 6; i++) {
            int nRoots = (int) (Math.random() * 3); // range [0, 2]
            switch (nRoots) {
                case 0:
                    question = new QuadraticQuestion("Q" + i);
                    break;
                case 1:
                    question = new QuadraticQuestion("Q" + i, rngObj.nextInt(11) - 5);
                    break;
                default:
                    question = new QuadraticQuestion("Q" + i, rngObj.nextInt(11) - 5, rngObj.nextInt(11) - 5);
            }

            // send messages to objects
            answer = question.getUserInputAnswer();
            if (question.checkAnswer(answer)) {
                panel.setScore(panel.getScore() + 1);
            }
        }

        System.out.println("The End");
    }
}
