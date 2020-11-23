using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Market
{
    class Cart
    {
        private string Name { get; set; }
        private double Price { get; set; }
        private int Number { get; set; }
        private double Sum { get; set; }
        public void AddCart()
        {
            Console.Write("Please enter name: ");
            Name = Console.ReadLine();
            Console.Write("Please enter price: ");
            Price = Convert.ToDouble(Console.ReadLine());
            Console.Write("Please enter number: ");
            Number = Convert.ToInt32(Console.ReadLine());
            Sum = Price * Number;
        }
        public void Add(ref Cart[] cart)
        {
            Array.Resize(ref cart, cart.Length + 1);
            cart[cart.Length - 1] = new Cart();
            cart[cart.Length - 1].AddCart();
        }
        public void PrintCheck()
        {
            Console.WriteLine("Name: {0}\nPrice: {1:F2} uah\nNumber: {2}\nSum: {3} uah\n", Name, Price, Number, Sum);
        }
    }
}