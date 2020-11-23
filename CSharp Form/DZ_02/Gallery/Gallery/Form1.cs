using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Gallery
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Gallery.Models.Gallery.AddGallery(listBox1);
        }

        private void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            FileInfo file = listBox1.SelectedItem as FileInfo;
            Bitmap img = new Bitmap(file.FullName);
            if (img.Width > pictureBox1.Width || img.Height > pictureBox1.Height)
                pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            else
                pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;
            pictureBox1.Image = img;
        }
    }
}
