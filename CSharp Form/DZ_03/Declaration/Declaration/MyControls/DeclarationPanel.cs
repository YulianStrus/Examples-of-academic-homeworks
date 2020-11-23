using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Declaration.MyControls
{
    class DeclarationPanel:Panel
    {
        public DeclarationPanel(FlowLayoutPanel flp)
        {
            Width = 230;
            Height = 250;
            Panel p = new Panel();
            p.Width = 230;
            p.Height = 250;
            p.BorderStyle = BorderStyle.FixedSingle;
            Label l1 = new Label();
            l1.Width = 220;
            l1.Location = new Point(5, 5);
            l1.Text = "Виберіть тип:";
            p.Controls.Add(l1);
            string[] types = { "Нерухомість", "Рухоме майно", "Транспортні засоби" };
            ComboBox comboBox = new ComboBox();
            comboBox.Name = "combobox";
            comboBox.Location = new Point(5, 28);
            comboBox.Items.AddRange(types);
            comboBox.Width = 220;
            comboBox.FlatStyle = FlatStyle.Popup;
            p.Controls.Add(comboBox);
            Label l2 = new Label();
            l2.Width = 220;
            l2.Location = new Point(5, 55);
            l2.Text = "Введіть назву:";
            p.Controls.Add(l2);
            TextBox tx1 = new TextBox();
            tx1.Width = 220;
            tx1.Location = new Point(5, 79);
            p.Controls.Add(tx1);
            Label l3 = new Label();
            l3.Width = 220;
            l3.Location = new Point(5, 106);
            l3.Text = "Введіть ціну:";
            p.Controls.Add(l3);
            TextBox tx2 = new TextBox();
            tx2.Width = 220;
            tx2.Location = new Point(5, 130);
            p.Controls.Add(tx2);
            Label l4 = new Label();
            l4.Width = 220;
            l4.Location = new Point(5, 154);
            l4.Text = "Виберіть дату набуття:";
            p.Controls.Add(l4);
            DateTimePicker dtp = new DateTimePicker();
            dtp.Location = new Point(5, 178);
            p.Controls.Add(dtp);
            Button bt = new Button();
            bt.Height = 28;
            bt.FlatStyle = FlatStyle.Popup;
            bt.Text = "Додати";
            bt.Location = new Point(148, 210);
            bt.Click += new EventHandler((sender, e) => button_Click(sender, e, flp));
            p.Controls.Add(bt);
            flp.Controls.Add(p);
            //Controls["bt"].Click += new System.EventHandler(this.button_Click);
        }

        public void button_Click(object sender, EventArgs e, FlowLayoutPanel flp)
        {
            //flp.Controls.RemoveAt(flp.Controls.Count - 1);
            Width = 230;
            Height = 205;
            Panel p = new Panel();
            p.Width = 230;
            p.Height = 205;
            p.BorderStyle = BorderStyle.FixedSingle;
            Button bt = new Button();
            bt.Width = 20;
            bt.Height = 20;
            bt.FlatStyle = FlatStyle.Flat;
            bt.FlatAppearance.BorderSize = 0;
            bt.FlatAppearance.MouseDownBackColor = Color.Transparent;
            bt.FlatAppearance.MouseOverBackColor = Color.Transparent;
            bt.Location = new Point(205, 5);
            bt.Click += new EventHandler((senderTemp, eTemp) => buttonPanel_Click(senderTemp, eTemp, p, flp));
            p.Controls.Add(bt);

            Label l1 = new Label();
            l1.Width = 220;
            l1.TextAlign = ContentAlignment.MiddleCenter;
            l1.AutoSize = false;
            l1.Location = new Point(5, 5);
            l1.Text = "Тип майна:";
            p.Controls.Add(l1);

            Label l2 = new Label();
            l2.Width = 220;
            l2.TextAlign = ContentAlignment.MiddleCenter;
            l2.AutoSize = false;
            l2.Location = new Point(5, 28);
            l2.Text = flp.Controls[flp.Controls.Count - 1].Controls[1].Text.ToString();
            l2.Font = new Font("Microsoft Sans Serif", 8, System.Drawing.FontStyle.Bold);
            p.Controls.Add(l2);

            Label l3 = new Label();
            l3.Width = 220;
            l3.TextAlign = ContentAlignment.MiddleCenter;
            l3.AutoSize = false;
            l3.Location = new Point(5, 51);
            l3.Text = "Назва майна:";
            p.Controls.Add(l3);
            Label l4 = new Label();
            l4.Width = 220;
            l4.TextAlign = ContentAlignment.MiddleCenter;
            l4.AutoSize = false;
            l4.Location = new Point(5, 74);
            l4.Text = flp.Controls[flp.Controls.Count - 1].Controls[3].Text.ToString();
            l4.Font = new Font("Microsoft Sans Serif", 8, System.Drawing.FontStyle.Bold);
            p.Controls.Add(l4);
            Label l5 = new Label();
            l5.Width = 220;
            l5.TextAlign = ContentAlignment.MiddleCenter;
            l5.AutoSize = false;
            l5.Location = new Point(5, 97);
            l5.Text = "Ціна майна:";
            p.Controls.Add(l5);
            Label l6 = new Label();
            l6.Width = 220;
            l6.TextAlign = ContentAlignment.MiddleCenter;
            l6.AutoSize = false;
            l6.Location = new Point(5, 120);
            l6.Text = flp.Controls[flp.Controls.Count - 1].Controls[5].Text.ToString() + " $";
            l6.Font = new Font("Microsoft Sans Serif", 8, System.Drawing.FontStyle.Bold);
            p.Controls.Add(l6);
            Label l7 = new Label();
            l7.Width = 220;
            l7.TextAlign = ContentAlignment.MiddleCenter;
            l7.AutoSize = false;
            l7.Location = new Point(5, 143);
            l7.Text = "Дата набуття майна:";
            p.Controls.Add(l7);
            Label l8 = new Label();
            l8.Width = 220;
            l8.TextAlign = ContentAlignment.MiddleCenter;
            l8.AutoSize = false;
            l8.Location = new Point(5, 166);
            l8.Text = flp.Controls[flp.Controls.Count - 1].Controls[7].Text.ToString();
            l8.Font = new Font("Microsoft Sans Serif", 8, System.Drawing.FontStyle.Bold);
            p.Controls.Add(l8);
            flp.Controls.RemoveAt(flp.Controls.Count - 1);
            flp.Controls.Add(p);
            DeclarationPanel dp = new DeclarationPanel(flp);
        }
        public void buttonPanel_Click(object sender, EventArgs e, Panel p, FlowLayoutPanel flp)
        {
            flp.Controls.RemoveAt(flp.Controls.GetChildIndex(p));
        }
    }
}
