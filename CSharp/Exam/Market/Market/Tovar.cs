using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Market
{
    class Tovar
    {
        private string Name { get; set; }
        private double Price { get; set; }
        private int Number { get; set; }
        public void AddTovar()
        {
            Console.Write("Please enter name: ");
            Name = Console.ReadLine(); 
            Console.Write("Please enter price: ");
            Price = Convert.ToDouble(Console.ReadLine()); 
            Console.Write("Please enter number: ");
            Number = Convert.ToInt32(Console.ReadLine());
        }
        public void Add(ref Tovar[] tovar)
        {
            Array.Resize(ref tovar, tovar.Length + 1);
            tovar[tovar.Length - 1] = new Tovar();
            tovar[tovar.Length - 1].AddTovar();
        }
        public void ShowGoods()
        {
            Console.WriteLine("Name: {0}\t\tPrice: {1:F2}", Name, Price);
        }
        public void FindGoods()
        {
            
        }
        public void SortBy()
        {

        }
    }
}