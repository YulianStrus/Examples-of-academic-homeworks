using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Declaration.Models
{
    public class Declaration
    {
        public string type { get; set; }
        public string name { get; set; }
        public int price { get; set; }
        public Declaration(string type, string name, string price)
        {
            this.type = type;
            this.name = name;
            this.price = int.Parse(price);
        }
    }
}
