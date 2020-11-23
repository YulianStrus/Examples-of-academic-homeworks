using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Model;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void RadioButton1_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = true;
            panel2.Visible = false;
            panel3.Visible = false;
            panel4.Visible = false;
        }
        private void RadioButton4_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = true;
            panel3.Visible = false;
            panel4.Visible = false;
        }
        private void RadioButton2_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = false;
            panel3.Visible = true;
            panel4.Visible = false;
        }
        private void RadioButton3_CheckedChanged(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = false;
            panel3.Visible = false;
            panel4.Visible = true;
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            if (radioButton5.Checked == true)
            {
            Data.addPerson(textBox1.Text, textBox2.Text, radioButton5.Text);
            textBox1.Text = "";
            textBox2.Text = "";
            radioButton5.Checked = false;
            radioButton6.Checked = false;
            }
            else if (radioButton6.Checked == true)
            {
            Data.addPerson(textBox1.Text, textBox2.Text, radioButton6.Text);
            textBox1.Text = "";
            textBox2.Text = "";
            radioButton5.Checked = false;
            radioButton6.Checked = false;
            }
            else MessageBox.Show("Виберіть стать!");
        }



        private void Button2_Click(object sender, EventArgs e)
        {
            Data.showPersons(textBox);
        }



        private void Button3_Click(object sender, EventArgs e)
        {
            Data.EditPerson(textBox3, textBox4, textBox5, textBox6);
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";

            label8.Visible = false;
            label9.Visible = false;
            label10.Visible = false;
            textBox4.Visible = false;
            textBox5.Visible = false;
            textBox6.Visible = false;
            button4.Visible = false;
        }


        private void Button5_Click_1(object sender, EventArgs e)
        {
            Data.deletePerson(textBox7);
            textBox7.Text = "";

            label13.Visible = false;
            label14.Visible = false;
            label15.Visible = false;
            button5.Visible = false;
            button4.Visible = false;
        }

        private void Button3_Click_1(object sender, EventArgs e)
        {
            label8.Visible = true;
            label9.Visible = true;
            label10.Visible = true;
            textBox4.Visible = true;
            textBox5.Visible = true;
            textBox6.Visible = true;
            button4.Visible = true;
            Data.EditPersonShow(textBox3, textBox4, textBox5, textBox6);
        }

        private void Button6_Click_1(object sender, EventArgs e)
        {
            label13.Visible = true;
            label14.Visible = true;
            label15.Visible = true;
            button5.Visible = true;
            Data.DelPersonShow(textBox7, label13, label14, label15);
        }
    }
}
