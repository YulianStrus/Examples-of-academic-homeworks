using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class Type
    {

        string carcase;
        public double price;
        public void addTypeDefault(string carcase, double price)
        {
            this.carcase = carcase;
            this.price = price;
        }
        public void addEngine()
        {
            Console.Write("Please enter info about new type:\nCarcase: ");
            this.carcase = Console.ReadLine();
            Console.Write("Price: ");
            this.price = Convert.ToDouble(Console.ReadLine());
        }
        public void getInfo()
        {
            Console.WriteLine("Carcase: {0}\nPrice: {1:F2} $\n", carcase, price);
        }

    }
}
