using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Supermarket
{
    class Tovar
    {
        private string Name;
        private double Price;
        private DateTime ManufactureDate;
        private int TakeUpTo;
        public string GetName() { return Name; }
        public Tovar(string Name, double Price, DateTime ManufactureDate, int TakeUpTo)
        {
            this.Name = Name;
            this.Price = Price;
            this.ManufactureDate = ManufactureDate;
            this.TakeUpTo = TakeUpTo;
        }
        public static bool operator >(Tovar t1, Tovar t2)
        {
            if (t1.Name.CompareTo(t2.Name) > 0) return true;
            else return false;
        }
        public static bool operator <(Tovar t1, Tovar t2)
        {
            if (t1.Name.CompareTo(t2.Name) < 0) return true;
            else return false;
        }
        public static bool operator ==(Tovar t1, Tovar t2)
        {
            if (t1.Name == t2.Name && t1.Price == t2.Price && t1.ManufactureDate == t2.ManufactureDate && t1.TakeUpTo == t2.TakeUpTo) return true;
            else return false;
        }
        public static bool operator !=(Tovar t1, Tovar t2)
        {
            if (t1.Name != t2.Name || t1.Price != t2.Price || t1.ManufactureDate != t2.ManufactureDate || t1.TakeUpTo != t2.TakeUpTo) return true;
            else return false;
        }
        public static double operator +(double sum, Tovar t1)
        {
            sum += t1.Price;
            return sum;
        }
        public static double operator -(double sum, Tovar t1)
        {
            sum -= t1.Price;
            return sum;
        }
        public static bool operator >(Tovar t1, DateTime dt)
        {
            if (t1.ManufactureDate.AddDays(t1.TakeUpTo) > dt) return true;
            else return false;
        }
        public static bool operator <(Tovar t1, DateTime dt)
        {
            if (t1.ManufactureDate.AddDays(t1.TakeUpTo) < dt) return true;
            else return false;
        }

        public void Print()
        {
            Console.WriteLine("Name: {0}\nPrice: {1:F2}\nRelease date: {2}\nExpiration date: {3} days\n", Name, Price, ManufactureDate.Date.ToShortDateString(), TakeUpTo);
        }
    }
}
