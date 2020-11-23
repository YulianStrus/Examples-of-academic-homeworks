using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    interface ITransport
    {
        int Distance { get; set; }
        double GetSum();
        int GetHour();
        double GetMin();
        void Show();
    }
}
