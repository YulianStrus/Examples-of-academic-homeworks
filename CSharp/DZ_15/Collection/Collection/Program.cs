using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collection
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please enter text: ");
            //string text = Console.ReadLine();
            string text = "Вот дом, Который построил Джек. А это пшеница, Которая в темном чулане хранится В доме, Который построил Джек. А это веселая птица-синица, Которая часто ворует пшеницу, Которая в темном чулане хранится В доме, Который построил Джек.";
            string[] words = text.ToLower().Split(new char[] { ' ', ',', '.', '!', '?', '-', '\"', ';', ':' }, StringSplitOptions.RemoveEmptyEntries);
            Dictionary<string, int> statistic = new Dictionary<string, int>();
            foreach (string word in words)
            {
                if (!statistic.ContainsKey(word))
                    statistic.Add(word, 1);
                else
                    statistic[word] += 1;
            }
            foreach (KeyValuePair<string, int> keyValue in statistic)
            {
                Console.WriteLine("{0} - {1}", keyValue.Key, keyValue.Value);
            }
            Console.ReadKey();
        }
    }
}
