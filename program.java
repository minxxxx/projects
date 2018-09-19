import java.io.*;
import java.util.*;

public class program
{
    static IO io_class = new IO();
    static colors colour = new colors();
    static int puzzle_size = 0;
    static String heuristic_function = "";

    static int check_dup_n_range(int [][]puzzle)
    {
        int max_num = (puzzle_size * puzzle_size) - 1;
        int []numbers = new int[(puzzle_size * puzzle_size)];

        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (puzzle[x][y] > max_num || puzzle[x][y] < 0)
                    return (1);
                if (numbers[puzzle[x][y]] == 1)
                    return (1);
                numbers[puzzle[x][y]] = 1;
            }
        }
        return (0);
    }

    static int errorHandling(int [][]puzzle)
    {
        if (puzzle == null || (puzzle_size < 3 || puzzle_size > 5)) //Error handling
        {
            if (puzzle_size < 3 || puzzle_size > 5)
                System.out.println(colour.RED + "Program only supports 3x3, 4x4 and 5x5 dimensions");
            System.out.println(colour.RED +"Invalid puzzle format"+ colour.CLR);
            return -1;
        }
        if (check_dup_n_range(puzzle) == 1)
        {
            System.out.println(colour.RED + "Error - Check for duplicates or puzzle numbers out of range" + colour.CLR);
            return -1;
        }
        return (0);
    }

    private static void print_solution(LinkedList<node> solution) //this simply prints the nodes that lead to the solution
    {
        int list_size = solution.size() - 1;
        int moves = 0;
        while (list_size > -1)
        {
            System.out.println(colour.YLW + solution.get(list_size).direction +" | move: "+ moves++ + colour.CLR);
            solution.get(list_size).printpuzzle();
            list_size--;
        }
    }

    private static void print_usage()
    {
        System.out.println(colour.RED + "usage: java program " + colour.B_RED + " <heuristic function> <puzzle input file>");
        System.out.println(colour.RED + "Available heuristics: 'man' / 'ham' / 'lin'"+ colour.CYN);
        System.out.println("\t'man': Manhattan Distance");
        System.out.println("\t'ham': Hamming Distance");
        System.out.println("\t'lin': Linear Conflict Distance"+ colour.CLR);
    }

    private static String []store_files(String []arg)
    {
        int nbr_of_files = arg.length - 1;
        int index = 1;
        String []files = new String [nbr_of_files];

        for (int i = 0; i < nbr_of_files; i++)
        {
            files[i] = arg[index];
            index++;
        }
        return (files);
    }

    private static final long MEGABYTE = 1024L * 1024L;

    public static long bytesToMegabytes(long bytes)
    {
        return bytes / MEGABYTE;
    }

    public static void main(String[] args) throws Exception
    {
        if (args.length >= 2)
        {
            String []files = store_files(args);
            for (String file: files)
            {
                if ((puzzle_size = io_class.getPuzzleSize(file)) == -1)
                    return ;
                astar_search astar = new astar_search();
                int [][]init_puzzle = io_class.getPuzzle(file);
                LinkedList<node> solution = new LinkedList<node>();
                heuristic_function = args[0];
                String prompt = "";
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                char s = 's';
                double stop_timer;
                double start_timer = System.currentTimeMillis();
                Runtime runtime = Runtime.getRuntime();

                if (errorHandling(init_puzzle) == -1)
                    return ;
                node root = new node(init_puzzle);
                if (heuristic_function.equals("man") || heuristic_function.equals("ham") || heuristic_function.equals("lin"))
                {
                    switch(heuristic_function)
                    {
                        case "man": System.out.println(colour.CYN + "Selected: "+ colour.B_CYN + " Manhattan Distance" + colour.CLR);
                        break ;
                        case "ham": System.out.println(colour.CYN + "Selected: "+ colour.B_CYN + "Hamming Distance"+ colour.CLR);
                        break ;
                        case "lin": System.out.println(colour.CYN + "Selected: "+ colour.B_CYN + "Linear Conflict"+ colour.CLR);
                        break ;
                    }
                    if (file.contains("/"))
                        file = file.substring(file.indexOf("/") + 1);
                    System.out.println(colour.YLW + "Reading File: "+ file + colour.CLR);
                    System.out.println(puzzle_size +" x " + puzzle_size + " Found\n");
                    root.printpuzzle();
                    System.out.println(colour.GRN + "Searching..."+ colour.CLR);
                    solution = astar.algorithm(root); //solution linkedlist saves the nodes that made it to goal
                    if (solution.size() == 0)
                    {
                        stop_timer = System.currentTimeMillis();
                        System.out.println(colour.RED + "No Solution found! - Suggestions:");
                        System.out.println("Try different heuristic function OR Solution may not exist at all"+ colour.CLR);
                    }
                    else
                    {
                        stop_timer = System.currentTimeMillis();
                        System.out.println(colour.B_GRN + "Solution Found!");
                        System.out.println("Would you like to print the solution? (y / n)"+ colour.CLR);
                        prompt = br.readLine();
                        if (prompt.equals("y") || prompt.equals("yes"))
                            print_solution(solution);
                        if (solution.size() == 2) //if only 2 steps, meaning 1 step, and not STEPS - this is jut for print out purposes (1 STEP || more than one STEPS)
                            s = ' ';
                        System.out.println(colour.RED + "Opened states: "+ astar.opened);
                        System.out.println(colour.GRN + "Solution found in "+ (solution.size() - 1) + " move"+ s + colour.CLR); //this will print MOVES if more than 1, and STEP if only 1
                    }
                    long memory = runtime.totalMemory() - runtime.freeMemory();
                    System.out.println(colour.CYN +"used memory in bytes: "+ memory);
                    System.out.println("used memory in megabytes: "+ bytesToMegabytes(memory));
                    System.out.println(colour.YLW + "time elapsed: "+ (stop_timer - start_timer)/1000 +"s\n" + colour.CLR);
                }
                else
                {
                    System.out.println(colour.B_RED + "Heuristic function not found!");
                    System.out.println(colour.RED + "    Try 'man' / 'ham' / 'lin'"+ colour.CLR);
                }
            }
        }
        else
            print_usage();
    }
}