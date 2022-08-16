#include<iostream>
using namespace std;

void Nhap( int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
    }
}

void Xuat( int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"a["<<i<<"] ="<<a[i]<<endl;
    }
}

void TBC (int a[], int n)
{
    float s = 0;
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2== 0 && a[i] < 0)
        {
            dem++;
            s = s + a[i];
        }
    }
    cout<<"\nTong tbc am chan la : "<<(float)s/dem<<endl;
}

void DEM_am(int a[], int n)
{
    int so_am = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < 0)
        {
            so_am++;
        }
    }
cout<<"\nMang co :"<<so_am<<" so am "<<endl;
}

void DEM_duong(int a[], int n)
{
    int so_duong = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            so_duong++;
        }
    }

    cout<<"\nMang co :"<<so_duong<< " so duong "<<endl;
}

	void sapXep(int &x, int &y) {
    int tmp;
    {
        tmp = x;
        x = y;
        y = tmp;
    }
}

void SapXepTLe(int a[], int n)
{
	
	cout<<"\nMang sap xep phan tu le tang dan:\n ";
	for( int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j] && a[i]%2!=0 && a[j]%2!=0)
				sapXep(a[i],a[j]);
}

void SapXepGChan(int a[], int n)
{
	
	cout<<"\nMang sap xep phan tu chan giam dan:\n ";
	for( int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]<a[j] && a[i]%2==0 && a[j]%2==0)
				sapXep(a[i],a[j]);
}

int main()
{
    int n, a[100];
    cout<<"\nNhap so luong mang :";
    cin>>n;
    Nhap(a, n);
    cout<<"\nMang da nhap la :"<<endl;
    Xuat(a, n);
    TBC(a, n);
    DEM_am(a, n);
    DEM_duong(a, n);
    SapXepTLe(a,n);
    Xuat(a, n);
    SapXepGChan(a, n);
    Xuat(a, n);

}