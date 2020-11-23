using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    class Program
    {

        static Engine[] EngineDefault()
        {
            Engine[] en = new Engine[2];
            en[0] = new Engine();
            en[1] = new Engine();
            en[0].addEngineDefault("Petrol", 1.9, 156, 3000);
            en[1].addEngineDefault("Diesel", 1.6, 102, 1500);
            return en;
        }
        static Type[] TypeDefault()
        {
            Type[] t = new Type[4];
            t[0] = new Type();
            t[1] = new Type();
            t[2] = new Type();
            t[3] = new Type();
            t[0].addTypeDefault("SUV", 6000);
            t[1].addTypeDefault("Crossover", 4000);
            t[2].addTypeDefault("Sedan", 3000);
            t[3].addTypeDefault("Coupe", 5000);
            return t;
        }
        static Transmission[] TransmissionDefault()
        {
            Transmission[] tr = new Transmission[3];
            tr[0] = new Transmission();
            tr[1] = new Transmission();
            tr[2] = new Transmission();
            tr[0].addTransmissionDefault("Mechanical", 5, 1000);
            tr[1].addTransmissionDefault("Automat", 6, 1500);
            tr[2].addTransmissionDefault("Robot", 5, 2000);
            return tr;
        }
        static Wheels[] WheelsDefault()
        {
            Wheels[] wh = new Wheels[2];
            wh[0] = new Wheels();
            wh[1] = new Wheels();
            wh[0].addWheelsDefault(21, 295, 2500);
            wh[1].addWheelsDefault(19, 235, 1500);
            return wh;
        }
        static Engine ChooseEngine(Engine[] en)
        {
            Console.WriteLine("Please choose engine:");
            for (int i = 0; i < en.Length; i++)
            {
                Console.Write((i + 1) + ". ");
                en[i].getInfo();
            }
            int select = Convert.ToInt32(Console.ReadLine());
            if (select <= en.Length)
                return en[select - 1];
            else
            {
                Console.WriteLine("Wrong choose. Try again!");
                return ChooseEngine(en);
            }
        }
        static Type ChooseType(Type[] t)
        {
            Console.WriteLine("Please choose type:");
            for (int i = 0; i < t.Length; i++)
            {
                Console.Write((i + 1) + ". ");
                t[i].getInfo();
            }
            int select = Convert.ToInt32(Console.ReadLine());
            if (select <= t.Length)
                return t[select - 1];
            else
            {
                Console.WriteLine("Wrong choose. Try again!");
                return ChooseType(t);
            }
        }
        static Transmission ChooseTransmission(Transmission[] tr)
        {
            Console.WriteLine("Please choose transmission:");
            for (int i = 0; i < tr.Length; i++)
            {
                Console.Write((i + 1) + ". ");
                tr[i].getInfo();
            }
            int select = Convert.ToInt32(Console.ReadLine());
            if (select <= tr.Length)
                return tr[select - 1];
            else
            {
                Console.WriteLine("Wrong choose. Try again!");
                return ChooseTransmission(tr);
            }
        }
        static Wheels ChooseWheels(Wheels[] wh)
        {
            Console.WriteLine("Please choose wheels:");
            for (int i = 0; i < wh.Length; i++)
            {
                Console.Write((i + 1) + ". ");
                wh[i].getInfo();
            }
            int select = Convert.ToInt32(Console.ReadLine());
            if (select <= wh.Length)
                return wh[select - 1];
            else
            {
                Console.WriteLine("Wrong choose. Try again!");
                return ChooseWheels(wh);
            }
        }
        static void Main(string[] args)
        {
            CreateCar car = new CreateCar();
            car.addCar();
            car.CarDetail(ChooseEngine(EngineDefault()), ChooseType(TypeDefault()), ChooseTransmission(TransmissionDefault()), ChooseWheels(WheelsDefault()));
            car.getInfo();
            Console.ReadKey();
        }
    }
}
