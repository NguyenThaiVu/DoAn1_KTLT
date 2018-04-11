#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
#pragma warning(disable:4996)

struct SV {
	wchar_t MSSV[15];
	wchar_t Ten[51];
	wchar_t Khoa[51];
	int Namvaohoc;
	wchar_t Nam[11];
	wchar_t Hinhanh[16];
	wchar_t Motabanthan[1001];
	wchar_t Sothich1[101];
	wchar_t Sothich2[101];
};

//tạo mảng a có kiểu dữ liệu là các chuỗi chứa thông tin
wchar_t** TaoMang(FILE *f, int &n)
{
	n = 0;
	wchar_t **a = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	while (!feof(f))
	{
		a[n] = (wchar_t*)malloc(1600 * sizeof(wchar_t));
		fgetws(a[n], 1600, f);		//đọc file dữ liệu vào chuỗi a[n]

		if (!feof(f))
		{
			n++;
			a = (wchar_t**)realloc(a, (n + 1) * sizeof(wchar_t*));
		}
		else
			break;
	}
	return a;
}

void chuyen(wchar_t *b, wchar_t a[])
{

	for (int i = 0; i <= wcslen(b); i++)
		a[i] = b[i];
}



SV* laythongtin(wchar_t a[])
{
	int index = 0;
	wchar_t **b = (wchar_t **)malloc(8 * sizeof(wchar_t));
	wchar_t *p;
	p = wcstok(a, L",");
	while (p != NULL)
	{
		b[index] = p;
		index++;
		p = wcstok(NULL, L","); //cat chuoi tu vi tri dung lai truoc do
	}

	SV* sv = (SV*)malloc(sizeof(SV));
	chuyen(b[0], sv->MSSV);
	chuyen(b[1], sv->Ten);
	chuyen(b[2], sv->Khoa);
	sv->Namvaohoc = _wtoi(b[3]);
	chuyen(b[4], sv->Hinhanh);
	chuyen(b[5], sv->Nam);
	chuyen(b[6], sv->Motabanthan);
	chuyen(b[7], sv->Sothich1);
	chuyen(b[8], sv->Sothich2);
	return sv;
}

void vietfile(wchar_t a[])
{
	SV *sv = laythongtin(a);
	wchar_t filename[60];
	wcscpy(filename, sv->MSSV);
	wcscat(filename, L".html");

	FILE* fo = _wfopen(filename, L"wt");
	_setmode(_fileno(fo), _O_U8TEXT);

	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(fo, L"		<title>HCMUS - %ls</title>\n", sv->Ten);
	fwprintf(fo, L"	</head>\n");
	fwprintf(fo, L"	<body>\n");
	fwprintf(fo, L"		<div class=\"Layout_container\">\n");
	fwprintf(fo, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(fo, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(fo, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(fo, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(fo, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(fo, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(fo, L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fo, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(fo, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
	fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<div class=\"Personal_Phone\">\n");
	fwprintf(fo, L"                         Email:nva@gmail.com\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"				<!-- End Below Banner Region -->\n");
	fwprintf(fo, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(fo, L"				<div class=\"MainContain\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					<!-- Begin Top Region -->\n");
	fwprintf(fo, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n", sv->Ten);
	fwprintf(fo, L"								 <li>MSSV: %ls </li>\n", sv->MSSV);
	fwprintf(fo, L"								 <li>Sinh viên khoa %ls </li>\n", sv->Khoa);
	fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n", sv->Nam);
	fwprintf(fo, L"                              <li>Email: nva@gmail.com</li>\n");
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>%ls</li>\n", sv->Sothich1);
	fwprintf(fo, L"								 <li>%ls</li>\n", sv->Sothich2);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fo, L"						<div class=\"Description\">\n");
	fwprintf(fo, L"                            %ls.\n", sv->Motabanthan);
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(fo, L"				<div class=\"divCopyright\">\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"				@2015</br>\n");
	fwprintf(fo, L"				Đồ án giữa kì</br>\n");
	fwprintf(fo, L"				Kỹ thuật lâp trình</br>\n");
	fwprintf(fo, L"				TH2014/03</br>\n");
	fwprintf(fo, L"				1712921 - Nguyễn Thái Vũ</br>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Footer -->\n");
	fwprintf(fo, L"		</div>\n");
	fwprintf(fo, L"	</body>\n");
	fwprintf(fo, L"</html>");
	fclose(fo);
	fclose(fo);
	free(sv);
}

int main()
{
	int n, i;
	FILE* fo = fopen("data.txt", "rt");
	wchar_t **a = TaoMang(fo, n);

	for (i = 0; i <= n; i++)
		vietfile(a[i]);
	
	if (i == n)
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\tThanh cong!!!");
	free(a);
	getch();
	return 0;
}