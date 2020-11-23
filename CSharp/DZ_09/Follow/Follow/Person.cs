using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Follow
{
    class Person
    {
        private string name;
        private DateTime dataBirth;
        private string gender;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public DateTime DataBirth
        {
            get { return dataBirth; }
            set { dataBirth = value; }
        }
        public string Gender
        {
            get { return gender; }
            set { gender = value; }
        }
        public Person() { }
        public Person(string name, int day, int month, int year, string gender)
        {
            this.name = name;
            DataBirth = new DateTime(day, month, year);
            this.gender = gender;
        }
        public void AddName()
        {
            Console.Write("Please enter name: ");
            name = Console.ReadLine();
        }
        public void AddBirthday()
        {
            Console.WriteLine("Please enter birthday:");
            Console.Write("                  Day: ");
            int day = Convert.ToInt16(Console.ReadLine());
            Console.Write("                Month: ");
            int month = Convert.ToInt16(Console.ReadLine());
            Console.Write("                 Year: ");
            int year = Convert.ToInt32(Console.ReadLine());
            dataBirth = new DateTime(year, month, day);
        }
        public void AddGender()
        {
            Console.Write("Please enter gender: ");
            gender = Console.ReadLine();
        }
        public void Show()
        {
            Console.WriteLine("Name: " + name + "\nData: " + DataBirth.ToShortDateString() + "\nGender: " + gender);
        }
        public double Paycheck()
        {
            return 0;
        }
        public void Input()
        {
            AddName();
            AddBirthday();
            AddGender();
        }


    }
    class Student : Person
    {
        private string specialty { get; set; }
        private int gradesBySubject { get; set; }
        private DateTime dateOfEntry { get; set; }

        public Student() { }
        public Student(string Name, int day, int month, int year, string Gender, string specialty, int gradesBySubject, int enterDay, int enterMonth, int enterYear) : base(Name, day, month, year, Gender)
        {
            this.specialty = specialty;
            this.gradesBySubject = gradesBySubject;
            dateOfEntry = new DateTime(enterDay, enterMonth, enterYear);
        }
        public new void Show()
        {
            base.Show();
            Console.WriteLine("Specialty: " + specialty + "\nGgrades By Subject: " + gradesBySubject + "\nDate Of Entry: " + dateOfEntry.ToShortDateString() + "\n");
        }
    }

    class Teacher : Person
    {
        private string specialization { get; set; }
        private int rate { get; set; }
        private string category { get; set; }
        private int hpm { get; set; }

        public Teacher() { }
        public Teacher(string Name, int day, int month, int year, string Gender, string specialization, int rate, string category, int hpm) : base(Name, day, month, year, Gender)
        {
            this.specialization = specialization;
            this.rate = rate;
            this.category = category;
            this.hpm = hpm;
        }
        public new void Show()
        {
            base.Show();
            Console.WriteLine("Specialization: " + specialization + "\nRate: " + rate + "\nCategory: " + category + "\nNumber of hours worked per month: " + hpm + "\nPaycheck: " + Paycheck() + "\n");
        }
        public new double Paycheck()
        {
            return rate + hpm * 62;
        }
    }

    class TechStaff : Person
    {
        private int rate { get; set; }
        private int wpm { get; set; }

        public TechStaff () { }
        public TechStaff(string Name, int day, int month, int year, string Gender, int rate, int wpm) : base(Name, day, month, year, Gender)
        {
            this.rate = rate;
            this.wpm = wpm;
        }
        public new void Show()
        {
            base.Show();
            Console.WriteLine("Rate: " + rate + "\nNumber of day worked per month: " + wpm + "\nPaycheck: " + Paycheck() + "\n");
        }
        public new double Paycheck()
        {
            return rate + wpm * 408.25;
        }
    }
}
