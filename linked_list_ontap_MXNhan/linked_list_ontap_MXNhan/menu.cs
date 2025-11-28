using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace linked_list_ontap_MXNhan
{
    internal class menu
    {
        thuvien tv = new thuvien();
        public void inmenu()
        {
            Console.WriteLine("0. THOAT CHUONG TRINH");
            Console.WriteLine("1. Nhap danh sach haa đan (Ma KH là duy nhat).");
            Console.WriteLine("2. Xuat danh sach haa đon với toan bo thong tin tren. ");
            Console.WriteLine("3. sap xep danh sach theo 3 yeu cau");
            Console.WriteLine("4. Tim kiem thong tin hoa đon theo ma khach hàng su dụng 3 phương phap");
            Console.WriteLine("5. Xuat ra thong tin hoa đon co so tien phai tra lon nhat");
            Console.WriteLine("6. Xoa hoa đon theo ma khach hang");
            Console.WriteLine("7. Chen khach hàng x sau khách hàng có mã y cho truoc");
            Console.WriteLine("8. Xuất thống kê số lượng hóa đơn có chỉ số tiêu thụ trong từng phạm vi");
            Console.WriteLine("9. Chinh sua thong tin Khach hang theo Ma KH");
            Console.WriteLine("10. Đọc du liệu tu file data.txt");
        }
        public int chonmenu()
        {

            int chon;
            do
            {
                Console.Write("Chon chuc nang (0-10): ");
                chon = int.Parse(Console.ReadLine());
                if (chon >= 0 && chon <= 10) 
                    break;
            } while (true);


            return chon;

        }
        public void Xuly(int sochon)
        {
            switch (sochon)
            {
                case 0:
                    break;
                case 1:
                    string path = "khachhang.txt";
                    tv.DocFile(path);
                    break;
                case 2:
                    tv.XuatDS();
                    break;

            }  
            Console.ReadKey();
        }
        public void chayCT()
        {
            int sochon;
            do
            {
                Console.Clear();
                inmenu();
                sochon = chonmenu();
                Xuly(sochon);
            } while (sochon != 0);
        }
    }
}
