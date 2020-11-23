using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Program
    {
        static void MainMenu(Banking bank)
        {
            Console.WriteLine("1. Add client\n2. Delete client\n3. Show clients\n4. Search client\n5. Sort clients\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 0: break;
                case 1:
                    bank.AddClient();
                    MainMenu(bank);
                    break;
                case 2:
                    Console.Write("Please enter the index of client what you wanna delete: ");
                    int index = Convert.ToInt32(Console.ReadLine());
                    bank.DeleteClient(index);
                    MainMenu(bank);
                    break;
                case 3:
                    bank.ShowClients();
                    SelectMenu(bank);
                    break;
                case 4:
                    bank.SearchClient();
                    MainMenu(bank);
                    break;
                case 5:
                    bank.SortClient();
                    MainMenu(bank);
                    break;
                default:
                    Console.WriteLine("Wrong select number! Please try again!\n");
                    MainMenu(bank);
                    break;
            }
        }
        static void SelectMenu(Banking bank)
        {
            Console.Write("Please enter index of client, what you wanna choose\n(If you wanna back please enter 0): ");
            int index = Convert.ToInt32(Console.ReadLine());
            if (index == 0) MainMenu(bank);
            else
            {
                if (bank.CheckClient(index))
                    ClientMenu(bank, index - 1);
                else MainMenu(bank);

            }
        }
        static void ClientMenu(Banking bank, int index)
        {
            Console.WriteLine("1. Show info about client\n2. Add money to account\n3. Charge off money from account\n4. Transfer money\n5. Money box\n6. Deposit\n0. Back");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 0:
                    MainMenu(bank);
                    break;
                case 1:
                    bank[index].ShowFullInfo();
                    ClientMenu(bank, index);
                    break;
                case 2:
                    Console.Write("Please enter sum, what you wanna add:");
                    int sum = Convert.ToInt32(Console.ReadLine());
                    bank[index].RefillSum(sum);
                    ClientMenu(bank, index);
                    break;
                case 3:
                    Console.Write("Please enter sum, what you wanna charge off:");
                    int chargeoff = Convert.ToInt32(Console.ReadLine());
                    bank[index].ChargeOffSum(chargeoff);
                    ClientMenu(bank, index);
                    break;
                case 4:
                    Console.Write("Please enter sum, what you wanna transfer:");
                    int sumTransfer = Convert.ToInt32(Console.ReadLine());
                    if (bank[index].CheckSum(sumTransfer))
                    {
                        bank[index].ChargeOffSum(sumTransfer);
                        bank.Transfer(sumTransfer);
                    }
                    ClientMenu(bank, index);
                    break;
                case 5:
                    bank[index].AddMoneyBoxRate();
                    ClientMenu(bank, index);
                    break;
                case 6:
                    bank[index].AddDepositSum();
                    ClientMenu(bank, index);
                    break;

                default:
                    ClientMenu(bank, index);
                    break;
            }
        }
        static void Main(string[] args)
        {
            Banking bank = new Banking();
            bank.AccountDefault();
            MainMenu(bank);
            Console.ReadKey();
        }
    }

}
