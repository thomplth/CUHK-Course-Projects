package exercise;

import javax.swing.JFrame;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.concurrent.TimeUnit;

/**
 * shakyDisplay Introduction to Computing: Java Assignment
 *
 * @author ***
 * @since 14 September 2020
 */
public class ShakyDisplay extends JFrame implements ActionListener {

    // instance fields
    protected int width, height;
    protected JButton buttons[][];

    // default constructor 
    public ShakyDisplay() {
        width = 20;
        height = 10;
        initDisplay();
    }

    // constructor with given width and height of the ShakyDisplay object 
    public ShakyDisplay(int w, int h) {
        width = w;
        height = h;
        initDisplay();
    }

    // initialize the ShakyDisplay window 
    public final void initDisplay() {
        try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
        } catch (ClassNotFoundException |
                 IllegalAccessException |
                 InstantiationException |
                 UnsupportedLookAndFeelException exceptionobject) {
        }

        setTitle("Java Shaky Display");
        setLayout(new GridLayout(height, width));
        buttons = new JButton[height][width];
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++) {
                buttons[row][col] = new JButton(row + ", " + col);
                buttons[row][col].setMargin(new Insets(1, 1, 1, 1));
                buttons[row][col].addActionListener(this);
                add(buttons[row][col]);
                if (row == height - 1) {
                    buttons[row][col].setForeground(Color.RED);
                }
            }
        setSize(width * 45, height * 45);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    // change button text color on user clicks
    @Override
    public void actionPerformed(ActionEvent eventObject) {
        JButton target = (JButton) (eventObject.getSource());
        if (target.getForeground() == Color.GREEN) {
            target.setForeground(Color.BLUE);
        } else if (target.getForeground() == Color.BLUE) {
            target.setForeground(null);
            shake();
        } else {
            target.setForeground(Color.GREEN);
        }
    }

    // slow down this process by sleeping this thread 
    private void delay(long sleepInMS) {
        try {
            TimeUnit.MILLISECONDS.sleep(sleepInMS);
        } catch (InterruptedException exceptionObject) {
            Thread.currentThread().interrupt();
        }
    }

    // shake the shakvpi splay
    private void shake() {
        Point windowLocation = getLocation();

        double round = 5, max_radius = 10, step = 100;

        double limit = 2 * Math.PI * round;
        double angle_increment = limit / step;
        double radius_increment = max_radius / step;

        for (double angle = 0, radius = 0;
                angle < limit;
                angle += angle_increment, radius += radius_increment) {
            setLocation((int) (Math.cos(angle) * radius) + windowLocation.x,
                        (int) (Math.sin(angle) * radius) + windowLocation.y);
            this.delay(6);
        }
        this.setLocation(windowLocation);
    }

    // *** TO DO: students should customize this method ***
    // - to show your PROJECT CREATION TIME in HH:MM in 24-hour format in YELLOW
    // - AND to show your SURNAME char-by-char as button text on the bottom
    public void showmyinfo() {
        // target: "12:28"
        // digit: 1 in YELLOW
        buttons[1][4].setBackground(Color.YELLOW);
        buttons[2][4].setBackground(Color.YELLOW);
        buttons[3][4].setBackground(Color.YELLOW);
        buttons[4][4].setBackground(Color.YELLOW);
        buttons[5][4].setBackground(Color.YELLOW);
        buttons[6][4].setBackground(Color.YELLOW);
        buttons[7][4].setBackground(Color.YELLOW);
        
        // digit: 2 in YELLOW
        buttons[1][10].setBackground(Color.YELLOW);
        buttons[2][10].setBackground(Color.YELLOW);
        buttons[3][10].setBackground(Color.YELLOW);
        buttons[4][10].setBackground(Color.YELLOW);
        buttons[5][7].setBackground(Color.YELLOW);
        buttons[6][7].setBackground(Color.YELLOW);
        buttons[7][10].setBackground(Color.YELLOW);

        buttons[1][7].setBackground(Color.YELLOW);
        buttons[1][8].setBackground(Color.YELLOW);
        buttons[1][9].setBackground(Color.YELLOW);
        buttons[4][7].setBackground(Color.YELLOW);
        buttons[4][8].setBackground(Color.YELLOW);
        buttons[4][9].setBackground(Color.YELLOW);
        buttons[7][7].setBackground(Color.YELLOW);
        buttons[7][8].setBackground(Color.YELLOW);
        buttons[7][9].setBackground(Color.YELLOW);
        
        // colon in YELLOW
        buttons[2][14].setBackground(Color.YELLOW);
        buttons[6][14].setBackground(Color.YELLOW);
        
        // digit: 2 in YELLOW
        buttons[1][21].setBackground(Color.YELLOW);
        buttons[2][21].setBackground(Color.YELLOW);
        buttons[3][21].setBackground(Color.YELLOW);
        buttons[4][21].setBackground(Color.YELLOW);
        buttons[5][18].setBackground(Color.YELLOW);
        buttons[6][18].setBackground(Color.YELLOW);
        buttons[7][21].setBackground(Color.YELLOW);

        buttons[1][18].setBackground(Color.YELLOW);
        buttons[1][19].setBackground(Color.YELLOW);
        buttons[1][20].setBackground(Color.YELLOW);
        buttons[4][18].setBackground(Color.YELLOW);
        buttons[4][19].setBackground(Color.YELLOW);
        buttons[4][20].setBackground(Color.YELLOW);
        buttons[7][18].setBackground(Color.YELLOW);
        buttons[7][19].setBackground(Color.YELLOW);
        buttons[7][20].setBackground(Color.YELLOW);
        
        // digit: 8 in YELLOW
        buttons[1][24].setBackground(Color.YELLOW);
        buttons[2][24].setBackground(Color.YELLOW);
        buttons[3][24].setBackground(Color.YELLOW);
        buttons[4][24].setBackground(Color.YELLOW);
        buttons[5][24].setBackground(Color.YELLOW);
        buttons[6][24].setBackground(Color.YELLOW);
        buttons[7][24].setBackground(Color.YELLOW);
        
        buttons[1][27].setBackground(Color.YELLOW);
        buttons[2][27].setBackground(Color.YELLOW);
        buttons[3][27].setBackground(Color.YELLOW);
        buttons[4][27].setBackground(Color.YELLOW);
        buttons[5][27].setBackground(Color.YELLOW);
        buttons[6][27].setBackground(Color.YELLOW);
        buttons[7][27].setBackground(Color.YELLOW);
        
        buttons[1][25].setBackground(Color.YELLOW);
        buttons[1][26].setBackground(Color.YELLOW);
        buttons[4][25].setBackground(Color.YELLOW);
        buttons[4][26].setBackground(Color.YELLOW);
        buttons[7][25].setBackground(Color.YELLOW);
        buttons[7][26].setBackground(Color.YELLOW);

        // example name: NAME
        int c = 0;
        buttons[height - 1][c++].setText("L");
        buttons[height - 1][c++].setText("A");
        buttons[height - 1][c++].setText("M");
        buttons[height - 1][c++].setText(" ");
        buttons[height - 1][c++].setText("T");
        buttons[height - 1][c++].setText("A");
        buttons[height - 1][c++].setText("K");
        buttons[height - 1][c++].setText(" ");
        buttons[height - 1][c++].setText("H");
        buttons[height - 1][c++].setText("I");
        buttons[height - 1][c++].setText("N");
        buttons[height - 1][c++].setText("G");
    }

    /**
     * main() method, starting point of the Java application
     *
     * @param args are command line arguments in a string array
     */
    public static void main(String[] args) {
        ShakyDisplay dpy;
        // may change this line to create a shakyDi spl ay of different size
        dpy = new ShakyDisplay(30, 10);
        dpy.showmyinfo();
    }
}
