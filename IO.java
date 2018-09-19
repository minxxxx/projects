import java.io.*;
import javax.imageio.IIOException;

public class IO extends program
{
    String file;
    static int puzzle_size = 0;
    static int startpos = 0;
    BufferedReader br = null;
    FileReader fr = null;

    public static boolean isNumber(String s)
    {
        try{
            double i  = Double.parseDouble(s);
        }
        catch (NumberFormatException e){
            return false;
        }
        return true;
    }

    public int getPuzzleSize(String args) throws Exception
    {
        IO.this.file = args;
        String line;

        try {
        fr = new FileReader(file);
        br = new BufferedReader(fr);
        } 
        catch (IOException e){
            System.out.println("No such file exists in this direcotry");
            return (-1);
        }
        
        line = br.readLine();
        while (puzzle_size == 0)
        {
            if (isNumber(line))
            {
                if (line.contains(" "))
                    puzzle_size = Integer.parseInt(line.substring(0, line.indexOf(" ")));
                else
                    puzzle_size = Integer.parseInt(line);
            }
            else
                line = br.readLine();    
            startpos++;
        }
        return (puzzle_size);
    }

    public int [][] getPuzzle(String file) throws Exception
    {
        fr = new FileReader(file);
        br = new BufferedReader(fr);
        String line;
        int [][] puzzle = new int[puzzle_size][puzzle_size];
        int i = 0;
        int j = -1;

        while (++j < startpos)
            br.readLine();
        while ((line = br.readLine()) != null && i < puzzle_size)
        {
            if (line.isEmpty())
                continue ;
            else
            {
                String []row = line.replaceAll("(^\\s+|\\s$)", "").split(" +");
                if (row.length != puzzle_size)      //ensuring we have 3 /4 /5 pieces if it is a 3 /4 /5 dimension puzzle
                    return (null);
                j = 0;
                for (String val:row)
                {
                    if (j < puzzle_size)
                    {
                        puzzle[i][j] = Integer.parseInt(val.trim());
                    }
                    j++;
                }
            }
            i++;
        }
        return (puzzle);
    }

public int [][]getGoalState()
{
    if (puzzle_size == 3)
    {
        int [][]goal_state = new int [][]{
                            {1, 2, 3},
                            {8, 0, 4},
                            {7, 6, 5}
        };
        return (goal_state);
    }
    if (puzzle_size == 4)
    {
        int [][]goal_state = new int [][]{
                            {1, 2, 3, 4},
                            {12, 13, 14, 5},
                            {11, 0, 15, 6},
                            {10, 9, 8, 7}
        };
        return (goal_state);
    }
    if (puzzle_size == 5)
    {
        int [][]goal_state = new int [][]{
                            {1, 2, 3, 4, 5},
                            {16, 17, 18, 19, 6},
                            {15, 24, 0, 20, 7},
                            {14, 23, 22, 21, 8},
                            {13, 12, 11, 10, 9},
        };
        return (goal_state);
    }
    else
        return (null);
    }
}