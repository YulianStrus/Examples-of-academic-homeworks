using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Weather
{
    class Program
    {
        static void Weather()
        {
            try
            {
                Console.Write("Please enter the city: ");
                string city = Console.ReadLine();
                string api = "http://api.apixu.com/v1/forecast.xml?key=5742bec32f4141e08db171907171010&q=" + city.ToLower();
                Console.WriteLine();
                XmlReader xmlFile;
                xmlFile = XmlReader.Create(api);
                XmlDocument xDoc = new XmlDocument();
                xDoc.Load(xmlFile);
                XmlElement xRoot = xDoc.DocumentElement;
                foreach (XmlNode xnode in xRoot)
                {
                    if (xnode.Name == "location")
                    {
                        foreach (XmlNode childnode in xnode)
                        {
                            if (childnode.Name == "name")
                                Console.Write("\t" + childnode.InnerText + ", ");
                            if (childnode.Name == "region")
                                Console.Write(childnode.InnerText + ", ");
                            if (childnode.Name == "country")
                                Console.WriteLine(childnode.InnerText + "\n");
                        }
                    }
                    if (xnode.Name == "current")
                    {
                        foreach (XmlNode childnode in xnode)
                        {
                            if (childnode.Name == "temp_c")
                                Console.Write("Current temperature: " + childnode.InnerText + "°С - ");
                            if (childnode.Name == "condition")
                            {
                                foreach (XmlNode childnodeCondition in childnode)
                                {
                                    if (childnodeCondition.Name == "text")
                                        Console.WriteLine(childnodeCondition.InnerText);
                                }
                            }
                            if (childnode.Name == "feelslike_c")
                                Console.WriteLine("Feel's like: " + childnode.InnerText + "°С\n");

                        }
                    }
                    if (xnode.Name == "forecast")
                    {
                        foreach (XmlNode childnode in xnode)
                        {
                            if (childnode.Name == "forecastday")
                            {
                                foreach (XmlNode childnodeForecast in childnode)
                                {
                                    if (childnodeForecast.Name == "day")
                                    {
                                        foreach (XmlNode childnodeDay in childnodeForecast)
                                        {
                                            if (childnodeDay.Name == "maxtemp_c")
                                                Console.WriteLine("Max. temp.: " + childnodeDay.InnerText + "°С");
                                            if (childnodeDay.Name == "mintemp_c")
                                                Console.WriteLine("Min. temp.: " + childnodeDay.InnerText + "°С\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Console.Write("Do you wanna try again? [y/n] ");
                char s = Convert.ToChar(Console.ReadLine());
                Console.WriteLine();
                if (s == 'y')
                    Weather();
            }
            catch
            {
                Console.WriteLine("Not found this city!\n");
                Weather();
            }
        }
        static void Main(string[] args)
        {
            Weather();
            Console.ReadKey();
        }
    }
}
