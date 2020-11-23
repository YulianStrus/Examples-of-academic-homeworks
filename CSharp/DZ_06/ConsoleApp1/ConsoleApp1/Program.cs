using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Arifmetics.Arifmetics;
using static Arifmetics.Sort;
using static Arifmetics.Search;
using static Arifmetics.User;
using Arifmetics;


namespace ConsoleApp1
{
    class Program
    {
        
        static void Main(string[] args)
        {
            tabSin(0, 15, 1);
            Console.WriteLine();
            quadEq(2, 8, 3);
            Console.WriteLine();
            Console.WriteLine("Enter number user:");
            int n = Convert.ToInt32(Console.ReadLine());
            User[] user = new User[n];
            for (int i=0; i<n; i++)
            {
                Console.Write("Please enter name of user: ");
                string name = Console.ReadLine();
                user[i] = new User(name);
            }
            search(user);
            sort(user);
            Console.ReadKey();
        }
    }
}

