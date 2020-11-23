using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class Program
    {
        static void CarCost(User us)
        {
            Car c = new Car(us.Distance);
            c.Show();
        }
        static void PlaneCost(User us)
        {
            Plane p = new Plane(us.Distance);
            p.Show();
        }
        static void ShipCost(User us)
        {
            Ship s = new Ship(us.Distance);
            s.Show();
        }

        static void Main(string[] args)
        {
            User us = new User();
            us.AddStart();
            us.AddFinish();
            us.AddDistance();
            Console.WriteLine("\n\t" + us.Start + " - " + us.Finish + "\nDistance: \t" + us.Distance + " km\n");
            CarCost(us);
            PlaneCost(us);
            ShipCost(us);

            Console.ReadKey();
        }
    }
}
