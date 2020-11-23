using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace Organizer
{
    class Program
    {
        static void SearchByDate(List<Person> persons)
        {
            Console.Write("Please enter date: ");
            string d = Console.ReadLine();
            DateTime date;
            if (DateTime.TryParse(d, out date))
            {
                //var searchDate = from person in persons
                //                 from events in person.GetEvents()
                //                 where events.date == date
                //                 select events;
                var searchDate = persons.SelectMany(p => p.GetEvents(), (p, e) => new { events = e }).Where(e => e.events.date == date).Select(e => e.events);
                foreach (Event s in searchDate)
                {
                    //var selectPerson = from person in persons
                    //                   from events in person.GetEvents()
                    //                   where events == s
                    //                   select person;
                    var selectPerson = persons.SelectMany(p => p.GetEvents(), (p, e) => new { person = p, events = e }).Where(e => e.events == s).Select(p => p.person);
                    foreach (Person p in selectPerson)
                    {
                        Console.WriteLine(p.Name);
                        Console.WriteLine();
                    }
                    s.ShowEvent();
                }

            }
            else
            {
                Console.WriteLine("Wrong date! Please try again\n");

            }
        }
        static void GroupByDate(List<Person> persons)
        {
            var groupEvents = from person in persons
                              from events in person.GetEvents()
                              select events;
            var groupDate = from events in groupEvents
                            orderby events.date
                            group events by events.date;

            foreach (var events in groupDate)
            {
                foreach (Event e in events)
                    e.ShowEvent();
                Console.WriteLine();
            }
        }
        static void Sort(List<Person> persons)
        {
            var sortName = persons.OrderBy(p => p.Name);
            int count = 0;
            foreach (Person p in sortName)
            {
                count++;
                Console.WriteLine(count + ". " + p.Name);
            }
            Console.WriteLine();
        }
        static void Search(List<Person> persons)
        {
            Console.Write("Please enter name what are you looking for: ");
            string s = Console.ReadLine();
            var searchName = persons.Where(p => p.Name.Contains(s));
            if (searchName != null)
            {
                int count = 0;
                foreach (Person p in searchName)
                {
                    count++;
                    Console.WriteLine(count + ". " + p.Name);
                }
                Console.WriteLine();
            }
            else Console.WriteLine("Not found\n");
        }
        static void Serialization(List<Person> persons)
        {
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, persons);
            }
        }
        static List<Person> Deserialization(List<Person> persons)
        {
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                persons = (List<Person>)formatter.Deserialize(fs);
            }
            return persons;
        }
        static List<Person> AddPerson(List<Person> persons)
        {
            Person p = new Person();
            p.InputName();
            persons.Add(p);
            return persons;
        }
        static void ShowPersons(List<Person> persons)
        {
            int count = 0;
            foreach (Person p in persons)
            {
                count++;
                Console.WriteLine(count + ". " + p.Name);
            }
            Console.WriteLine();
        }
        static void MenuEvent(Person p)
        {
            Console.WriteLine("\t" + p.Name);
            Console.WriteLine();
            Console.WriteLine("1. Add event\n2. Show events\n0. Back");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 0:
                    break;
                case 1:
                    p.AddEvent();
                    MenuEvent(p);
                    break;
                case 2:
                    p.ShowEvents(0);
                    MenuEvent(p);
                    break;
            }
        }
        static void SelectMenu(List<Person> persons)
        {
            Console.Write("Choose person? [y/n]: ");
            char s = Convert.ToChar(Console.ReadLine());
            if (s == 'y')
            {
                Console.Write("Please enter the index of person: ");
                int index = Convert.ToInt32(Console.ReadLine());
                if (index - 1 <= persons.Count())
                {
                    MenuEvent(persons[index - 1]);
                    Serialization(persons);
                    Menu(persons);
                }
                else
                {
                    Console.WriteLine("The wrong index!");
                    Menu(persons);
                }
            }
            else Menu(persons);
        }
        static void Menu(List<Person> persons)
        {
            Console.WriteLine("1. Add person\n2. Show persons\n3. Search by name\n4. Sort by name\n5. Search by date\n6. Group by date\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 0: break;
                case 1:
                    persons = AddPerson(persons);
                    MenuEvent(persons[persons.Count() - 1]);
                    Serialization(persons);
                    Menu(persons);
                    break;
                case 2:
                    ShowPersons(persons);
                    SelectMenu(persons);
                    break;
                case 3:
                    Search(persons);
                    Menu(persons);
                    break;
                case 4:
                    Sort(persons);
                    Menu(persons);
                    break;
                case 5:
                    SearchByDate(persons);
                    Menu(persons);
                    break;
                case 6:
                    GroupByDate(persons);
                    Menu(persons);
                    break;
            }
        }
        static void Main(string[] args)
        {
            List<Person> persons = new List<Person>();
            Menu(persons);
            persons = Deserialization(persons);
            //p.InputName();
            //p.AddEvent();
            //p.AddEvent();
            //p.AddEvent();
            //p.AddEvent();
            //p.AddEvent();
            //p.ShowEvents(0);
            ////using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            ////{
            ////    formatter.Serialize(fs, p);
            ////}
            //using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            //{
            //    List<Person> newPerson = (List<Person>)formatter.Deserialize(fs);
            //}
            Console.ReadKey();
        }
    }
}
