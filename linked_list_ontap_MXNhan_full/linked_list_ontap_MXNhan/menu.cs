using System;
using System.CodeDom;
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
                case 3:
                    tv.XuatDS();
                    Console.WriteLine("nhap phuong phap sap xep (1,2,3: \n chen truc tiep \n noi bot \n doi cho truc tiep ");
                    int pp  =int.Parse( Console.ReadLine());
                    switch(pp)
                    {
                        case 1:
                           tv.ChenTrucTiep();
                            tv.XuatDS();
                            break;
                            
                        case 2:
                            tv.bubblesort();
                            tv.XuatDS();
                            break;
                        case 3:
                            tv.selectionsort();
                            tv.XuatDS();
                            break;
                    }    
                    break;
               case 4:
                    tv.XuatDS();
                    Console.WriteLine(" CAC PHUONG PHAP TIM KIEM \n tuyen tinh \n tuyen tinh linh canh \n nhi phan " );
                    int chon = int.Parse(Console.ReadLine());
                    switch(chon)
                        {
                        case 1:
                            Console.Write("Nhap ma khach hang can tim: ");
                            string makhtim1 = Console.ReadLine();
                               var tk1 = tv.LinerSearch(makhtim1);
                            tv.LinerSearch(makhtim1);
                            if(tk1 != null)
                            {
                                Console.WriteLine("Tim thay khach hang: ");
                                Console.WriteLine(tk1.ToString());


                            }
                            else
                            {
                                Console.WriteLine("Khong tim thay khach hang voi ma nay.");
                            }
                            break;
                        case 2:
                            Console.Write("Nhap ma khach hang can tim: ");
                            string makhtim2 = Console.ReadLine();
                            var tk2 = tv.LinerSearch_linhcanh(makhtim2);
                            if(tk2 != null)
                            {
                                Console.WriteLine("Tim thay khach hang: ");
                                Console.WriteLine(tk2.ToString());
                            }
                            else
                            {
                                Console.WriteLine("Khong tim thay khach hang voi ma nay.");
                            }
                            break;
                            case 3:
                            Console.Write("Nhap ma khach hang can tim: ");
                            string makhtim3 = Console.ReadLine();
                            var tk3 = tv.binary_search(makhtim3);
                            if (tk3 != null)
                            {
                                Console.WriteLine("Tim thay khach hang: ");
                                Console.WriteLine(tk3.ToString());
                            }
                            else
                            {
                                Console.WriteLine("Khong tim thay khach hang voi ma nay.");
                            }
                            break;


                    }
                    break;
                    case 5:
                    var khmax = tv.TimMAXhoadon();
                    Console.WriteLine(khmax.ToString());
                    break;
                    case 6:
                    Console.Write("Nhap ma khach hang can xoa: ");
                    string makhxoa = Console.ReadLine();
                    tv.Xoatheoma(makhxoa);
                    break;
                case 7:

                    Console.WriteLine("Nhap ma khach hang y de chen khach hang x sau khach hang y: ");
                    string may = Console.ReadLine();
                     tv.ChenKhachHang(may);
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
