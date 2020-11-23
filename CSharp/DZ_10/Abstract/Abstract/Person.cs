using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Abstract
{
    abstract class Person
    {
        public List<Document> docs { get; set; }
        public string fullName { get; set; }
        public abstract void Print();

    }
}
