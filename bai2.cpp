// de so 5
// LE VAN MANH
// MSV 21810310138
// LOP D16CNPM6

#include<iostream >
#include<string>
using namespace std;
struct date{
	int ngay,thang,nam;
};
struct nhanvien{
	int manv;
	string ten;
	date ngaysinh;
	string que;
	float luong;
	
};
  struct node{
  	    nhanvien data;
  	    node*next;
  	    
  };
  struct list{
  	node*head;
  	node*tail;
  
  };
  void danhsach(list &l){
  	l.head=l.tail=NULL;
  	;
  	
  }
  node *khoitao(nhanvien &nv){
  	  node*p=new node;
  	  if(p==NULL){
  	  	return NULL;
		}
		else{
			p->data=nv;
			p->next=NULL;
			return p;
		}
  }
  void chenDau(list&l,node*p){
  	   if(l.head==NULL){
  	   	l.head=l.tail=NULL;
		 }else{
		 	p->next=l.head;
		 	l.head=p;
		 	
		 }
		 
  }
  void chenCuoi(list&l,node*p){
  	   if(l.head==NULL){
  	   	l.head=l.tail=p;
  	   	
		 }else{
		 	l.tail->next=p;
		 	l.tail=p;
		 }
  }
  void nhap(nhanvien &nv){
  	cout<<"nhap vao ma ";cin>>nv.manv;
      cout<<"nhap vao ten nv";cin>>nv.ten;
      cout<<"nhap ngay thang nam";cin>>nv.ngaysinh.ngay>>nv.ngaysinh.thang>>nv.ngaysinh.nam;
      cout<<"nhap tuoi";cin>>nv.que;
      cout<<"nhap vap ten ";cin>>nv.luong;
  }
  void add(list&l,nhanvien&nv){
  	     int n;cout<<"nhap vao n nhan vien";
  	     node*p;
  	     cin>>n;
  	     for(int i=0;i<n;i++){
  	     	nhap(nv);
  	     	p=khoitao(nv);
  	     	chenCuoi(l,p);
		   }
  }
  void xuat(list l){
  	int i=0;
  	for(node*p=l.head;p!=NULL;p=p->next){
  		cout<< "\n\t====================   "<<++i<<"=================================\n";
  		cout<<"\tnnhap vao ma "<<p->data.manv;
        cout<<"\tnhap vao ten nv"<<p->data.ten;
       cout<<"\tnhap ngay thang nam"<<p->data.ngaysinh.ngay<<p->data.ngaysinh.thang<<p->data.ngaysinh.nam;
       cout<<"\tnhap que"<<p->data.que;
       cout<<"\tnhap vap luong "<<p->data.luong;
	  }
  }
  void sapsep(list l){
  		for(node*p=l.head;p!=NULL;p=p->next){
  				for(node*k=l.head;k!=NULL;k=k->next){
  					if(p->data.luong<k->data.luong){
  						swap(p->data,k->data);
					  }
				}
			}
	xuat(l);
  }
 
  void xoaNodeBatKy(list&l){
  	   node*k=l.head;
  	     for(node*p=l.head;p!=NULL;p=p->next){
  	     	if(l.head->data.ngaysinh.nam==1){
  	     		 k=l.head;
  	     		  l.head=k->next;
  	     		   delete k;
			   }else if(p->data.ngaysinh.nam==1){
			   	       node*k;
			   	       node*g=p;
			   	        k->next=g->next;
			   	       delete g;
				   }else if(p->next==l.tail&&l.tail->data.ngaysinh.nam==1)
				   	   {   k=NULL;
				   	    	node*g=l.tail;
				   	    	  l.tail=k;
				   	    	  delete g;
				  }else{
				  	k=p;
				  }
			   }
		  cout<<"\n xuat nodw\n"; 
	xuat(l);
  }
  
  main(){
  	node*p;
	  list l;
	  nhanvien nv;
	  danhsach(l);
	  add(l,nv);
	  xuat(l);
	  cout<<"\n===SAP SEP DANH SACH TANG DAN THEO DIEM\n" ;
	  sapsep(l);
	  cout<<"\nXOA DI NOODE BAT KI TRONG DANH SACH"<<endl;
	xoaNodeBatKy(l);
}
