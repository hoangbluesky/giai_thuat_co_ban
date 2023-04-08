#include<iostream>
#include<string>
using namespace std;

struct DUAN{
	int maduan;
	string tenduan;
	string quimo;
	float kinhphi;
};
typedef struct DUAN duan;

struct NODE{
	duan data;
	NODE *next;
};
typedef struct NODE node;

struct LIST{
	node *head;
	node *tail;
};
typedef struct LIST list;

node *taonode(duan &x){
	node *p= new node;
	if(p==NULL){
		cout<<"Khong du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}

void taolist(list &ds){
	ds.head=ds.tail=NULL;
}
void themdau(list &ds, node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		p->next=ds.head;
		ds.head=p;
	}
}

void themcuoi(list &ds, node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		ds.tail=p;
	}	
}
void nhaplist(list &ds,duan x,int n){
	for (int i=0;i<n;i++){
		cout<<"Nhap ma du an: ";
		cin>>x.maduan;
		cout<<"Nhap ten du an: ";
		fflush(stdin);
		getline(cin,x.tenduan);
		cout<<"Nhap qui mo du an: ";
		fflush(stdin);
		getline(cin,x.quimo);
		cout<<"Nhap kinh phi: ";
		cin>>x.kinhphi;
		node *p= taonode(x);
		themcuoi(ds,p);
		cout<<endl;
	}
}
void outlist(list ds){

	for(node *p=ds.head; p!=NULL;p=p->next){
		cout<<p->data.maduan<<"\t\t"<<p->data.tenduan<<"\t\t"<<p->data.quimo<<"\t\t"<<p->data.kinhphi<<endl;
	}
}
int main(){
	duan x;
	list ds;
	taolist(ds);
	int n;
	cout<<"Nhap so luong du an: ";
	cin>>n;
	nhaplist(ds,x,n);
	outlist(ds);
	
}
