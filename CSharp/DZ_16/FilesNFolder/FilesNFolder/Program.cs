using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FilesNFolder
{
    class FolderFile
    {
        public void CFold(string foldernane)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(foldernane);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }
        }
        public void CFile(string filename)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (!fileInf.Exists)
            {
                fileInf.Create();
            }
        }
        
        public void RenameFold(string foldername, string newfold)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(foldername);
            if (dirInfo.Exists && Directory.Exists(newfold) == false)
            {
                dirInfo.MoveTo(newfold);
            }

            try
            {
                dirInfo = new DirectoryInfo(foldername);
                dirInfo.Delete(true);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public void RenameFile(string filename, string newfile)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                fileInf.CopyTo(newfile, true);
            }

            fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
        }
        public void CopyFold(string foldername, string newfold)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(foldername);
            if (dirInfo.Exists && Directory.Exists(newfold) == false)
            {
                dirInfo.MoveTo(newfold);
            }
        }
        public void CopyFile(string filename, string newfile)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                fileInf.CopyTo(newfile, true);
            }
        }
        public void MoveFold(string foldername, string newfold)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(foldername);
            if (dirInfo.Exists && Directory.Exists(newfold) == false)
            {
                dirInfo.MoveTo(newfold);
            }
        }
        public void MoveFile(string filename, string newfile)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                fileInf.MoveTo(newfile);
            }
        }
        public void DelFolder(string foldername)
        {
            try
            {
                DirectoryInfo dirInfo = new DirectoryInfo(foldername);
                dirInfo.Delete(true);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public void DelFile(string filename)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
        }
        public void InfoFolder(string foldername)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(foldername);

            Console.WriteLine("Название каталога: {0}", dirInfo.Name);
            Console.WriteLine("Полное название каталога: {0}", dirInfo.FullName);
            Console.WriteLine("Время создания каталога: {0}", dirInfo.CreationTime);
            Console.WriteLine("Корневой каталог: {0}", dirInfo.Root);
        }
        public void InfoFile(string filename)
        {
            FileInfo fileInf = new FileInfo(filename);
            if (fileInf.Exists)
            {
                Console.WriteLine("Имя файла: {0}", fileInf.Name);
                Console.WriteLine("Время создания: {0}", fileInf.CreationTime);
                Console.WriteLine("Размер: {0}", fileInf.Length);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int m = 1;
            string filename = @"first", foldername = @"newfolder", path = @"D:\", delfil = "y", delfold = "y", newfold, newfile;
            FolderFile ff = new FolderFile();
            foldername = path + foldername;
            ff.CFold(foldername);
            filename = foldername + "\\" + filename + ".txt";
            ff.CFile(filename);

            while (m != 0)
            {
                Console.WriteLine("Working with: \n1. files \n2. folder \n0. Exit");
                m = Convert.ToInt32(Console.ReadLine());
                switch (m)
                {
                    case 1:
                        Console.WriteLine("\n1. Create \n2. Rename \n3. Copy \n4. Move \n5. Delete \n6. Info \n0. Exit");
                        int mfile = Convert.ToInt32(Console.ReadLine());
                        switch (mfile)
                        {
                            case 1:
                                Console.WriteLine("Enter name text file: ");
                                filename = foldername + "\\" + Console.ReadLine() + ".txt";
                                ff.CFile(filename);
                                Console.WriteLine("file: \"" + filename + "\" is complite!");
                                break;
                            case 2:
                                Console.WriteLine("Enter name text file: ");
                                newfile = foldername + "\\" + Console.ReadLine() + ".txt";
                                ff.RenameFile(filename, newfile);
                                Console.WriteLine("file: \"" + filename + "\" is complite!");
                                break;
                            case 3:
                                Console.WriteLine("Enter name text file: ");
                                newfile = foldername + "\\" + Console.ReadLine() + ".txt";
                                ff.CopyFile(filename, newfile);
                                Console.WriteLine("file: \"" + newfile + "\" is complite!");
                                break;
                            case 4:
                                Console.WriteLine("Enter name text file: ");
                                newfile = foldername + "\\" + Console.ReadLine() + ".txt";
                                ff.MoveFile(filename, newfile);
                                Console.WriteLine("file: \"" + newfile + "\" is complite!");
                                break;
                            case 5:
                                Console.WriteLine("Delete file? (y/n)");
                                delfil = Console.ReadLine();
                                if (delfil == "y")
                                {
                                    ff.DelFile(filename);
                                }
                                else
                                {
                                    Console.WriteLine("File is not delete!");
                                }
                                break;
                            case 6:
                                ff.InfoFile(filename);
                                break;
                            case 0: break;
                        }
                        break;

                    case 2:
                        Console.WriteLine("\n1. Create \n2. Rename \n3. Copy \n4. Move \n5. Delete \n6. Info \n0. Exit");
                        int mfold = Convert.ToInt32(Console.ReadLine());
                        switch (mfold)
                        {
                            case 1:
                                Console.WriteLine("Enter folder name: ");
                                foldername = path + Console.ReadLine();
                                ff.CFold(foldername);
                                Console.WriteLine("folder: \"" + foldername + "\" is complite!");
                                break;
                            case 2:
                                Console.WriteLine("Enter new folder path: ");
                                path = Console.ReadLine();
                                Console.WriteLine("Enter folder name: ");
                                newfold = path + Console.ReadLine();
                                ff.RenameFold(foldername, newfold);
                                Console.WriteLine("file: \"" + foldername + "\" is complite!");
                                break;
                            case 3:
                                Console.WriteLine("Enter new folder path: ");
                                path = Console.ReadLine();
                                Console.WriteLine("Enter folder name: ");
                                newfold = path + Console.ReadLine();
                                ff.CopyFold(foldername, newfold);
                                Console.WriteLine("file: \"" + foldername + "\" is complite!");
                                break;
                            case 4:
                                Console.WriteLine("Enter new folder path: ");
                                path = Console.ReadLine();
                                Console.WriteLine("Enter folder name: ");
                                newfold = path + Console.ReadLine();
                                ff.MoveFold(foldername, newfold);
                                Console.WriteLine("file: \"" + filename + "\" is complite!");
                                break;
                            case 5:
                                Console.WriteLine("Delete folder? (y/n)");
                                delfold = Console.ReadLine();
                                if (delfold == "y")
                                {
                                    ff.DelFolder(foldername);
                                }
                                else
                                {
                                    Console.WriteLine("File is not delete!");
                                }
                                break;
                            case 6:
                                ff.InfoFolder(foldername);
                                break;
                            case 0: break;
                        }
                        break;

                    case 0: break;
                }
            }

            Console.WriteLine("Ok!");

            Console.ReadKey();
        }
    }
}