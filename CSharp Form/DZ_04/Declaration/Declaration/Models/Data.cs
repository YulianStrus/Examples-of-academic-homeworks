using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Declaration.Models
{
    static public class Data
    {
        static List<Person> persons = new List<Person>();
        static public void AddPerson(Person person)
        {
            persons.Add(person);
        }
        static public List<Person> GetPersons()
        {
            return persons;
        }
    }
}
