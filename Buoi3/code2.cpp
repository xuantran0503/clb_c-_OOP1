#include<iostream>
#include<iomanip> // dung setw
#include<windows.h> // he thong (text color)
#include<conio.h>  // dung getch()
#include <math.h>  //tinh toan
#include<fstream> // file tep

using namespace std;
#define max 50

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

struct NhanVien
{
    char name[30];
    int maNV;
    char chucvu[20];
    long long heSoluong;
    long long luong;
    long long phuCap;
    long long thucLinh;
};

typedef struct NhanVien nhanvien;

void nhapDSNV(nhanvien nv[], int &n)
{
    cout << setw(50) << " NHAP THONG TIN NHAN VIEN \n";
    for(int i = 0; i < n; i++)
    {
        cout << "\n <> Nhap vao thong nhan vien thu "<< i + 1 << endl;
        cin.ignore();
        cout << " Ten nhan vien: ";
        cin.getline(nv[i].name,30);
        cout << " Ma nhan vien: ";
        cin >> nv[i].maNV;
        cin.ignore();
        cout << " Chuc vu (TP / PP / NV): ";
        cin.getline(nv[i].chucvu,20);
        cout << " Nhap vao he so luong: ";
        cin >> nv[i].heSoluong;
        }
}

void tinhLuongNV(nhanvien nv[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        nv[i].luong = nv[i].heSoluong * 1490000;
    }
}

void phuCapNV(nhanvien nv[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        if (stricmp(nv[i].chucvu,"TP") == 0)
        {
            nv[i].phuCap = 1000000;
        }
        else if (stricmp(nv[i].chucvu,"PP") == 0)
        {
            nv[i].phuCap = 700000;
        }
        else if (stricmp(nv[i].chucvu,"NV") == 0)
        {
            nv[i].phuCap = 300000;
        }
    }
}

void thucLinhNV(nhanvien nv[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        nv[i].thucLinh = nv[i].luong + nv[i].phuCap;
    }
}

void tieuDe()
{
    textcolor(14);
    cout << "\n+--------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ \n";
    cout <<"|"<< setw(20) <<"MA NHAN VIEN" << "|"
        << setw(30) <<"TEN NHAN VIEN" << "|"
        << setw(20) <<"CHUC VU" << "|"
        << setw(20) <<"HE SO LUONG" << "|"
        << setw(20) <<"LUONG" << "|"
        << setw(20) <<"PHU CAP" << "|"
        << setw(20) <<"THUC LINH" << "|";
    cout << "\n+--------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ ";
    textcolor(7);
    cout<< endl;
}

void xuatDSNV(nhanvien nv[], int n)
{
    tieuDe();
    tinhLuongNV(nv,n);
    phuCapNV(nv,n);
    thucLinhNV(nv,n);
    for (int i = 0 ; i < n; i++)
    {
        cout<<"|"<< setw(20) << nv[i].maNV << "|"
            << setw(30) << nv[i].name << "|"
            << setw(20) << nv[i].chucvu << "|"
            << setw(20) << nv[i].heSoluong << "|"
            << setw(20) << nv[i].luong << "|"
            << setw(20) << nv[i].phuCap << "|"
            << setw(20) << nv[i].thucLinh << "|";
        cout << "\n---------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ ";
        cout << endl;
    }
}

void hoanDoi(nhanvien &a, nhanvien &b)
{
    NhanVien t = a;
    a = b;
    b = t;
}

void BubbleSort(nhanvien nv[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = n - 1; j > i; j--)
		{
			if(nv[j].thucLinh > nv[j - 1].thucLinh)
			{
				hoanDoi(nv[j],nv[j - 1]);
			}
		}
	}
    cout << "\n" << endl;
    cout << setw(85)<< " DANH SACH SAU KHI SAP XEP\n ";
}

void SelectionSort(nhanvien nv[], int n)
{
	int smax;
	for (int  i = 0; i < n - 1; i++)
    {
		smax = i; 
		for(int j = i + 1; j < n; j++)
        {
            if (nv[j].thucLinh > nv[smax].thucLinh)
            {
                smax = j;
            }
        }
        if(smax != i)
        {
            hoanDoi(nv[smax], nv[i]);
        }
	}
    cout << "\n" << endl;
    cout << setw(85)<< " DANH SACH SAU KHI SAP XEP\n ";
}

void chucVuNV(nhanvien nv[], int n)
{
    int dem = 0;
    tieuDe();
	for(int i = 0 ; i < n; i++)
	{
		if(stricmp(nv[i].chucvu,"TP") == 0)
		{
            tinhLuongNV(nv,n);
            phuCapNV(nv,n);
            thucLinhNV(nv,n);
            cout<<"|"<< setw(20) << nv[i].maNV << "|"
                << setw(30) << nv[i].name << "|"
                << setw(20) << nv[i].chucvu << "|"
                << setw(20) << nv[i].heSoluong << "|"
                << setw(20) << nv[i].luong << "|"
                << setw(20) << nv[i].phuCap << "|"
                << setw(20) << nv[i].thucLinh << "|";
            cout << "\n---------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ ";
            cout << endl;
            dem ++;
        }
    }
    if (dem == 0)
    {
        cout << endl;
        cout <<setw(85) << " DOI TUONG CAN TIM KHONG CO TRONG DAN SACH " << endl;
    }
}

void Ghi_File(nhanvien nv[], int n)
{
	fstream f("nv1.dat",ios::out);
	if(!f)
	{
		cout<<"Khong the tao tep tin ";
		exit(1);
	}
    textcolor(14);
    f   << "\n+--------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ \n"
        <<"|"<< setw(20) <<"MA NHAN VIEN" << "|"
        << setw(30) <<"TEN NHAN VIEN" << "|"
        << setw(20) <<"CHUC VU" << "|"
        << setw(20) <<"HE SO LUONG" << "|"
        << setw(20) <<"LUONG" << "|"
        << setw(20) <<"PHU CAP" << "|"
        << setw(20) <<"THUC LINH" << "|"
        << "\n+--------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ ";
    textcolor(7);
    cout<< endl;
    for ( int i = 0 ; i < n ; i++)
    {
        tinhLuongNV(nv,n);
        phuCapNV(nv,n);
        thucLinhNV(nv,n);
        f <<"|"<< setw(20) << nv[i].maNV << "|"
            << setw(30) << nv[i].name << "|"
            << setw(20) << nv[i].chucvu << "|"
            << setw(20) << nv[i].heSoluong << "|"
            << setw(20) << nv[i].luong << "|"
            << setw(20) << nv[i].phuCap << "|"
            << setw(20) << nv[i].thucLinh << "|"
         << "\n---------------------+------------------------------+--------------------+--------------------+--------------------+--------------------+--------------------+ "
         << endl;
    }
	f.close();
    cout << setw(85) << "-----DA LUU DANH SACH!!----- \n";
}

void Doc_File(nhanvien nv[], int &n)
{
	cout << endl;
	cout <<setw(85)<< " ----------Danh sach nhan vien tu tep 'nv1.dat'----------  \n" << endl;
	ifstream f;
	f.open("nv1.dat");
	string data;
	while (getline(f, data))
	{
		cout << data << endl;
	}
	f.close();
}

void menu()
{
    system("cls");
    textcolor(5);
    cout<< setw(100) << "0o======================================================================o0\n";
    cout<< setw(100) << "||                     0o----------MENU----------o0                     ||\n";
    cout<< setw(100) << "||**********************************************************************||\n";
    cout<< setw(100) << "|| 1 . Nhap danh sach nhan vien.                                        ||\n";
    cout<< setw(100) << "|| 2 . In ra danh sach nhan vien.                                       ||\n";
    cout<< setw(100) << "|| 3 . Sap xep giam dan theo thuc linh                                  ||\n";
    cout<< setw(100) << "|| 4 . Nhan vien co chuc vu la 'TP'                                     ||\n";
    cout<< setw(100) << "|| 5 . Luu danh sach ra tep nv1.dat                                     ||\n";
    cout<< setw(100) << "|| 5 . doc danh sach tu tep nv1.dat va in ra man hinh                   ||\n";
    cout<< setw(100) << "|| 0 . Thoat.                                                           ||\n";
    cout<< setw(100) << "0o=================================~END~================================o0\n";
    cout<< endl;
}

int main ()
{
    int luachon,n;
	nhanvien nv[max];
    bool in = false;
    do
    {
        menu();
        cout << "-> Nhap lua chon cua ban: ";
        cin >> luachon ;
        textcolor(7);
        cout << endl;
        switch(luachon)
        {
            case 1:
            {
                cout << "\n (?) So nhan vien: ";
                do
                {
                    cin >> n;
                    if (n <= 0 || n > max)
                    {
                        cout << "(!) Khong hop le !!! Phai lon hon 1 va nho hon "<< max << endl;
                    }
                } while (n <= 0 || n > max);
                cout << endl;
                nhapDSNV(nv,n);
                in = true;
                break;
            }
            case 2:
            {
                if (in)
                {
                    xuatDSNV(nv,n);
                }
                else
                {
                    cout << "(!)Chua nhap danh sach!!! \n";
                }
                break;
            }
            case 3:
            {
                if (in)
                {
                    textcolor(10);
                    cout << "\n\t\t  > 1. Bubble Sort (Noi bot)";
                    cout << "\n\t\t  > 2. Selection Sort (Chon truc tiep)";
                    cout << "\n\t\t  > 0. Thoat ";
                    cout << "\n\t\t-> Lua chon: ";
                    do
                    {
                        cin >> luachon;
                        textcolor(7);
                        if (n < 0 || n > 3)
                        {
                            cout << "(!) Khong hop le !!! Phai lon hon 1 va nho hon 3"<< endl;
                        }
                        
                    } while (n < 0 || n > 4);
                    switch(luachon)
                    {
                        case 1:
                        {
                            BubbleSort(nv,n);
                            xuatDSNV(nv,n);
                            break;
                        }
                        case 2:
                        {
                            SelectionSort(nv,n);
                            xuatDSNV(nv,n);
                            break;
                        }
                    }
                }
                else 
                cout << "(!)Chua nhap danh sach!!! \n";
                break;
            }
            case 4:
            {
                if (in)
                {
                    chucVuNV(nv,n);
                }
                else 
                cout << "(!)Chua nhap danh sach!!! \n";
                break;
            }
            case 5:
            {
                if (in)
                {
                    Ghi_File(nv,n);
                }
                else
                {
                    cout << "(!)Chua nhap danh sach!!! \n";
                }
                break;
            }
            case 6:
            {
                if (in)
                {
                    Doc_File(nv,n);
                }
                else
                {
                    cout << "(!)Chua nhap danh sach!!! \n";
                }
                break;
            }
            default:
                cout << setw(85) << "(!) Xac nhan thoat an lien tiep 2 lan ENTER";
        }
        cout << "\n "<< endl;
        cout << setw(85) << " BAM PHIM BAT KY DE TIEP TUC CHUONG TRINH...";
        _getch();
    } while (luachon > 0 && luachon <= 5);
    system("pause");
}