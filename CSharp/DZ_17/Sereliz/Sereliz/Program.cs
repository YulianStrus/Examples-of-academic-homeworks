using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Sereliz
{
    [DataContract]
    [Serializable]
    public class Person
    {
        [DataMember]
        public string Name { get; set; }
        [DataMember]
        public int Age { get; set; }
        public Person() { }
        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }
    class ListPerson
    {
        Person[] persons;
        public ListPerson()
        {
            persons = new Person[0];
        }
        public void AddPerson()
        {
            Console.Write("Please enter name: ");
            string name = Console.ReadLine();
            Console.Write("Please enter age: ");
            int age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
            Person person = new Person(name, age);
            Array.Resize(ref persons, persons.Length + 1);
            persons[persons.Length - 1] = person;
            //persons.Add(person);
        }
        public void DeletePerson()
        {
            Console.Write("Please enter index of person: ");
            int index = Convert.ToInt32(Console.ReadLine());
            if (index <= persons.Length)
            {
                for (int i = index - 1; i < persons.Length - 1; i++)
                {
                    persons[i] = persons[i + 1];
                }
                Array.Resize(ref persons, persons.Length - 1);
                //persons.RemoveAt(index-1);
                Console.WriteLine("The person successfully deleted!\n");
            }
            else Console.WriteLine("Wrong index\n");
        }
        public void EditPerson()
        {
            Console.Write("Please enter index of person: ");
            int index = Convert.ToInt32(Console.ReadLine());
            if (index <= persons.Length)
            {
                Console.Write("Please enter name: ");
                persons[index - 1].Name = Console.ReadLine();
                Console.Write("Please enter age: ");
                persons[index - 1].Age = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("The person successfully edited!\n");
            }
            else Console.WriteLine("Wrong index\n");
        }
        public void ShowPersons()
        {
            int count = 0;
            foreach (Person person in persons)
            {
                count++;
                Console.WriteLine("{0}. {1} --- {2} years", count, person.Name, person.Age);
            }
            Console.WriteLine();
        }
        public void BinarySerialization()
        {
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, persons);
                Console.WriteLine("Persons successfully serialized in binary file!\n");
            }
        }
        public void BinaryDeserialization()
        {
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                persons = (Person[])formatter.Deserialize(fs);
                Console.WriteLine("Persons successfully deserialized from binary file!\n");
            }
        }
        public void SoapSerialization()
        {
            SoapFormatter formatter = new SoapFormatter();
            using (FileStream fs = new FileStream("people.soap", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, persons);
                Console.WriteLine("Persons successfully serialized in soap file!\n");
            }
        }
        public void SoapDeserialization()
        {
            SoapFormatter formatter = new SoapFormatter();
            using (FileStream fs = new FileStream("people.soap", FileMode.OpenOrCreate))
            {
                persons = (Person[])formatter.Deserialize(fs);
                Console.WriteLine("Persons successfully deserialized from soap file!\n");
            }
        }
        public void XmlSerialization()
        {
            XmlSerializer formatter = new XmlSerializer(typeof(Person[]));
            using (FileStream fs = new FileStream("people.xml", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, persons);
                Console.WriteLine("Persons successfully serialized in xml file!\n");
            }
        }
        public void XmlDeserialization()
        {
            XmlSerializer formatter = new XmlSerializer(typeof(Person[]));
            using (FileStream fs = new FileStream("people.xml", FileMode.OpenOrCreate))
            {
                persons = (Person[])formatter.Deserialize(fs);
                Console.WriteLine("Persons successfully deserialized from xml file!\n");
            }
        }
        public void JsonSerialization()
        {
            DataContractJsonSerializer jsonFormatter = new DataContractJsonSerializer(typeof(Person[]));
            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                jsonFormatter.WriteObject(fs, persons);
                Console.WriteLine("Persons successfully serialized in json file!\n");
            }
        }
        public void JsonDeserialization()
        {
            DataContractJsonSerializer jsonFormatter = new DataContractJsonSerializer(typeof(Person[]));
            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                persons = (Person[])jsonFormatter.ReadObject(fs);
                Console.WriteLine("Persons successfully deserialized from json file!\n");
            }
        }
    }
    class Program
    {
        static void SerializeMenu(ListPerson listPersons)
        {
            Console.WriteLine("1. Binary\n2. SOAP\n3. XML\n4. JSON\n0. Back");
            int choose = Convert.ToInt32(Console.ReadLine());
            switch (choose)
            {
                case 0:
                    break;
                case 1:
                    listPersons.BinarySerialization();
                    SerializeMenu(listPersons);
                    break;
                case 2:
                    listPersons.SoapSerialization();
                    SerializeMenu(listPersons);
                    break;
                case 3:
                    listPersons.XmlSerialization();
                    SerializeMenu(listPersons);
                    break;
                case 4:
                    listPersons.JsonSerialization();
                    SerializeMenu(listPersons);
                    break;
                default:
                    Console.WriteLine("Wrong select, try again!\n");
                    break;
            }
        }
        static void MainMenu(ListPerson listPersons)
        {
            Console.WriteLine("1. Add person\n2. Delete person\n3. Edit person\n4. Show persons\n5. Serializations\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 0: break;
                case 1:
                    listPersons.AddPerson();
                    MainMenu(listPersons);
                    break;
                case 2:
                    listPersons.DeletePerson();
                    MainMenu(listPersons);
                    break;
                case 3:
                    listPersons.EditPerson();
                    MainMenu(listPersons);
                    break;
                case 4:
                    listPersons.ShowPersons();
                    MainMenu(listPersons);
                    break;
                case 5:
                    SerializeMenu(listPersons);
                    MainMenu(listPersons);
                    break;
                default:
                    Console.WriteLine("Wrong select, try again!\n");
                    break;
            }
        }
        static void DeserializeMenu(ListPerson listPersons)
        {
            Console.WriteLine("Please choose which file do you wanna deserialize:\n1. Binary\n2. SOAP\n3. XML\n4. JSON");
            int choose = Convert.ToInt32(Console.ReadLine());
            switch (choose)
            {
                case 1:
                    listPersons.BinaryDeserialization();
                    break;
                case 2:
                    listPersons.SoapDeserialization();
                    break;
                case 3:
                    listPersons.XmlDeserialization();
                    break;
                case 4:
                    listPersons.JsonDeserialization();
                    break;
                default:
                    Console.WriteLine("Wrong select, try again!\n");
                    break;
            }
        }
        static void Main(string[] args)
        {
            ListPerson listPersons = new ListPerson();
            MainMenu(listPersons);
            DeserializeMenu(listPersons);
            Console.ReadKey();
        }
    }
}
