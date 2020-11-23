using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Supermarket
{
    class Program
    {
        static Tovar[] List()
        {
            Tovar[] tv = new Tovar[7];
            DateTime tvrDate1;
            tv[0] = new Tovar("Beef 1 kg", 10.57, tvrDate1 = new DateTime(2019, 7, 10), 3);
            tv[1] = new Tovar("Watermelon 1 kg", 8.49, tvrDate1 = new DateTime(2019, 7, 10), 30);
            tv[2] = new Tovar("Mozzarella 200 gr", 29.99, tvrDate1 = new DateTime(2019, 3, 5), 180);
            tv[3] = new Tovar("Milk 1 l", 19.5, tvrDate1 = new DateTime(2019, 7, 1), 12);
            tv[4] = new Tovar("Sugar 1 kg", 16.29, tvrDate1 = new DateTime(2019, 3, 24), 365);
            tv[5] = new Tovar("Milk 1 l", 19.5, tvrDate1 = new DateTime(2019, 7, 1), 12);
            tv[6] = new Tovar("Ice Cream Monaco 80 gr", 23.99, tvrDate1 = new DateTime(2019, 3, 1), 90);

            return tv;
        }
        static void Show(Tovar[] tv)
        {
            for (int i = 0; i < tv.Length; ++i)
                tv[i].Print();
        }
        static void Sort(Tovar[] tv)
        {
            Tovar temp;
            for (int i = 0; i < tv.Length - 1; ++i)
            {
                for (int j = 0; j < tv.Length - i - 1; ++j)
                {
                    if (tv[j] > tv[j + 1])
                    {
                        temp = tv[j];
                        tv[j] = tv[j + 1];
                        tv[j + 1] = temp;
                    }
                }
            }
            Show(tv);
        }

        static void Sum(Tovar[] tv)
        {
            double sum = 0;
            for (int i = 0; i < tv.Length; ++i)
                sum += tv[i];
            Console.WriteLine("Summa = {0:F2}", sum);
        }
        static void Overdue(Tovar[] tv)
        {
            int count = 0;
            DateTime localDate = new DateTime();
            localDate = DateTime.Now;
            for (int i = 0; i < tv.Length; ++i)
            {
                if (tv[i] < localDate)
                {
                    Console.WriteLine(tv[i].GetName() + " - The goods are terminated\n");
                    count++;
                }
            }
            if (count == 0) Console.WriteLine("No extended product found!\n");
        }

        static void CheckTovar(Tovar[] tv)
        {
            int count = 0;
            for (int i = 0; i < tv.Length - 1; ++i)
            {
                for (int k = i + 1; k < tv.Length; ++k)
                {
                    if (tv[i] == tv[k])
                    {
                        count++;
                        if (count == 1) Console.WriteLine("The identical goods are found:");
                        tv[k].Print();
                    }
                }
            }
            if (count == 0) Console.WriteLine("Identical products not found!");
        }

        static void Main(string[] args)
        {
            Tovar[] tvr = new Tovar[7];
            tvr = List();
            Console.WriteLine("\n\tSort list:");
            Sort(tvr);
            Console.WriteLine("\n\tTotal amount of goods:");
            Sum(tvr);
            Console.WriteLine("\n\tProtracted goods:");
            Overdue(tvr);
            Console.WriteLine("\n\tIdentical products:");
            CheckTovar(tvr);

            Console.ReadKey();
        }
    }
}
