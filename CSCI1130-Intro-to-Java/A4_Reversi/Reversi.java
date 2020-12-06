package reversi;

import java.awt.Color;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

/**
 * CSCI1130 Java Assignment
 * Reversi board game
 * 
 * Date        : 02 December 2020
 * 
 * @author based on skeleton code provided by ***
 */
public class Reversi {

    // pre-defined class constant fields used throughout this app
    public static final int BLACK = -1;
    public static final int WHITE = +1;
    public static final int EMPTY =  0;
    
    // a convenient constant field that can be used by students
    public final int FLIP  = -1;
    
    // GUI objects representing and displaying the game window and game board
    protected JFrame window;
    protected ReversiPanel gameBoard;
    protected Color boardColor = Color.GREEN;

    
    // a 2D array of pieces, each piece can be:
    //  0: EMPTY/ unoccupied/ out of bound
    // -1: BLACK
    // +1: WHITE
    protected int[][] pieces;
    
    
    // currentPlayer:
    // -1: BLACK
    // +1: WHITE
    protected int currentPlayer;

    
    
    // STUDENTS may declare other fields HERE
    protected boolean blackPassed = false;
    protected boolean whitePassed = false;
    
    
    
    /**
     * The only constructor for initializing a new board in this app
     */
    public Reversi() {
        window = new JFrame("Reversi");
        gameBoard = new ReversiPanel(this);
        window.add(gameBoard);
        window.setSize(850, 700);
        window.setLocation(100, 50);
        window.setVisible(true);
        
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // use of implicitly extended inner class with overriden method, advanced stuff
        window.addWindowListener(
            new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e)
                {
                    sayGoodbye();
                }
            }
        );


        // a 8x8 board of pieces[1-8][1-8] surrounded by an EMPTY boundary of 10x10 
        pieces = new int[10][10];
        
        pieces[4][4] = WHITE;
        pieces[4][5] = BLACK;
        pieces[5][4] = BLACK;
        pieces[5][5] = WHITE;

        currentPlayer = BLACK;  // black plays first
        
        gameBoard.updateStatus(pieces, currentPlayer);
    }

    
    
    /**
     * setupDebugBoard for testing END-game condition
     * students can freely make any changes to this method for testing purpose
     * TEMPORARY testing case
     */
    protected void setupDebugBoardEndGame()
    {
        gameBoard.addText("setupDebugBoardEndGame():");

        for (int row = 1; row <= 8; row++)
            for (int col = 1; col <= 8; col++)
                pieces[row][col] = BLACK;
        pieces[5][8] = WHITE;
        pieces[6][8] = EMPTY;
        pieces[7][8] = EMPTY;
        pieces[8][8] = EMPTY;

        currentPlayer = BLACK;  // BLACK plays first
        
        gameBoard.updateStatus(pieces, currentPlayer);
    }


    
    /**
     * setupDebugBoard for testing MID-game condition
     * students can freely make any changes to this method for testing purpose
     * TEMPORARY testing case
     */
    protected void setupDebugBoardMidGame()
    {
        gameBoard.addText("setupDebugBoardMidGame():");

        int row, col, distance;
        
        // make all pieces EMPTY
        for (row = 1; row <= 8; row++)
            for (col = 1; col <= 8; col++)
                pieces[row][col] = EMPTY;
        
        // STUDENTS' TEST and EXPERIMENT
        // setup a star pattern as a demonstration, you may try other setups
        // relax, we will NOT encounter array index out of bounds, see below!!
        row = 5;
        col = 3;
        distance = 3;
        
        // beware of hitting the boundary or ArrayIndexOutOfBoundsException
        for (int y_dir = -1; y_dir <= +1; y_dir++)
            for (int x_dir = -1; x_dir <= +1; x_dir++)
            {
                try {
                    int move;
                    // setup some opponents
                    for (move = 1; move <= distance; move++)
                        pieces[row + y_dir * move][col + x_dir * move] = BLACK;

                    // far-end friend piece
                    pieces[row+y_dir * move][col + x_dir*move] = WHITE;
                }
                catch (ArrayIndexOutOfBoundsException e)
                {
                    // intentionally do nothing in this catch block
                    // this is simple and convenient in guarding array OOB
                }
            }
        // leave the center EMPTY for the player's enjoyment
        pieces[row][col] = EMPTY;
        
        // pieces[row][col] = 999;  // try an invalid piece

        
        // restore the fence of 10x10 EMPTY pieces around the 8x8 game board
        for (row = 1; row <= 8; row++)
            pieces[row][0] = pieces[row][9] = EMPTY;
        for (col = 1; col <= 8; col++)
            pieces[0][col] = pieces[9][col] = EMPTY;

        
        currentPlayer = WHITE;  // WHITE plays first
        // currentPlayer = 777;    // try an invalid player
        
        gameBoard.updateStatus(pieces, currentPlayer);
    }
    
    
    
    // STUDENTS are encouraged to define other instance methods here
    // to aid the work of the method userClicked(row, col)
    
    /**
     * validate an move by checking in ONE direction
     * 
     * @param r is the row number of the clicked button
     * @param c is the column number of the clicked button
     * @param y is the in/decrement value for y-coordinate
     * @param x is the in/decrement value for x-coordinate
     * @return 
     */
    protected boolean validate(int r, int c, int y, int x) {
        int opponent = (currentPlayer == BLACK) ? WHITE : BLACK;
        
        r += y;
        c += x;
        
        if (r > 8 || c > 8 || r < 1 || c < 1) return false;
        else if (pieces[r][c] != opponent) return false;
//        System.out.println(r + " " + c + " " + y + " " + x);
        
        while (r <= 8 && c <= 8 && r >= 1 && c >= 1) {
//            System.out.println(r + " " + c + " " + y + " " + x);
            if (pieces[r][c] == EMPTY) return false;
            else if (pieces[r][c] == currentPlayer) return true;
            r += y;
            c += x;
        }
        
        return false;
    }
    
    /**
     * flip all bounded chips
     * 
     * @param r is the row number of the clicked button
     * @param c is the column number of the clicked button
     * @param y is the in/decrement value for y-coordinate
     * @param x is the in/decrement value for x-coordinate
     */
    protected void flip(int r, int c, int y, int x) {
        int opponent = (currentPlayer == BLACK) ? WHITE : BLACK;
        
        r += y;
        c += x;
        
        if (r > 8 || c > 8 || r < 1 || c < 1) return;
        else if (pieces[r][c] != opponent) return;
        
        while (r <= 8 && c <= 8 && r >= 1 && c >= 1) {
            if (pieces[r][c] == currentPlayer) break;
            else if (pieces[r][c] == opponent) pieces[r][c] = currentPlayer;
            r += y;
            c += x;
        }
    }
    
    
    /**
     * STUDENTS' WORK HERE
     * 
     * As this is a GUI application, the gameBoard object (of class ReversiPanel)
     * actively listens to user's actionPerformed.  On user clicking of a
     * ReversiButton object, this callback method will be invoked to do some
     * game processing.
     * 
     * @param row is the row number of the clicked button
     * @param col is the col number of the clicked button
     */
    public void userClicked(int row, int col)
    {
        // major operation of this method:
        // make a valid move by placing a piece at [row][col]
        // AND flipping some opponent piece(s) in all available directions
        boolean pass = true;
        boolean valid_move = false;
        
        
        if (pieces[row][col] == EMPTY) {
            boolean nn = validate(row, col , -1, 0);
            boolean ne = validate(row, col , -1, 1);
            boolean ee = validate(row, col , 0, 1);
            boolean se = validate(row, col , 1, 1);
            boolean ss = validate(row, col , 1, 0);
            boolean sw = validate(row, col , 1, -1);
            boolean ww = validate(row, col , 0, -1);
            boolean nw = validate(row, col , -1, -1);
            if (nn || ne || ee || se || ss || sw || ww || nw) {
                    valid_move = true;
                    pieces[row][col] = currentPlayer;
                    if (nn) flip(row, col , -1, 0);
                    if (ne) flip(row, col , -1, 1);
                    if (ee) flip(row, col , 0, 1);
                    if (se) flip(row, col , 1, 1);
                    if (ss) flip(row, col , 1, 0);
                    if (sw) flip(row, col , 1, -1);
                    if (ww) flip(row, col , 0, -1);
                    if (nw) flip(row, col , -1, -1);
            }
        }
        
        // check and handle forced pass
        if (valid_move) {
            currentPlayer = FLIP * currentPlayer;
            gameBoard.updateStatus(pieces, currentPlayer);
            
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    if (pieces[i][j] != EMPTY) continue;
                    boolean nn = validate(i, j , -1, 0);
                    boolean ne = validate(i, j , -1, 1);
                    boolean ee = validate(i, j , 0, 1);
                    boolean se = validate(i, j , 1, 1);
                    boolean ss = validate(i, j , 1, 0);
                    boolean sw = validate(i, j , 1, -1);
                    boolean ww = validate(i, j , 0, -1);
                    boolean nw = validate(i, j , -1, -1);
                    if (nn || ne || ee || se || ss || sw || ww || nw) {
                        pass = false;
                        break;
                    }
                }
                if (!pass) break;
            }
            
            switch (currentPlayer) {
                case BLACK:
                    // check and handle first forced pass
                    if (pass && !blackPassed) {
                        gameBoard.addText("Forced Pass");
                        blackPassed = true;
                        currentPlayer = FLIP * currentPlayer;
                        gameBoard.updateStatus(pieces, currentPlayer);
                    }
                    // check and handle double forced pass
                    if (blackPassed) {
                        gameBoard.addText("Double Forced Pass");
                        gameBoard.addText("End game!");
                        currentPlayer = FLIP * currentPlayer;
                    }
                    break;

                case WHITE:
                    // check and handle first forced pass
                    if (pass && !whitePassed) {
                        gameBoard.addText("Forced Pass");
                        whitePassed = true;
                        currentPlayer = FLIP * currentPlayer;
                        gameBoard.updateStatus(pieces, currentPlayer);
                    }
                    // check and handle double forced pass
                    if (whitePassed) {
                        gameBoard.addText("Double Forced Pass");
                        gameBoard.addText("End game!");
                        currentPlayer = FLIP * currentPlayer;
                    }
                    break;
            }
        } else {
            // check for invalid move, i.e., a cell is occupied or
            // a move that cannot take any opponent pieces
            gameBoard.addText("Invalid move");
        }
    }

    
    
    /**
     * sayGoodbye on System.out, before program termination
     */
    protected void sayGoodbye()
    {
        System.out.println("Goodbye!");
    }

    
    
    // main() method, starting point of basic Reversi game
    public static void main(String[] args) {
        Reversi game = new Reversi();
        
        // comment or remove the following statements for real game play
//        game.setupDebugBoardEndGame();
//        game.setupDebugBoardMidGame();
        // end of sample/ debugging code

        
        // *** STUDENTS need NOT write anything here ***
        
        // this application still runs in the background!!
        // the gameBoard object (of class ReversiPanel) listens and handles
        // user interactions as well as invoking method userClicked(row, col)
        
        // although this is end of main() method
        // THIS IS NOT THE END OF THE APP!
    }
}
