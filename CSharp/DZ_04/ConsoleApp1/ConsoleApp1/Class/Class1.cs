using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    class Birthday
    {
        int day;
        int month;
        int year;

        public void SetDay(int day) { this.day = day; }
        public void SetMonth(int month) { this.month = month; }
        public void SetYear(int year) { this.year = year; }
        public int GetDay() { return day; }
        public int GetMonth() { return month; }
        public int GetYear() { return year; }
    }

    class Person
    {
        string Name;
        string Country;
        string Phone;
        Birthday bd;

        public string GetName() { return Name; }
        public void AddPerson()
        {
            Console.Write("Please enter name: ");
            Name = Console.ReadLine();
            Console.Write("Please enter country: ");
            Country = Console.ReadLine();
            Console.Write("Please enter phone: ");
            Phone = Console.ReadLine();
            Console.Write("Please enter birthday:\n\t\tDay: ");
            int day = Convert.ToInt32(Console.ReadLine());
            bd = new Birthday();
            bd.SetDay(day);
            Console.Write("\t\tMonth: ");
            int month = Convert.ToInt32(Console.ReadLine());
            bd.SetMonth(month);
            Console.Write("\t\tYear: ");
            int year = Convert.ToInt32(Console.ReadLine());
            bd.SetYear(year);
        }

        public void Show()
        {
            Console.WriteLine("Name: {0}\n   Country: {1}\n   Phone: {2}\n   Birthday: {3:00}.{4:00}.{5}\n", Name, Country, Phone, bd.GetDay(), bd.GetMonth(), bd.GetYear());
        }

        public bool Search(string st)
        {
            if (Name.Contains(st) || Country.Contains(st) || Phone.Contains(st)) return true;
            else return false;
        }
    }
}
