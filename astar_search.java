import java.util.*;

public class astar_search extends program
{
    public int opened = 0;
    private static int index = 0;

    public LinkedList<node> algorithm (node root)
    {
        LinkedList<node> solution_path = new LinkedList<node>(); //will save the solution path
        LinkedList<node> open_list = new LinkedList<node>(); //stores a queue of nodes that will be inspected
        LinkedList<node> closed_list = new LinkedList<node>(); //stores nodes that have been inspected
        boolean solution_found = false;
        node current;
        
        open_list.add(root);
        if (is_solvable(root.puzzle))
        {
            while (!open_list.isEmpty() && !solution_found)
            {
                opened++;
                current = open_list.getFirst();
                open_list.removeFirst();
                closed_list.add(current);
                if (current.is_goal())
                {
                    solution_found = true;
                    path_to_solution(solution_path, current);
                }
                current.expand_node();
                for (node child: current.child_nodes)
                {
                    child.calc_heuristic_value();
                    if (!contained(open_list, child) && !contained(closed_list, child))
                        open_list.add(child);
                    else if (contained(open_list, child))
                    {
                        if (child.g_value > open_list.get(index).g_value)
                            continue ;
                    }
                    else if (contained(closed_list, child))
                    {
                        if (child.g_value > closed_list.get(index).g_value)
                            continue ;
                    }
                }
                reorder_list(open_list);
            }
        }
        return (solution_path);
    }

    private static void reorder_list(LinkedList<node> list)
    {
        Collections.sort(list, new compare_f_value());
    }

    private static boolean contained (LinkedList<node> list, node n)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (n.same_puzzle(list.get(i).puzzle))
            {
                index = i;
                return (true);
            }
        }
        return (false);
    }

    private static void path_to_solution(LinkedList<node> path, node n) //this inserts the nodes that lead to the solution into the linkedlist path
    {
        while (n != null)
        {
            path.add(n);
            n = n.parent;
        }
    }

    private static int inv_count(int []pz)
    {
        int inverses = 0;

        for (int i = 0; i < ((puzzle_size * puzzle_size) - 1); i++)
        {
            for (int j = i + 1; j < (puzzle_size * puzzle_size); j++)
                if (pz[i] > pz[j] && pz[i] != 0 && pz[j] != 0)
                    inverses++;
        }
        return (inverses);
    }

    public static boolean is_solvable(int [][]puzzle)
    {
        int []checker_puzzle = new int [(puzzle_size * puzzle_size)];
        int i = -1;

        for (int x = 0; x < puzzle_size; x++)
        {
            for (int y = 0; y < puzzle_size; y++)
                checker_puzzle[++i] = puzzle[x][y];
        }
        i = inv_count(checker_puzzle);
        if (i % 2 == 0)
            return (false);
        return (true);
    }
}

class compare_f_value implements Comparator<node>
{
    public int compare (node x1, node x2)
    {
        if (x1.f_value > x2.f_value)
            return (1);
        else if (x1.f_value == x2.f_value)
        {
            if (x1.h_value > x2.h_value)
                return (0);
        }
        else
            return (-1);
        return (0);
    }
}