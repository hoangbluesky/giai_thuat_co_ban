#include <iostream>
#include<stdlib.h>
#include <string.h>
using namespace std;


//dinh nghia cau truc hanh khach
struct khachhang{
	int makh;
	char tenkh[15];
	char diachi[15];
	char sodienthoai[15];
	int tongtien;
};
typedef struct khachhang kh;
//dinh nghia node
struct NODE{
	kh data;
	NODE *next;
	NODE *prev;
};
typedef struct NODE node;

//dinh nghia list

struct LIST {
	node *Head;
	node *Tail;
};
typedef struct LIST list;

//tao node
node *taonode(kh &x){
	node *p=new node;
	if (p==NULL){
		cout <<"ko du bo nho";
	}else {
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
	}
	return p;
}

//tao list
void taolist(list &ds){
	ds.Head=NULL;
	ds.Tail=NULL;
}

//chen dau
void inputhead(list &ds, node *p){
	if(ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else{
		p->next=ds.Head;
		ds.Head->prev=p;
		ds.Head=p;
	}
}
//chen cuoi
void inputtail(list &ds,node *p){
	if (ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else{
		ds.Tail->next=p;
		p->prev=ds.Tail;
		ds.Tail=p;
	}
}
void input(list &ds,kh x,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap khach hang thu: "<<i+1<<endl;
		cout<<"Nhap ma khach hang: ";
		fflush(stdin);
		cin>> x.makh;
		cout<<"Nhap ten khach hang: ";
		fflush(stdin);
		gets(x.tenkh);
		cout<<"Nhap dia chi khach hang: ";
		fflush(stdin);
		gets(x.diachi);
		cout<<"Nhap so dt khach hang: ";
		fflush(stdin);
		gets(x.sodienthoai);
		cout<<"Nhap tong so tien: ";
		fflush(stdin);
		cin>>x.tongtien;
		node *p= taonode(x);
//		inputhead(ds,p);
		inputtail(ds,p);
		cout <<endl;
	}
}
void timkiemn(list ds){
	string dia_chi ="ha noi";
	node *p=ds.Head;
	while((p!=NULL) && p->data.diachi==dia_chi){
			p=p->next;
	if (p==NULL){
		cout<<"ko thay";
	}else cout<<"thay";
	}
}
void timkiem(list ds){
	char dia_chi[10]="ha noi";
	node *p=ds.Head;
	while( (p!=NULL) && (strcmp(p->data.diachi,dia_chi)==1))
		p=p->next;
	if (p==NULL){
		cout<<"ko thay";
	}else cout<<"thay";
}
void output(list ds){
	for(node *p=ds.Head; p!=NULL; p=p->next){
		cout<<p->data.makh<<"\t\t"<<p->data.tenkh<<"\t\t"<<p->data.diachi<<"\t\t"<<p->data.sodienthoai<<"\t\t"<<p->data.tongtien<<endl;
	}
}
void hienthi(list ds){
	char hienthi[15]="ha noi";
	for(node *p=ds.Head; p!=NULL; p=p->next){
		if(strcmp(p->data.diachi,hienthi)==0){
			cout<<p->data.makh<<"\t\t"<<p->data.tenkh<<"\t\t"<<p->data.diachi<<"\t\t"<<p->data.sodienthoai<<"\t\t"<<p->data.tongtien<<endl;	
		}
	}
}
void sapxepgiamtien(list ds){
	for (node *p=ds.Head;p!=ds.Tail;p=p->next){
		for (node *q=p->next;q!=NULL;q=q->next){
			if(p->data.tongtien>q->data.tongtien){
				swap(p->data,q->data);
			}
		}
	}
}
int main(){
	kh x;
	list ds;
	taolist(ds);
	int n;
	cout <<"Nhap so luong khach hang: ";
	cin >>n;
	input(ds,x,n);
	cout<<"\nMa KH\t\tTen KH\t\tDia chi\t\tSo dien thoai\t\tTong tien\n";
	output(ds);
	cout <<"\nDanh sach khach hang dia chi ha noi:\n";
	cout<<"\nMa KH\t\tTen KH\t\tDia chi\t\tSo dien thoai\t\tTong tien\n";
	hienthi(ds);
	sapxepgiamtien(ds);
	cout<<"\n\nMa KH\t\tTen KH\t\tDia chi\t\tSo dien thoai\t\tTong tien\n";
	output(ds);
	timkiemn(ds);
	
}

