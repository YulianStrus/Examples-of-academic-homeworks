using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int m = -1;
            int[] arr = new int[0];
            while (m != 0)
            {
                Console.WriteLine("\n1.Add element \n2.Show all \n3.Sort Array \n4.Find in array \n5.Reverse \n6.Remove element \n7.Random elements \n0.Exit");
                m = Convert.ToInt32(Console.ReadLine());
                switch (m)
                {
                    case 1:
                        Console.Clear();
                        Array.Resize(ref arr, arr.Length + 1);
                        arr[arr.Length - 1] = Convert.ToInt32(Console.ReadLine());
                        break;
                    case 2:
                        Console.Clear();
                        int count = 1;
                        Console.WriteLine("\t\tElements of Array");
                        foreach (int el in arr)
                        {
                            Console.WriteLine("{0}. {1}", count, el);
                            count++;
                        }
                        break;
                    case 3:
                        Console.Clear();
                        int temp;
                        for (int i = 0; i < arr.Length - 1; ++i)
                        {
                            for (int k = 0; k < arr.Length - i - 1; ++k)
                            {
                                if (arr[k] > arr[k + 1])
                                {
                                    temp = arr[k];
                                    arr[k] = arr[k + 1];
                                    arr[k + 1] = temp;
                                }
                            }
                        }
                        break;
                    case 4:
                        Console.Clear();
                        Console.WriteLine("Please enter number what you search:");
                        int numb = Convert.ToInt32(Console.ReadLine());
                        int[] arr_pos = new int[0];
                        for (int i = 0; i < arr.Length; ++i)
                        {
                            if (arr[i] == numb)
                            {
                                Array.Resize(ref arr_pos, arr_pos.Length + 1);
                                arr_pos[arr_pos.Length - 1] = i;
                            }
                        }
                        break;
                    case 5:
                        Console.Clear();
                        Array.Reverse(arr);
                        break;
                    case 6:
                        Console.Clear();
                        Console.WriteLine("1. By index\n2. By Value\n0. Exit");
                        int choose = Convert.ToInt32(Console.ReadLine());
                        switch (choose)
                        {
                            case 0: break;
                            case 1:
                                {
                                    Console.WriteLine("Please enter index:");
                                    int index = Convert.ToInt32(Console.ReadLine());
                                    if (index > arr.Length - 1)
                                        Console.WriteLine("Not this index in array!");
                                    else
                                    {
                                        for (int i = index; i < arr.Length - 1; i++)
                                        {
                                            arr[i] = arr[i + 1];
                                        }
                                        Array.Resize(ref arr, arr.Length - 1);
                                    }
                                    break;
                                }
                            case 2:
                                {
                                    Console.WriteLine("Please enter value:");
                                    int value = Convert.ToInt32(Console.ReadLine());
                                    int[] arr_temp = new int[0];
                                    int cnt = 0;
                                    for (int i = 0; i < arr.Length; ++i)
                                    {
                                        if (value == arr[i])
                                            cnt++;
                                        else
                                        {
                                            Array.Resize(ref arr_temp, arr_temp.Length + 1);
                                            arr_temp[arr_temp.Length - 1] = arr[i];
                                        }
                                    }
                                    if (cnt == 0) Console.WriteLine("Not this value in array");
                                    else
                                    {
                                        Array.Resize(ref arr, arr.Length - cnt);
                                        Array.Copy(arr_temp, arr, arr.Length);
                                    }
                                    break;
                                }
                            default:
                                {
                                    Console.WriteLine("Incorrect choose! Please try again");
                                    break;
                                }
                        }
                        break;
                    case 7:
                        Console.Clear();
                        Random rand = new Random();
                        Array.Resize(ref arr, arr.Length + 1);
                        arr[arr.Length - 1] = rand.Next(100);
                        break;
                    default:
                        Console.Clear();
                        break;
                }
            }

            Console.ReadKey();
        }
    }
}