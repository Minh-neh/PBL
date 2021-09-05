#include<iostream>
#include<iomanip>	//use for setw()
using namespace std;
class date
{
	private:
		int ngay;
		int thang;
		int nam;
	public:
		date()
		{
			this-> ngay = 0;
			this-> thang = 0;
			this-> nam = 0; 
		}
		void nhapngay()
		{
			cin>> this->ngay >> this->thang >> this->nam;
		}
		void hienthi()
		{
			cout << "" << this->ngay << "/" << this->thang << "/" << this->nam << setw(14) << left;
		}															
	};
class hanghoa
{	
	private:
	string tenhang;
	date ngaysanxuat;
	int gia;
	public:
		hanghoa()
		{
			this -> tenhang ="";
			this -> gia = 0;
		}
		void nhap_thongtin()
		{
			cin.ignore();	//xóa bộ nhớ đệm
			cout<<"Nhap ten hang hoa: ";
			getline(cin,this->tenhang);
			cout<<"Nhap ngay san xuat: ";
			ngaysanxuat.nhapngay();			
		}
		void giatien()
		{
			cin>>this->gia;
		}
		void xuat_thongtin()
		{
			cout << setw(18) << left << this->tenhang << "\t";
			ngaysanxuat.hienthi();
		}
		int getgia() 						//truy cap gian tiep thuoc tinh gia (use at line 90, 126 and 167)
		{
			return this->gia;				
		}
		string get_tenhang()				//use at line 225
		{
			return tenhang;
		}
		
};
class hangnhap
{
	private:
		date ngaynhap;
		int soluongnh;
		hanghoa hangnh;
		int tongtiennh;
	public:
		hangnhap()
		{
			soluongnh = 0;
			tongtiennh = 0;
		}
		void nhap_slnh_nnh_tiennh()
		{
			cout <<"Nhap so luong hang loai do: ";
			cin >> soluongnh;
			cout <<"Ngay nhap hang: ";
			ngaynhap.nhapngay();
			cout <<"Nhap gia goc cua 1 san pham loai do: ";
			hangnh.giatien();
			
			for(int i = 0; i < soluongnh;i++)
			{
				tongtiennh += hangnh.getgia();			
			}
		}
		void xuat_nnh_tnh()
		{
			ngaynhap.hienthi();
			cout << "" << setw(20) << left << this->tongtiennh << "\t";
		}
		int getSLN() // truy cap gian tiep thuoc tinh soluongnh (use at line 162)
		{
			return soluongnh;
		}
};
class hangban
{
	private:
		date ngayban;
		int soluongb;
		hanghoa hangb;
		int tongtienb;
	public:
		hangban()
		{
			soluongb = 0;
			tongtienb = 0;	
		}
		void nhap_slb_nb_tienb()
		{
			cout <<"Nhap so luong hang hoa ban duoc: ";
			cin >> soluongb;
			cout <<"Nhap ngay ban: ";
			ngayban.nhapngay();
			cout <<"Nhap gia 1 san pham khi ban: ";
			hangb.giatien();
			for(int i = 0; i < this->soluongb;i++)
			{
				tongtienb += hangb.getgia();
			}
		}
		void xuat_nb_tb()
		{
			ngayban.hienthi();
			cout << "" << setw(16) << left << this->tongtienb <<endl;
		}
		int getSLB() //truy cap gian tiep thuoc tinh soluongb (use at line 162)
		{
			return soluongb;
		}
};
class hangton:public hanghoa, hangnhap, hangban //da ke thua theo tu tu duoc khai bao
{
	private:
		int soluongt;
		hanghoa hangt;
		int tongtient;
		
	public:
		hangton()
		{
			soluongt = 0;
			tongtient = 0;
		}
		~hangton()	//cap phat dong con tro phai khai bao ham huy
		{
			soluongt = 0;
			tongtient = 0;
		}
		void nhap()
		{	//Goi toi cac phuong thuc duoc ke thua tu ham co so
			hanghoa::nhap_thongtin();
			hangnhap::nhap_slnh_nnh_tiennh();
			hangban::nhap_slb_nb_tienb();
			soluongt = hangnhap::getSLN() - hangban::getSLB();	//lay gia tri duoc tra ve tu ham get bang toan tu ::
			cout <<"So tien ban 1 san pham con ton: ";
			hangt.giatien();
			for(int i = 0; i < this->soluongt;i++)
			{
				tongtient += hangt.getgia();					
			}
		}
		void xuat()
		{	//Goi toi cac phuong thuc duoc ke thua tu ham co so
			hanghoa::xuat_thongtin();		
			hangnhap::xuat_nnh_tnh();
			hangban::xuat_nb_tb();
		}
		int get_soluong_ton()
		{
			soluongt = hangnhap::getSLN()-hangban::getSLB(); 	
			return soluongt;									//tra ve gia tri hang ton (use at line 225)
		}
		int get_tien_hangton()
		{
			return tongtient;									//tra ve gia tri tien ton (use at line 225)
		}
};
main()
{
	int n,num;
	char y;
	cout<<"Nhap so luong hang hoa kinh doanh: ";
	cin>>n;
	hangton *hh; 
	hh = new hangton[1000]; //khoi tao bo nho dong
	cout << "CHUONG TRINH QUAN LY HANG TON KHO\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Nhap thong tin hang hoa.                      **\n";
        cout << "**  2. Xuat hang hoa.                                **\n";
        cout << "**  3. Kiem tra so luong hang ton.                   **\n";
        cout <<	"**  4. Ket thuc chuong trinh.                        **\n";
        cout << "*******************************************************\n";

	while(true) {
        cout << "Nhap tuy chon: ";
        cin >> num;

	switch(num){
		case 1: for(int i = 1;i <= n;i++){
						hh[i].nhap(); 	//ham nhap du lieu
							cout << "---------------------DA LUU DU LIEU---------------------"<<endl;
	}break;
		case 2: 	cout << "=====================================================================BANG KE KHAI HANG HOA============================================================================" << endl;
	cout << setw(18) << left << "TEN HANG" << "\t"<< setw(20) << left << "NGAY SAN XUAT" <<"\t"<< setw(20) << left <<"NGAY NHAP" 
	<<"\t" <<setw(20) << left << "TONG TIEN NHAP" <<"\t" <<setw(20) << left << "NGAY BAN" <<"\t"<< setw(15) << left <<"DOANH THU" 
	<< endl;
		
		
			for(int i = 1;i <= n;i++){
				hh[i].xuat();			//ham xuat du lieu
			}cout << "======================================================================================================================================================================" << endl;
			break;
		case 3:
				cout<<"====================BANG KE KHAI HANG TON===================="<<endl;
				cout<< setw(18) << left << "TEN HANG"<<setw(25)<<left<<"SO LUONG HANG TON"<<setw(25)<<left<<"TONG TIEN HANG TON"<<endl;
			for(int i=1;i <= n;i++)
			{	//lay gia tri tu ham get de hien thi ra man hinh
				cout<< setw(18) << left << hh[i].get_tenhang() << setw(25) << left << hh[i].get_soluong_ton() << setw(25) << left << hh[i].get_tien_hangton() << endl;
				
			}break;
		case 4:
			cout<<"Ban da ket thuc, vui long nhan ""y"" de thoat ra "<<endl;
			cin>>y;
		break; 
	}
	if(y == 'y')break;
				}
	delete[]hh;							//xoa bo nho dong
	return 0;
	system("pause");
}