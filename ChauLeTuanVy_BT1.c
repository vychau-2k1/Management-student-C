//Khai bao thu vien su dung
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Khai bao struct luu thong tin Sinh Vien
struct SinhVien
{
	int id;
	char name[100];
	char genre[6];
	char age[3];
	float math, physics, chemistry;
	float gpa;
	char result[10];
};

//Khai bao ham
void Nhap(struct SinhVien *sv); //Ham nhap thong tin sinh vien cho sinh vien dau tien
void NhapNextStudent(struct SinhVien *sv, int i); //Ham nhap sinh vien tiep theo
void addFirstStudent(struct SinhVien temp[], int n); //Ham them sinh vien dau tien
void addNextStudent(struct SinhVien temp[], int n); //Ham them thong tin tiep theo
void updateStudent(struct SinhVien temp[], int idC, int n); //Ham cap nhat thong tin sinh vien bang id
void show(struct SinhVien *sv); //Ham hien thi thong tin sinh vien
void showStudent(struct SinhVien temp[], int n); //Ham hien thi toan bo sinh vien trong danh sach
void sortName(struct SinhVien a[], int n); //Ham sap xep ten theo thu tu tang dan
void calAverageScore(struct SinhVien *sv); //Ham tinh diem trung binh
void Classification(struct SinhVien *sv); //Ham xep loai hoc luc sinh vien
void updateInfor(struct SinhVien *sv); //Ham cap nhat thong tin sinh vien
void deleteById(struct SinhVien temp[], int *n, int id); //Ham xoa sinh vien bang id
void sortScore(struct SinhVien temp[], int n); //Ham sap xep diem theo thu tu tang dan
void searchByName(struct SinhVien temp[], int n, char nameSearch[]); //Ham tim kiem sinh vien bang ten
//void splitName(struct SinhVien temp[], char name[], int n);

//Main function
int main(void)
{
	int number, n;
	int idUpdate;
	int idDelete;
	char nameSearch[10];
	bool nhapXong = false; //de dam bao co du lieu sinh vien nhap vao moi co the su dung cac chuc nang
	while(n <= 0)
	{
		printf("Nhap so Sinh vien can them: \n");
		scanf("%d", &n);
	}
	struct SinhVien temp[n];
	//Vong lap vo tan
	while(1)
	{
		system("cls"); //Ham xoa man hinh
		printf("-----------------------------------------\n");
		printf("| Chuong trinh Quan ly sinh vien bang C |\n");
		printf("| Cac chuc nang: 			|\n");
		printf("| 1. Them thong tin Sinh vien		|\n");
		printf("| 2. Cap nhat thong tin Sinh vien boi ID|\n");
		printf("| 3. Xoa Sinh vien bang ID		|\n");
		printf("| 4. Tim kiem Sinh vien bang ten	|\n");
		printf("| 5. Sap xep Sinh vien theo GPA		|\n");
		printf("| 6. Hien thi danh sach theo ten   	|\n");
		printf("| 7. Thoat				|\n");
		printf("-----------------------------------------\n");
		printf("Nhap chuc nang can thuc hien: \n");
		scanf("%d", &number);
		switch(number) //Su dung switch de lua chon cac chuc nang
		{
			case 1: //chuc nang them thong tin SV
				printf("\nBan da chon them thong tin Sinh vien\n");
				addFirstStudent(temp, n); //Goi ham them thong tin sinh vien
				addNextStudent(temp, n);
				printf("Ban da nhap xong danh sach sinh vien\n");
				nhapXong = true;
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 2: //cap nhat thong tin sinh vien bang id
				if(nhapXong == true)
				{
					printf("\nBan da chon cap nhat thong tin Sinh vien bang ID\n");
					printf("Ban vui long nhap id sinh vien can cap nhat thong tin: "); 
					scanf("%d", &idUpdate); //Nhap id can cap nhat
					updateStudent(temp, idUpdate, n); //Goi ham update thong tin bang id
				}
				else
				{
					printf("\nBan vui long nhap danh sach sinh vien truoc khi cap nhat\n");
				}
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 3: //xoa sinh vien bang id
				if(nhapXong == true)
				{
					printf("Ban da chon xoa sinh vien bang ID\n");
					printf("Ban vui long nhap ID cua sinh vien can xoa: \n");
					scanf("%d", &idDelete);
					deleteById(temp, &n, idDelete);
				}
				else
				{
					printf("\nBan vui long nhap danh sach sinh vien truoc khi cap nhat\n");
				}
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 4: //Tim kiem thong tin sinh vien bang ten
				if(nhapXong == true)
				{
					printf("Ban da lua chon chuc nang tim kiem thong tin bang ten\n");
					printf("Vui long nhap ten sinh vien ban muon tim kiem: \n");
					scanf("%s", &nameSearch);
					searchByName(temp, n, nameSearch);
				}
				else
				{
					printf("\nBan vui long nhap danh sach sinh vien truoc khi cap nhat\n");
				}
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 5: //Sap xep danh sach theo diem trung binh GPA
				if(nhapXong == true)
				{
					printf("Ban da chon chuc nang sap xep danh sach theo GPA\n");
					sortScore(temp, n);
					showStudent(temp, n);
				}
				else
				{
					printf("\nBan vui long nhap danh sach sinh vien truoc khi cap nhat\n");
				}
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 6: //Hien thi danh sach sinh vien theo ten
				if(nhapXong == true)
				{
					printf("\nBan da chon hien thi danh sach Sinh vien theo ten\n");
					sortName(temp, n);
					showStudent(temp, n); //Goi ham update thong tin bang id
				}
				else
				{
					printf("\nBan vui long nhap danh sach sinh vien truoc khi hien thi\n");
				}
				printf("Lua chon chuc nang khac de tiep tuc\n");
				getch();
				break;
			case 7: //Thoat khoi chuong trinh
				printf("Ban da chon thoat");
				getch();
				exit(0); //function use to exit program
			default: //Neu nhap so khong co chuc nang thi yeu cau nhap lai cho phu hop
				printf("Chuc nang nay hien khong co, vui long nhap lai: ");
				getch();
				break;
		}
	}
	return 0;
}
void Nhap(struct SinhVien *sv)
{
	printf("\nNhap id: "); scanf("%d", &sv->id); //id
	printf("\nNhap ho ten sinh vien: "); //ho va ten
	fflush(stdin); //Used to clear the buffer and accept the next string
	gets(sv->name);
	printf("\nNhap gioi tinh sinh vien: "); gets(sv->genre); //gioi tinh
	printf("\nNhap tuoi cua sinh vien: "); scanf("%s", &sv->age); //tuoi
	printf("\nNhap lan luot diem toan, ly, hoa cua sinh vien: "); scanf("%f %f %f", &sv->math, &sv->physics, &sv->chemistry); //diem toan ly hoa
	calAverageScore(sv);
	Classification(sv);
}
void NhapNextStudent(struct SinhVien *sv, int i)
{
	sv->id = i;
	printf("\nNhap ho ten sinh vien: "); //ho va ten
	fflush(stdin); //Used to clear the buffer and accept the next string
	gets(sv->name);
	printf("\nNhap gioi tinh sinh vien: "); gets(sv->genre); //gioi tinh
	printf("\nNhap tuoi cua sinh vien: "); scanf("%s", &sv->age); //tuoi
	printf("\nNhap lan luot diem toan, ly, hoa cua sinh vien: "); scanf("%f %f %f", &sv->math, &sv->physics, &sv->chemistry); //diem toan ly hoa
	calAverageScore(sv);
	Classification(sv);
}
void addFirstStudent(struct SinhVien temp[], int n)
{
	printf("\n---------------------------------\n");
	printf("Nhap sinh vien dau tien: ");
	Nhap(&temp[0]);
}
void addNextStudent(struct SinhVien temp[], int n)
{
	int i = 0;
	printf("\n---------------------------------\n");
	int a = temp[0].id;
	for(i = 1; i < n; i++)
	{
		printf("Nhap sinh vien thu %d: ", i+1);
		NhapNextStudent(&temp[i], a+i);
		
	}
}
void updateInfor(struct SinhVien *sv)
{
	printf("\nCap nhat ho ten sinh vien: "); //ho va ten
	fflush(stdin); //Clear space va nhan chuoi string tiep theo
	gets(sv->name);
	printf("\nCap nhat gioi tinh sinh vien: "); gets(sv->genre); //gioi tinh
	printf("\nCap nhat tuoi cua sinh vien: "); scanf("%s", &sv->age); //tuoi
	printf("\nCap nhat lan luot diem toan, ly, hoa cua sinh vien: "); scanf("%f %f %f", &sv->math, &sv->physics, &sv->chemistry); //diem toan ly hoa
	calAverageScore(sv); //Tinh diem trung binh
	Classification(sv); //Phan loai hoc luc
}
void updateStudent(struct SinhVien temp[], int idC, int n)
{
	int found = 0;
	int i = 0;
	for(i = 0; i < n; i++)	
	{
		if(temp[i].id == idC && found == 0)
		{
			printf("Cap nhat thong tin cho sinh vien co ID: %d", idC);
			updateInfor(&temp[i]);
			found = 1;
			break;
		}
	}
	if(found == 0)
	{
		printf("Sinh vien co ID: %d khong ton tai\n", idC);
	}
}
void show(struct SinhVien *sv)
{
	
	printf("ID Sinh vien: %d\n", sv->id);
	printf("Ho ten Sinh vien: %s\n", sv->name);
	printf("Gioi tinh: %s\n", sv->genre);
	printf("Tuoi cua Sinh vien: %s\n", sv->age);
	printf("Diem Toan: %.2f\n", sv->math);
	printf("Diem Ly: %.2f\n", sv->physics);
	printf("Diem Hoa: %.2f\n", sv->chemistry);
	printf("Diem trung binh (GPA): %.2f\n", sv->gpa);
	printf("Hoc luc cua Sinh vien: %s\n", sv->result);
	printf("----------------------------------\n");
}
void showStudent(struct SinhVien temp[], int n)
{
	int i = 0;
	printf("\n---------------------------------\n");
	for(i = 0; i < n; i++)
	{
		show(&temp[i]);
	}
}
void calAverageScore(struct SinhVien *sv)
{
	sv->gpa = (sv->math+sv->physics+sv->chemistry)/3.0;
}
void Classification(struct SinhVien *sv)
{
	if(sv->gpa >= 8.0)
	{
		strcpy(sv->result, "Gioi");
	}
	else if(sv->gpa >= 6.5 && sv->gpa < 8.0)
	{
		strcpy(sv->result, "Kha");
	}
	else if(sv->gpa >= 5.0 && sv->gpa < 6.5)
	{
		strcpy(sv->result, "Trung binh");
	}
	else
	{
		strcpy(sv->result, "Yeu");
	}
}
/*
void splitName(struct SinhVien temp[], char name[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		int j = 0;
		for(j = strlen(temp[i].name)-1; j >= 0; j--)
		{
			if(temp[i].name == ' ')
			{
				strcpy(name, temp[i].name);
				break;
			}
		}
	}
	
}
*/
void sortName(struct SinhVien a[], int n)     //Sap xep sinh vien theo ten theo thu tu tang dan
{
	struct SinhVien temp;
	int i = 0;
	char nameSV1[30];
    char nameSV2[30];
    for(i = 0; i < n; i++) 
	{
		int j = 0;
		//splitName(temp[i], nameSV1, n);
		strcpy(nameSV1, a[i].name);
		for(j = i+1; j < n; j++)
		{
			//splitName(temp[j], nameSV2, n);
			strcpy(nameSV2, a[j].name);
			if(strcmp(strupr(nameSV1), strupr(nameSV2)) > 0)
			{
				temp = a[i];
        		a[i] = a[j];
        		a[j] = temp;
			}
		}
    }
}
void sortScore(struct SinhVien temp[], int n) //Sort score using BoubleSort
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		int j = 0;
		for(j = i + 1; j < n; j++)
		{
			if(temp[i].gpa > temp[j].gpa)
			{
				struct SinhVien tmp;
				tmp = temp[i];
				temp[i] = temp[j];
				temp[j] = tmp;
			}
		}
	}
}
void deleteById(struct SinhVien temp[], int *n, int id)
{
	int i = 0;
	int found = 0;
	for(i = 0; i < *n; i++)
	{
		if(temp[i].id == id && found == 0)
		{
			int j = 0;
			found = 1;
			for(j = i; j < *n; j++)
			{
				temp[j] = temp[j+1];
			}
			*n -= 1;	
		}
	}
	if(found == 1)
	{
		printf("Da xoa Sinh vien co id: %d\n", id);
		return;
	}
	else
	{
		printf("Khong ton tai sinh vien co ID: %d\n", id);
		return;		
	}
}
void searchByName(struct SinhVien temp[], int n, char nameSearch[])
{
	struct SinhVien arr[100];
	char nameOfStudent[30];
	int found = 0;
	int i = 0;
	for(i = 0; i<n ; i++)
	{
		strcpy(nameOfStudent, temp[i].name);
		if(strstr(strupr(nameOfStudent), strupr(nameSearch)))
		{
			arr[found] = temp[i];
			found++;
		}
	}
	if(found != 0)
	{
		showStudent(arr, found);
	}
	else
	{
		printf("Khong tim thay sinh vien!\n");
	}
}

