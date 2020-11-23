using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PropertyChange
{
    class Program
    {
        static void Main(string[] args)
        {
            Property p = new Property("Ivanov Ivan Ivanovuch", 44);
            p.Show();
            p.PropertyChanged += Show_Message;
            p.Add();
            Console.ReadKey();
        }
        private static void Show_Message(object sender, PropertyEventArgs e)
        {
            Console.WriteLine(e.Message + "\nNew name: " + e.Name + "\nNew age: " + e.Age + "\n");
        }
    }
}
