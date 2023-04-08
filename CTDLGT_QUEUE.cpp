//bai1 
#include <iostream>
#include <string>
using namespace std;
#define MAX_OF_QUEUE 100
int top = -1;
struct Date 
{
    int Ngay, Thang, Nam;
    void Nhap()
    {
        cout << "Ngay : "; cin >> Ngay;
        cout << "Thang :"; cin >> Thang;
        cout << "Nam : "; cin >> Nam;
    }
    void Xuat()
    {
        cout << Ngay << "/" << Thang << "/" << Nam << endl;
    }

};
struct HangHoa
{
    string ID, Ten;
    Date NgayXuat;
    float GiaXuat;
    void Nhap()
    {
        cout << "ID : ";
        getline(cin, ID);
        cout << "Ten : ";
        getline(cin, Ten);
        NgayXuat.Nhap();
        cout << "Gia xuat : ";
        cin >> GiaXuat;
        cin.ignore();
    }
    void Xuat()
    {
        cout << "ID :" << ID << endl;
        cout << "Ten : " << Ten << endl;
        cout << "Ngay Xuat : "; NgayXuat.Xuat();
        cout << "Gia Xuat : " << GiaXuat << endl;
    };

};
void push(HangHoa** queue,HangHoa* data)
{
    if (top < MAX_OF_QUEUE)
    {
        top = top + 1;
	for (int i = top; i > 0; i--)
		queue[i] = queue[i-1];
		queue[0] = data;
    }
    else
    {
        cout << "Queue da day!";
        exit(0);
    }
}
HangHoa* pop(HangHoa** queue)
{
    HangHoa* Data;
    if (top >= 0)
    {
        Data = queue[top];
        top = top - 1;
    }
    else
    {
        cout << "queue rong!";
        return NULL;
    }
    return Data;
}
void SearchQueue(HangHoa** queue,string ID = "001")
{
    cout << "------------------------------------\n";
    int count = 0;
    for (int i = 0; i <= top; ++i)
    {
        HangHoa* hh = queue[i];
        if (hh->ID == ID)
        {
            hh->Xuat();
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Khong co hang hoa nao ID = " << ID << endl;
    }
    cout << "------------------------------------\n";

}
void EmptyQueue(HangHoa** queue)
{
    while (top > -1)
    {
        cout << "Thong tin hang hoa chuan bi boc ra :\n";
        HangHoa* hh = pop(queue);
        hh->Xuat();
        cout << "Da boc goi hang ra khoi bang truyen!\n";
        cout << "-----------------------\n";
    }
    cout << "Da boc het hang ra khoi bang truyen!\n";
    
}
int main()
{
    //Cau 1
    HangHoa* hangHoa = new HangHoa();
    hangHoa->Nhap();
    hangHoa->Xuat();
    delete hangHoa;
    cout << "------------------------------------\n";
    //Cau 2
    int n;
    HangHoa** queue = new HangHoa*[MAX_OF_QUEUE];
    cout << "So luong hang hoa : "; cin >> n;
    cin.ignore();
    cout << "Nhap danh sach hang hoa :" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Thong tin hang hoa thu " << i + 1 << ":\n";
        HangHoa* hh = new HangHoa();
        hh->Nhap();
        push(queue, hh);
    }
    //Cau 3
    SearchQueue(queue);
    //Cau 4
    EmptyQueue(queue);
}
