#include <iostream>
#include <string.h>
#include<cstdlib>
using namespace std;

//dinh nghia truct 3 cai
struct mathang{
	int mahang;
	char tenhang[10];
	char loaihang[10];
	int namsx;
	char xuatxu[10];
	float giaban;
};
typedef struct mathang mh;
struct NODE{
	mh data;
	NODE *next;	
	NODE *prev;
};
typedef struct NODE node;
struct LIST{
	node *head;
	node *tail;
};
typedef struct LIST list;
//tao 
node *taonode(mh &x){
	node *p=new node;
	if(p==NULL){
		cout<<"ko du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
	}
	return p;
}
void taolist(list &ds){
	ds.head=ds.tail=NULL;
}
//input head and tail
void inputhead(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		p->next=ds.head;
		ds.head->prev=p;
		ds.head=p;
	}
}
void inputtail(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		p->prev=ds.tail;
		ds.tail=p;
	}
}
void input(list &ds,mh x,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap mat hang thu: "<<i+1<<endl;
		cout<<"Nhap ma hang: ";
		cin>>x.mahang;
		cout<<"Nhap ten hang: ";
		fflush(stdin);
		gets(x.tenhang);
		cout<<"Nhap loai hang: ";
		fflush(stdin);
		gets(x.loaihang);
		cout<<"Nhap nam san xuat: ";
		cin>>x.namsx;
		cout<<"Nhap xuat xu: ";
		fflush(stdin);
		gets(x.xuatxu);
		cout<<"Nhap gia ban: ";
		cin>>x.giaban;
		node *p=taonode(x);
		inputhead(ds,p);
		cout<<endl;
	}
}
void output(list ds){
	for(node *p=ds.head; p != NULL;p=p->next){
		cout<<p->data.mahang<<"\t\t"<<p->data.tenhang<<"\t\t"<<p->data.loaihang<<"\t\t"<<p->data.namsx<<"\t\t"<<p->data.xuatxu<<"\t\t"<<p->data.giaban<<endl;
	}
}
void giadung(list ds){
	char giadung[10]="gia dung";
	for(node *p=ds.head; p != NULL;p=p->next){
		if(strcmp(p->data.tenhang,giadung)==0 && p->data.giaban>=5 && p->data.giaban<10)
		cout<<p->data.mahang<<"\t\t"<<p->data.tenhang<<"\t\t"<<p->data.loaihang<<"\t\t"<<p->data.namsx<<"\t\t"<<p->data.xuatxu<<"\t\t"<<p->data.giaban<<endl;
	}
}
// xoa dau lien ket doi
void delhead(list &ds){
	node *p=ds.head;
	if(ds.head==NULL){
		cout<<"KO co du lieu";
	}else{
		ds.head=ds.head->next;
		ds.head->prev=NULL;
		p->next=NULL;
		delete p;
	}
}
//xoa cuoi lien ket doi
void deltail(list &ds){
	node *p=ds.tail;
	if(ds.tail==NULL){
		cout<<"Khong co du lieu";
	}else{
		ds.tail=ds.tail->prev;
		ds.tail->next=NULL;
		p->prev=NULL;
		delete p;
	}
}
//xoa bon trung quoc
void delnode(list &ds){    
	string xx;
	fflush(stdin);
	getline(cin,xx);
	for(node *p=ds.head;p!=NULL;p=p->next){
		if(ds.head->data.xuatxu==xx){
			node *k=ds.head;
			ds.head=ds.head->next;
			ds.head->prev=NULL;
			delete k;
		}else if(p->data.xuatxu==xx){
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p->next=p->prev=NULL;
			delete p;
		}
		else if(ds.tail->data.xuatxu==xx){
			node *k=ds.tail;
			ds.tail=ds.tail->prev;
			ds.tail->next=NULL;
			delete k;
		}
	}
}
int main(){
	mh x;
	list ds;
	taolist(ds);
	int n;
	cout<<"Nhap so luong mat hang: ";
	cin >>n;
	input(ds,x,n);
	cout<<"\nMa hang\t\tTen hang\t\tLoaihang\t\tNam SX\t\tXuatxu\t\tGiaban\n";
	output(ds);
	cout<<"\nDanh sach loai hang gia dung gia tu 5 den 10:";
	cout<<"\nMa hang\t\tTen hang\t\tLoaihang\t\tNam SX\t\tXuatxu\t\tGiaban\n";
	giadung(ds);
	cout<<"\nxoa turng quoc\n";
	delnode(ds);
	output(ds);
}















