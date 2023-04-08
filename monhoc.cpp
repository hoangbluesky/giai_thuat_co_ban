#include<iostream>
#include<string>
using namespace std;
struct MONHOC{
	int mamh;
	char tenmon[10];
	char chuyennganh[10];
	int sotinchi;
};
typedef struct MONHOC mh;
struct NODE{
	mh data;
	NODE *next;
};
typedef struct NODE node;
struct LIST{
	node *head;
	node *tail;
};
typedef struct LIST list;
node *taonode(mh &x){
	node *p=new node;
	if(p==NULL){
		cout<<"Ko co du lieu";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void taolist(list &ds){
	ds.head=ds.tail=NULL;
}
void inputtail(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		ds.tail=p;
	}
}
void input(list &ds,mh x,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap mon hoc thu: "<<i+1<<endl;
		cout<<"Nhap ma mon hoc: ";
		cin>>x.mamh;
		cout<<"Nhap ten mon hoc: ";
		fflush(stdin);
		gets(x.tenmon);
		cout<<"Nhap chuyen nganh: ";
		fflush(stdin);
		gets(x.chuyennganh);
		cout<<"Nhap so tin chi: ";
		cin>>x.sotinchi;
		node *p =taonode(x);
		inputtail(ds,p);
		cout<<endl;
	}
}
void output(list ds){
	
	for(node *p=ds.head;p!=NULL;p=p->next){
		cout<<p->data.mamh<<"\t\t"<<p->data.tenmon<<"\t\t"<<p->data.chuyennganh<<"\t\t"<<p->data.sotinchi<<endl;
	}
}
void delhead(list &ds){
	if(ds.head==NULL){
		cout<<"KO co du lieu";
	}else{
		node *p=ds.head;
		ds.head=ds.head->next;
		delete p;
	}
}
void thuongmdt(list ds){
	string tmdt="tmdt";
	for(node *p=ds.head;p!=NULL;p=p->next){
		if(p->data.chuyennganh==tmdt)
		cout<<p->data.mamh<<"\t\t"<<p->data.tenmon<<"\t\t"<<p->data.chuyennganh<<"\t\t"<<p->data.sotinchi<<endl;
	}
}
int main(){
	mh x;
	list ds;
	taolist(ds);
	int n;
	cout<<"Nhap so luong mon hoc: ";
	cin>>n;
	input(ds,x,n);
	cout<<"\nMamh\t\ttenmh\t\tchuyennganh\t\tsotinchi\n";
	output(ds);
	cout<<"Danh sach thuong mai dt: \n";
	cout<<"\nMamh\t\ttenmh\t\tchuyennganh\t\tsotinchi\n";
	thuongmdt(ds);
	delhead(ds);
	cout<<endl<<endl;
	cout<<"\nMamh\t\ttenmh\t\tchuyennganh\t\tsotinchi\n";
	output(ds);
}










