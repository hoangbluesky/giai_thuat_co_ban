#include <iostream>
#include <string.h>
using namespace std;

//dinh nghia cau truc may bay
struct vemaybay {
	int mave;
	char loaive[15];
	char diemkhoihanh[20];
	char diemden[20];
	float giave;
};
typedef struct vemaybay mb;

//dinh nghia node
struct NODE {
	mb data;
	NODE *next;
};
typedef struct NODE node;

//dinh nghai list
struct LIST {
	node *Head;
	node *Tail;
};
typedef struct LIST list;

//tao node
node *taonode(mb &x){
	node *p= new node;
	if (p==NULL){
		cout <<"ko du bo nho";
	}else {
		p->data=x;
		p->next=NULL;
	}
}
//tao list
void taolist(list &ds){
	ds.Head = NULL;
	ds.Tail = NULL;
}

//chen dau
void inputhead(list &ds,node *p){
	if (ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else {
		p->next=ds.Head;
		ds.Head=p;
	}
}
//chen cuoi
void inputtail(list &ds,node *p){
	if(ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else{
		ds.Tail->next=p;
		ds.Tail=p;
	}
}
void input(list &ds,mb x, int n){
	for(int i=0;i<n;i++){
		cout <<"Nhap ve thu: "<<i+1<<endl;
		cout <<"Nhap ma ve: ";
		fflush(stdin);
		cin >>x.mave;
		cout <<"Nhap loai ve: ";
		fflush(stdin);
		gets(x.loaive);
		cout <<"Nhap diem khoi hanh: ";
		fflush(stdin);
		gets(x.diemkhoihanh);
		cout <<"Nhap diem den: ";
		fflush(stdin);
		gets(x.diemden);
		cout <<"Nhap gia ve: ";
		fflush(stdin);
		cin >>x.giave;
		node *p =taonode(x);
//		inputhead(ds,p);
		inputtail(ds,p);
		cout<<endl;
	}
}
void output(list ds){
	for(node *p=ds.Head; p!=NULL; p=p->next){
		cout<<p->data.mave<<"\t\t"<<p->data.loaive<<"\t\t"<<p->data.diemkhoihanh<<"\t\t"<<p->data.diemden<<"\t\t"<<p->data.giave<<endl;
	}
}
void sapxepgiave(list ds){
	for (node *p=ds.Head; p!=ds.Tail; p=p->next){
		for (node *q=p->next; q!=NULL; q=q->next){
			if (p->data.giave>q->data.giave){
				swap(p->data,q->data);
			}
		}
	}
}
void lietke(list ds){
	char x[15]="noi bai";
	for (node *p=ds.Head; p!=ds.Tail; p=p->next){		
		if (strcmp(p->data.diemkhoihanh,x)==0){
			cout<<p->data.mave<<"\t\t"<<p->data.loaive<<"\t\t"<<p->data.diemkhoihanh<<"\t\t"<<p->data.diemden<<"\t\t"<<p->data.giave<<endl;
		}
	}
}
int main(){
	mb x;
	list ds;
	taolist(ds);
	int n;
	cout <<"Nhap so luong ve may bay: ";
	cin >>n;
	input(ds,x,n);
	cout<<"\nMa ve\t\tLoai ve\t\tDiem khoi hanh\t\tDiem den\t\tGiave\n";
	output(ds);
	sapxepgiave(ds);
	cout<<"\nMa ve\t\tLoai ve\t\tDiem khoi hanh\t\tDiem den\t\tGiave\n";
	output(ds);
	cout<<"\nMa ve\t\tLoai ve\t\tDiem khoi hanh\t\tDiem den\t\tGiave\n";
	lietke(ds);
	
}
