#include <iostream>
using namespace std;

void XepLoai(float dtb, float a, float b, float c)
{
	dtb = (a + b + c ) / 3;
	cout<<"\nDiem TBC he 10 :"<<dtb<<endl;
	cout<<endl;
	if (dtb >= 9 && dtb <10)
	{
		cout << "Xep loai Xuat sac" << endl;
	}
	else if(dtb >= 8 && dtb <9)
	{
		cout<<"Xep loai gioi "<<endl;
	}
	else if(dtb >= 7 && dtb <8)
	{
		cout<<"Xep loai kha "<<endl;
	}
	else if(dtb >= 6 && dtb <7)
	{
		cout<<"Xep loai trung binh "<<endl;
	}
	else if(dtb >= 5 && dtb <6)
	{
		cout<<"Xep loai yeu "<<endl;
	}
	else if(dtb < 5)
	{
		cout<<"Xep loai kem "<<endl;
	}
	cout<<endl;
}

int XepLoai_he4(float dtb, float a, float b, float c)
{
	dtb = (a + b + c ) / 3;
	
	
		if (dtb >= 9 && dtb <10)
		{
			int tbc4 = 4;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => A+"<<endl;
			return tbc4;
		}
		
		else if(dtb >= 8 && dtb <9)
		{
			int tbc4 = 3.5;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => A"<<endl;
			return tbc4;
		}
		else if(dtb >= 7 && dtb <8)
		{
			int tbc4 = 3;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => B+"<<endl;
			return tbc4;
		}
		else if(dtb >= 6 && dtb <7)
		{
			int tbc4 = 2.5;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => B"<<endl;
			return tbc4;
		}
		else if(dtb >= 5 && dtb <6)
		{
			int tbc4 = 2;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => C"<<endl;
			return tbc4;
		}
		else if(dtb < 5)
		{
			int tbc4 = 1;
			cout<<"\Diem tbc he 4 : "<<tbc4<<" => D/F"<<endl;
			return tbc4;
		}
	
}

int main()
{
	float a, b, c, dtb;
	cout<<"Nhap thong tin diem sinh vien UNETI :"<<endl;
	cout << "\tNhap diem Toan: ";
	cin >> a;
	cout << "\n\tNhap diem Ly: ";
	cin >> b;
	cout << "\n\tNhap diem Hoa: ";
	cin >> c;
	XepLoai_he4(dtb, a,b, c);
	XepLoai(dtb, a,b, c);
return 0;
}