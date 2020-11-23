using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PropertyChange
{
    class Property:IPropertyChanged
    {
        public delegate void PropertyEventHandler (object sender, PropertyEventArgs e);

        public event PropertyEventHandler PropertyChanged;

        string name;
        int age;

        public Property(string name, int age)
        {
            this.name = name;
            this.age = age;
        }
        public void Show()
        {
            Console.WriteLine("Name: {0}\nAge: {1}\n", name, age);
        }
        public void Add()
        {
            Console.Write("Please enter name: ");
            name = Console.ReadLine();
            Console.Write("Please enter age: ");
            age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
            if(PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyEventArgs("Properties changed!", name, age));
            }
        }

    }
}
