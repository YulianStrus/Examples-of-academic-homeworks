using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PropertyChange
{
    class PropertyEventArgs
    {
        public string Message { get; }
        public string Name { get; }
        public int Age { get; }
        public PropertyEventArgs(string Message, string Name, int Age)
        {
            this.Message = Message;
            this.Name = Name;
            this.Age = Age;
        }
    }
}
