﻿using Personville.Models;
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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public static List<Person> person = new List<Person>();

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 fr = new Form2();
            fr.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Show fr = new Personville.Show();
            fr.ShowDialog();
        }
    }
}
