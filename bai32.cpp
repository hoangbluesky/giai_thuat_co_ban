#include <iostream>
using namespace std;

class dichvu{
	private:
		int madv;
		string tendv;
		float giacuoc;
	public:
		dichvu();
		void nhap();
		void xuat();
		float laygiacuoc();
};
dichvu::dichvu(){
	madv=giacuoc=0;
	tendv="";
}
void dichvu::nhap(){
	cout<<"Nhap ma dich vu: ";
	cin >> madv;
	cout<<"Nhap ten dich vu: ";
	fflush(stdin);
	getline(cin,tendv);
	cout<<"Nhap gia cuoc: ";
	cin>>giacuoc;
}
void dichvu::xuat(){
	cout<<"Ma dich vu: "<<madv<<endl;
	cout<<"Ten dich vu: "<<tendv<<endl;
	cout<<"Gia cuoc: "<<giacuoc<<endl;;
}
float dichvu::laygiacuoc(){
	return this->giacuoc;
}

class nguoi:public dichvu{
	private:
		string hoten;
		string diachi;
		string sodt;
	public:
		nguoi();
		void nhap();
		void xuat();
};
nguoi::nguoi(){
	
	hoten= diachi= sodt= "";
}
void nguoi::nhap(){
	cout<<"Nhap ho ten: ";
	fflush(stdin);
	getline(cin,hoten);
	cout<<"Nhap dia chi: ";
	fflush(stdin);
	getline(cin,diachi);
	cout<<"Nhap so dien thoai: ";
	fflush(stdin);
	getline(cin,sodt);
}
void nguoi::xuat(){
	cout<<"Ho ten: "<<hoten<<endl;
	cout<<"Dia chi: "<<diachi<<endl;
	cout<<"So dien thoai: "<<sodt<<endl;;
}

class khachhang:public nguoi{
	private:
		int soluongdichvu;
		dichvu dv[20];
	public:
		khachhang();
		void nhap();
		void xuat();
		float tonggiacuoc();
};

khachhang::khachhang(){
	soluongdichvu=0;
}
void khachhang::nhap(){
	cout<<"Nhap so luong dich vu: ";
	cin>>soluongdichvu;
	dichvu::dichvu::nhap();
}
void khachhang::xuat(){
	cout<<"So luong dich vu: "<<soluongdichvu<<endl;
	dichvu::dichvu::xuat();
}
float khachhang::tonggiacuoc(){
	return laygiacuoc() * soluongdichvu;
}
int main(){
	dichvu dv;
	nguoi nguoi;
	khachhang kh;
//	nguoi;
//	dv.nhap();
//	dv.xuat();
	cout<<"Nhap thong tin cho 1 doi tuong nguoi: \n";
	nguoi.nguoi::nhap();
	cout<<endl;
	nguoi.nguoi::xuat();
	cout<<"\nNhap thong tin cho 1 khach hang: \n";
	kh.khachhang::nhap();
	cout<<endl;
	kh.khachhang::xuat();
	cout<<"Tong gia cuoc: "<<kh.tonggiacuoc();
}
