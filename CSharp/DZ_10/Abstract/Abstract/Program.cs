using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Abstract
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Person> p = new List<Person>();
            p.Add(new Worker("Ivanov Ivan Ivanonich"));
            p[0].docs.Add(new Passport("AA137964", 21, 12, 1991, "Zabolotiv"));
            p[0].docs.Add(new IDCode("9876543219"));
            p[0].Print();
            Console.ReadLine();
        }
    }
}
