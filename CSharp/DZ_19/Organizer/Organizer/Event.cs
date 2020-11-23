using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Organizer
{
    [Serializable]
    class Event
    {
        public DateTime date { get; set; }
        string nameEvent;
        string details;
        public void InputDate()
        {
            Console.Write("Please enter date: ");
            string d = Console.ReadLine();
            DateTime dt_temp;
            if (DateTime.TryParse(d, out dt_temp))
            {
                date = dt_temp;
            }
            else
            {
                Console.WriteLine("Wrong date! Please try again\n");
                InputDate();
            }
        }
        public void InputName()
        {
            Console.Write("Please enter event name: ");
            nameEvent = Console.ReadLine();
        }
        public void InputDetails()
        {
            Console.Write("Please enter some details: ");
            details = Console.ReadLine();
        }
        public void ShowEvent()
        {
            Console.WriteLine(date.ToShortDateString());
            Console.WriteLine(nameEvent);
            Console.WriteLine("Details: " + details);
            Console.WriteLine();
        }
    }
}
