#include<iostream>
#include<stdbool.h>
using namespace std;

struct DU_AN{
	int mada;
	char tenduan[10];
	char quimo[10];
	float tongkp;
};
typedef struct DU_AN da;
struct NODE{
	da data;
	NODE *next;
};
typedef struct NODE node;
struct LIST {
	node *head;
	node *tail;
};
typedef struct LIST list;

node *createnode(da &x){
	node *p=new node;
	if(p==NULL){
		cout<<"Khong du bo nho";
	}else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void createlist(list &ds){
	ds.head=ds.tail=NULL;
}
void inputtail(list &ds,node *p){
	if(ds.head==NULL){
		ds.head=ds.tail=p;
	}else {
		ds.tail->next=p;
		ds.tail=p;
	}
}
void input(list &ds,da x,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap du an so: "<<i+1<<endl;
		cout<<"Nhap ma du an: ";
		cin>>x.mada;
		cout<<"Nhap ten du an: ";
		fflush(stdin);
		gets(x.tenduan);
		cout<<"Nhap qui mo: ";
		fflush(stdin);
		gets(x.quimo);
		cout<<"Nhap tong kinh phi: ";
		cin>>x.tongkp;
		node *p=createnode(x);
		inputtail(ds,p);
		cout<<endl;
	}
}
void output(list ds){
	for(node *p=ds.head;p!=NULL;p=p->next){
		cout<<"hi";
		cout<<p->data.mada<<"\t\t"<<p->data.tenduan<<"\t\t"<<p->data.quimo<<"\t\t"<<p->data.tongkp<<endl;
	}
}
void kinhphilon(list ds){
	for(node *p=ds.head; p!=NULL; p=p->next){
		if(p->data.tongkp>=5&&p->data.tongkp<=10)
		cout<<p->data.mada<<"\t\t"<<p->data.tenduan<<"\t\t"<<p->data.quimo<<"\t\t"<<p->data.tongkp<<endl;
	}
}
void timkiem(list ds, int serch){
	node *p=ds.head;
	while( (p!=NULL) && (p->data.mada!=serch))
		p=p->next;
	if (p==NULL){
		cout<<"Thay";
	}cout<<"Ko thay";
}
void delhead(list &ds){
	if(ds.head==NULL){
		cout<<"KO du du lieu";
	}else {
		node *p=ds.head;
		ds.head=ds.head->next;
		delete p;
	}
}
void deltail(list &ds){
	if(ds.head==NULL){
		cout<<"KO du du lieu";
	}else {
		for(node *p=ds.head; p!=NULL;p=p->next){
			if(p->next=ds.tail){
				delete ds.tail;
				p->next=NULL;
				ds.tail=p;
			}
		}
	}
}

void delnode(list &ds,int serch){
	for(node *p=ds.head;p!=NULL;p=p->next){
		if(ds.head->data.mada== serch){
			node *k=ds.head;
			ds.head=ds.head->next;
			delete k;
		}else{
			if(p->data.mada==serch){
				node *k;
				node *g;
				k->next=g->next;
				delete g;
			}else if(p->next=ds.tail){
				if(ds.tail->data.mada=serch){
					node *k =ds.tail;
					delete k;
					p->next=NULL;
					ds.tail=p;	
				}
			}
		}
	}
}

void XoaNut(list &ds, int k) {
		node *p = ds.head;	
		node *q = NULL;
		while (p!=NULL && p->data.mada!=k) {	
			q = p;
			p=p->next;	
		}
		if(p!=NULL){
			if (q==NULL){
				delhead(ds);
			}					
		}else if (p == ds.tail){
			delete p; q->next = NULL; ds.tail = q;
		}	
		else deltail(ds);
}

int main(){
	da x;
	list ds;
	createlist(ds);
	int n;
	cout<<"Nhap so du an: ";
	cin>>n;
	
	input(ds,x,n);
	cout<<"\nMa du an\t\t Ten du an\t\tQui mo\t\tTong kinh phi\n";
	output(ds);
	cout<<"\nKInh phi tu 5 den 10: \n";
	kinhphilon(ds);
	int serch;
	cout<<"Nhap ma tim kiem: ";
	cin >>serch;
	timkiem(ds,serch);
//	delnode(ds,serch);
//	XoaNut(ds,serch);
cout<<"\nMa du an\t\t Ten du an\t\tQui mo\t\tTong kinh phi\n";
	
//	output(ds);
}
















//#include <iostream>
//#include <cstring>
//using namespace std;
//
//typedef struct CONGTRINH{
//    int mact;
//    string tenct;
//    string quimo;
//    float tkp;
//} CT;
//
//typedef struct NODE{
//    CT data;
//    NODE *next;
//    NODE *pre;
//} node;
//
//typedef struct LIST{
//    node *head;
//    node *tail;
//} list;
//
//void taods(list &l){
//    l.head=l.tail=NULL;
//}
//
//node *taonode(CT ct){
//    node *p=new node;
//    if(p==NULL){
//        cout << "Khong du bo nho";
//        exit(1);
//    }
//    else{
//        p->data=ct;
//        p->next=p->pre=NULL;
//        return p;
//    }
//}
//
//void chencuoi(list &l,node *p){
//    if(l.head==NULL){
//        l.head=l.tail=p;
//    }
//    else{
//        l.tail->next=p;
//        p->pre=l.tail;
//        l.tail=p;
//    }
//}
//
//void Nhap(list &l,int n){
//    CT ct;
//    for(int i=0;i<n;i++){
//        cout << "\nNhap thong tin sinh vien so " << i+1 << endl;
//        cout << "Nhap ma cong trinh: ";
//        cin >> ct.mact;
//        cout << "Nhap ten cong trinh: ";
//        cin.ignore();
//        fflush(stdin);
//        getline(cin,ct.tenct);
//        cout << "Nhap qui mo cong trinh: ";
//        undo:
//        fflush(stdin);
//        getline(cin,ct.quimo);
//        if ( (ct.quimo!="nho") and (ct.quimo!="trung binh") and (ct.quimo!="lon") ){
//            cout << "Nhap lai qui mo cong trinh: ";
//            goto undo;
//        }
//        cout << "Nhap tong kinh phi: ";
//        cin >> ct.tkp;
//        node *p;
//        p=taonode(ct);
//        chencuoi(l,p);
//    }
//}
//
//void Xuat(node *p){
//    cout << "\nMa cong trinh: " << p->data.mact << endl;
//    cout << "Ten cong trinh: " << p->data.tenct << endl;
//    cout << "Qui mo cong trinh: " << p->data.quimo << endl;
//    cout << "Tong kinh phi: " << p->data.tkp << " ty" <<endl;
//}
//
//void Duyetds(list l){
//    node *p=l.head;
//    while(p!=NULL){
//        Xuat(p);
//        p=p->next;
//    }
//}
//
//void lietke(list l){
//    node *p;
//    cout << "Cong trinh co kinh phi tu 5000-10000 ty: "<< endl;
//    for(p=l.head;p!=NULL;p=p->next){
//        if(p->data.tkp>5000 and p->data.tkp<10000) Xuat(p);
//    }
//}
//void timkiem(list &l){
//    node *p;
//    int q;
//    int d;
//    cout << "Nhap ma cong trinh: ";
//    cin >> q;
//    for(p=l.head;p!=NULL;p=p->next){
//        if(p->data.mact==q){
//            d=1;
//            if(p->pre==NULL){
//                l.head=p->next;
//            }
//            else if(p->next==NULL){
//                p->pre->next=NULL;
//            }
//            else{
//                p->pre->next=p->next;
//                p->next->pre=p->pre;
//            }
//        }
//    }
//    if(d==1){
//        cout << "Danh sach sau khi xoa" << endl;
//        Duyetds(l);
//    }
//    else cout << "Ma du an tuong ung chua duoc luu trong danh sach";
//    
//}
//int main(){
//    LIST l;
//    taods(l);
//    int n;
//    cout << "Nhap so cong trinh: ";
//    cin >> n;
//    Nhap(l,n);
//    cout << "\n--------------------\n";
//    Duyetds(l);
//    cout << "\n--------------------\n";
//    lietke(l);
//    cout << "\n--------------------\n";
//    timkiem(l);
//    
//}
