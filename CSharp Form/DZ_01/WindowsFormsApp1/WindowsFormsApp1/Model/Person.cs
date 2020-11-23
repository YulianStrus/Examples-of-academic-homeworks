using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1.Model
{
    class Person
    {
        public string PIB { get; set; }
        public int Age { get; set; }
        public string Sex { get; set; }
        public Person(string PIB, string Age, string Sex)
        {
            this.PIB = PIB;
            this.Age = int.Parse(Age);
            this.Sex = Sex;
        }
        public string showPerson()
        {
            string person = PIB + " - " + Age + " ";
            if (Age % 10 == 1 && Age % 100 != 11) person += "рік";
            else if ((Age % 10 >= 2 && Age % 10 <= 4) && (Age % 100 != 12 && Age % 100 != 13 && Age % 100 != 14)) person += "роки";
            else person += "років";
            person += " " + Sex + " ";
            return person;
        }
    }
}
