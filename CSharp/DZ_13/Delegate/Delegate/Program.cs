using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegate
{
    class Program
    {
        delegate double Operation(int x, int y);
        private static double Summ(int x, int y)
        {
            return x + y;
        }
        private static double Difference(int x, int y)
        {
            return x - y;
        }
        private static double Multiply(int x, int y)
        {
            return x * y;
        }
        private static double Division(int x, int y)
        {
            return x / y;
        }
        private static double Root(int x, int y)
        {
            return Math.Sqrt(x);
        }
        private static double Module(int x, int y)
        {
            return Math.Abs(x);
        }
        private static double Power(int x, int y)
        {
            return Math.Pow(x,y);
        }
        static void Main(string[] args)
        {
            string m = "1";
            double result;
            int a, b;
            Console.WriteLine("\tCalculate:");
            Operation calc;
            while (m!="0")
            {
                Console.WriteLine("\nEnter num1: ");
                a = Convert.ToInt16(Console.ReadLine());
                Console.WriteLine("\nEnter operation: \n'+' - summ  '-' - difference  '*' - multiplication  '/' - division  '!' - root  '|' - module  '^' - power");
                m = Console.ReadLine();
                Console.WriteLine("\nEnter num2: ");
                b = Convert.ToInt16(Console.ReadLine());                
                switch (m)
                {
                    case "+":
                        calc = Summ;
                        result = calc(a, b);
                        Console.WriteLine(result);
                        break;
                    case "-":
                        calc = Difference;
                        result = calc(a, b);
                        Console.WriteLine(result);
                        break;
                    case "*":
                        calc = Multiply;
                        result = calc(a, b);
                        Console.WriteLine(result);
                        break;
                    case "/":
                        calc = Division;
                        result = calc(a, b);
                        Console.WriteLine(result);
                        break;
                    case "!":
                        calc = Root;
                        result = calc(a,b);
                        Console.WriteLine(result);
                        break;
                    case "|":
                        calc = Module;
                        result = calc(a,b);
                        Console.WriteLine(result);
                        break;
                    case "^":
                        calc = Power;
                        result = calc(a, b);
                        Console.WriteLine(result);
                        break;
                    case "0": break;
                }
                Console.WriteLine("\n1. To calculate again\n0. Exit");
                m = Console.ReadLine();
            }

            Console.ReadKey();
        }
    }
}
