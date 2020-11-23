using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Logger
{
    public class LogManager
    {
        public void Trace(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | TRACE | " + message);
            }
        }
        public void Debug(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | DEBUG | " + message);
            }
        }
        public void Info(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | INFO | " + message);
            }
        }
        public void Warn(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | WARN | " + message);
            }
        }
        public void Error(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | ERROR | " + message);
            }
        }
        public void Fatal(string message)
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Append))
            using (StreamWriter sw = new StreamWriter(fstream))
            {
                sw.WriteLine(DateTime.Now + " | FATAL | " + message);
            }
        }
        public void Show()
        {
            using (FileStream fstream = new FileStream("logger.txt", FileMode.Open))
            using (StreamReader sr = new StreamReader(fstream))
            {
                Console.WriteLine(sr.ReadToEnd());
                Console.WriteLine();
            }
        }
    }
}