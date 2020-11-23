using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class Car : ITransport
    {
        public int Distance { get; set; }
        public Car() { }
        public Car(int Distance) { this.Distance = Distance; }
        public int GetHour()
        {
            return Distance / 50;
        }
        public double GetMin()
        {
            return (Distance/50.0 - GetHour()) * 60;
        }

        public double GetSum()
        {
            return Distance * 8;
        }

        public void Show()
        {
            Console.WriteLine("\tCar: \nCost: \t" + GetSum() + " UAH \nTime: \t" + GetHour() +  "h " + Math.Round(GetMin()) + "min\n");
        }
    }
    class Plane : ITransport
    {
        public int Distance { get; set; }
        public Plane() { }
        public Plane(int Distance) { this.Distance = Distance; }
        public int GetHour()
        {
            return Distance / 350;
        }
        public double GetMin()
        {
            return (Distance / 350.0 - GetHour()) * 60;
        }

        public double GetSum()
        {
            return Distance * 25;
        }

        public void Show()
        {
            Console.WriteLine("\tPlane: \nCost: \t" + GetSum() + " UAH \nTime: \t" + GetHour() + "h " + Math.Round(GetMin()) + "min\n");
        }
    }
    class Ship : ITransport
    {
        public int Distance { get; set; }
        public Ship() { }
        public Ship(int Distance) { this.Distance = Distance; }
        public int GetHour()
        {
            return Distance / 15;
        }
        public double GetMin()
        {
            return (Distance / 15.0 - GetHour()) * 60;
        }

        public double GetSum()
        {
            return Distance * 0.5;
        }

        public void Show()
        {
            Console.WriteLine("\tShip: \nCost: \t" + GetSum() + " UAH \nTime: \t" + GetHour() + "h " + Math.Round(GetMin()) + "min\n");
        }
    }
}
