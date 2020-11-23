using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Gallery.Models
{
    public static class Gallery
    {
        public static string Path { get; set; }
        public static void AddGallery(ListBox cb)
        {
            Path = System.IO.Directory.GetCurrentDirectory() + "\\img";
            DirectoryInfo dir = new DirectoryInfo(Path);
            cb.Items.AddRange(dir.GetFiles());
        }
    }
}
