#include<iostream>
#include<string>
using namespace std;
struct KHACHHANG{
	int makh;
	string tenkh;
	string diachi;
	string sodt;
	float tongtien;
};
typedef struct KHACHHANG kh;
struct NODE{
	kh data;
	NODE *next;
	NODE *prev;
};
typedef struct NODE node;
struct LIST{
	node *head;
	node *tail;
};
typedef struct LIST list;
node *createnodee(kh &x){
	node *p=new node;
	if(p==NULL){
		cout<<"Khong du bo nho!!!";
	}else{
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
	}
}
void taolistt(list &ds){
	ds.head=ds.tail=NULL;
}
void themdau(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		p->next=ds.head;
		ds.head->prev=p;
		ds.head=p;
	}
}
void themcuoi(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else{
		ds.tail->next=p;
		p->prev=ds.tail;
		ds.tail=p;
	}
}
int main(){
	
}
