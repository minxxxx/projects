import java.util.*;

class node extends program
{
    colors colour = new colors();
    public int [][]goal_state = io_class.getGoalState();
    private int row = 0;
    private int col = 0;
    public node parent;
    public int [][]puzzle = new int[puzzle_size][puzzle_size];
    public LinkedList <node> child_nodes = new LinkedList<node>();
    public int f_value = 0;
    public int g_value = 0;
    public int h_value = 0;
    public String direction = "initial";
    
    public node(int [][]puz)
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
                this.puzzle[x][y] = puz[x][y];
        }
    }

    public int [][]copy_puzzle(int [][]src)
    {
        int [][]dest = new int[puzzle_size][puzzle_size];
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
                dest[x][y] = src[x][y];
        }
        return (dest);
    }

    public boolean is_goal()
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (puzzle[x][y] != goal_state[x][y])
                    return (false);
            }
        }
        return (true);
    }

    public boolean same_puzzle (int [][]puz)
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (this.puzzle[x][y] != puz[x][y])
                    return (false);
            }
        }
        return (true);
    }

    public void find_piece(int [][]puz, int piece)
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (puz[x][y] == piece)
                {
                    row = x;
                    col = y;
                }
            }
        }
    }
    //HEURISTIC FUNCTIONS BELOW
    private void man_hattan_distance()
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (this.puzzle[x][y] == 0)
                    continue ;
                find_piece(goal_state, this.puzzle[x][y]);
                this.h_value += Math.abs(x - row) + Math.abs(y - col);
            }
        }
        this.f_value = this.h_value + this.g_value;
    }

    private void hamming_distance()
    {
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (this.puzzle[x][y] == 0)
                    continue ;
                if (goal_state[x][y] != this.puzzle[x][y])
                    this.h_value++;
            }
        }
        this.f_value = this.h_value + this.g_value;
    }

    private void linear_conflict()
    {
        int i; int j; int goal_row; int goal_col;
        boolean linear_conflict = false;

        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                if (this.puzzle[x][y] == 0)
                    continue ;
                find_piece(goal_state, this.puzzle[x][y]);
                this.h_value += (Math.abs(x - row) + Math.abs(y - col));
                goal_row = row; //coordinates of goal state of current piece
                goal_col = col; 
                if (x > goal_row) //checks going up
                {
                    i = x - 1;
                    while (i >= goal_row)
                    {
                        find_piece(goal_state, this.puzzle[i][y]);
                        if (y == col) //checks conflict
                            linear_conflict = true;
                        i--;
                    }
                }
                else //checks going down
                {
                    i = x + 1;
                    while (i <= goal_row)
                    {
                        find_piece(goal_state, this.puzzle[i][y]);
                        if (y == col) //checks conflict
                            linear_conflict = true;
                        i++;
                    }
                }
                if (y > goal_col && !linear_conflict) //checks going left
                {
                    i = y - 1;
                    while (i >= goal_col)
                    {
                        find_piece(goal_state, this.puzzle[x][i]);
                        if (x == row) //checks conflict
                            linear_conflict = true;
                        i--;
                    }
                }
                else if (y < goal_col && !linear_conflict) //checks going right
                {
                    i = y + 1;
                    while (i <= goal_col)
                    {
                        find_piece(goal_state, this.puzzle[x][i]);
                        if (x == row) //checks conflict
                            linear_conflict = true;
                        i++;
                    }
                }
                if (linear_conflict == true)
                    h_value += 2;
            }
        }
        this.f_value = this.h_value + this.g_value;
    }

    public void calc_heuristic_value ()
    {
        this.g_value = calc_gvalue();
        switch (heuristic_function)
        {
            case "man": man_hattan_distance();
                break ;
            case "ham": hamming_distance();
                break ;
            case "lin": linear_conflict();
                break ;
        }
    }

    public void printpuzzle()
    {
        int t_x; int t_y;

        find_piece(this.puzzle, 0);
        t_x = row;
        t_y = col;
        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
            {
                switch (this.direction)
                {
                    case "left": t_y = col + 1;
                    break ;
                    case "right": t_y = col - 1;
                    break ;
                    case "up": t_x = row + 1;
                    break ;
                    case "down": t_x = row - 1;
                    break ;
                }
                if (this.puzzle[x][y] == 0)
                    System.out.print(colour.B_GRN);
                else if (this.puzzle[x][y] == this.puzzle[t_x][t_y])
                    System.out.print(colour.RED);
                System.out.print("["+ this.puzzle[x][y] +"]"+ colour.CLR);
            }
            System.out.println();
        }
        System.out.println();
    }

    private int calc_gvalue()
    {
        int gvalue = 0;
        node copy_node = this;
        while (copy_node.parent != null)
        {
            gvalue++;
            copy_node = copy_node.parent;
        }
        return (gvalue);
    }

    public void move_left()
    {
        find_piece(this.puzzle, 0);
        if (col - 1 > -1)
        {
            int [][]copy_puzzle = copy_puzzle(this.puzzle);

            copy_puzzle[row][col] = copy_puzzle[row][col - 1];
            copy_puzzle[row][col - 1] = 0;
            node child = new node(copy_puzzle);
            child.parent = this;
            child.direction = "left";
            child_nodes.add(child);
        }
    }

    public void move_right()
    {
        find_piece(this.puzzle, 0);
        if (col + 1 < puzzle_size)
        {
            int [][]copy_puzzle = copy_puzzle(this.puzzle);

            copy_puzzle[row][col] = copy_puzzle[row][col + 1];
            copy_puzzle[row][col + 1] = 0;
            node child = new node(copy_puzzle);
            child.parent = this;
            child.direction = "right";
            child_nodes.add(child);
        }
    }

    public void move_up()
    {
        find_piece(this.puzzle, 0);
        if (row - 1 > -1)
        {
            int [][]copy_puzzle = copy_puzzle(this.puzzle);

            copy_puzzle[row][col] = copy_puzzle[row - 1][col];
            copy_puzzle[row - 1][col] = 0;
            node child = new node(copy_puzzle);
            child.parent = this;
            child.direction = "up";
            child_nodes.add(child);
        }
    }

    public void move_down()
    {
        find_piece(this.puzzle, 0);
        if (row + 1 < puzzle_size)
        {
            int [][]copy_puzzle = copy_puzzle(this.puzzle);

            copy_puzzle[row][col] = copy_puzzle[row + 1][col];
            copy_puzzle[row + 1][col] = 0;
            node child = new node(copy_puzzle);
            child.parent = this;
            child.direction = "down";
            child_nodes.add(child);
        }
    }

    public void expand_node()
    {
        move_left();
        move_right();
        move_up();
        move_down();
    }
}