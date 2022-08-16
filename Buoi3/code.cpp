#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;
struct Hanghoa {
	string Ma_hang;
	string Ten_hang;
	string don_vi_tinh;
	int so_luong;
	float don_gia, thanh_tien;
};

void Nhap_hh(Hanghoa	 hh[] , int n) 
{
	for(int i = 0; i < n; i++) {
		cout<<"+Hang hoa thu: "<<i+1<<endl;
		cout<<"\t->Nhap ma hang hoa: ";
		getline (cin , hh[i].Ma_hang);
		cout<<"\t->Nhap ten hang hoa: ";
		getline (cin , hh[i].Ten_hang);
		cout<<"\t->Nhap don vi tinh: ";
		getline (cin , hh[i].don_vi_tinh);
		cout<<"\t->Nhap so luong: ";
		cin >> hh[i].so_luong;
		cout<<"\t->Nhap don gia: ";
		cin >> hh[i].don_gia;
		
		cin.ignore();
	}
}
void Tieude() {
	cout<<"|  "<<left<<setw(20)<<"Ma hang hoa"<<left<< setw(2) <<"|  "
	    <<left<<setw(20)<<"Ten hang hoa"<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<"don vi tinh"<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<"so luong"<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<"don gia"<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<"thanh tien"<<left<< setw(2)<<"| \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
}
void inds(Hanghoa	 hh[],int i ,int n) {
	cout<<"|  "<<left<<setw(20)<<hh[i].Ma_hang<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<hh[i].Ten_hang<<left<< setw(2)<<"|  "
	    <<left<<setw(20)<<hh[i].don_vi_tinh<<left<< setw(2)<<"|  "
		<<left<<setw(20)<<hh[i].so_luong<<left<< setw(2)<<"|  "
	
		<<left<<setw(20)<<hh[i].don_gia<<left<< setw(2)<<"|  "
	    <<left<<setw(10)<<(long long)hh[i].thanh_tien<<left<< setw(2)<<"| \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
	if (i + 1 == n) {
		cout << endl<<endl <<endl;
	}
}

void Tinh_thanhtien(Hanghoa	 a[],  int n) 
{
	for (int i = 0; i < n; i++)
	{
		a[i].thanh_tien = a[i].don_gia * a[i].so_luong;
	}
}

void hang_hoa_max(Hanghoa	 hh[] , int n)
{
	int k;
    int max = hh[0].thanh_tien;
    for (int i = 1; i < n; i++)
    {
    	if (max < hh[i].thanh_tien)
    	{
	    	max = hh[i].thanh_tien;
	    	k =i;
	    }
    }
    inds(hh,k,n);
}

void sap_xep_tang_dan_so_luong(Hanghoa	 hh[], int n) 
{
    Tieude();
    Hanghoa nn;
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < n; j++)
		{
            if(hh[i].so_luong	 < hh[j].so_luong	)
			{
                nn = hh[i];
                hh[i] = hh[j];
                hh[j] = nn;
            }
        }
    }
    for(int i = 0; i < n; i++)
		{
			inds(hh,i,n);
		}
	cout<<endl;
}


void Luu(Hanghoa a[], int n)
{
   	ofstream file;
	file.open("product.dat");

	if (!file) {
		cout << "khong the tao duoc tap tin" << endl;
		exit(1);
	}
	file << setw(20) << "Ma hang hoa" << "|";
	file << setw(20) << "Ten hang hoa" << "|";
	file << setw(20) << "don vi tinh" << "|";
	file << setw(20) << "so luong" << "|";
	file << setw(20) << "don gia" << "|";
	file << setw(10) << "thanh tien" << "|\n";
	for (int i = 0; i < n; i++) {
		file << setw(20) << a[i].Ma_hang << "|";
		file << setw(20) << a[i].Ten_hang << "|";
		file << setw(20) << a[i].don_vi_tinh << "|";
		file << setw(20) << a[i].so_luong << "|";
		file << setw(20) << a[i].don_gia << "|";
		file << setw(10) << (long long)a[i].thanh_tien << "|\n";
	}
	cout << "Luu file thanh cong!";
	file.close();
}


void Doc(Hanghoa a[], int n)
{
	cout << "\t\t\t\t-----DANH SACH hang hoa TU TEP product.DAT-----" << endl;
	ifstream file("product.dat");
	if (!file)
	{
		cout << "Khong doc duoc tap tin" << endl;
		exit(1);
	}
	while (!file.eof())
	{
		string s;
		getline(file, s);
		cout << s << endl;
	}
	file.close();
}
void Menu() {
	    cout << "\n+******************************************************************************+";
        cout << "\n|               MENU QUAN LY HANG HOA				                          |";
        cout << "\n| 1. Nhap danh sach hang hoa  tu ban phim.                                     |";
        cout << "\n| 2. Tinh thanh tien cho cac hang hoa.                                         |";
        cout << "\n| 3. Xuat thong tin cac hang hoa  duoi dang bang.                              |";
        cout << "\n| 4. Sap xep danh sach hang hoa theo thu tu tang dan so luong.                 |";
        cout << "\n| 5. In thong tin hang hoa co thanh tien lon nhat                              |";
        cout << "\n| 6. Luu danh sach hang hoa tu tep product.dat.                                |";
        cout << "\n| 7. Doc danh sach hang hoa tu tep product.dat.                                |";
        cout << "\n| 0. Thoat khoi chuong trinh.                                                  |";
        cout << "\n+******************************************************************************+";                                                             
}


int main() {
	Hanghoa hh[1000];
	int n,x;
	
	do {
		Menu();
		cout<<"\nMoi ban nhap lua chon: ";
		cin>>x;
		cout << endl ;
		switch(x) {
			case 1 :
				cout<<"\nNhap so luong hang hoa: ";
				cin>>n;
				cin.ignore();
				Nhap_hh(hh,n);
				break;
			case 2:
				cout <<"Tinh thanh tien cho cac hang hoa\n";
				for (int i = 0 ; i < n ; i ++) {
					Tinh_thanhtien(hh, n);
				}
				cout <<"Da tinh thanh tien cho cac hang hoa\n";
				break;
			case 3:
				cout <<"Xuat thong tin cac hang hoa duoi dang bang\n";
				Tieude();
				for (int i = 0 ; i < n ; i ++) {
					inds(hh,i,n);
				}
				break;
				
			case 4:
            	cout<<"\t\t\t\t Danh sach hang hoa sap xep tang dan theo so luong \n\n";
                sap_xep_tang_dan_so_luong(hh , n);
				break;
				
			case 5:
				cout <<"In thong tin hang hoa co thanh tien cao nhat\n";
				hang_hoa_max(hh , n);
				break;
            
            case 6:
                Luu(hh , n);
				break;
            case 7:
                Doc(hh , n);
                
				break;
            case 0:
            	cout<<endl;
			default:
				cout << endl;
				break;
		}
	} while (x != 0);
        cout<<endl;
		cout<<endl; 
	return 0;
}