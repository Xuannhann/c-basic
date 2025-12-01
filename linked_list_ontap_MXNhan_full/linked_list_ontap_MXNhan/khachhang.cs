using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace linked_list_ontap_MXNhan
{
    internal class khachhang
    {
        public String MaKH { get; set;}
       public string hoten { get; set; }
        public string ten { get; set; }
        public string diachi { get; set; }
       public  int CS_tieuthutrc { get; set; }
       public int  CS_tieuthusau { get; set; }
        
        public int CS_TieuThu
        {
            get { return CS_tieuthusau - CS_tieuthutrc; }

        }
        public int sotientra
        {
                       get { return CS_TieuThu * 3000; }
        }
        public khachhang( string MaKH, string hoten,string ten, string diachi, int CS_tieuthutrc, int CS_tieuthusau)
        {
            this.MaKH = MaKH;
            this.hoten = hoten;
            this.ten = ten;
            this.diachi = diachi;
            this.CS_tieuthutrc = CS_tieuthutrc;
            this.CS_tieuthusau = CS_tieuthusau;
        }
        public khachhang() { }
        public khachhang(string line)
        {
         
            String[] s = line.Split('|');
            this.MaKH = s[0];
            this.hoten = s[1];
            this.ten = s[2];
            this.diachi = s[3];
            this.CS_tieuthutrc = int.Parse(s[4]);
            this.CS_tieuthusau = int.Parse(s[5]);
        }

        public override string ToString()
        {
            return string.Format ("{0,-7}|{1,-20}{2,-5}|{3,-25}|{4,25}|{5,8}|{6,9}|{7,8}", MaKH, hoten,ten, diachi, CS_tieuthutrc, CS_tieuthusau,CS_TieuThu, sotientra);
        }
    }
 
}
