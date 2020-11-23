using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Market
{
    class Person
    {
        string Username { get; set; }
        string Password { get; set; }

        public void AddPerson()
        {
            Console.Write("Please enter Login: ");
            Username = Console.ReadLine();
            Console.Write("Please enter passord: ");
            Password = Console.ReadLine();          
        }
        public void Add(ref Person[] person)
        {
            Array.Resize(ref person, person.Length + 1);
            person[person.Length - 1] = new Person();
            person[person.Length - 1].AddPerson();
        }
        public bool SearchUsername(string un)
        {
            if (Username.Contains(un)) return true;
            else return false;
        }
        public bool SearchPassword(string pw)
        {
            if (Password.Contains(pw)) return true;
            else return false;
        }
        public void LogIn(ref Person[] person)
        {
            Console.Write("Please enter username: ");
            string un = Console.ReadLine();
            int countUn = 0;
            for (int i = 0; i < person.Length; ++i)
            {
                if (person[i].SearchUsername(un))
                {
                    countUn++;
                }
            }
            if (countUn == 0) Console.WriteLine("Username not found");

            Console.Write("Please enter password: ");
            string pw = Console.ReadLine();
            int countPw = 0;
            for (int i = 0; i < person.Length; ++i)
            {
                if (person[i].SearchPassword(pw))
                {
                    countPw++;
                }
            }
            if (countUn == 0) Console.WriteLine("Password not found");
        }
    }
}