using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Http.Headers;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace linked_list_ontap_MXNhan
{
    internal class thuvien
    {
        LinkedList<khachhang> ds = new LinkedList<khachhang>();
        public LinkedList<khachhang> DocFile(string path)
        {

            using (StreamReader sr = new StreamReader(path))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    string[] arr = line.Split('|');
                    if (arr.Length < 5) continue;
                    khachhang kh = new khachhang(line);
                    ds.AddLast(kh);
                }
                return ds;

            }
        }
        public void XuatDS()
        {
            Console.WriteLine("{0,-7}|{1,-25}|{2,-25}|{3,25},|{4,8}|{5,9}|{6,8}", "MaKH", "Ho ten", "Dia chi", "CS truoc", "CS sau", "CS tieu thu", "So tien tra");
            foreach (var kh in ds)
            {
                Console.WriteLine(kh.ToString());
            }
        }
    }
}

