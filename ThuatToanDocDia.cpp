
#include <iostream>
#include<cmath>
#include<Windows.h>
using namespace std;
#define MAX 9

//void NhapMang();
void XuatMang(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ">[" << arr[i] << "]<";
	}
}
void XuatCacKhoi(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Sleep(300);
		cout << arr[i] << "  =>  ";
	}
}

void Tangdan(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

int TimVitri(int arr[], int n, int data)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == data)
			return  i;
}

void FCFS(int queue[], int& n, int data)
{
	++n;
	queue[n] = data;
}

void SSTF(int sstf[], int arr[], int& n, int data)
{
	int temp[MAX];
	for (int i = 0; i < MAX; i++)
		temp[i] = abs(data - arr[i]);

	Tangdan(temp, MAX);
	for (int i = 0; i < MAX; i++)
	{
		sstf[n] = data + temp[i];
		n++;
	}
	int test;
	for (int i = 0; i < n; i++)
	{
		test = data - temp[i];
		for (int j = 0; j < MAX; j++)
			if (test == arr[j])
				sstf[i] = test;
	}
}



void SCAN(int scan[], int arr[], int& n, int data)
{
	int vitri = TimVitri(arr, MAX, data);
	int temp = vitri;
	while (true)
	{
		n++;
		scan[n] = arr[--temp];
		if (arr[0] == scan[n])
		{
			scan[++n] = arr[0];
			break;
		}
	}

	//cout << vitri<<" "<<n;
	for (int j = n; j < MAX; j++)
	{
		scan[n] = arr[j];
		n++;
	}
}


void C_SCAN(int cscan[], int arr[], int& n, int data)
{
	int vitri = TimVitri(arr, MAX, data);
	for (int i = vitri + 1; i <= MAX; i++)
	{
		n++;
		cscan[n] = arr[i];
	}

	for (int j = 0; j < vitri; j++)
	{
		cscan[n] = arr[j];
		++n;
	}
}

int main()
{
	int a[9] = { 14,37,53,65,67,98,122,124,183 };
	int request[8] = { 98,183,37,122,14,124,65,67 };
	int begin = 53;
	int n = 0;
	int result[9];


	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t=====================MENU=======================" << endl;
		cout << "\n\t\t1. Thuat toan FCFS";
		cout << "\n\t\t2. Thuat toan SSTF";
		cout << "\n\t\t3. Thuat toan SCAN";
		cout << "\n\t\t4. Thuat toan C-SCAN";
		cout << "\n\t\t0.ket thuc";
		cout << "\n\n\t\t=====================END=======================";
		cout << "\n\n\t cac khoi:";
		XuatMang(request, 8);
		cout << "\nNhap thuat toan: ";


		cin >> choose;
		if (choose == 1)
		{
			n = 0;
			result[n] = begin;
			cout << "Cac Khoi lap lich cho truoc: ";
			XuatCacKhoi(request, sizeof(request) / sizeof(int));
			Sleep(200);
			cout << "\nChon Khoi Doc Bat Dau: ";
			cout << begin;
			cout << "\n1. Thuat toan FCFS se ra cac khoi sau: " << endl;
			cout << "\t\t";
			for (int i = 0; i < sizeof(a) / sizeof(int); i++)
				FCFS(result, n, request[i]);
			XuatCacKhoi(result, n);
			Sleep(150);
			cout << "\n\n\t\t================== DOC XONG ! =================" << endl;
			system("pause");
		}
		if (choose == 2)
		{
			n = 0;
			result[n] = begin;
			Sleep(250);
			cout << "\nChon Khoi Doc Bat Dau: " << begin;
			cout << "\n2. Thuat toan SSTF se ra cac khoi sau: " << endl;
			cout << "\t\t";
			SSTF(result, a, n, begin);
			XuatCacKhoi(result, n);
			Sleep(150);
			cout << "\n\n\t\t================== DOC XONG ! =================" << endl;
			system("pause");
		}
		if (choose == 3)
		{
			n = 0;
			result[n] = begin;
			Sleep(250);
			cout << "\nChon Khoi Doc Bat Dau: " << begin;
			cout << "\n3. Thuat toan SCAN se ra cac khoi sau: " << endl;
			cout << "\t\t";
			SCAN(result, a, n, begin);
			XuatCacKhoi(result, n);
			Sleep(150);
			cout << "\n\n\t\t================== DOC XONG ! ==================" << endl;
			system("pause");
		}
		if (choose == 4)
		{
			n = 0;
			result[n] = begin;
			Sleep(250);
			cout << "\nChon Khoi Doc Bat Dau: " << begin;
			cout << "\n4. Thuat toan C-SCAN se ra cac khoi sau: " << endl;
			cout << "\t\t";
			C_SCAN(result, a, n, begin);
			XuatCacKhoi(result, n);
			Sleep(150);
			cout << "\n\n\t\t================== DOC XONG ! ==================" << endl;
			system("pause");
		}
		if (choose == 0) break;
	}
	return 0;
}



