using Declaration.Models;
using Declaration.MyControls;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Declaration
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (Data.GetPersons().Select(per => per.name).Contains(textBox1.Text))
            {
                MessageBox.Show("Такий громадянин вже є в базі!");
            }
            else
            {
                Person person = new Person(textBox1.Text);
                Data.AddPerson(person);
                button2.Enabled = false;
                flowLayoutPanel1.Controls.Clear();
                DeclarationPanel dp = new DeclarationPanel(flowLayoutPanel1);       
            }
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if(button2.Enabled == false)
            {
                button2.Enabled = true;
            }
        }
    }
}
