#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#include<ctime>
struct datetime1 {
	int ngay, thang, nam;
};
struct nhanvien
{
	char ma_nv[20];
	char ten_nv[20];
	datetime1 begin;
	int ngay_lamviec;
	int tuoi; 
	
};
void input_nv(nhanvien nv[], int &n)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	char *ch = asctime(t); 
	cout<<"\nNhap so nhan vien can them thong tin: ";
	do
	{
		cin >> n;
		if(n<1)
		cout <<"\nMoi ban nhap lai so luong nhan vien: ";
	}while(n < 1);
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNhap thong tin cho nhan vien thu "<<i+1;
		cin.ignore();
		cout<<"\nMa NV: ";
		cin.getline(nv[i].ma_nv,20);
		cout<<"Ho & ten: ";
		cin.getline(nv[i].ten_nv,20);
		cout<<"Tuoi: ";
		cin>>nv[i].tuoi;
		cout<<"Ngay vao lam: ";
		do{
	    	cin>>nv[i].begin.ngay;
	     	if(nv[i].begin.ngay >= 32 || nv[i].begin.ngay <= 0)
	    	cout<<"\nVui long nhap lai ngay: ";
     	}while(nv[i].begin.ngay >= 32 || nv[i].begin.ngay <= 0);
		cout<<"Thang vao lam: ";
		do{
	    	cin>>nv[i].begin.thang;
	     	if(nv[i].begin.thang >= 13 || nv[i].begin.thang <= 0)
	    	cout<<"\nVui long nhap lai thang: ";
     	}while(nv[i].begin.thang >= 13 || nv[i].begin.thang <= 0);
		cout<<"Nam vao lam: ";
		do{
	    	cin>>nv[i].begin.nam;
	     	if(nv[i].begin.nam>t->tm_year+1900 || nv[i].begin.nam <= 1900)
	    	cout<<"\nVui long nhap lai nam: ";
     	}while(nv[i].begin.nam>t->tm_year+1900 || nv[i].begin.nam <= 1900);
	}
}

void title()
{
	cout<<"\n";
	cout<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
	cout<<"|  Ma nhan vien      |    Ten nhan vien   |   Tuoi nhan vien   | Thoi gian bat dau  |  So ngay lam viec  |      Xep hang      |\n";
	cout<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
}

int nam_nhuan(int nam)
{
    if (nam % 400 == 0) return 1;
    else if (nam% 100 != 0 && nam % 4 == 0) return 1;
    return 0;
}

int dk_ngay(int ngay, int thang, int nam)
{
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (nam_nhuan(nam))
	a[1] = 29;
	
    if (thang < 1 || thang >12)
 	return 0;
 	
    if (ngay < 1 || ngay > a[thang -1]) 
	return 0;
	
    return 1;
}

int so_ngay_lamviec(int &date, int &month, int &year)
{
	// gan gia tri cua bien ngay lam viec 
	int d1, m1 , y1 ,d2 , m2 ,y2;
	d1 = date ;
	m1 = month;
	y1 = year;
	
	// gan gia tri hien tai
	time_t now = time('\0');
	tm *t = localtime(&now);
	char *ch = asctime(t); 
    d2 = t -> tm_mday;
    m2 = t -> tm_mon+1;
    y2 = t -> tm_year+1900;
    
    // khoi tao 3 bien de luu tong so ngay 
    int ngay =0,thang =0, nam=0;
    
    // Tinh khoang cach so ngay giua 2 thoi diem nam
    for (int i = y1; i < y2; i++)
        if( nam_nhuan(i))
 			nam += 366; 
			  
        else nam += 365;
     
     // Tinh khoang cach so ngay giua 2 thang 
    int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ( nam_nhuan(y2)) 
	a[1] = 29;
	           
    if (m1 > m2)
    {
        for (int i = m2; i < m1; i++)
            thang -= a[i-1];
    }
    else
    {
        for (int i=m1;i<m2;i++)
            thang +=a[i-1];
    }
    
    // Tinh khoang cach giua 2 ngay 
    ngay = d2-d1;       
	return (ngay + thang + nam);
}

void xep_loai( int day){
	if(day >= 0 && day < 100)
	cout<<"   Kem";
	if(day  >=  100  && day < 200)
	cout<<"   Trung binh";
	if(day >= 200  && day < 300)
	cout<<"   Kha";
	if(day >= 300 &&  day< 500)
	cout<<"   Gioi";
	if(day  >=  500)
	cout<<"   Xuat sac";
	if(day < 0)
	cout<<"Co cai nit ";
	
}

void output_nv(nhanvien nv[], int n)
{
	title();
	for(int i = 0; i  <n; i++)
	{
    	cout<<"| "<<setw(19)<<left<<nv[i].ma_nv;
	    cout<<"| "<<setw(19)<<left<<nv[i].ten_nv;
	    cout<<"| "<<setw(19)<<left<<nv[i].tuoi;
    	cout<<"| "<<setw( 2)<<right<<nv[i].begin.ngay<<"/"<<setw(2)<<right<<nv[i].begin.thang<<"/"<<setw(13)<<left<<nv[i].begin.nam;
    	cout<<"| "<<setw(19)<<left<<so_ngay_lamviec(nv[i].begin.ngay,nv[i].begin.thang,nv[i].begin.nam);
		cout<<"| "<<setw(19)<<left;xep_loai(so_ngay_lamviec(nv[i].begin.ngay,nv[i].begin.thang,nv[i].begin.nam));
		cout<<"|\n";
	}
	cout<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
}
void sort_age(nhanvien nv[], int n)
{
	for(int i = 0;  i < n-1; i++)
	for(int j = i+1; j < n; j++)
	if(nv[i].tuoi  > nv[j].tuoi)
	{
		nhanvien tg = nv[i];
 	          nv[i] = nv[j];
		      nv[j] = tg;
	}
	cout<<"\n\t\t\t\t    * DA SAP XEP DANH SACH NHAN VIEN THEO TUOI *";
	output_nv(nv,n);
}
void add_nv(nhanvien nv[], int &n)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	char *ch = asctime(t); 
	nhanvien nv_them;
	cout<<"\nNhap thong tin cho nhan vien muon them vao danh sach";
	cin.ignore();
	cout<<"\nMa NV: ";
	cin.getline(nv_them.ma_nv,20);
	cout<<"Ho & ten: ";
	cin.getline(nv_them.ten_nv,20);
	cout<<"Tuoi: ";
	cin>>nv_them.tuoi;
	cout<<"Ngay vao lam: ";
	do{
    	cin>>nv_them.begin.ngay;
     	if(nv_them.begin.ngay  >=  32  ||  nv_them.begin.ngay <=  0)
    	cout<<"\n[!]Vui long nhap lai ngay: ";
 	}while(nv_them.begin.ngay >= 32 ||  nv_them.begin.ngay  <= 0);
	cout<<"Thang vao lam: ";
	do{
    	cin>>nv_them.begin.thang;
     	if(nv_them.begin.thang  >=  13  ||  nv_them.begin.thang  <=  0)
    	cout<<"\n[!]Vui long nhap lai thang: ";
 	}while(nv_them.begin.thang  >=  13  || nv_them.begin.thang  <=  0);
	cout<<"Nam vao lam: ";
	do{
    	cin>>nv_them.begin.nam;
     	if(nv_them.begin.nam>t->tm_year+1900  ||  nv_them.begin.nam  <=  1900)
    	cout<<"\n[!]Vui long nhap lai nam: ";
 	}while(nv_them.begin.nam>t->tm_year+1900  ||  nv_them.begin.nam   <=  1900);
	n++;
	nv[n-1]  =  nv_them;
	cout<<"\n\t\t\t\t DANH SACH THONG TIN NHAN VIEN SAU KHI THEM ";
	output_nv(nv,n);
}

void delete_nv (nhanvien nv[], int &n)
{
	char s[20];
	cin.ignore();
	cout<<"\n[!]Nhap ma nhan vien muon xoa: ";
	cin.getline(s,20);
	int vitri = 0 , dem = 0;
	for(int i =  0 ; i <= n; i++)
	if(strcmpi(nv[i].ma_nv,s) ==  0)
	{
		vitri  = i;
		dem++;
		break;
	}
	if(dem  ==  0)
	{
		cout<<"\n---Ma nhan vien khong ton tai!---";
	}
	else
	{
		for(int i =  vitri; i < n; i++)
		{
			nv[i] =  nv[i+1];
		}
		n--;
	    cout<<"\n\t\t\t\t DANH SACH THONG TIN NHAN VIEN SAU KHI XOA ";
		output_nv(nv,n);
	}
}

void set_nv(nhanvien nv[], int n)
{
	char s[20];
	cin.ignore();
	cout<<"\nNhap ma nhan vien muon sua: ";
	cin.getline(s,20);
	int vitri=0 , dem = 0;
	for(int i =  0 ; i <= n ; i++)
	if(strcmpi(nv[i].ma_nv,s)  == 0)
	{
		vitri =  i;
		dem++;
		break;
	}
	if(dem  ==  0)
	{
		cout<<"\n---Ma nhan vien khong ton tai!---";
	}
	else
	{
		for(int i =  0 ; i <=  n ; i++ )
		{
			time_t now = time('\0');
			tm *t = localtime(&now);
			char *ch = asctime(t); 
			nhanvien nv_them;
			cin.ignore();
			cout<<"Nhap thong tin cho nhan vien muon sua lai\n";
			cout<<"\nMa NV: ";
			cin.getline(nv[vitri].ma_nv,20);
			cout<<"Ho & ten: ";
			cin.getline(nv[vitri].ten_nv,20);
			cout<<"Tuoi: ";
			cin>>nv[vitri].tuoi;
			cout<<"Ngay vao lam: ";
			do{
		    	cin>>nv[vitri].begin.ngay;
		     	if(nv[vitri].begin.ngay  >=  32  ||  nv[vitri].begin.ngay  <= 0)
		    	cout<<"\nVui long nhap lai ngay: ";
		 	}while(nv[vitri].begin.ngay  >=  32  ||  nv[vitri].begin.ngay  <= 0);
			cout<<"Thang vao lam: ";
			do{
		    	cin>>nv[vitri].begin.thang;
		     	if(nv[vitri].begin.thang>=13||nv[vitri].begin.thang <= 0)
		    	cout<<"\nVui long nhap lai thang: ";
		 	}while(nv[vitri].begin.thang>=13||nv[vitri].begin.thang  <=  0);
			cout<<"Nam vao lam: ";
			do{
		    	cin>>nv[vitri].begin.nam;
		     	if(nv[vitri].begin.nam>t->tm_year+1900  ||  nv[vitri].begin.nam  <=  1900)
		    	cout<<"\nVui long nhap lai nam: ";
		 	}while(nv[vitri].begin.nam>t->tm_year+1900  ||  nv[vitri].begin.nam  <=  1900);
		 	break;
		}
		
	    cout<<"\n\t\t\t\t DANH SACH THONG TIN NHAN VIEN SAU KHI SUA ";
		output_nv(nv,n);
	}
}
void save_file(nhanvien nv[],int n)
{
	ofstream output;
	output.open("xuan .out",ios::out);// duong dan tuong doi 
	if(!output)
	{
		cout<<"KHONG THE LUU TEP TIN!";
	}
	else
	{
		output<<"\n\t\t\t\t\t\t\t THONG TIN NHAN VIEN ";
		output<<"\n";
		output<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
		output<<"|  Ma nhan vien      |    Ten nhan vien   |   Tuoi nhan vien   | Thoi gian bat dau  |  So ngay lam viec  |      Xep hang      |\n";
		output<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
    	for(int i = 0; i < n; i++)
    	{
		    output<<"| "<<setw(19)<<left<<nv[i].ma_nv;
		    output<<"| "<<setw(19)<<left<<nv[i].ten_nv;
		    output<<"| "<<setw(19)<<left<<nv[i].tuoi;
	    	output<<"| "<<setw( 2)<<right<<nv[i].begin.ngay<<"/"<<setw(2)<<right<<nv[i].begin.thang<<"/"<<setw(13)<<left<<nv[i].begin.nam;
	    	output<<"| "<<setw(19)<<left<<so_ngay_lamviec(nv[i].begin.ngay,nv[i].begin.thang,nv[i].begin.nam);
			output<<"| "<<setw(19)<<left;
			int day =  so_ngay_lamviec(nv[i].begin.ngay,nv[i].begin.thang,nv[i].begin.nam);
			if(day >= 0  &&  day < 100)
			output<<"Kem";
			if(day >= 100 && day<200)
			output<<"Trung binh";
			if(day >=  200  && day  <  300)
			output<<"Kha";
			if(day  >=  300  && day < 500)
			output<<"Gioi";
			if(day  >=  500)
			output<<"Xuat sac";
			if(day < 0)
			output<<"Loi";
			output<<"|\n";
        }
	        output<<"+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
        	cout<<"\n\t\t\t\t\t  LUU TEP THANH CONG ";
        	/*
cout<<"\n\t\t\t\t* MO TEP 'nv.out' DE XEM DANH SACH NHAN VIEN * \n\n";*/	
  	}
	output.close();
}

void time()
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	char *ch = asctime(t); 
	/*
cout<<"\n\t\t+------------------------------< TIME >-------------------------------+";*/
	cout<<"\n\t\t|\t\t  HOM NAY LA NGAY "<< t->tm_mday <<" THANG "<<t->tm_mon+1 <<" NAM "<<t->tm_year+1900<<"                 |";
	/*
cout<<"\n\t\t+---------------------------------------------------------------------+";*/
	cout<<"\n\n";
}
void menu()
{

	/*
cout<<"\n\t\t+------------------------------< MENU >-------------------------------+";
	cout<<"\n\t\t|           * HAY LUA CHON CONG VIEC BAN MUON THUC HIEN *             |";*/
	cout<<"\n\t\t+---------------------------------------------------------------------+";
	cout<<"\n\t\t|        1.Nhap danh sach nhan vien tu ban phim                       |";
	cout<<"\n\t\t|        2.In danh sach thong tin nhan vien duoi dang bang            |";
	cout<<"\n\t\t|        3.Xap xep va in danh sach theo tuoi tang dan                 |";
	cout<<"\n\t\t|        4.Sua thong tin nhan vien                                    |";
	cout<<"\n\t\t|        5.Them thong tin nhan vien                                   |";
    cout<<"\n\t\t|        6.Xoa thong tin nhan vien                                    |";
    cout<<"\n\t\t|        7.Luu danh sach nhan vien                                    |";
    cout<<"\n\t\t|        0.thoat khoi chuong trinh                                    |";
	cout<<"\n\t\t+---------------------------------------------------------------------+";
}
int main()
{
	time();
	nhanvien *nv;
	int n;
	nv = new nhanvien[n];
	int cv;
	int dem = 0;
    laplai:
	menu();
	cout<<"\n\n LUA CHON CONG VIEC : ";
	cin>>cv;
	switch(cv)
    {
    	case 1:
    	    dem++;
	    	input_nv(nv,n);
            goto laplai;
    	case 2:
	       	if(dem == 0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	    		cout<<"\n\t\t\t\t\t\t< DANH SACH THONG TIN NHAN VIEN >";
	            output_nv(nv,n);
    		    goto laplai;
	    	}
        case 3:
        	if(dem == 0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	    		cout<<"\n\t\t\t\t< DANH SACH THONG TIN NHAN VIEN THEO TUOI TANG DAN >";
	            sort_age(nv,n);
    		    goto laplai;
	    	}
	    case 4:
        	if(dem  ==  0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	            set_nv(nv,n);
    		    goto laplai;
	    	}
	    case 5:
			if(dem == 0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	    		add_nv(nv,n);
    		    goto laplai;
	    	}
		case 6:
			if(dem == 0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	            delete_nv(nv,n);
    		    goto laplai;
	    	}
		case 7:
			if(dem == 0)
			{
	    		cout<<"\nVui long chon cong viec 1 de nhap thong tin truoc!";
	    		goto laplai;
	    	}
	    	else
	    	{
	    		save_file(nv,n);
    		    goto laplai;
	    	}
		case 0:
			cout<<"\n\t\t\t\t KET THUC CHUONG TRINH! "<<endl;
			break;	
		default:
			cout<<" Vui long nhap lai!";
			goto laplai;
    }
	_getche;
	return 0;
}