using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometricFigure
{
    enum Color
    {
        White,
        Red,
        Green,
        Blue
    }
    struct Figures
    {
        public void ShowRectangle()
        {
            Console.WriteLine("\n\t***************\n\t***************\n\t***************\n\t***************\n\t***************\n\t***************\n\t***************\n");
        }
        public void ShowRhomb()
        {
            Console.WriteLine("\n\t       *\n\t     *****\n\t   *********\n\t *************\n\t   *********\n\t     *****\n\t       *\n");
        }
        public void ShowTriangle()
        {
            Console.WriteLine("\n\t       *\n\t      ***\n\t     *****\n\t    *******\n\t   *********\n\t  ***********\n\t *************\n\t***************\n");
        }
        public void ShowTrapeze()
        {
            Console.WriteLine("\n\t    *******\n\t   *********\n\t  ***********\n\t *************\n\t***************\n");
        }
        public void ShowPolygon()
        {
            Console.WriteLine("\n\t    *******\n\t   *********\n\t  ***********\n\t *************\n\t***************\n\t *************\n\t  ***********\n\t   *********\n\t    *******\n");
        }
    }
    class GeneralFigure
    {
        public Color color { get; set; }
        public Figures figure { get; }
        public GeneralFigure() { }
        public void ChooseColor()
        {
            if (color == Color.Red)
                Console.ForegroundColor = ConsoleColor.Red;
            if (color == Color.Green)
                Console.ForegroundColor = ConsoleColor.Green;
            if (color == Color.Blue)
                Console.ForegroundColor = ConsoleColor.Blue;
            if (color == Color.White)
                Console.ForegroundColor = ConsoleColor.White;
        }
        public void ShowFigures()
        {
            figure.ShowRectangle();
            figure.ShowRhomb();
            figure.ShowTriangle();
            figure.ShowTrapeze();
            figure.ShowPolygon();
        }
    }
    class Program
    {
        static void Menu(GeneralFigure f)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("1. Change figure\n2. Change color\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    ChooseFigure(f);
                    break;
                case 2:
                    ChooseColor(f);
                    break;
                case 0:
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    Menu(f);
                    break;

            }
        }
        static void ChooseFigure(GeneralFigure f)
        {
            Console.WriteLine("1. Show rectangle\n2. Show rhomb\n3. Show triangle\n4. Show trapeze\n5. Show polygon\n6. Show all\n0. Exit");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    f.ChooseColor();
                    f.figure.ShowRectangle();
                    Menu(f);
                    break;
                case 2:
                    f.ChooseColor();
                    f.figure.ShowRhomb();
                    Menu(f);
                    break;
                case 3:
                    f.ChooseColor();
                    f.figure.ShowTriangle();
                    Menu(f);
                    break;
                case 4:
                    f.ChooseColor();
                    f.figure.ShowTrapeze();
                    Menu(f);
                    break;
                case 5:
                    f.ChooseColor();
                    f.figure.ShowPolygon();
                    Menu(f);
                    break;
                case 6:
                    f.ChooseColor();
                    f.ShowFigures();
                    Menu(f);
                    break;
                case 0:
                    Menu(f);
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    Menu(f);
                    break;
            }
        }
        static void ChooseColor(GeneralFigure f)
        {
            Console.WriteLine("1. Red\n2. Green\n3. Blue\n4. White\n0. Back");
            int select = Convert.ToInt32(Console.ReadLine());
            switch (select)
            {
                case 1:
                    f.color = Color.Red;
                    Menu(f);
                    break;
                case 2:
                    f.color = Color.Green;
                    Menu(f);
                    break;
                case 3:
                    f.color = Color.Blue;
                    Menu(f);
                    break;
                case 4:
                    f.color = Color.White;
                    Menu(f);
                    break;
                case 0:
                    Menu(f);
                    break;
                default:
                    Console.WriteLine("Wrong select, Try again");
                    Menu(f);
                    break;
            }
        }
        static void Main(string[] args)
        {
            GeneralFigure figure = new GeneralFigure();
            Menu(figure);

            Console.ReadKey();
        }
    }

}
