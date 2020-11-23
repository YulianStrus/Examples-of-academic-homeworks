using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class CreateCar
    {

        string brand;
        string model;
        Engine en;
        Type t;
        Transmission tr;
        Wheels wh;
        double price;
        public void CarDetail(Engine en, Type t, Transmission tr, Wheels wh)
        {
            this.en = en;
            this.t = t;
            this.tr = tr;
            this.wh = wh;
            this.price = en.price + t.price + tr.price + wh.price;
        }
        public void addCar()
        {
            Console.Write("Please enter info about new car:\nBrand: ");
            this.brand = Console.ReadLine();
            Console.Write("Model: ");
            this.model = Console.ReadLine();
        }
        public void getInfo()
        {
            Console.WriteLine("\t\tYour car:\nBrand: {0}\nModel: {1}", brand, model);
            Console.WriteLine("\tEngine:");
            en.getInfo();
            Console.WriteLine("\tType:");
            t.getInfo();
            Console.WriteLine("\tTransmission:");
            tr.getInfo();
            Console.WriteLine("\tWheels:");
            wh.getInfo();
            Console.WriteLine("\n\t\tPrice:" + price);
        }
    }
}
