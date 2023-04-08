#include<iostream>
#include<string>
using namespace std;
struct vandongvien{
	int mavdv;
	string tenvdv;
	int tuoi;
	string quequan;
	float luong;
};
typedef struct vandongvien vdv;
struct NODE{
	vdv data;
	NODE *next;
	NODE *prev;
};
typedef struct NODE node;
struct LIST {
	node *head;
	node *tail;
};
typedef struct LIST list;

node *taonode(vdv &x){
	node *p=new node;
	if (p==NULL){
		cout<<"Khong du bo nho";
	}else{
		p->data=x;
		p->next =NULL;
		p->prev=NULL;
	}
	return p;
}
void taolist(list &ds){
	ds.head=ds.tail=NULL;
} 
void inputhead(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		p->next=ds.head;
		ds.head->prev=p;
		ds.head=p;
	}
}
void inputtail(list &ds, node *p){
	if (ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		p->prev=ds.tail;
		ds.tail=p;
	}
}
void intput(list &ds,vdv x,int n){
	for (int i=0;i<n;i++){
		cout<<"Nhap van dong vien thu: "<<i+1<<endl;
		cout<<"Nhap ma van dong vien: ";
		cin>>x.mavdv;
		cout<<"Nhap ten van dong vien: ";
		fflush(stdin);
		getline(cin,x.tenvdv);
		cout<<"Nhap tuoi: ";
		cin>>x.tuoi;
		cout<<"Nhap que quan: ";
		fflush(stdin);
		getline(cin,x.quequan);
		cout<<"Nhap luong: ";
		cin>>x.luong;
		node *p =taonode(x);
		inputtail(ds,p);
		cout<<endl;
	}
}
void output(list ds,node *p){
	cout<<p->data.mavdv<<"\t\t"<<p->data.tenvdv<<"\t\t"<<p->data.quequan<<"\t\t"<<p->data.tuoi<<"\t\t"<<p->data.luong<<endl;
}
void nghean(list ds,node *p){
	string nghean="nghe an";
	if(p->data.quequan==nghean){
		output(ds,p);
	}
}
void nghidau(list &ds){
	for(node *p=ds.head;p!=NULL;p=p->next){
		if(ds.head->data.tuoi==1){
			node *k=ds.head;
			ds.head=ds.head->next;
			ds.head->prev=NULL;
			delete k;
		}else if(p->data.tuoi==1){
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p->next=p->prev=NULL;
			delete p;	
		}else if(ds.tail->data.tuoi==1){
			node *k=ds.tail;
			ds.tail=ds.tail->prev;
			ds.tail->next=NULL;
			delete k;
		}
	}
}


int main(){
	vandongvien x;
	list ds;
	taolist(ds);
	int n;
	cout<<"Nhap so luong van dong vien: ";
	cin>>n;
	intput(ds,x,n);
	cout<<"\nDanh sach van dong vien\n";
	cout<<endl;
	for (node *p =ds.head;p!=NULL;p=p->next){
		output(ds,p);
	}
	cout<<"\nDanh sach van dong vien o nghe an: \n";
	for (node *p =ds.head;p!=NULL;p=p->next){
		nghean(ds,p);
	}
	

	cout<<"\nDanh sach van dong vien < 50 tui: \n";
	nghidau(ds);
	for (node *p =ds.head;p!=NULL;p=p->next){
		output(ds,p);
	}
}










