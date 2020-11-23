using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1.Model
{
    class Data
    {
        public static List<Person> persons = new List<Person>();
        public static void addPerson(string PIB, string Age, string Sex)
        {
            persons.Add(new Person(PIB, Age, Sex));
        }
        public static void showPersons(TextBox tx)
        {
            int count = 0;
            tx.Text = "";
            foreach (Person person in persons)
            {
                count++;
                tx.Text += count + ". " + person.showPerson() + Environment.NewLine;
            }
        }
        public static void deletePerson(TextBox tx)
        {
            int index = int.Parse(tx.Text);
            if (index > persons.Count || index <= 0)
            {
                MessageBox.Show("Запису не знайдено!");
            }

            else
            {
                persons.RemoveAt(index - 1);
            }

        }
        public static void EditPerson(TextBox tx1, TextBox tx2, TextBox tx3, TextBox tx4)
        {
            int index = int.Parse(tx1.Text);
            if (index > persons.Count || index <= 0)
            {
                MessageBox.Show("Запису не знайдено!");
            }

            else
            {
                persons[index - 1].PIB = tx2.Text;
                persons[index - 1].Age = int.Parse(tx3.Text);
                persons[index - 1].Sex = tx4.Text;
            }
        }
        public static void EditPersonShow(TextBox tx1, TextBox tx2, TextBox tx3, TextBox tx4)
            {
                int index = int.Parse(tx1.Text);
                if (index > persons.Count || index <= 0)
                {
                    MessageBox.Show("Запису не знайдено!");
                }

                else
                {
                int stx3 = persons[index - 1].Age;
                    tx2.Text = persons[index - 1].PIB;
                    tx3.Text = stx3.ToString();
                    tx4.Text = persons[index - 1].Sex;
                }
        }
        public static void DelPersonShow(TextBox tx1, Label tx2, Label tx3, Label tx4)
        {
            int index = int.Parse(tx1.Text);
            if (index > persons.Count || index <= 0)
            {
                MessageBox.Show("Запису не знайдено!");
            }

            else
            {
                int stx3 = persons[index - 1].Age;
                tx2.Text = persons[index - 1].PIB;
                tx3.Text = stx3.ToString();
                tx4.Text = persons[index - 1].Sex;
            }
        }
    }
}