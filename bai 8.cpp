#include <iostream>
#include<stdlib.h>
#include <string.h>
using namespace std;


//dinh nghia cau truc nhan vien
struct nhanvien{
	int manv;
	char tennv[15];
	int tuoi;
	float hesoluong;
};
typedef struct nhanvien nv;

//dinh nghia node
 struct NODE{
	nv data;
	NODE *next;
};
typedef struct NODE node;

//dinh nghia list
struct LIST {
	node *head;
	node *tail;
};
typedef struct LIST list;

//khoi tao node
node *taonode(nv &x){
	node *p =new node;
	if (p==NULL){
		cout <<"ko du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}

// khoi tao list
void taolist(list &ds){
	ds.head=NULL;
	ds.tail=NULL;
}

// them dau
void inputhead(list &ds, node *p){
	if (ds.head==NULL){
		ds.head=ds.tail=p;
	}else {
		p->next=ds.head;
		ds.head=p;
	}
}

//them cuoi
void inputtail(list &ds, node*p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		ds.tail=p;
	}
}

void nhap(list &ds, nv x, int n){
	for (int i=0;i<n;i++){
		cout<<"Nhap nhan vien thu:"<<i+1<<endl;
		cout <<"Nhap ma nhan vien: ";
		cin >> x.manv;
		fflush(stdin);
		cout <<"Nhap ten nhan vien: ";
		gets(x.tennv);
		fflush(stdin);
		cout <<"Nhap tuoi nhan vien: ";
		cin >> x.tuoi;
		cout <<"Nhap he so luong nhan vien: ";
		cin >> x.hesoluong;
		node *p = taonode(x);
		inputhead(ds,p);
		cout <<endl;
	}
}

void xuat(list ds){
	for (node *p=ds.head; p!=NULL; p=p->next){
		cout<<p->data.manv<<"\t\t"<<p->data.tennv<<"\t\t"<<p->data.tuoi<<"\t\t"<<p->data.hesoluong<<endl;
	}
}

void vehuu(list ds){
	for (node *p=ds.head; p!=NULL; p=p->next){
		if (p->data.tuoi==60){
			cout<<p->data.manv<<"\t\t"<<p->data.tennv<<"\t\t"<<p->data.tuoi<<"\t\t"<<p->data.hesoluong<<endl;
		}
	}
}
void swap(list ds){
	for (node *p=ds.head; p!=ds.tail;p=p->next){
		for(node *q=p->next;q!=NULL;q=q->next){
			if (p->data.hesoluong >q->data.hesoluong){
				swap(p->data,q->data);
			}
		}
	}
}
int main(){
	nv x;
	list ds;
	int n;
	cout <<"Nhap so luong nhan vien: ";
	cin >>n;
	taolist(ds);
	nhap(ds,x,n);
	cout <<"\nDanh sach nhan vien: \n";
	cout <<"\nMa nhan vien\tHo ten\t\tTuoi\t\tHe so luong\n";
	xuat(ds);
	cout <<"\nDanh sach nhan vien: \n";
	cout <<"\nMa nhan vien\tHo ten\t\tTuoi\t\tHe so luong\n";
	vehuu(ds);
	swap(ds);
	cout <<"\nDanh sach nhan vien: \n";
	cout <<"\nMa nhan vien\tHo ten\t\tTuoi\t\tHe so luong\n";
	xuat(ds);
}

