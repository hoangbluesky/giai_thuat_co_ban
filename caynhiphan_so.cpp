#include<iostream >
#include<string>
using namespace std;
struct node{
	  int data;
	  node*right;
	  node*left;
};
  typedef node*tree;

void khoitaoTree(tree &t){
	t=NULL;
}
 
node*khoitaonode(int &x){
	node*p=new node;
	if(p==NULL){
		cout<<"khoi tao khong thanh cong"<<endl;
		return NULL;
	}else{
		p->data=x;
		p->right=NULL;
		p->left=NULL;
		return p;
	}
}

// daay nhuw la phuowng thucs them vao cuoi trong dang sach lien ket 
void chenNut(tree &t,int &x,node*p){
	
	if(t==NULL){
		t=p;	
	}else if(t!=NULL){
		if(t->data>x){
			chenNut(t->left,x,p);
		}else if(t->data<x){
			chenNut(t->right,x,p);	
		}	
	}
}

void nhap(int &x){
	cin>>x;
}

void addNut(tree&t,int &x){
	node*p;
	int n; cout<<"nhap vao so luong cua n "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		nhap(x);
		p=khoitaonode(x);
		chenNut(t,x,p);	
	}
}

void duyetNLR(tree t){
	if(t!=NULL){
		cout<<"\ndta "<<t->data;
		duyetNLR(t->left);
		duyetNLR(t->right);
	}
}
int dem=0;
void demSoNgto(tree t,int x){
	cout<<"\ndem phan tu so  nguyen to trong bai "<<endl;
	    if(t!=NULL){
		   if(t->data%2!=0){
		    	for(int i=0;i<t->data;i++){
				    if(t->data%i!=0&&t->data%1==0){
				     	dem++;
				   }
	        	}
           }
		demSoNgto(t->left,x);
		demSoNgto(t->right,x);
	}
	cout<<"dem la"<<dem;
}
main(){
	int x;
	tree t;
	khoitaoTree(t);
	node*p;
	addNut(t,x);
	duyetNLR(t);
//	demSoNgto(t,x);
}
