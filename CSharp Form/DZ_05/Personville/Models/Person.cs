using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Personville.Models
{
    public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public Person(string Name, string Age)
        {
            this.Name = Name;
            this.Age = int.Parse(Age);
        } 
    }
}
