using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter number A: ");
            int A = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number B: ");
            int B = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number h: ");
            int h = Convert.ToInt32(Console.ReadLine());
            double x;
            for (int i = A; i < B; i = i + h)
            {
                x = i;
               double y = Math.Sin(x);
                Console.WriteLine("y=" + y(0.0) + "; x=" + x(0.0));
            }
            Console.ReadKey();
        }
    }
}
