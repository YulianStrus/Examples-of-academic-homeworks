using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    class Program
    {
        static void Add(ref Person[] person)
        {
            Array.Resize(ref person, person.Length + 1);
            person[person.Length - 1] = new Person();
            person[person.Length - 1].AddPerson();
        }
        static void Sort(ref Person[] person)
        {
            if (person.Length == 0) Console.WriteLine("Empty! Please add first person");
            else
            {
                Person temp = new Person();
                for (int i = 0; i < person.Length - 1; ++i)
                {
                    for (int k = 0; k < person.Length - i - 1; ++k)
                    {
                        if (person[k].GetName().CompareTo(person[k + 1].GetName()) > 0)
                        {
                            temp = person[k];
                            person[k] = person[k + 1];
                            person[k + 1] = temp;
                        }
                    }
                }
                Console.WriteLine("\t\tPersons");
                for (int i = 0; i < person.Length; ++i)
                {
                    Console.Write("\n" + (i + 1) + ". ");
                    person[i].Show();
                }
            }

        }
        static void Remove(ref Person[] person)
        {
            if (person.Length == 0) Console.WriteLine("Empty! Please add first person");
            else
            {
                Console.Write("Please enter index what you wanna delete:");
                int index = Convert.ToInt32(Console.ReadLine());
                if (index > person.Length - 1)
                    Console.WriteLine("Not this index in array!");
                else
                {
                    for (int i = index; i < person.Length - 1; i++)
                    {
                        person[i] = person[i + 1];
                    }
                    Array.Resize(ref person, person.Length - 1);
                    Console.WriteLine("\t\tPersons");
                    for (int i = 0; i < person.Length; ++i)
                    {
                        Console.Write("\n" + (i + 1) + ". ");
                        person[i].Show();
                    }
                }
            }
        }

        static void Main()
        {
            Person[] p = new Person[0];
            int m = 1;
            while (m!=0)
            { 
            Console.WriteLine("1. Add person\n2. Show all\n3. Search\n4. Sort\n5. Remove\n0. Exit");
            m = Convert.ToInt32(Console.ReadLine());
            switch (m)
            {
                case 0: break;
                case 1:
                    Add(ref p);
                    break;
                case 2:
                    if (p.Length == 0) Console.WriteLine("Empty! Please add first person");
                    else
                    {
                        Console.WriteLine("\t\tPersons");
                        for (int i = 0; i < p.Length; ++i)
                        {
                            Console.Write("\n" + (i + 1) + ". ");
                            p[i].Show();
                        }
                    }
                    break;
                case 3:
                    Console.Write("Please enter what you\'re searching: ");
                    string st = Console.ReadLine();
                    int count = 0;
                    for (int i = 0; i < p.Length; ++i)
                    {
                        if (p[i].Search(st))
                        {
                            count++;
                            Console.WriteLine(count + ". ");
                            p[i].Show();
                        }
                    }
                    if (count == 0) Console.WriteLine("Not found");
                    break;
                case 4:
                    Sort(ref p);
                    break;
                case 5:
                    Remove(ref p);
                    break;
            }
            }
            Console.ReadKey();
        }
    }
}
