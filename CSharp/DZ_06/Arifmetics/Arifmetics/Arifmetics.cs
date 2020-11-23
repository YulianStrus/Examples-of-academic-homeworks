using System;

namespace Arifmetics
{
    public class Arifmetics
    {
        public static void tabSin(int A, int B, int h)
        {
            int x;
            for (int i = A; i < B; i = i + h)
            {
                x = i;
                double y = Math.Sin(x);
                Console.WriteLine("y=" + y + "; x=" + x);
            }
        }
        public static void quadEq(int a, int b, int c)
        {

            double D = (b * b) - 4 * a * c;

            if (D > 0)
            {
                double x1 = (-b + Math.Sqrt(D)) / (2 * a);
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
    public class User
        {
            string name;
            public User() { }
            public User(string name) { this.name = name; }
            public void addName()
            {
                Console.Write("Please enter name of user: ");
                name = Console.ReadLine();
            }
            public string getName() { return name; }
            public bool search(string s)
            {
                if (name.Contains(s)) return true;
                else return false;
            }
        }
        public class Sort
        {
            public static void sort(User[] user)
            {
                if (user.Length == 0) Console.WriteLine("Empty! Not yet users");
                else
                {
                    User temp = new User();
                    for (int i = 0; i < user.Length - 1; ++i)
                    {
                        for (int k = 0; k < user.Length - i - 1; ++k)
                        {
                            if (user[k].getName().CompareTo(user[k + 1].getName()) > 0)
                            {
                                temp = user[k];
                                user[k] = user[k + 1];
                                user[k + 1] = temp;
                            }
                        }
                    }
                    Console.WriteLine("\t\tUsers");
                    for (int i = 0; i < user.Length; ++i)
                    {
                        Console.Write("\n" + (i + 1) + ". ");
                        Console.WriteLine(user[i].getName());
                    }
                }
            }
        }
        public class Search
        {
            public static void search(User[] user)
            {
                Console.Write("Enter name for searching: ");
                string st = Console.ReadLine();
                int count = 0;
                for (int i = 0; i < user.Length; ++i)
                {
                    if (user[i].search(st))
                    {
                        count++;
                        Console.Write(count + ". ");
                        Console.WriteLine(user[i].getName());
                    }
                }
                if (count == 0) Console.WriteLine("Not found");
            }
        }
    
}
