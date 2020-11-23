using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Organizer
{

    [Serializable]
    class Person
    {
        public string Name { get; set; }
        Event[] events;
        public Person()
        {
            events = new Event[0];
        }
        public void InputName()
        {
            Console.Write("Please enter name: ");
            Name = Console.ReadLine();
        }
        public Event this[int index]
        {
            get { return events[index]; }
            set { events[index] = value; }
        }
        public Event[] GetEvents()
        {
            return events;
        }
        public void AddEvent()
        {
            Array.Resize(ref events, events.Length + 1);
            events[events.Length - 1] = new Event();
            events[events.Length - 1].InputDate();
            events[events.Length - 1].InputName();
            events[events.Length - 1].InputDetails();
        }
        public void ShowEvents(int skip)
        {
            int count = events.OrderBy(e => e.date).Skip(skip).Count();
            var orderEvents = events.OrderBy(e => e.date).Skip(skip).Take(3);
            foreach (Event e in orderEvents)
                e.ShowEvent();
            if (count > 3)
            {
                Console.Write("Next page? [y/n]: ");
                char s = Convert.ToChar(Console.ReadLine());
                if (s == 'y')
                    ShowEvents(skip + 3);
            }
        }
    }
}
