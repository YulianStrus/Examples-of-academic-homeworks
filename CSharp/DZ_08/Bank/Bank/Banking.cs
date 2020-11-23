using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Banking
    {
        Account[] accounts;
        public void AccountDefault()
        {
            Array.Resize(ref accounts, accounts.Length + 5);
            accounts[accounts.Length - 5] = new Account("Ivanov Petro Mukolahovich", "5168757098765432", 358.65);
            accounts[accounts.Length - 4] = new Account("Petrov Mukola Ivanovich", "5168757091732684", 12900);
            accounts[accounts.Length - 3] = new Account("Ivanov Ivan Ivanovich", "5168757025896412", 5365.37);
            accounts[accounts.Length - 2] = new Account("Petrov Petro Petrovich", "5168757064879213", 7755.10);
            accounts[accounts.Length - 1] = new Account("Mukolchuk Mukola Mukolahovich", "5168757012365478", 123);
        }
        public Banking()
        {
            accounts = new Account[0];
        }
        public Account this[int index]
        {
            get { return accounts[index]; }
            set { accounts[index] = value; }
        }
        public void AddClient()
        {
            Array.Resize(ref accounts, accounts.Length + 1);
            accounts[accounts.Length - 1] = new Account();
            accounts[accounts.Length - 1].AddName();
            accounts[accounts.Length - 1].AddNumber();
        }
        public void DeleteClient(int index)
        {
            if (index > accounts.Length)
                Console.WriteLine("Wrong index of client!\n");
            else
            {
                for (int i = index - 1; i < accounts.Length - 1; i++)
                {
                    accounts[i] = accounts[i + 1];
                }
                Array.Resize(ref accounts, accounts.Length - 1);
                ShowClients();
            }
        }
        public bool CheckClient(int index)
        {
            if (index - 1 > accounts.Length)
            {
                Console.WriteLine("Wrong index of client!\n");
                return false;
            }
            else
            {
                Console.Write("\n\t");
                accounts[index - 1].ShowShortInfo();
                Console.WriteLine();
                return true;
            }
        }
        public void Transfer(int sum)
        {
            Console.Write("Please enter account for transfer: ");
            string account = Console.ReadLine();
            for (int i = 0; i < accounts.Length; ++i)
            {
                if (account == accounts[i].Number)
                    accounts[i].RefillSum(sum);
            }
            Console.WriteLine();
        }
        public void ShowClients()
        {
            for (int i = 0; i < accounts.Length; i++)
            {
                Console.Write((i + 1) + ". ");
                accounts[i].ShowShortInfo();
            }
            Console.WriteLine();
        }
        public void SearchClient()
        {
            Console.Write("Please enter name or number of client what you search: ");
            string search = Console.ReadLine();
            int count = 0;
            for (int i = 0; i < accounts.Length; i++)
            {
                if (accounts[i].Name.Contains(search) || accounts[i].Number.Contains(search))
                {
                    count++;
                    Console.Write((i + 1) + ". ");
                    accounts[i].ShowShortInfo();
                }
            }
            if (count == 0) Console.WriteLine("No found");
            Console.WriteLine();
        }
        public void SortClient()
        {
            Console.WriteLine("Please select what sort would you like:\n1. By name\n2. By sum");
            int choose = Convert.ToInt16(Console.ReadLine());
            if (choose == 1)
            {
                Account[] temp = new Account[accounts.Length];
                temp = accounts;
                Account temp2 = new Account();
                for (int i = 0; i < temp.Length - 1; ++i)
                {
                    for (int k = 0; k < temp.Length - i - 1; k++)
                    {
                        if (temp[k].Name.CompareTo(temp[k + 1].Name) > 0)
                        {
                            temp2 = temp[k];
                            temp[k] = temp[k + 1];
                            temp[k + 1] = temp2;
                        }
                    }
                }
                ShowClients();
            }
            else if (choose == 2)
            {
                Account[] temp = new Account[accounts.Length];
                temp = accounts;
                Account temp2 = new Account();
                for (int i = 0; i < temp.Length - 1; ++i)
                {
                    for (int k = 0; k < temp.Length - i - 1; k++)
                    {
                        if (temp[k].Sum.CompareTo(temp[k + 1].Sum) > 0)
                        {
                            temp2 = temp[k];
                            temp[k] = temp[k + 1];
                            temp[k + 1] = temp2;
                        }
                    }
                }
                ShowClients();
            }
            else Console.WriteLine("Wrong select. Have a nice day)\n");
        }
    }

}
