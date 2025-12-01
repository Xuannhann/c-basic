using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Http.Headers;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
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



        public void ChenTrucTiep() //insertion sort
        {
            // Bước 1: chuyển LinkedList → List
            List<khachhang> list = new List<khachhang>(ds);


            for (int i = 1; i < list.Count; i++) // i là mảng xuất phát từ 1 đến hết mảng
            {
                var x = list[i]; // gán x là phần tử thứ i trong mảng
                int pos = i; // gán pos = i để làm vị trí so sánh

                while (pos > 0 && list[pos - 1].ten.CompareTo(x.ten) > 0) // so sánh phần tử trước pos với x, nếu phần tử trước pos > x thì dịch chuyển phần tử đó về sau 1 vị trí
                {
                    list[pos] = list[pos - 1]; // dịch chuyển phần tử về sau 1 vị trí
                    pos--; // giảm pos để tiếp tục so sánh với phần tử trước đó
                }
                list[pos] = x; // gán x vào vị trí đúng
            }
            ds = new LinkedList<khachhang>(list);
        }

        public void bubblesort()
        {
            List<khachhang> list1 = new List<khachhang>(ds);

            for (int i = 0; i < list1.Count - 1; i++)
            {
                for (int j = 0; j < list1.Count - 1 - i; j++) // j chạy từ 0 đến n-1-i để tránh so sánh những phần tử đã được sắp xếp ở cuối mảng
                {

                    if (list1[j].ten.CompareTo(list1[j + 1].ten) > 0) // lệnh compare giúp so sánh 2 chuỗi và dấu > 0 là để kt chuổi 1 lớn hơn chũi 2 thì đổi ch
                    {
                        var temp = list1[j];
                        list1[j] = list1[j + 1];
                        list1[j + 1] = temp;

                    }
                }
            }
            ds = new LinkedList<khachhang>(list1);

        }
        public void selectionsort()
        {
            List<khachhang> a = new List<khachhang>(ds);
            for (int i = 0; i < a.Count - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < a.Count; j++)
                {
                    if (a[j].ten.CompareTo(a[min].ten) < 0)
                    {
                        min = j;
                    }
                    if (min != i)
                    {
                        var temp = a[i];
                        a[i] = a[min];
                        a[min] = temp;
                    }
                }
            }
            ds = new LinkedList<khachhang>(a);
        }
        public khachhang LinerSearch(String makh)
        {
            List<khachhang> sr = new List<khachhang>(ds);
            foreach (var kh in ds)
            {
                if (kh.MaKH == makh)
                {
                    return kh;
                }

            }
            return null;
        }
        public khachhang LinerSearch_linhcanh(String makh)
        {
            List<khachhang> sr = new List<khachhang>(ds);

            // them linh canh
            sr.Add(new khachhang { MaKH = makh });

            int i = 0;

            while (sr[i].MaKH != makh) // duyết đến khi tìm thấy mã khách hàng hoặc đến phần tử linh canh
            {
                i++;
            }
            if (i == sr.Count - 1) // nếu i là phần tử linh canh thì không tìm thấy
            {
                return null;
            }
            else
            {
                return sr[i]; // trả về khách hàng tìm thấy
            }


        }
        public khachhang binary_search(String makh)
        {
            List<khachhang> bs = new List<khachhang>(ds);
            int left = 0;
            int right = bs.Count - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int cmp = bs[mid].MaKH.CompareTo(makh); // này giúp so sánh mã khách hàng ở giữa với mã khách hàng cần tìm
                if(cmp ==0)
                {
                    return bs[mid];

                }  
                if(cmp <0)
                {
                    left = mid + 1; // tìm bên phải
                }    
                else
                {
                    right = mid - 1; // tìm bên trái
                }
                
            }
            return null; // không tìm thấy

        }
        public khachhang TimMAXhoadon()
        {
           List<khachhang> tim = new List<khachhang>(ds);
            khachhang max = tim[0];
            foreach (var kh in ds)
            {
                if (kh.sotientra > max.sotientra)
                {
                    max = kh;
                }
            }
            return max;
        }
        public bool Xoatheoma(string ma)
        {
            var node = binary_search(ma);
            if (node != null)
            {
                ds.Remove(node);
                return true;
            }
            return false;

        }
        public khachhang Nhap1kh()
        {
            Console.Write("Nhap ma khach hang: ");
            string makh = Console.ReadLine();
            Console.Write("Nhap ho ten: ");
            string hoten = Console.ReadLine();
            Console.Write("Nhap ten: ");
            string ten = Console.ReadLine();
            Console.Write("Nhap dia chi: ");
            string diachi = Console.ReadLine();
            Console.Write("Nhap chi so tieu thu truoc: ");
            int cs_truoc = int.Parse(Console.ReadLine());
            Console.Write("Nhap chi so tieu thu sau: ");
            int cs_sau = int.Parse(Console.ReadLine());
            khachhang kh = new khachhang(makh, hoten, ten, diachi, cs_truoc, cs_sau);
            return kh;
        }
        public void ChenKhachHang(string ma_y)
        {
            khachhang kh = Nhap1kh();
            var node = ds.Find(binary_search(ma_y));
            if (node!= null)
            {
               ds.AddAfter(node, kh);
               
            }
            if (node == null)
            {
                Console.WriteLine("khong tim thay ma khach hang y");
            }

        }
    }
}

