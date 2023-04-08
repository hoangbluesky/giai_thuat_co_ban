#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct HocVien{
	int maHV;
	char hoTen[20];
	char lop[15];
	char chuyennganh[20];
	float diem;
};
typedef struct HocVien hv;

struct NODE{
	hv data;
	NODE *next;
	NODE *prev;
};
typedef struct NODE node;

struct LIST{
	node *Head;
	node *Tail;
};
typedef struct LIST list;

node *TaoNode(hv &x){
	node *p=new node;
	if(p==NULL){
		cout <<"ko du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
		p->prev=NULL;	
	}
	return p;
}

void TaoList(list &ds){
	ds.Head=NULL;
	ds.Tail=NULL;
}

void InputHead (list &ds, node *p){
	if (ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else{
		p->next=ds.Head;
		ds.Head->prev=p;
		ds.Head=p;
	}
}

void InputTail(list &ds, node *p){
	if(ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else {
		ds.Tail->next=p;
		p->prev=ds.Tail;
		ds.Tail=p;
	}
}

void Input (list &ds,hv x, int n){
	for (int i=0;i<n;i++){
		cout << "Nhap ma hoc vien: ";
		cin >> x.maHV;
		fflush(stdin);
		cout << "Nhap ho ten hoc vien: ";
		gets(x.hoTen);
		fflush(stdin);
		cout << "Nhap lop cua hoc vien: ";
		gets(x.lop);
		fflush(stdin);
		cout <<"Nhap chuyen nganh: ";
		gets(x.chuyennganh);
		cout << "Nhap diem: ";
		cin >> x.diem;
		node *p =TaoNode(x);
		InputTail(ds,p);
		cout <<endl;
	}	
}

void Output(list ds){
	
	for(node *p=ds.Head; p!=NULL; p=p->next){
		cout<<p->data.maHV<<"\t\t"<<p->data.hoTen<<"\t\t"<<p->data.lop<<"\t\t"<<p->data.chuyennganh<<"\t\t"<<p->data.diem<<"\n";
	}
}
// tm kiem hv co diem =8
void timkiem(list ds, hv x){
	node*p;
	p=ds.Head;
	
	while((p!=NULL)&&(p->data.diem !=8)){
		p=p->next;
	}
	if (p==NULL) cout<<"ko";
		else cout <<"co";	
}

// tm kiem hv co diem =8
node* TimKiem (list ds,hv x){
	node *p;
	p = ds.Head;
	while ((p!=NULL) && (p->data.diem !=x.diem))
		p=p->next;
	return p;
}
//duyet danh sach
void Lietkehv(list ds){
	char tmdt[20]="TM dien tu";
	for(node *p=ds.Head;p!=NULL;p=p->next){
		if(strcmp( p->data.chuyennganh,tmdt) ==0 && p->data.diem >=8){
			cout<<p->data.maHV<<"\t\t"<<p->data.hoTen<<"\t\t"<<p->data.lop<<"\t\t"<<p->data.chuyennganh<<"\t\t"<<p->data.diem<<"\n";
		}
	}
}
//sap xep danh sach
void SwapList(list ds){
	node *p, *q;
	for (p=ds.Head;p!=ds.Tail;p=p->next){
		for (q=p->next; q!=NULL;q=q->next){
			if(strcmp(p->data.hoTen,q->data.hoTen) >0){         
				swap(p->data,q->data);
         }
		}
	}
}
int main (){
	int n;
	cout<<"Nhap so luong hoc vien: ";
	cin >>n;
	hv x;
	list ds;
	Input(ds,x,n);
	cout<<"Danh sach hoc vien:\n";
	cout <<"MaHV\t\tHoten\t\tlop\t\tChuyen nganh\t\tDiem\n";
	Output(ds);
	cout<<"Danh sach hoc vien TMDT diem >=8:\n";
	cout <<"MaHV\t\tHoten\t\tlop\t\tChuyen nganh\t\tDiem\n";
	Lietkehv(ds);
	SwapList(ds);
	cout<<"Danh sach sinh vien thu tu alphabet:\n";
	cout <<"MaSV\t\tHoten\t\tDiachi\t\tDiem\n";
	Output(ds);
//	timkiem(ds,x);
		
	
}

void DelHead(list &ds){
	if(ds.Head==NULL){
		cout<<"Ko co du lieu";
	}else {
		node *p=ds.Head;
		ds.Head=ds.Head->next;
		delete p;
	}
}
void DelTail(list &ds){
	if (ds.Head==NULL){
		cout<<"Ko co du lieu";
	}else {
		for (node *p =ds.Head; p!=NULL; p=p->next){
			if (p->next=ds.Tail){
				delete ds.Tail;
				p->next=NULL;
				ds.Tail=p;
			}
		
		}
	}
}
//void SwapList(list ds){
//	node *p, *q;
//	for (p=ds.Head;p!=ds.Tail;p=p->next){
//		for (q=p->next; q!=NULL;q=q->next){
//			if (p->data.diem > q->data.diem){
//				swap(p->data,q->data);
//			}
//		}
//	}
//}

//	DelHead(ds);
//	cout<<"Danh sach sinh vien:\n";
//	cout <<"MaSV\t\tHoten\t\tDiachi\t\tDiem\n";
//	Output(ds);
//	DelTail(ds);






