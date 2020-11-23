using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class Wheels
    {

        string season;
        int diameter;
        int width;
        public double price;
        public void addWheelsDefault(int diameter, int width, double price)
        {
            this.diameter = diameter;
            this.width = width;
            this.price = price;
        }
        public void addEngine()
        {
            Console.Write("Please enter info about new wheels:\nRadius: ");
            this.diameter = Convert.ToInt32(Console.ReadLine());
            Console.Write("Width: ");
            this.width = Convert.ToInt32(Console.ReadLine());
            Console.Write("Price: ");
            this.price = Convert.ToDouble(Console.ReadLine());
        }
        public void getInfo()
        {
            Console.WriteLine("Diameter: R{0}\nWidth: {1} mm\nPrice: {2:F2} $\n", diameter, width, price);
        }

    }
}
