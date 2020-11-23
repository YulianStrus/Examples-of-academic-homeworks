using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Abstract
{
    class IDCode : Document
    {
        public IDCode(string number)
        {
            base.number = number;
        }
        public override void Print()
        {
            Console.WriteLine("\tID code\nNumber: \n" + number);
        }

    }
}
