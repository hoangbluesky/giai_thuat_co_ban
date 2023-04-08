#include <iostream>
#include <string>
using namespace std;

struct congtrinh{
	int mactr;
	string tenctr;
	string quimo;
	float tongkp;
};
typedef struct congtrinh ct;
struct NODE {
	ct data;
	NODE *next;
	NODE *prev;
};
typedef struct NODE node;
struct LIST {
	node *head;
	node *tail;
};
typedef struct LIST list;
node *taonode(ct &x){
	node *p =new node;
	if(p==NULL){
		cout<<"Ko du bo nho";
	}else{
		p->data =x;
		p->next=NULL;
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
void inputail(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		p->prev=ds.tail;
		ds.tail=p;
	}
}
void input(list &ds,ct x,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap cong trinh thu: "<<i+1<<endl;
		cout<<"Nhap ma cong trinh: ";
		cin >> x.mactr;
		cout<<"Nhap ten cong trinh: ";
		fflush(stdin);
		getline(cin,x.tenctr);
		cout<<"Nhap quy mo: ";
		fflush(stdin);
		getline(cin,x.quimo);
		cout<<"Nhap tong kinh phi: ";
		cin >>x.tongkp;
		node *p =taonode(x);
		inputail(ds,p);
		cout<<endl; 
	}
}
void output(list ds){
	for(node *p=ds.head;p!=NULL;p=p->next){
		cout<<p->data.mactr<<"\t\t"<<p->data.tenctr<<"\t\t"<<p->data.quimo<<"\t\t"<<p->data.tongkp<<endl;
	}
}
int main(){
	congtrinh x;
	list ds;
	taolist(ds);
	
	int n;
	cout<<"Nhap so luong cong trinh: ";
	cin>>n;
	
	input(ds,x,n);
	cout<<"\nMa ct\t\tTen ct\t\tQui mo\t\tTong kp\n";
	output(ds);
}



























