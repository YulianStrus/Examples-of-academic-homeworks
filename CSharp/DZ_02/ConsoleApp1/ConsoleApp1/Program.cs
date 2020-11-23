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
            Console.WriteLine("Enter number a: ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number b: ");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number c: ");
            int c = Convert.ToInt32(Console.ReadLine());

            double D=(b*b)-4*a*c;

            if (D > 0)
            { double x1 = (-b + Math.Sqrt(D)) / (2 * a);
              double x2 = (-b - Math.Sqrt(D)) / (2 * a);
                Console.WriteLine("x1 = " + x1 + "; x2 = " + x2);
            }
            else if (D == 0)
            {
                double x = (-b) / 2 * a;
                Console.WriteLine("x = " + x);
            }
            else { Console.WriteLine("Error D < 0!"); }
            Console.ReadKey();
        }
    }
}
