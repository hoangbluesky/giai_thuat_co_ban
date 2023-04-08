#include <iostream>
#include<string>
using namespace std;

struct DATE {
	int ngay,thang,nam;
};
typedef struct DATE date;

struct HANG {
	char id[6];
	char ten[100];
	date ngayxuat;
	float giaxuat;
};
typedef struct HANG hang;
struct NODE{
	hang data;
	NODE *next;
};
typedef struct NODE node;
struct QUEUE{
	node *front;
	node *rear;
};
typedef struct QUEUE queue;
void lnit(queue &q){
	q.front=q.rear=NULL;
}
int isempty(queue q){
	if(q.front==NULL){
		return 1;
	}else return  0;
}
node *taonode(hang &x){
	node *p= new node;
	if(p==NULL){
		cout<<"Ko du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void add(queue &q,hang x){
	node *p=taonode(x);
	if(q.front==NULL){
		q.front=q.rear=p;
	}else{
		q.rear->next=p;
		q.rear=p;
	}
}
hang remove(queue &q){
	hang x;
	node *p = NULL;
	if (isempty(q)==0) {
		p = q.front;
		x = p->data;
		q.front = q.front->next;
		delete p;
		if (q.front==NULL){
			q.rear = NULL;	
		}
	}
	return x;
}
void input(queue &q,hang x){
	cout <<"Nhap ma hang hoa: ";
	fflush(stdin);
	gets(x.id);
	cout<<"Nhap ten hang: ";
	fflush(stdin);
	gets(x.ten);
	cout<<"NHap ngay xuat: ";
	cin>>x.ngayxuat.ngay>>x.ngayxuat.thang>>x.ngayxuat.nam;
	cout<<"Nhap gia xuat: ";
	cin >>x.giaxuat;
	add(q,x);
	cout<<endl;
}
void xuat(queue &q){
	hang y;
	y=remove(q);
	cout<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
}
void output(queue &q){
	string truong_id="001";
	hang y;
	while(isempty(q)==0){
		y=remove(q);
		if(y.id==truong_id){
			cout<<"\nCac ma hang ma 001:\n";
			cout<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
		}
		cout<<"\nThong tin hang hoa chuan bi boc\n";
		cout<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
	}
	cout<<"\nDa boc xep toan bo hang!!!!";
	
}
int main(){
	hang x;
	queue q;
	lnit(q);
	cout<<"Nhap cho 1 hang hoa: \n";
	input(q,x);
	xuat(q);
	int n;
	cout <<"Nhap so luong hang hoa: ";
	cin >>n;
	for (int i=0;i<n;i++){
		input(q,x);
	}
	output(q);
}












