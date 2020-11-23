using Personville.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Personville
{
    public partial class Show : Form
    {
        public Show()
        {
            InitializeComponent();
            foreach (Person p in Form1.person)
            {
                dataGridView1.Rows.Add(p.Name.ToString(), p.Age.ToString());
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void dataGridView1_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            Form2 fr = new Form2();
            fr.button1.Text = "Редаг.";
            fr.button1.Click -= fr.button1_Click;
            fr.button1.Click += new EventHandler((s, ev) => fr.button1_Click2(s, ev, e.RowIndex));
            fr.ShowDialog();
            dataGridView1.Rows.Clear();
            foreach (Person p in Form1.person)
            {
                dataGridView1.Rows.Add(p.Name.ToString(), p.Age.ToString());
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        //public void button1_Click2(object sender, EventArgs e, int index)
        //{
        //    Form1.person[index].Name = textBox1.Text;
        //    Form1.person[index].Age = int.Parse(textBox2.Text);
        //}
    }
}
