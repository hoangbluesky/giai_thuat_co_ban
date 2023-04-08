#include<iostream>
#include <stdlib.h>
#include<cstring>
using namespace std;

//dinh nghia cau truc sv
struct SinhVien{
	int MaSV;
	char HoTen[30];
	char Lop[10];
	float DiemTK;
	char HanhK[20];
};
typedef struct SinhVien sv;

struct NODE{
	SinhVien data;
	NODE *next;
};

struct List {
	NODE* Head;
	NODE* Tail;
};
// khoi tao node
NODE* taonode(sv &x){
	NODE*p = new NODE;
	if (p==NULL){
		cout<<"Ko du bo nho!";
		return NULL;
	}else{
		p->data =x;
		p->next = NULL;	
	}
	return p;
}
// khoi tao list 
void taolist(List &ds){
	ds.Head = NULL;
	ds.Tail = NULL;
}
// kiem tra node rong
int check (List ds){
	if(ds.Head==NULL){
		return 1;
	}
	return 0;
}
// them LIST
void intputhead (List &ds, NODE*p){
	if(ds.Head==NULL){
		ds.Head=ds.Tail=p;
	}else {
		p->next = ds.Head;
		ds.Head=p;
	}
}

void input(sv &x){
	cout << "Nhap ma sinh vien: ";
	cin >> x.MaSV;
	fflush(stdin);
	cout << "Nhap ten sinh vien: ";
	gets(x.HoTen);
	fflush(stdin);
	cout << "Nhap Lop: ";
	gets(x.Lop);
	fflush(stdin);
	cout << "Nhap diem tong ket: ";
	cin >>x.DiemTK;
	fflush(stdin);
	cout << "Nhap hanh kiem: ";
	gets(x.HanhK);
	fflush(stdin);
}
void output (sv x){
	cout << "Ma sinh vien: " << x.MaSV << endl;
	cout << "Ten sinh vien: " << x.HoTen << endl;
	cout << "Lop: " << x.Lop << endl;
	cout << "Diem tong ket: " << x.DiemTK << endl;
	cout << "Hanh kiem: " << x.HanhK << endl;
} 
void outputlist(List ds){
	cout << "\nThong tin sinh vien:\n";
	for(NODE *k =ds.Head;k!=NULL ; k=k->next){
		output(k->data);
		cout<<endl;
	}
}
int main (){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	sv x;
	List ds;
	taolist(ds);
	for (int i=0;i<n;i++){
		input(x);
		NODE *p = taonode (x);
		intputhead(ds,p);
		cout << endl;
	}
	outputlist(ds);
}

