using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Abstract
{
    class Worker : Person
    {
        public Worker() { }
        public Worker(string fullName)
        {
            docs = new List<Document>();
            base.fullName = fullName;
        }
        public void AddName()
        {
            Console.Write("Please enter full name: ");
            fullName = Console.ReadLine();
        }
        public void ShortPrint()
        {
            Console.WriteLine("Full name: " + fullName);
        }
        public override void Print()
        {
            Console.WriteLine("Full name: " + fullName + "\n");
            for (int i = 0; i < docs.Count; ++i)
            {
                docs[i].Print();
            }
        }

    }
}
