using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class User : IAccount
    {
        public int Distance { get; set; }
        public string Start { get; set; }
        public string Finish { get; set; }
        public User() { }
        public void AddDistance()
        {
            Console.Write("Enter distance: ");
            Distance = Convert.ToInt32(Console.ReadLine());
        }

        public void AddFinish()
        {
            Console.Write("Enter city of destination: ");
            Finish = Console.ReadLine();
        }

        public void AddStart()
        {
            Console.Write("Enter sender city: ");
            Start = Console.ReadLine();
        }
    }
}
