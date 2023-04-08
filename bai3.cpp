#include <iostream>
#include <fstream>
using namespace std;

struct DATE {
	int ngay,thang, nam;
};
typedef struct DATE date;

struct HANG {
	int id;
	char ten[10];
	date ngayxuat;
	float giaxuat;
};
typedef struct HANG typeOfItem;

struct NODE {
	typeOfItem data;
	NODE *next;
};
typedef struct NODE node;

struct STACK {
	node *top;
};
typedef struct STACK stack;
//khoi tao stack

void lnit (stack &s){
	s.top =NULL;
}
//danh sach rong
int isempty(stack s){
	if(s.top == NULL)
		return 1;
	return 0;
}
//tao node
node *taonode(typeOfItem &x){
	node *p=new NODE;
	if (p==NULL){
		cout<<"Ko du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}


void push(stack &s,typeOfItem x){
	node *p =taonode(x);
	if (p!=NULL){
		if(isempty(s)==1){
			s.top =p;
		}else {
			p->next=s.top;
			s.top =p;
		}
	}
}

typeOfItem pop(stack &s){
	typeOfItem x;
	if(isempty(s)==0){
		node *p=s.top;
		s.top=p->next;
		x=p->data;
		delete p;
		return x;
	}
}

void input(stack &s,typeOfItem x){
	cout <<"Nhap ma hang hoa: ";
	cin >>x.id;
	cout<<"Nhap ten hang: ";
	fflush(stdin);
	gets(x.ten);
	cout<<"NHap ngay xuat: ";
	cin>>x.ngayxuat.ngay>>x.ngayxuat.thang>>x.ngayxuat.nam;
	cout<<"Nhap gia xuat: ";
	cin >>x.giaxuat;
	push(s,x);
	cout<<endl;
}

void xuat(stack &s){
	typeOfItem y;
	y=pop(s);
	cout<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
}
void output(stack &s){
	typeOfItem y;
	ofstream outfile;
	outfile.open("D:\\hanghoa.txt");
	outfile<<"\nID\t\tTen\t\tNgay xuat\t\t Giaxuat\n";
	while(isempty(s)==0)
	{
		y=pop(s);
		if(y.giaxuat>1){
			cout<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
		}
		outfile<<y.id<<"\t\t"<<y.ten<<"\t\t"<<y.ngayxuat.ngay<<"/"<<y.ngayxuat.thang<<"/"<<y.ngayxuat.nam<<"\t\t"<<y.giaxuat<<endl;
	}
	outfile.close();
}
int main(){
	typeOfItem x;
	stack s;
	lnit(s);
	cout<<"Nhap cho 1 hang hoa: \n";
	input(s,x);
	xuat(s);
	int n;
	cout <<"Nhap so luong hang hoa: ";
	cin >>n;
	for (int i=0;i<n;i++){
		input(s,x);
	}
	cout<<"\nDANH SACH HANG HOA CO GIA XUAT HANG LON HON 1.0\n";
	cout<<"\nID\t\tTen\t\tNgay xuat\t\t Giaxuat\n";
	output(s); 
}
