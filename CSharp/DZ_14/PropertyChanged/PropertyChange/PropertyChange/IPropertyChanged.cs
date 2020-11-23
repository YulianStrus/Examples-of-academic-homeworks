using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PropertyChange
{
    interface IPropertyChanged
    {
        event Property.PropertyEventHandler PropertyChanged;
    }
}
