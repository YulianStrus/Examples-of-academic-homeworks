using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Follow
{
    class Program
    {
        static List<Person> StudentDefault(List<Person> ar)
        {
            Student s1 = new Student("Bill", 2001, 5, 21, "male", "Programer", 10, 2018, 9, 1);
            ar.Add(s1);
            return ar;
        }
        static List<Person> TeacherDefault(List<Person> ar)
        {
            Teacher t1 = new Teacher("Joan", 2004, 11, 11, "female", "History", 3200, "hight", 30);
            ar.Add(t1);
            return ar;
        }
        static List<Person> TechStaffDefault(List<Person> ar)
        {
            TechStaff ts1 = new TechStaff("Genry", 2004, 6, 18, "male", 4500, 22);
            ar.Add(ts1);
            return ar;
        }
        static void Search(List<Person> ar)
        {
            int count = 0;
            Console.Write("Please enter the name what are you looking for: ");
            string search = Console.ReadLine();
            for (int i = 0; i < ar.Count; ++i)
            {
                if (ar[i].Name.Contains(search))
                {
                    if (ar[i].GetType() == typeof(Student))
                        ((Student)ar[i]).Show();
                    if (ar[i].GetType() == typeof(Teacher))
                        ((Teacher)ar[i]).Show();
                    if (ar[i].GetType() == typeof(TechStaff))
                        ((TechStaff)ar[i]).Show();
                    count++;
                }
            }
            if (count == 0) Console.WriteLine("Not found!\n");
        }
        static double SortPaycheck(Person p)
        {
            if (p.GetType() == typeof(Student))
                return ((Student)p).Paycheck();
            if (p.GetType() == typeof(Teacher))
                return ((Teacher)p).Paycheck();
            if (p.GetType() == typeof(TechStaff))
                return ((TechStaff)p).Paycheck();
            else return 0;
        }
        static void Sort(List<Person> ar)
        {
            Person p = new Person();
            for (int i = 0; i < ar.Count - 1; ++i)
            {
                for (int k = 0; k < ar.Count - i - 1; ++k)
                {
                    if (SortPaycheck(ar[k]) > SortPaycheck(ar[k + 1]))
                    {
                        p = ar[k];
                        ar[k] = ar[k + 1];
                        ar[k + 1] = p;
                    }
                }
            }
            for (int i = 0; i < ar.Count; ++i)
            {
                if (ar[i].GetType() == typeof(Teacher))
                    ((Teacher)ar[i]).Show();
                if (ar[i].GetType() == typeof(TechStaff))
                    ((TechStaff)ar[i]).Show();
            }
        }
        static void MenuPersons(List<Person> ar)
        {
            Console.WriteLine("1. Student\n2. Teacher\n3. Technical staff\n0. Back");
            int select = Convert.ToInt16(Console.ReadLine());
            switch (select)
            {
                case 0:
                    break;
                case 1:
                    for (int i = 0; i < ar.Count; ++i)
                    {
                        if (ar[i].GetType() == typeof(Student))
                            ((Student)ar[i]).Show();
                    }
                    MenuPersons(ar);
                    break;
                case 2:
                    for (int i = 0; i < ar.Count; ++i)
                    {
                        if (ar[i].GetType() == typeof(Teacher))
                            ((Teacher)ar[i]).Show();
                    }
                    MenuPersons(ar);
                    break;
                case 3:
                    for (int i = 0; i < ar.Count; ++i)
                    {
                        if (ar[i].GetType() == typeof(TechStaff))
                            ((TechStaff)ar[i]).Show();
                    }
                    MenuPersons(ar);
                    break;
                default:
                    Console.WriteLine("Wrong select, try again!\n");
                    MenuPersons(ar);
                    break;
            }
        }
        static void Main(string[] args)
        {
            List<Person> ar = new List<Person>();
            ar = StudentDefault(ar);
            ar = TeacherDefault(ar);
            ar = TechStaffDefault(ar);
            int select = 1;
            while (select!=0)
            {
                Console.WriteLine("1. Show\n2. Search\n3. Sort\n0. Exit");
                select = Convert.ToInt16(Console.ReadLine());
                switch (select)
                {
                    case 0: break;
                    case 1:
                        MenuPersons(ar);
                        break;
                    case 2:
                        Search(ar);
                        break;
                    case 3:
                        Sort(ar);
                        break;
                    default:
                        Console.WriteLine("Wrong select, try again!\n");
                        break;
                }
            }

            Console.ReadKey();
        }
    }
}
