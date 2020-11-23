using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Abstract
{
    class Passport : Document
    {
        DateTime birthday;
        string cityBirth;
        public Passport() { }
        public Passport(string number, int day, int month, int year, string cityBirth)
        {
            base.number = number;
            birthday = new DateTime(year, month, day);
            this.cityBirth = cityBirth;
        }
        public void AddPassport()
        {
            Console.Write("Please enter number: ");
            number = Console.ReadLine();
            Console.WriteLine("Please enter birthday:");
            Console.Write("Day: ");
            int day = Convert.ToInt16(Console.ReadLine());
            Console.Write("Month: ");
            int month = Convert.ToInt16(Console.ReadLine());
            Console.Write("Year: ");
            int year = Convert.ToInt32(Console.ReadLine());
            birthday = new DateTime(year, month, day);
            cityBirth = Console.ReadLine();
        }
        public override void Print()
        {
            Console.WriteLine("\tPassport\nNumber: " + number+ "\nBirthday: " + birthday +"\nCity of birth:" + cityBirth + "\n");
        }

    }
}
