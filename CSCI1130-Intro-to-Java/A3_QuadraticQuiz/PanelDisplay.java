package quadraticquiz;

import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * PanelDisplay for keeping and displaying score and hint
 *
 * @author ***, ***
 */
public class PanelDisplay {

    final private JFrame window;
    // private PieDrawing hintFigure;
    final private JLabel scoreLabel;
    private int score;

    /**
     * Constructor of PanelDisplay
     */
    public PanelDisplay() {
        score = 0;

        window = new JFrame("Score Board");

        JLabel scoreTitle = new JLabel("<html><h1 style='color:red;'>Score</h1></html>");
        scoreTitle.setBounds(20, 0, 150, 100);
        window.getContentPane().add(scoreTitle);

        scoreLabel = new JLabel("<html><h2 style='color:blue;'>&nbsp;&nbsp;&nbsp;&nbsp;" + score + " / 6" + "</h2></html>");
        scoreLabel.setBounds(20, 0, 100, 100);
        window.getContentPane().add(scoreLabel);

        window.setSize(250, 200);
        window.setLocation(50, 20);
        window.setVisible(true);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    /**
     * get score displayed in panel
     *
     * @return an integer of score
     */
    public int getScore() {
        return score;
    }

    /**
     * set score to be displayed in panel
     *
     * @param newScore an integer of score to be set
     */
    public void setScore(int newScore) {
        //System.out.println(this.getClass().getSimpleName() + " instance method setScore(" + newScore + ")");
        score = newScore;
        scoreLabel.setText("<html><h2 style='color:blue;'>&nbsp;&nbsp;&nbsp;&nbsp;" + +score + " / 6" + "</h2></html>");
    }

}
