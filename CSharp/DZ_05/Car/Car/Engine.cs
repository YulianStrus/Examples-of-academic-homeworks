using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class Engine
    {

        string type;
        double v;
        int power;
        public double price;
        public Engine() { }
        public void addEngineDefault(string type, double v, int power, double price)
        {
            this.type = type;
            this.v = v;
            this.power = power;
            this.price = price;
        }
        public void addEngine()
        {
            Console.Write("Please enter info about new engine:\nType: ");
            this.type = Console.ReadLine();
            Console.Write("Volume: ");
            this.v = Convert.ToDouble(Console.ReadLine());
            Console.Write("Power: ");
            this.power = Convert.ToInt32(Console.ReadLine());
            Console.Write("Price: ");
            this.price = Convert.ToDouble(Console.ReadLine());
        }
        public void getInfo()
        {
            Console.WriteLine("Type: {0}\nVolume: {1:F2}\nPower: {2} hp\nPrice: {3:F2} $\n", type, v, power, price);
        }

    }
}
