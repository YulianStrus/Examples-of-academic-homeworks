using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Market
{
    class Program
    {
        static void Menu(Person person, Tovar tovar)
        {
            Person[] p = new Person[0];
            Console.WriteLine("1. LogIn\n2. Registered\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    Console.Write("Please enter username: ");
                    string un = Console.ReadLine();
                    int count = 0;
                    for (int i = 0; i < p.Length; ++i)
                    {
                        if (p[i].SearchUsername(un))
                        {
                            count++;

                            Console.Write("Please enter password: ");
                            string pw = Console.ReadLine();
                            for (int j = 0; j < p.Length; ++j)
                            {
                                if (p[j].SearchPassword(pw))
                                {
                                    count++;
                                }
                            }
                        }
                    }
                    if (count == 0) {Console.WriteLine("Username not found!"); Menu(person, tovar); }
                    if (count == 1) {Console.WriteLine("Incorrectly specified login or password!"); Menu(person, tovar); }
                    else MenuTovar(person, tovar);
                    break;
                case 2:
                    person.Add(ref p);
                    MenuTovar(person, tovar);
                    break;                
                case 0:
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    Menu(person, tovar);
                    break;

            }
        }
        static void MenuTovar(Person person, Tovar tovar)
        {
            Console.WriteLine("1. ShowAllGoods\n2. FindGoods\n3. SortBy\n0. Back");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    tovar.ShowGoods();
                    MenuTovar(person, tovar);
                    break;
                case 2:
                    tovar.FindGoods();
                    MenuTovar(person, tovar);
                    break;
                case 3:
                    tovar.SortBy();
                    MenuTovar(person, tovar);
                    break;
                case 0:
                    Menu(person, tovar);
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    MenuTovar(person, tovar);
                    break;
            }
        }

        static void MenuCart(Person person, Tovar tovar, Cart cart)
        {
            Person[] c = new Person[0];
            Console.WriteLine("1. Add\n2. Delete\n0. Back");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    cart.Add(ref c);
                    MenuCart(person, tovar, cart);
                    break;
                case 2:
                    cart.Remove();
                    MenuCart(person, tovar, cart);
                    break;
                case 0:
                    MenuTovar(person, tovar);
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    MenuCart(person, tovar, cart);
                    break;
            }
        }


        static void Main(string[] args)
        {
            Person person = new Person();
            Tovar tovar = new Tovar();
            Cart cart = new Cart();
            Menu(person, tovar);
           

            Console.ReadKey();
        }
    }
}