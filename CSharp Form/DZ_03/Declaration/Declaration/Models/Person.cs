using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Declaration.Models
{
    public class Person
    {
        public string name { get; set; }
        List<Declaration> declarations;
        public Person(string name)
        {
            this.name = name;
            declarations = new List<Declaration>();
        }
        public void AddDeclaration(Declaration declaration)
        {
            declarations.Add(declaration);
        }
    }
}
