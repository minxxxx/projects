using System;

namespace ComputerV1
{
    internal static class Program
    {
        public static void Main(string[] args)
        {
            string eq = "";
            if (args.Length != 0)
            {
                if (args.Length == 1) { eq = args[0]; }
                else { Console.WriteLine("Equation Must be the only argument and must be inclosed in quotes"); return; }
            }
            else
            {
                Console.WriteLine("please enter an equation.");
                eq = Console.ReadLine();
            }
            try { var newEq = new Poly(eq); newEq.Calculate(); }
            catch (Exception e) { Console.WriteLine(e.Message); }
        }
    }
}