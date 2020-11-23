using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Account
    {
        string name;
        string number;
        double sum;
        double moneyBox;
        int moneyBoxRate;
        int depositSum;
        DateTime depositFinalDate;
        double depositFinalSum;

        public Account() { }
        public Account(string name, string number, double sum)
        {
            this.name = name;
            this.number = number;
            this.sum = sum;
        }

        public string Name { get { return name; } set { name = value; } }
        public string Number { get { return number; } set { number = value; } }
        public double Sum { get { return sum; } set { sum = value; } }
        public double MoneyBox { get { return moneyBox; } set { moneyBox = value; } }
        public int MoneyBoxRate { get { return moneyBoxRate; } set { moneyBoxRate = value; } }
        public int DepositSum { get { return depositSum; } set { depositSum = value; } }
        public DateTime DepositFinalDate { get { return depositFinalDate; } set { depositFinalDate = value; } }
        public double DepositFinalSum { get { return depositFinalSum; } set { depositFinalSum = value; } }

        public void AddName()
        {
            Console.Write("Please enter the full name of client: ");
            name = Console.ReadLine();
        }

        public void AddNumber()
        {
            Console.Write("Please enter the number of account: ");
            number = Console.ReadLine();
        }

        public void RefillSum(double sum)
        {
            if (moneyBoxRate > 0)
            {
                this.sum += (sum * (1 - moneyBoxRate / 100.0));
                RefillMoneyBox(sum * moneyBoxRate / 100);
            }
            else this.sum += sum;
        }
        public void ChargeOffSum(double sum)
        {
            if (sum <= this.sum)
                this.sum -= sum;
            else Console.WriteLine("You don\'t have enough money on this account!\n");
        }
        public bool CheckSum(double sum)
        {
            if (sum <= this.sum)
                return true;
            else return false;
        }
        public void RefillMoneyBox(double sum) { moneyBox += sum; }
        public void ChargeOffMoneyBox(double sum)
        {
            if (sum <= moneyBox)
                moneyBox -= sum;
            else Console.WriteLine("You don\'t have enough money on your money box!\n");
        }
        public void AddMoneyBoxRate()
        {
            if (moneyBoxRate == 0)
            {
                Console.WriteLine("Money box disabled\nDo you wanna create money box?\n1. Yes\n2. No");
                int choose = Convert.ToInt16(Console.ReadLine());
                if (choose == 1)
                {
                    Console.Write("Please enter percents from sum what wil be save in your money box\n(If you don\'t wanna use money box, please enter 0): ");
                    moneyBoxRate = Convert.ToInt16(Console.ReadLine());
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("Money box rate: " + moneyBoxRate + "%");
                Console.WriteLine("Money box: " + moneyBox);
                Console.WriteLine("Do you wanna change money box rate?\n1. Yes\n2. No");
                int choose = Convert.ToInt16(Console.ReadLine());
                if (choose == 1)
                {
                    Console.Write("Please enter percents from sum what wil be save in your money box\n(If you don\'t wanna use money box, please enter 0): ");
                    moneyBoxRate = Convert.ToInt16(Console.ReadLine());
                }
                Console.WriteLine();
            }
        }
        public void AddDepositSum()
        {
            if (depositSum == 0)
            {
                Console.WriteLine("Deposit disabled\nDo you wanna open deposit (14,5%)?\n1. Yes\n2. No");
                int choose = Convert.ToInt16(Console.ReadLine());
                if (choose == 1)
                {
                    Console.Write("Please enter sum what you wanna to put on deposit: ");
                    depositSum = Convert.ToInt32(Console.ReadLine());
                    if (CheckSum(depositSum))
                    {
                        int month = 0;
                        Console.Write("Please enter month (from 6 -18): ");
                        month = Convert.ToInt32(Console.ReadLine());
                        if (month >= 6 && month <= 18)
                        {
                            ChargeOffSum(depositSum);
                            depositFinalDate = DateTime.Now;
                            depositFinalDate = depositFinalDate.AddMonths(month);
                            depositFinalSum = depositSum * Math.Pow((1 + 0.145 / month), month);
                        }
                        else
                        {
                            Console.WriteLine("Wrong month. Please the next time enter from 6-18!");
                            AddDepositSum();
                        }
                    }
                    else
                    {
                        depositSum = 0;
                        Console.WriteLine("Please the next time enter the sum what you have in your account\nOr refill your account! Have nice day)");
                    }
                }
            }
            else
            {
                Console.WriteLine("Deposit sum: " + depositSum);
                Console.WriteLine("Final date of deposit: " + depositFinalDate.ToShortDateString());
                Console.WriteLine("Final sum: {0:F2}", depositFinalSum);
            }
            Console.WriteLine();
        }
        public void ShowFullInfo()
        {
            Console.WriteLine("Full name: " + name);
            Console.WriteLine("Account number: " + number);
            Console.WriteLine("Account sum: " + sum);
            if (moneyBoxRate > 0)
            {
                Console.WriteLine("Money box rate: " + moneyBoxRate + "%");
                Console.WriteLine("Money box: " + moneyBox);
            }
            else Console.WriteLine("Money box: Disabled");
            if (depositSum > 0)
            {
                Console.WriteLine("Deposit sum: " + depositSum);
                Console.WriteLine("Final date of deposit: " + depositFinalDate.ToShortDateString());
                Console.WriteLine("Final sum: {0:F2}", depositFinalSum);
            }
            else Console.WriteLine("Deposit: Disabled");
            Console.WriteLine();
        }
        public void ShowShortInfo()
        {
            Console.WriteLine("{0} - {1} - {2:F2}", name, number, sum);
        }
    }

}
