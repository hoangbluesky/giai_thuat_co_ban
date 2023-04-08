#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct DATE
{
	int ngay,thang,nam;
};
typedef struct DATE date;
struct congnhan
{
	char id[6];
	char ten[50];
	date ngaysinh;
	char quequan[15];
	float luong;
};

typedef struct congnhan cn;
struct NODE
{
	cn data;
	NODE *next;
};
typedef struct NODE node;
struct LIST
{
	node *head= NULL;
	node *tail= NULL;
};
typedef struct LIST list ;

void khoitao(list &ds){
	ds.head=ds.tail=NULL;
}

node *taonode(cn &x){
	node *p=new node;
	if(p==NULL){
		cout<<"chua cap phat bo nho:"<<endl;
	}
	else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void themdau(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}
	else{
		p->next=ds.head;
		ds.head=p;
	}
}
void nhap(list &ds,cn &x,int n){
	for(int i=0;i<n;i++){
		cout<<"nhap id: ";
		cin>>x.id;
		fflush(stdin);
		cout<<"nhap ten cong nhan: ";
		gets(x.ten);
		fflush(stdin);
		cout<<"nhap ngay sinh: ";
		cin>>x.ngaysinh.ngay>>x.ngaysinh.thang>>x.ngaysinh.nam;
		fflush(stdin);
		cout<<"nhap que quan: ";
		gets(x.quequan);
		fflush(stdin);
		cout<<"nhap luong: ";
		cin>>x.luong;
		fflush(stdin);
		node *p=taonode(x);
		themdau(ds,p);
		cout<<endl;
	}
}
void xuat(list ds){
	for(node *p=ds.head;p!=NULL;p=p->next){
		cout<<p->data.id<<"\t\t"<<p->data.ten<<"\t\t"<<p->data.ngaysinh.ngay<<"/"<<p->data.ngaysinh.thang<<"/"<<p->data.ngaysinh.nam<<"\t\t"<<p->data.quequan<<"\t\t"<<p->data.luong<<endl;
	}
}

void sapxep(list &ds){
	for(node *p=ds.head;p!=ds.tail;p=p->next){
		for(node *q=p->next;q!=NULL;q=q->next){
			if( strcmp(p->data.ten,q->data.ten) > 0 ){
				swap(p->data,q->data);
			}
		}
	}
	xuat(ds);
}

void xoaNodeBatKy(list &ds){
  	node *k=new node;
  	
  	for(node *p=ds.head; p!=NULL; p=p->next){
  		if(ds.head->data.ngaysinh.nam==1){
  			node *h=ds.head;
	  		ds.head=ds.head->next;
		   	delete h; 
		}
  	    if(p->data.ngaysinh.nam==1){
		   	k->next=p->next;
		   	p->next=NULL;
		   	delete p;
		}
		k=p;
		if(ds.tail->data.ngaysinh.nam==1){
				delete ds.tail;
				p->next=NULL;
				ds.tail=p;
		}
	}
}
int main()
{
	list ds;
	khoitao(ds);
	cn x;
	int n;
	cout<<"nhap so luong cong nhan:";
	cin>>n;
	
	nhap(ds,x,n);
	cout<<"\nID\t\tTen\t\tNgay sinh\t\tQue\t\tluong"<<endl;
	xuat(ds);
	
	cout<<"sap xep theo alphabe:"<<endl;
//	sapxep(ds);
	
	cout<<"danh sach sau khi xoa la:"<<endl;
	xoaNodeBatKy(ds);
	xuat(ds);
	cout<<"\n-------\n";

}
