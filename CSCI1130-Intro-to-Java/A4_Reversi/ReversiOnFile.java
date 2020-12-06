package reversi;

import java.awt.Color;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 * ReversiOnFile is a subclass of Reversi, adding File I/O capabilities for
 * loading and saving game.
 * 
 * Date : 02 December 2020
 *
 */
public class ReversiOnFile extends Reversi {

    public static final char UNICODE_BLACK_CIRCLE = '\u25CF';
    public static final char UNICODE_WHITE_CIRCLE = '\u25CB';
    public static final char UNICODE_WHITE_SMALL_SQUARE = '\u25AB';

    // constructor to give a new look to new subclass game
    public ReversiOnFile() {
        window.setTitle("ReversiOnFile");
        gameBoard.setBoardColor(Color.BLUE);
    }

    // STUDENTS' WORK HERE    
    public void loadBoard(String filename) {
        // 1) prepare an empty board
        int[][] load_pieces = new int[10][10];

        try {
            // 2) load board and current player from file in UTF-8 Charset encoding
            Scanner load = new Scanner(new File(filename));
            int line_index = 1;

            while (load.hasNextLine() && line_index <= 9) {
                String data = load.nextLine();
                String[] result = data.split("");

                // last symbol represents current player
                if (line_index == 9) {
                    currentPlayer = result[0].equals(UNICODE_BLACK_CIRCLE) ? BLACK : WHITE;
                    break;
                }

                // load pieces for one line
                for (int i = 1; i <= result.length; i++) {
                    switch (result[i].charAt(0)) {
                        case UNICODE_BLACK_CIRCLE:
                            load_pieces[line_index][i] = BLACK;
                            break;
                        case UNICODE_WHITE_CIRCLE:
                            load_pieces[line_index][i] = WHITE;
                            break;
                        case UNICODE_WHITE_SMALL_SQUARE:
                            load_pieces[line_index][i] = EMPTY;
                            break;
                        default:
                            throw new Exception();
                    }
                }
                line_index++;
            }

            pieces = load_pieces;

            // 3) display successful messages and update game status on screen
            gameBoard.addText("Loaded board from " + filename);
            System.out.println("Loaded board from " + filename);
            gameBoard.updateStatus(pieces, currentPlayer);

        } catch (FileNotFoundException fe) {
            // 4) in case of any Exception:
            gameBoard.addText("Cannot load board from " + filename);
            System.out.println("Cannot load board from " + filename);
        } catch (Exception e) {
            gameBoard.addText("Some characters in " + filename + " can't be read");
            System.out.println("Some characters in " + filename + " can't be read");
        }
        // you may implement a method to setupBoardDefaultGame();
    }

    // STUDENTS' WORK HERE    
    public void saveBoard(String filename) {
        try {
            // 1) open/overwrite a file for writing text in UTF-8 Charset encoding
            PrintStream write = new PrintStream(filename);

            // 2) save board to the file on 8 lines of 8 Unicode char on each line
            for (int i = 1; i < 9; i++) {
                for (int j = 1; j < 9; j++) {
                    switch (pieces[i][j]) {
                        case WHITE:
                            write.print(UNICODE_WHITE_CIRCLE);
                            break;
                        case BLACK:
                            write.print(UNICODE_BLACK_CIRCLE);
                            break;
                        case EMPTY:
                            write.print(UNICODE_WHITE_SMALL_SQUARE);
                            break;
                        default:
                            throw new Exception();
                    }
                }
                write.println();
            }
            
            char currentColor = currentPlayer == BLACK ? UNICODE_BLACK_CIRCLE : UNICODE_WHITE_CIRCLE;
            write.println(currentColor);

            // 3) save current player on line 9 and display successful messages
            gameBoard.addText("Saved board to " + filename);
            System.out.println("Saved board to " + filename);

        } catch (FileNotFoundException fe) {
            // 4) in case of any Exception:
            gameBoard.addText("Cannot save board to " + filename);
            System.out.println("Cannot save board to " + filename);
        } catch (Exception e) {
            gameBoard.addText("Exception ocuured while writing characters in " + filename);
            System.out.println("Exception ocuured while writing characters in" + filename);
        }
    }

    // STUDENTS' WORK HERE    
    /**
     * Override sayGoodbye method of super class, to save board
     */
    @Override
    protected void sayGoodbye() {
        //as usual, sayGoodbye...
        System.out.println("Goodbye!");

        //ask for save filename
        String filename = JOptionPane.showInputDialog("Save board filename");

        // save board to file
        saveBoard(filename);
    }

    // STUDENTS' WORK HERE    
    // main() method, starting point of subclass ReversiOnFile
    public static void main(String[] args) {
        ReversiOnFile game = new ReversiOnFile();

        // comment or remove the following statements for real game play
//        game.setupDebugBoardEndGame();
//        game.saveBoard("game4.txt");
//        game.setupDebugBoardMidGame();
//        game.saveBoard("game8.txt");
        // end of sample/ debugging code
        // ask for load filename
        String filename = JOptionPane.showInputDialog("Load board filename");

        // load board from file
        game.loadBoard(filename);
    }
}
