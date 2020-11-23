using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class Transmission
    {

        string type;
        int numbGears;
        public double price;
        public void addTransmissionDefault(string type, int numbGears, double price)
        {
            this.type = type;
            this.numbGears = numbGears;
            this.price = price;
        }
        public void addEngine()
        {
            Console.Write("Please enter info about new transmission:\nType: ");
            this.type = Console.ReadLine();
            Console.Write("Number of gears: ");
            this.numbGears = Convert.ToInt32(Console.ReadLine());
            Console.Write("Price: ");
            this.price = Convert.ToDouble(Console.ReadLine());
        }
        public void getInfo()
        {
            Console.WriteLine("Type: {0}\nNumber of gears: {1}\nPrice: {2:F2} $\n", type, numbGears, price);
        }
    }
}
