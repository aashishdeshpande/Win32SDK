#include<Windows.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <stdio.h>
#include "TestForDialogAndCombo.h"
#include "TestForDialogName.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProcName(HWND, UINT, WPARAM, LPARAM);


BOOL Text_Out = FALSE;

HWND ghwnd;
TCHAR FinaPriceTextOut[20];
TCHAR CpuName[4][20] = { TEXT("----SELECT----"),TEXT("INTEL"),TEXT("AMD"),TEXT("XYZ") };
TCHAR GpuName[4][20] = { TEXT("----SELECT----"),TEXT("NVIDIA"),TEXT("AMD"),TEXT("XYZ") };
TCHAR KeyBoard[4][20] = { TEXT("----SELECT----"),TEXT("LOGITECH"),TEXT("INTEX"),TEXT("XYZ") };
TCHAR KeyBoardPrice[4][20] = { TEXT("2000"),TEXT("1500") };
TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
TCHAR CpuTypeAmd[4][20] = { TEXT("----SELECT----"),TEXT("BOBCAT"),TEXT("BULLDOZER"),TEXT("JAGUAR") };
TCHAR GpuTypeNvidia[4][20] = { TEXT("----SELECT----"),TEXT("Geforce 820M"),TEXT("GTX 960M"),TEXT("GTX 1050Ti") };
TCHAR GpuTypeAmd[4][20] = { TEXT("----SELECT----"),TEXT("RX 470"),TEXT("RX 560"),TEXT("RX 570") };
TCHAR Motherboard[3][30] = { TEXT("----SELECT----"),TEXT("Asus"),TEXT("Gigabyte") };
TCHAR AsusTypes[3][20] = { TEXT("----SELECT----"),TEXT("Asus Intel B85M-G"),TEXT("Asus Intel H61M-CS")};
TCHAR AsusPrice[2][20] = { TEXT("5789"),TEXT("9870") };
TCHAR GigabytePrice[2][20] = { TEXT("5609"),TEXT("8970") };
TCHAR GigabyteTypes[3][20] = {TEXT("----SELECT----"),TEXT("GA-B250M"),TEXT("GA-H81M") };
TCHAR Ram[4][30] = { TEXT("----SELECT----"),TEXT("Corsair"),TEXT("G.Skill"),TEXT("Muskin") };
TCHAR RamSize[3][20] = { TEXT("4GB"),TEXT("8GB"),TEXT("16GB") };
TCHAR RamPrice[3][20] = { TEXT("3000"),TEXT("4000"),TEXT("8000") };

TCHAR CpuVersionIntel[4][20] = { TEXT("----SELECT----"),TEXT("Haswell"),TEXT("Broadwell"),TEXT("Skylake") };
TCHAR CpuVersionAmdBulldozerArch[4][20] = { TEXT("----SELECT----"),TEXT("Interlagos"),TEXT("Zambezi"),TEXT("Vishera") };
TCHAR CpuVersionAmdBoabcatArch[3][20] = { TEXT("----SELECT----"),TEXT("Ontario"),TEXT("Zacate") };
TCHAR CpuVersionAmdJaguarArch[3][20] = { TEXT("----SELECT----"),TEXT("Kabini"),TEXT("Temash") };
TCHAR CpuPricei3[3][20] = { TEXT("200"),TEXT("300"),TEXT("400") };
TCHAR CpuPricei5[3][20] = { TEXT("500"),TEXT("600"),TEXT("700") };
TCHAR CpuPricei7[3][20] = { TEXT("800"),TEXT("900"),TEXT("1000") };
TCHAR CpuPriceBuldozer[2][20] = { TEXT("950"), TEXT("850") };
TCHAR CpuPriceBobcat[2][20] = { TEXT("925"), TEXT("825") };
TCHAR CpuPriceJaguar[2][20] = { TEXT("880"), TEXT("775") };

TCHAR GpuPriceNvidia[3][20] = { TEXT("200"),TEXT("300"),TEXT("400") };
TCHAR GpuPriceAmd[3][20] = { TEXT("250"),TEXT("350"),TEXT("450") };
TCHAR HardDisk[3][20] = { TEXT("----SELECT----"), TEXT("Western Digital"), TEXT("Segate") };
TCHAR HardDiskTypesWD[2][20] = { TEXT("500GB"),TEXT("1TB") };
TCHAR HardDiskTypesSegate[2][20] = { TEXT("2TB"),TEXT("4TB") };
TCHAR HardDiskPrice[4][20] = { TEXT("2500"),TEXT("3500"),TEXT("5500"),TEXT("8000") };
TCHAR Mouse[3][20] = {TEXT("----SELECT----"),TEXT("Logitech"), TEXT("Dell") };
TCHAR MouseType[2][20] = { TEXT("Wired"),TEXT("Wireless") };
TCHAR MousePriceLogitech[2][20] = { TEXT("600"), TEXT("950")};
TCHAR MousePriceDell[2][20] = { TEXT("900"), TEXT("1500") };
TCHAR SMPS[3][20] = {TEXT("----SELECT----"),TEXT("Corsair"), TEXT("Antec") };
TCHAR SMPSCorsairTypes[2][20] = { TEXT("Corsair RM650"), TEXT("Corsair RM750") };
TCHAR SMPSAntecTypes[2][20] = { TEXT("Antec HCG-900"), TEXT("Antec VP450P") };
TCHAR SMPSCorsairPrice[2][20] = { TEXT("7600"), TEXT("8700") };
TCHAR SMPSAntecPrice[2][20] = { TEXT("7800"), TEXT("9000") };
//TCHAR GpuPriceAmd[3][20] = {TEXT("2")}

TCHAR Speaker[4][20] = {TEXT("----SELECT----"),TEXT("Jbl"), TEXT("Sony"), TEXT("Panasonic") };
TCHAR Speakerjbl[3][20] = { TEXT("Arena 120"), TEXT("Arena 170"), TEXT("Arena 180") };
TCHAR SpeakerSony[3][20] = { TEXT("Sony XB20"), TEXT("Sony XB10"), TEXT("Sony CT290") };
TCHAR SpeakerPanasonic[3][20] = { TEXT("SC-HT31"), TEXT("SC-HTB485"), TEXT("SC-BTT785") };
TCHAR SpeakerjblPrice[3][20] = { TEXT("5000"), TEXT("5500"), TEXT("6000") };
TCHAR SpeakerSonyPrice[3][20] = { TEXT("5300"), TEXT("5700"), TEXT("6200") };
TCHAR SpeakerPanasonicPrice[3][20] = { TEXT("4900"), TEXT("4950"), TEXT("6250") };


TCHAR Pendrive[3][20] = { TEXT("----SELECT----"),TEXT("SandDisk"), TEXT("HP") };
TCHAR PendriveSize[2][20] = { TEXT("16gb"), TEXT("32gb") };
TCHAR PendriveSandDiskPrice[2][20] = { TEXT("1350"), TEXT("1500") };
TCHAR PendriveHPPrice[2][20] = { TEXT("1250"), TEXT("1400") };

TCHAR Cabinet[3][20] = { TEXT("----SELECT----"),TEXT("Zebronics"), TEXT("Circle Desire") };
TCHAR CabinetPrice[2][20] = { TEXT("6500"), TEXT("8000") };

TCHAR Fan[3][20] = { TEXT("----SELECT----"),TEXT("Corsair"), TEXT("Cooler Master") };
TCHAR FanPrice[2][20] = { TEXT("7500"), TEXT("8000") };

struct GetPrice
{
	TCHAR Processor[100]; //cpu
	TCHAR CpuPrice[20];

	TCHAR WellVersion[100]; //cpu broadwell skylake haswell
	TCHAR CoreGeneration[100];//for i3 i5 i7
	//TCHAR ProcessorType[100];
	//TCHAR ProcessorVersion[100];
	TCHAR GraphicsCard[100];
	TCHAR GraphicsCardType[100];
	TCHAR GpuPrice[20];
	
	TCHAR Ram[100];
	TCHAR RamSize[100];
	TCHAR RamPrice[20];

	TCHAR Motherboard[100];
	TCHAR MotherboardType[100];
	TCHAR MotherboardPrice[20];

	TCHAR Keyboard[100];
//	TCHAR KeyboardType[100];
	TCHAR KeyboardPrice[20];

	TCHAR HardDisk[100];
	TCHAR HardDiskSize[100];
	TCHAR HardDiskPrice[20];

	TCHAR MouseType[100];
	TCHAR Mouse[100];//for mouse logitech or dell
	TCHAR MousePrice[20];

	TCHAR Smps[100];
	TCHAR SmpsType[100];
	TCHAR SmpsPrice[20];

	TCHAR Speaker[100];
	TCHAR SpeakerType[100];
	TCHAR SpeakerPrice[100];

	TCHAR Penddrive[100];
	TCHAR PendriveSize[100];
	TCHAR PendrivePrice[100];

	TCHAR Cabinet[100];
	TCHAR CabinetType[100];
	TCHAR CabinetPrice[100];

	TCHAR Fan[100];
	TCHAR FanPrice[100];
};

//ZeroMemory(&myGetPrice, sizeof(myGetPrice));
errno_t err;
FILE *fp = NULL;
TCHAR Vadidation[255];
TCHAR CustomerName[500];

//MyInput in;
int xPos, yPos;
struct  GetPrice * myGetPrice;
int gemptyCheckFlag = 0;
TCHAR gstrForEmptyString[20];
int getCpuPrice = 0, getGpuPrice = 0, getRamPrice = 0, getMotherboardPrice = 0, getKeyboardPrice = 0,getHardDsikPrice = 0,getsmpsPrice,getMousePrice = 0, getSpeakerPrice = 0, getPenddrivePrice = 0, getCabinetPrice = 0, getFanPrice = 0;
int getFinalPrice = 0;

int gSmpsPrice = 0;
int gSmpsType = 0;
int gSmps = 0;
int gMousePrice = 0;
int gMouse = 0;
int gMouseType = 0;
int gHardDiskPrice = 0;
int gHardDiskSize = 0;
int gHardDisk = 0;
int gKeyboard = 0;
int gKeyboardPrice = 0;
int gMotherboard = 0;
int gMotherboardType = 0;
int gMotherboardPrice = 0;
int gRam = 0;
int gRamSize = 0;
int gRamPrice = 0;
int gGraphicsCard = 0;
int gGraphicsCardType = 0;
int gGpuPrice = 0;
int gCoreGeneration = 0;
int gWellVersion = 0;
int gCpuPrice = 0;
int gProcessor = 0;
int gSpeaker = 0;
int gSpeakerType = 0;
int gSpeakerPrice = 0;
int gPendrive = 0;
int gPendriveSize = 0;
int gPendrivePrice = 0;
int gCabinet = 0;
//int gCabinetType = 0;
int gCabinetPrice = 0;
int gFan = 0;
int gFanType = 0;
int gFanPrice = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	MSG msg;
	HWND hwnd;
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("MyApp");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	RegisterClassEx(&wndclass);

	xPos = GetSystemMetrics(SM_CXSCREEN);
	yPos = GetSystemMetrics(SM_CYSCREEN);

	hwnd = CreateWindow(szAppName,
		TEXT("MyDialogBox"),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		xPos,
		yPos,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;
	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = NULL;
	HINSTANCE hInstName = NULL;
	HBITMAP hImage = NULL;
	HDC hdc=NULL;
	RECT rc;
	long lfHeight;
	HFONT hf;
	TCHAR class_name[20];
	TCHAR batch_name[20];
	TCHAR my_name[500];
	TCHAR system_time[20];
	TCHAR system_date[20];
	TCHAR CategoryName[50];
	TCHAR CompanyName[50];
	TCHAR Product[50];
	TCHAR OtherInformation[50];
	TCHAR Price[60];
	SYSTEMTIME st;
	/////////////////////
	BITMAP bm;
	PAINTSTRUCT ps;
	HDC hdcMem;
	static COLORREF blackbackground = RGB(0, 0, 0);
	HBITMAP hbmOld;
	TCHAR Category[12][50] = {TEXT("Processor"),TEXT("Ram"),TEXT("Motherboard"),TEXT("Graphic Card"),TEXT("HardDisk"),TEXT("SMPS"),TEXT("Keyboard"),TEXT("Mouse"), TEXT("Speaker"), TEXT("Penddrive"), TEXT("Cabinet"), TEXT("Fan") };
	///////////////////////////////////
	switch (iMsg)
	{

	case WM_CREATE:
		
		hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
		hInstName = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
		myGetPrice=(struct GetPrice *)malloc(sizeof(struct GetPrice));
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_SPACE:
			DialogBox(hInst, TEXT("COMPUTER_SHOP"), hwnd, MyDlgProc);
			break;

		case 'p':
		case 'P':
			DialogBox(hInst, TEXT("CustomerName"), hwnd, MyDlgProcName);
			lstrcat(CustomerName, TEXT(".txt"));
			GetLocalTime(&st);
			GetDateFormat(LOCALE_CUSTOM_DEFAULT, NULL, &st, TEXT("ddd','MMM dd yy"), system_date, lstrlen(system_date));
			wsprintf(system_time, TEXT("%i:%i:%i"), st.wHour, st.wMinute, st.wSecond);
			_wfopen_s(&fp, CustomerName, TEXT("w"));
			if (fp == NULL)
			{
				MessageBox(NULL, TEXT("file cannot be opened"), TEXT("file error"), MB_OK);
				exit(0);
			}
			else
			{
				fwprintf_s(fp, TEXT("\n\n\n\t---------------------------------------------------------Receipt-----------------------------------------------------------"));
				fwprintf_s(fp,TEXT("\n\n\tTime:"));
				fwprintf_s(fp, system_time);
				fwprintf_s(fp, TEXT("\t\t\t\t\t\t\t\t\tDate:"));
				fwprintf_s(fp, system_date);
				fwprintf_s(fp, TEXT("\n\n\t01]processor :"));
				if (gProcessor == 1)
				{
					fwprintf_s(fp, myGetPrice->Processor);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tCoreGeneartion :"));
				if (gCoreGeneration == 1)
				{
					fwprintf_s(fp, myGetPrice->CoreGeneration);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tVersion :"));
				if (gWellVersion == 1)
				{
					fwprintf_s(fp, myGetPrice->WellVersion);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
			
				fwprintf_s(fp, TEXT("\t\tCost :"));

				if (gCpuPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->CpuPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				
				fwprintf_s(fp, TEXT("\n\n\t02]Graphics card :"));
				if (gGraphicsCard == 1)
				{
					fwprintf_s(fp, myGetPrice->GraphicsCard);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\tSubtype :"));
				if (gGraphicsCardType == 1)
				{
					fwprintf_s(fp, myGetPrice->GraphicsCardType);
				}

				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));

				if (gGpuPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->GpuPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t03]Ram :"));
				if (gRam == 1)
				{
					fwprintf_s(fp, myGetPrice->Ram);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\tSize :"));
				if (gRamSize == 1)
				{
					fwprintf_s(fp, myGetPrice->RamSize);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\t\tCost :"));
				if (gRamPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->RamPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t04]MotherBoard :"));
				if (gMotherboard == 1)
				{
					fwprintf_s(fp, myGetPrice->Motherboard);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tCompany :"));
				if (gMotherboardType == 1)
				{
					fwprintf_s(fp, myGetPrice->MotherboardType);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\tCost :"));
				if (gMotherboardPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->MotherboardPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t05]Keyboard :"));
				if (gKeyboard == 1)
				{
					fwprintf_s(fp, myGetPrice->Keyboard);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\t\t\t\t\tCost :"));
				if (gKeyboardPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->KeyboardPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t06]HardDisk :"));
				if (gHardDisk == 1)
				{
					fwprintf_s(fp, myGetPrice->HardDisk);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\tHardDisk Size :"));
				if (gHardDiskSize == 1)
				{
					fwprintf_s(fp, myGetPrice->HardDiskSize);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gHardDiskPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->HardDiskPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t07]Mouse :"));
				if (gMouse == 1)
				{
					fwprintf_s(fp, myGetPrice->Mouse);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tType :"));
				if (gMouseType == 1)
				{
					fwprintf_s(fp, myGetPrice->MouseType);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\t\tCost :"));
				if (gMousePrice == 1)
				{
					fwprintf_s(fp, myGetPrice->MousePrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\n\n\t08]Smps :"));
				if (gSmps == 1)
				{
					fwprintf_s(fp, myGetPrice->Smps);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tCompany :"));
				if (gSmpsType == 1)
				{
					fwprintf_s(fp, myGetPrice->SmpsType);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gSmpsPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->SmpsPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\n\n\t09]Speaker :"));
				if (gSpeaker == 1)
				{
					fwprintf_s(fp, myGetPrice->Speaker);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tCompany :"));
				if (gSpeakerType == 1)
				{
					fwprintf_s(fp, myGetPrice->SpeakerType);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gSpeakerPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->SpeakerPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\n\n\t10]Pendrive :"));
				if (gPendrive == 1)
				{
					fwprintf_s(fp, myGetPrice->Penddrive);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\tSize :"));
				if (gPendriveSize == 1)
				{
					fwprintf_s(fp, myGetPrice->PendriveSize);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gPendrivePrice == 1)
				{
					fwprintf_s(fp, myGetPrice->PendrivePrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\n\n\t11]Cabinet :"));
				if (gCabinet == 1)
				{
					fwprintf_s(fp, myGetPrice->Cabinet);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
				
				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gCabinetPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->CabinetPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\n\n\t12]Fan :"));
				if (gFan == 1)
				{
					fwprintf_s(fp, myGetPrice->Fan);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}

				fwprintf_s(fp, TEXT("\t\t\t\t\t\tCost :"));
				if (gFanPrice == 1)
				{
					fwprintf_s(fp, myGetPrice->FanPrice);
				}
				else
				{
					fwprintf_s(fp, TEXT("---"));
				}
	
			}
			
			DestroyWindow(hwnd);
			break;
		default:
			break;
		}
		break;

	case WM_PAINT:
		if (Text_Out == FALSE)
		{

		hImage = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_ImageWallpaper));
		if (hImage == NULL)
		{
			MessageBox(NULL, TEXT("Could not Load ID_Image"), TEXT("Error"), MB_OK);
		}

		hdc = BeginPaint(hwnd, &ps);
	//	SetBkColor(hdc, blackbackground);
		lfHeight = -MulDiv(48, GetDeviceCaps(hdc, LOGPIXELSY), 144);
		hf = CreateFont(lfHeight, 0, 0, 0, FW_EXTRABOLD, TRUE, TRUE, 0, 0, 0, 0, 0, 0, TEXT("Times New Roman"));

		SetBkMode(hdc, TRANSPARENT);
		SetBkColor(hdc, RGB(0, 0, 0)); 
		SetTextColor(hdc, RGB(255, 255, 255));
		HFONT hfOld = (HFONT)SelectObject(hdc, hf);
		hdcMem = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcMem, hImage);
		GetObject(hImage, sizeof(bm), &bm);
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		GetClientRect(hwnd, &rc);
		DrawText(hdc, TEXT("PRESS SPACEBAR TO CONTINUE"), -1, &rc, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
		DrawText(hdc, TEXT("MY COMPUTER SHOP"), -1, &rc, DT_SINGLELINE | DT_CENTER| DT_RIGHT);
		wsprintf(class_name, TEXT("ASTROMEDICOMP"));
		lfHeight = -MulDiv(48, GetDeviceCaps(hdc, LOGPIXELSY), 144);
		hf = CreateFont(lfHeight, 0, 0, 0, FW_EXTRABOLD, TRUE, 0, 0, 0, 0, 0, 0, 0, TEXT("Times New Roman"));
		HFONT hfOld_className = (HFONT)SelectObject(hdc, hf);
		TextOut(hdc, 200, 200, class_name,lstrlen(class_name));
		wsprintf(batch_name, TEXT("WinRT 2017"));
		TextOut(hdc, 1000, 200, batch_name, lstrlen(batch_name));
		wsprintf(my_name, TEXT("Aashish Deshpande"));
		TextOut(hdc, 1000, 300, my_name, lstrlen(my_name));
		SelectObject(hdcMem, hbmOld);
		SelectObject(hdc, hfOld);
		SelectObject(hdc, hfOld_className);
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		}
		else
		{
			hdc = GetDC(hwnd);
		
			MoveToEx(hdc, 50 , 30, NULL);
			LineTo(hdc, 1300, 30);

			MoveToEx(hdc, 50, 30, NULL);
			LineTo(hdc, 50, 600);

			MoveToEx(hdc, 50, 600, NULL);
			LineTo(hdc, 1300, 600);

			MoveToEx(hdc, 1300, 600, NULL);
			LineTo(hdc, 1300, 30);

			MoveToEx(hdc, 250, 30, NULL);
			LineTo(hdc, 250, 600);

			MoveToEx(hdc, 500, 30, NULL);
			LineTo(hdc, 500, 600);

			MoveToEx(hdc, 750, 30, NULL);
			LineTo(hdc, 750, 600);

			MoveToEx(hdc, 1000, 30, NULL);
			LineTo(hdc, 1000, 600);

			MoveToEx(hdc, 50, 75, NULL);
			LineTo(hdc, 1300, 75);

			MoveToEx(hdc, 50, 115, NULL);
			LineTo(hdc, 1300, 115);

			MoveToEx(hdc, 50, 155, NULL);
			LineTo(hdc, 1300, 155);

			MoveToEx(hdc, 50, 195, NULL);
			LineTo(hdc, 1300, 195);

			MoveToEx(hdc, 50, 235, NULL);
			LineTo(hdc, 1300, 235);

			MoveToEx(hdc, 50, 275, NULL);
			LineTo(hdc, 1300, 275);

			MoveToEx(hdc, 50, 315, NULL);
			LineTo(hdc, 1300, 315);

			MoveToEx(hdc, 50, 355, NULL);
			LineTo(hdc, 1300, 355);

			MoveToEx(hdc, 50, 395, NULL);
			LineTo(hdc, 1300, 395);

			MoveToEx(hdc, 50, 435, NULL);
			LineTo(hdc, 1300, 435);

			MoveToEx(hdc, 50, 475, NULL);
			LineTo(hdc, 1300, 475);

			MoveToEx(hdc, 50, 515, NULL);
			LineTo(hdc, 1300, 515);


			SetTextColor(hdc, RGB(255, 0, 0));

			for (int i = 0, y = 50; i < 12; i++, y += 40)
			{
				TextOut(hdc,70,y,Category[i],lstrlen(Category[i]));
			}
			
			wsprintf(CategoryName, TEXT("CATEGORY"));
			TextOut(hdc, 60, 10, CategoryName, lstrlen(CategoryName));

			wsprintf(CompanyName, TEXT("COMPANY"));
			TextOut(hdc, 340, 10, CompanyName, lstrlen(CompanyName));

			wsprintf(Product, TEXT("PRODUCT"));
			TextOut(hdc, 590, 10, Product, lstrlen(Product));

			wsprintf(OtherInformation, TEXT("OTHER INFORMATION"));
			TextOut(hdc, 815, 10, OtherInformation, lstrlen(OtherInformation));

			wsprintf(Price, TEXT("PRICE"));
			TextOut(hdc, 1095, 10, Price, lstrlen(Price));

			//TextOut(hdc,100, 640, system_date, lstrlen(system_date));

			//TextOut(hdc, 1000, 640, system_time, lstrlen(system_time));


			if(gProcessor == 1)
				TextOut(hdc, 350, 50,myGetPrice->Processor , lstrlen(myGetPrice->Processor));
			else
				TextOut(hdc, 350, 50, TEXT("---"), 3);
			
			if(gCpuPrice == 1)
				TextOut(hdc, 1100, 50, myGetPrice->CpuPrice, lstrlen(myGetPrice->CpuPrice));
			else
				TextOut(hdc, 1100, 50, TEXT("---"), 3);

			if(gCoreGeneration == 1)
				TextOut(hdc, 600, 50, myGetPrice->CoreGeneration, lstrlen(myGetPrice->CoreGeneration));
			else
				TextOut(hdc, 600, 50, TEXT("---"), 3);

			if(gWellVersion == 1)
				TextOut(hdc, 830, 50, myGetPrice->WellVersion, lstrlen(myGetPrice->WellVersion));
			else
				TextOut(hdc, 830, 50, TEXT("---"), 3);
			
			if(gRam == 1)
				TextOut(hdc, 350, 90, myGetPrice->Ram, lstrlen(myGetPrice->Ram));
			else
				TextOut(hdc, 350, 90, TEXT("---"), 3);

			if(gRamSize == 1)
				TextOut(hdc, 830, 90, myGetPrice->RamSize, lstrlen(myGetPrice->RamSize));
			else
				TextOut(hdc, 830, 90, TEXT("---"), 3);

			if(gRamPrice == 1)
				TextOut(hdc, 1100, 90, myGetPrice->RamPrice, lstrlen(myGetPrice->RamPrice));
			else
				TextOut(hdc, 1100, 90, TEXT("---"), 3);

			if(gMotherboard == 1)
				TextOut(hdc, 350, 130, myGetPrice->Motherboard, lstrlen(myGetPrice->Motherboard));
			else
				TextOut(hdc, 350, 130, TEXT("---"), 3);

			if(gMotherboardType == 1)
				TextOut(hdc, 600, 130, myGetPrice->MotherboardType, lstrlen(myGetPrice->MotherboardType));
			else
				TextOut(hdc, 600, 130, TEXT("---"), 3);

			if(gMotherboardPrice == 1)
				TextOut(hdc, 1100, 130, myGetPrice->MotherboardPrice, lstrlen(myGetPrice->MotherboardPrice));
			else
				TextOut(hdc, 1100, 130, TEXT("---"), 3);

			if(gGraphicsCard == 1)
				TextOut(hdc, 350, 170, myGetPrice->GraphicsCard, lstrlen(myGetPrice->GraphicsCard));
			else
				TextOut(hdc, 350, 170, TEXT("---"), 3);

			if(gGraphicsCardType == 1)
				TextOut(hdc, 600, 170, myGetPrice->GraphicsCardType, lstrlen(myGetPrice->GraphicsCardType));
			else
				TextOut(hdc, 600, 170, TEXT("---"), 3);

			if (gGpuPrice == 1)
				TextOut(hdc, 1100, 170, myGetPrice->GpuPrice, lstrlen(myGetPrice->GpuPrice));
			else
				TextOut(hdc, 1100, 170, TEXT("---"), 3);

			if(gHardDisk == 1)
				TextOut(hdc, 350, 210, myGetPrice->HardDisk, lstrlen(myGetPrice->HardDisk));
			else
				TextOut(hdc, 350, 210, TEXT("---"), 3);

			if(gHardDiskSize == 1)
				TextOut(hdc, 830, 210, myGetPrice->HardDiskSize, lstrlen(myGetPrice->HardDiskSize));
			else
				TextOut(hdc, 830, 210, TEXT("---"), 3);

			if(gHardDiskPrice == 1)
				TextOut(hdc, 1100, 210, myGetPrice->HardDiskPrice, lstrlen(myGetPrice->HardDiskPrice));
			///
			else
				TextOut(hdc, 1100, 210, TEXT("---"), 3);

			if(gSmps == 1)
				TextOut(hdc, 350, 250, myGetPrice->Smps, lstrlen(myGetPrice->Smps));
			else
				TextOut(hdc, 350, 250, TEXT("---"), 3);

			if(gSmpsType == 1)
				TextOut(hdc, 600, 250, myGetPrice->SmpsType, lstrlen(myGetPrice->SmpsType));
			else
				TextOut(hdc, 600, 250, TEXT("---"), 3);

			if(gSmpsPrice == 1)
				TextOut(hdc, 1100, 250, myGetPrice->SmpsPrice, lstrlen(myGetPrice->SmpsPrice));
			else
				TextOut(hdc, 1100, 250, TEXT("---"), 3);

			if(gKeyboard == 1)
				TextOut(hdc, 350, 290, myGetPrice->Keyboard, lstrlen(myGetPrice->Keyboard));
			else
				TextOut(hdc, 350, 290, TEXT("---"), 3);
			
			//	TextOut(hdc, 830, 460, myGetPrice->KeyboardType, lstrlen(myGetPrice->KeyboardType));
			if(gKeyboardPrice == 1)
				TextOut(hdc, 1100, 290, myGetPrice->KeyboardPrice, lstrlen(myGetPrice->KeyboardPrice));
			else
				TextOut(hdc, 1100, 290, TEXT("---"), 3);

			if(gMouse == 1)
				TextOut(hdc, 350, 330, myGetPrice->Mouse, lstrlen(myGetPrice->Mouse));
			else
				TextOut(hdc, 350, 330, TEXT("---"), 3);
			
			if(gMouseType == 1)
				TextOut(hdc, 600, 330, myGetPrice->MouseType, lstrlen(myGetPrice->MouseType));
			else
				TextOut(hdc, 600, 330, TEXT("---"), 3);
			
			if(gMousePrice == 1)
				TextOut(hdc, 1100, 330, myGetPrice->MousePrice, lstrlen(myGetPrice->MousePrice));
			else
				TextOut(hdc, 1100, 330, TEXT("---"), 3);

			if (gSpeaker == 1)
				TextOut(hdc, 350, 370, myGetPrice->Speaker, lstrlen(myGetPrice->Speaker));
			else
				TextOut(hdc, 350, 370, TEXT("---"), 3);

			if (gSpeakerType == 1)
				TextOut(hdc, 600, 370, myGetPrice->SpeakerType, lstrlen(myGetPrice->SpeakerType));
			else
				TextOut(hdc, 600, 370, TEXT("---"), 3);

			if (gSpeakerPrice == 1)
				TextOut(hdc, 1100, 370, myGetPrice->SpeakerPrice, lstrlen(myGetPrice->SpeakerPrice));
			else
				TextOut(hdc, 1100, 370, TEXT("---"), 3);

			if (gPendrive == 1)
				TextOut(hdc, 350, 410, myGetPrice->Penddrive, lstrlen(myGetPrice->Penddrive));
			else
				TextOut(hdc, 350, 410, TEXT("---"), 3);


			if (gPendriveSize == 1)
				TextOut(hdc, 830, 410, myGetPrice->PendriveSize, lstrlen(myGetPrice->PendriveSize));
			else
				TextOut(hdc, 830, 410, TEXT("---"), 3);

			if (gPendrivePrice == 1)
				TextOut(hdc, 1100, 410, myGetPrice->PendrivePrice, lstrlen(myGetPrice->PendrivePrice));
			else
				TextOut(hdc, 1100, 410, TEXT("---"), 3);

			if (gCabinet == 1)
				TextOut(hdc, 350, 450, myGetPrice->Cabinet, lstrlen(myGetPrice->Cabinet));
			else
				TextOut(hdc, 350, 450, TEXT("---"), 3);

			/*if (gCabinetType == 1)
				TextOut(hdc, 600, 490, myGetPrice->CabinetType, lstrlen(myGetPrice->CabinetType));
			else
				TextOut(hdc, 600, 490, TEXT("---"), 3);*/

			if (gCabinetPrice == 1)
				TextOut(hdc, 1100, 450, myGetPrice->CabinetPrice, lstrlen(myGetPrice->CabinetPrice));
			else
				TextOut(hdc, 1100, 450, TEXT("---"), 3);

			if (gFan == 1)
				TextOut(hdc, 350, 490, myGetPrice->Fan, lstrlen(myGetPrice->Fan));
			else
				TextOut(hdc, 350, 490, TEXT("---"), 3);

			if (gFanPrice == 1)
				TextOut(hdc, 1100, 490, myGetPrice->FanPrice, lstrlen(myGetPrice->FanPrice));
			else
				TextOut(hdc, 1100, 490, TEXT("---"), 3);


			int FinalCpuPrice = _wtoi(myGetPrice->CpuPrice);
			int FinalGpuPrice = _wtoi(myGetPrice->GpuPrice);
			int FinalKeyboardPrice = _wtoi(myGetPrice->KeyboardPrice);
			int FinalMousePrice = _wtoi(myGetPrice->MousePrice);
			int FinalSmpsPrice = _wtoi(myGetPrice->SmpsPrice);
			int FinalHardDiskPrice = _wtoi(myGetPrice->HardDiskPrice);
			int FinalMotherboardPrice = _wtoi(myGetPrice->MotherboardPrice);
			int FinalRamPrice = _wtoi(myGetPrice->RamPrice);
			int FinalSpeakerPrice = _wtoi(myGetPrice->SpeakerPrice);
			int FinalFanPrice = _wtoi(myGetPrice->FanPrice);
			int FinalCabinetPrice = _wtoi(myGetPrice->CabinetPrice);
			int FinalPendrivePrice = _wtoi(myGetPrice->PendrivePrice);

			int FinalPrice = FinalCpuPrice + FinalGpuPrice + FinalHardDiskPrice + FinalKeyboardPrice + FinalMotherboardPrice + FinalMousePrice + FinalRamPrice + FinalSmpsPrice + FinalCabinetPrice + FinalFanPrice + FinalPendrivePrice + FinalSpeakerPrice;
			wsprintf(FinaPriceTextOut, TEXT("Total : %d"), FinalPrice);
			TextOut(hdc, 1050, 550,FinaPriceTextOut, lstrlen(FinaPriceTextOut));
			wsprintf(FinaPriceTextOut, TEXT("Press p for receipt"));
			TextOut(hdc, 500, 670, FinaPriceTextOut, lstrlen(FinaPriceTextOut));

			ReleaseDC(hwnd, hdc);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int flag=0;
	int index = 0;
	TCHAR A[100];
	TCHAR buffer[100];
	TCHAR B[100];
//	TCHAR str[256];
	int k = 0;
	HBITMAP hImage = NULL;
	HDC hdc;
	BITMAP bm;
	PAINTSTRUCT ps;
	HDC hdcMem=NULL;
	HBITMAP hbmOld;
	memset(&A, 0, sizeof(A));
	//	int k = 0;
	memset(&B, 0, sizeof(B));

	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	switch (iMsg)
	{

	case WM_PAINT:
		
		
		hImage = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_Image));
		if (hImage == NULL)
		{
			MessageBox(NULL, TEXT("Could not Load ID_Image"), TEXT("Error"), MB_OK);
		}

		
		hdc = BeginPaint(hDlg, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcMem, hImage);
		GetObject(hImage, sizeof(bm), &bm);
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		//StretchBlt(hdc, 0, 0, x, y, hdcMem, 0, 0 ,bm.bmHeight, bm.bmWidth, SRCCOPY);
		SelectObject(hdcMem, hbmOld);
		//DeleteDC(hdcMem);
		//GetClientRect(hwnd, &rc);
		//DrawText(hdc, TEXT("PRESS SPACEBAR TO CONTINUE"), -1, &rc, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
		//DrawText(hdc, TEXT("MY COMPUTER SHOP"), -1, &rc, DT_SINGLELINE | DT_TOP | DT_RIGHT);
		EndPaint(hDlg, &ps);

		break;

	case WM_INITDIALOG:
		ShowWindow(hDlg, SW_MAXIMIZE);
		//SetFocus(GetDlgItem(hDlg, ID_ETNAME));
		//SendDlgItemMessage(hDlg, ID_RBMARRIED, BM_SETCHECK, 1, 0);
		//SendDlgItemMessage(hDlg,ID_CBCPU,)
		ShowWindow(GetDlgItem(hDlg, ID_Combo2a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo2b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo3a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo3b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo4a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo4b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo5a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo6a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo7a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo7b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo8a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo8b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo9a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo9b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo10a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo10b), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo11a), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, ID_Combo12a), SW_HIDE);
		//ShowWindow(GetDlgItem(hDlg, ID_Combo1b), SW_HIDE);

		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)CpuName[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo1), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
		}

		SendMessage(GetDlgItem(hDlg, ID_Combo1), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);



		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)KeyBoard[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo5), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo5), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		//if (flag==1)
		//{
			//MessageBox(hDlg, TEXT("ho"), TEXT("h"), MB_OK);
			
		//}
		//if(flag==2)
		//{
			//MessageBox(hDlg, TEXT("ho"), TEXT("h"), MB_OK);
			
		//}



		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)GpuName[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo2), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)GpuTypeNvidia[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo2a), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);



		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)GpuTypeAmd[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo2b), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Motherboard[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo4), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo4), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 3; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Ram[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo3), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo3), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		/*for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)CpuTypeIntel[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo1aVer), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
		}

		SendMessage(GetDlgItem(hDlg, ID_Combo1aVer), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
*/      
		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)HardDisk[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo6), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo6), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Mouse[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo7), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo7), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)SMPS[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo8), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo8), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

			for (int k = 0; k <= 3; k++)
			{
				wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Speaker[k]);
				SendMessage(GetDlgItem(hDlg, ID_Combo9), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
			}
		SendMessage(GetDlgItem(hDlg, ID_Combo9), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Pendrive[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo10), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo10), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Cabinet[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo11), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo11), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		for (int k = 0; k <= 2; k++)
		{
			wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)Fan[k]);
			SendMessage(GetDlgItem(hDlg, ID_Combo12), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)B);
		}
		SendMessage(GetDlgItem(hDlg, ID_Combo12), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		return(TRUE);

		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{

			//case ID_PBCONTINUE:



			//EndDialog(hDlg, 0);
			//break;

			//	case IDOK:
			//GetDlgItemText(hDlg, ID_ETNAME, (LPWSTR)in.name, 50);
			//GetDlgItemText(hDlg, ID_ETADDRESS, (LPWSTR)in.address, 50);
			//GetDlgItemText(hDlg, ID_ETCPUNAME, (LPWSTR)in.CPU, 50);
			//	GetDlgItemInt(hDlg, ID_ETAGE,(BOOL)in.age, NULL,TRUE);
			//	GetDlgItemText(hDlg, ID_ETSALRS, salrs, 6);
			//	EndDialog(hDlg, 0);
			//break;
		case ID_OK:
			/*SelectObject(hdcMem, hbmOld);
			DeleteDC(hdcMem);*/
			
		/*	if (wcscmp(myGetPrice->Processor, TEXT("")) == 0)
			{
				gemptyCheckFlag = 1;
			}

			if (wcscmp(myGetPrice->WellVersion, TEXT("")) == 0)
			{
				gemptyCheckFlag = 2;
			}

			if (wcscmp(myGetPrice->CoreGeneration, TEXT("")) == 0)
			{
				gemptyCheckFlag = 3;
			}

			if (wcscmp(myGetPrice->GraphicsCard, TEXT("")) == 0)
			{
				gemptyCheckFlag = 4;
			}

			if (wcscmp(myGetPrice->GraphicsCardType, TEXT("")) == 0)
			{
				gemptyCheckFlag = 5;

			}

			if (wcscmp(myGetPrice->HardDisk, TEXT("")) == 0)
			{
				gemptyCheckFlag = 6;
			}

			if (wcscmp(myGetPrice->HardDiskSize, TEXT("")) == 0)
			{
				gemptyCheckFlag = 7;
			}

			if (wcscmp(myGetPrice->Keyboard, TEXT("")) == 0)
			{
				gemptyCheckFlag = 8;
			}

			if (wcscmp(myGetPrice->Motherboard, TEXT("")) == 0)
			{
				gemptyCheckFlag = 9;
			}


			if (wcscmp(myGetPrice->MotherboardType, TEXT("")) == 0)
			{
				gemptyCheckFlag = 10;
			}

			if (wcscmp(myGetPrice->Mouse, TEXT("")) == 0)
			{
				gemptyCheckFlag = 11;
			}

			if (wcscmp(myGetPrice->MouseType, TEXT("")) == 0)
			{
				gemptyCheckFlag = 12;
			}


			if (wcscmp(myGetPrice->Smps, TEXT("")) == 0)
			{
				gemptyCheckFlag = 13;
			}

			if (wcscmp(myGetPrice->SmpsType, TEXT("")) == 0)
			{
				gemptyCheckFlag = 14;
			}

			if (wcscmp(myGetPrice->Ram, TEXT("")) == 0)
			{
				gemptyCheckFlag = 15;
			}

			if (wcscmp(myGetPrice->RamSize, TEXT("")) == 0)
			{
				gemptyCheckFlag = 16;
			}
*/

			Text_Out = TRUE;
			InvalidateRect(ghwnd,NULL,TRUE);
			DeleteDC(hdcMem);
			EndDialog(hDlg, 0);

			break;
	


		case ID_CANCEL:
			EndDialog(hDlg, 0);
			break;


		}

		

		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			if ((HWND)lParam==GetDlgItem(hDlg,ID_Combo1))
			{
				//MessageBox(NULL, TEXT("In ID_Combo1"), TEXT("Message"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo1, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo1, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("INTEL")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					SetFocus(GetDlgItem(hDlg,ID_Combo1a));
					for (int i = 0; i <= 3; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo1a),CB_ADDSTRING,0, (LPARAM)(CpuTypeIntel+i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo1a),SW_SHOW);
				}
			}


			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo1))
			{
				//MessageBox(NULL, TEXT("In ID_Combo1"), TEXT("Message"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo1, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo1, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("AMD")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo1a));
					for (int i = 0; i <= 3; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_ADDSTRING, 0, (LPARAM)(CpuTypeAmd + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_SETCURSEL, 0, 0); //wparam ->index
					
					ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_SHOW);

				//	SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);

				}
			}
			
			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo1a))
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_GETLBTEXT, index, (LPARAM)buffer);
				SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_RESETCONTENT, 0, 0);
				if (lstrcmp(buffer, CpuTypeIntel[1]) == 0)
				{
					for (int i = 0; i <=3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionIntel + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}

				if (lstrcmp(buffer, CpuTypeIntel[2]) == 0)
				{
					for (int i = 0; i <= 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionIntel + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
																					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}


				if (lstrcmp(buffer, CpuTypeIntel[3]) == 0)
				{
					for (int i = 0; i <= 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionIntel + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
																					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}
				else if (lstrcmp(buffer, CpuTypeAmd[1]) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i <= 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionAmdBoabcatArch + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}

				else if (lstrcmp(buffer, CpuTypeAmd[2]) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i <= 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionAmdBulldozerArch + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}

				else if (lstrcmp(buffer, CpuTypeAmd[3]) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i <= 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_ADDSTRING, 0, (LPARAM)(CpuVersionAmdJaguarArch + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}
				ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
			}


		

			//if ((HWND)lParam == GetDlgItem(hDlg, ID_ComboVer))
			//{
			//	index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
			//	SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer);
			//	if (lstrcmp(buffer, CpuVersion[0]) == 0)
			//	{
			//		for (int i = 0; i < 3; i++)
			//		{
			//			SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPrice + i));
			//		}
			//		SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
			//		ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
			//	}
			//}
			if ((HWND)lParam == GetDlgItem(hDlg, ID_ComboVer))
			{
				//MessageBox(NULL, TEXT("ID_ComboVer"), TEXT("Message"), MB_OK);
				index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer);
				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);
				//MessageBox(NULL, myGetPrice->WellVersion, TEXT("Message"), MB_OK);
				//myGetPrice->Version
				if ((wcscmp(myGetPrice->CoreGeneration, CpuTypeIntel[1]) == 0))
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					//MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionIntel[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei3[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
						//ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionIntel[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei3[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					else if ((wcscmp(buffer, CpuVersionIntel[3]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei3[2]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
						
					}
					
					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;
				}

				else if(wcscmp(myGetPrice->CoreGeneration, CpuTypeIntel[2]) == 0)
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					//MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionIntel[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei5[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionIntel[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei5[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					else if ((wcscmp(buffer, CpuVersionIntel[3]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei5[2]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

					}
					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;

				}

				
				else if (wcscmp(myGetPrice->CoreGeneration, CpuTypeIntel[3]) == 0)
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					//MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionIntel[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei7[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionIntel[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei7[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					else if ((wcscmp(buffer, CpuVersionIntel[3]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPricei7[2]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

					}

					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;

				}
////////////////////////////////For AMD Bobcat////////////////////////////////////////////////////////////////////////

			
				else if (wcscmp(myGetPrice->CoreGeneration, CpuTypeAmd[1]) == 0)
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
				//	MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionAmdBoabcatArch[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceBobcat[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionAmdBoabcatArch[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceBobcat[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;

				}
///////////////////////////////////////////////////////For AMD Buldozer///////////////////////////////////////////////////

				else if (wcscmp(myGetPrice->CoreGeneration, CpuTypeAmd[2]) == 0)
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					//MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionAmdBulldozerArch[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceBuldozer[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionAmdBulldozerArch[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceBuldozer[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;

				}

//////////////////////////////////////////////For Jaguar///////////////////////////////////////////////////


				else if (wcscmp(myGetPrice->CoreGeneration, CpuTypeAmd[3]) == 0)
				{
					wsprintf(Vadidation, myGetPrice->WellVersion);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
				//	MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, CpuVersionAmdJaguarArch[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceJaguar[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, CpuVersionAmdJaguarArch[2]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In Price"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_ADDSTRING, 0, (LPARAM)(CpuPriceJaguar[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}

					ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					getCpuPrice = SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_GETLBTEXT, getCpuPrice, (LPARAM)myGetPrice->CpuPrice);
					gCpuPrice = 1;

				}


			}


			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo2))
			{
				//MessageBox(NULL, TEXT("In ID_Combo1"), TEXT("Message"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo2, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo2, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("NVIDIA")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo1a));
					for (int i = 0; i <= 3; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_ADDSTRING, 0, (LPARAM)(GpuTypeNvidia + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_SETCURSEL, 0, 0); //wparam ->index

						
				  //ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_SHOW);

					//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0);
					

				}


				else if (lstrcmp(buffer, TEXT("AMD")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i <= 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_ADDSTRING, 0, (LPARAM)(GpuTypeAmd + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_SETCURSEL, 0, 0); //wparam ->index
																					//ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}

				ShowWindow(GetDlgItem(hDlg, ID_Combo2a), SW_SHOW);
			}


			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo2a))
			{
			//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("Price"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo2a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo2a, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Geforce 820M")) == 0)
				{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("Geforce 820M"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo1a));
					//for (int i = 0; i <= 3; i++)
					//{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceNvidia[0]));
					//}
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index


				   //ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_SHOW);

	   		   //SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0)

				}

				else if (wcscmp(buffer, TEXT("GTX 960M")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("GTX 960M"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceNvidia[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index


				}

				else if (wcscmp(buffer, TEXT("GTX 1050Ti")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("GTX 1050Ti"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceNvidia[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("RX 470")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 470"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[0]));
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("RX 560")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 560"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("RX 570")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 570"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				ShowWindow(GetDlgItem(hDlg, ID_Combo2b), SW_SHOW);
				getGpuPrice = SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_GETLBTEXT, getGpuPrice, (LPARAM)myGetPrice->GpuPrice);
				gGpuPrice = 1;
			}

			//////////////////////////////////////////////////////For Ram///////////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo3))
			{
		//		SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Ram"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo3, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo3, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if ((wcscmp(buffer, TEXT("Corsair")) == 0) || (wcscmp(buffer,TEXT("G.Skill"))==0) || (wcscmp(buffer,TEXT("Muskin"))==0))
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
			//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					for (int i = 0; i <= 2; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_ADDSTRING, 0, (LPARAM)(RamSize+i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo3a), SW_SHOW);
				}

				//else if (wcscmp(buffer, TEXT("G.Skill")) == 0)
				//{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("G.Skill"), MB_OK);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[2]));
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				//}
			}

			///////////////////////////For RAM Price////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo3a))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_RESETCONTENT, 0, 0);
			//	MessageBox(NULL, TEXT("In ID_Combo3b"), TEXT("RamPrice"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo3a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo3a, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("4GB")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
				//	MessageBox(NULL, TEXT("In ID_Combo3b"), TEXT("4GB"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_ADDSTRING, 0, (LPARAM)(RamPrice[0]));
					
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_SETCURSEL, 0, 0); //wparam ->index
					//ShowWindow(GetDlgItem(hDlg, ID_Combo3b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("8GB")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo3b"), TEXT("8GB"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_ADDSTRING, 0, (LPARAM)(RamPrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("16GB")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo3b"), TEXT("16GB"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_ADDSTRING, 0, (LPARAM)(RamPrice[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_SETCURSEL, 0, 0); //wparam ->index

				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo3b), SW_SHOW);
				getRamPrice = SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_GETLBTEXT, getRamPrice, (LPARAM)myGetPrice->RamPrice);
				gRamPrice = 1;
			}
////////////////////////////////////For Motherboard//////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo4))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_RESETCONTENT, 0, 0);
		//		MessageBox(NULL, TEXT("In ID_Combo4"), TEXT("Asus"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo4, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo4, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Asus")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
			//		MessageBox(NULL, TEXT("In ID_Combo4a"), TEXT("Asus"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i <= 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_ADDSTRING, 0, (LPARAM)(AsusTypes + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo4a), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Gigabyte")) == 0)
				{
				//	MessageBox(NULL, TEXT("In ID_Combo4a"), TEXT("Gigabyte"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_RESETCONTENT , 0,0);
					for (int i = 0; i <= 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_ADDSTRING, 0, (LPARAM)(GigabyteTypes + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_SETCURSEL, 0, 0);
				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo4a), SW_SHOW);
			}


/////////////////////For MotherBoard price//////////////////////////////
			//TEXT("Asus Intel B85M-G"), TEXT("Asus Intel H61M-CS")
			//TEXT("GA-B250M"), TEXT("GA-H81M")
			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo4a))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_RESETCONTENT, 0, 0);
			//	MessageBox(NULL, TEXT("In ID_Combo4b"), TEXT("MotherboardPrice"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo4a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo4a, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Asus Intel B85M-G")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
				//	MessageBox(NULL, TEXT("In ID_Combo4b"), TEXT("Asus"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));

					//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_ADDSTRING, 0, (LPARAM)(AsusPrice[0]));

					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_SETCURSEL, 0, 0); //wparam ->index
																				   //ShowWindow(GetDlgItem(hDlg, ID_Combo3b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Asus Intel H61M-CS")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo4b"), TEXT("Asus"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_ADDSTRING, 0, (LPARAM)(AsusPrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("GA-B250M")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo4b"), TEXT("gigabyte"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_ADDSTRING, 0, (LPARAM)(GigabytePrice[0]));
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("GA-H81M")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo4b"), TEXT("gigabyte"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_ADDSTRING, 0, (LPARAM)(GigabytePrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_SETCURSEL, 0, 0); //wparam ->index

				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo4b), SW_SHOW);
				getMotherboardPrice = SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_GETLBTEXT, getMotherboardPrice, (LPARAM)myGetPrice->MotherboardPrice);
				gMotherboardPrice = 1;
			}
			///////////////////////////////For Keyboard Price/////////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo5))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_RESETCONTENT, 0, 0);
			//	MessageBox(NULL, TEXT("In ID_Combo5"), TEXT("Keyboard"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo5, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo5, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("LOGITECH")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
				//	MessageBox(NULL, TEXT("In ID_Combo5a"), TEXT("LOGITECH"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_RESETCONTENT, 0, 0);
					
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_ADDSTRING, 0, (LPARAM)(KeyBoardPrice[0]));
					
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo4a), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("INTEX")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo5a"), TEXT("INTEX"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_RESETCONTENT, 0, 0);
					
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_ADDSTRING, 0, (LPARAM)(KeyBoardPrice[1]));
					
					SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_SETCURSEL, 0, 0);
				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo5a), SW_SHOW);
				getKeyboardPrice = SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_GETLBTEXT, getKeyboardPrice, (LPARAM)myGetPrice->KeyboardPrice);
				gKeyboardPrice = 1;
			}

/////////////////////////////////////////For HardDisk///////////////////////////////////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo6))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_RESETCONTENT, 0, 0);
			//	MessageBox(NULL, TEXT("In ID_Combo6"), TEXT("HardDisk"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo6, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo6, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Western Digital")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
				//	MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("Western Digital"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_ADDSTRING, 0, (LPARAM)(HardDiskTypesWD + i));
					}
					
					SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_SETCURSEL, 0, 0);
					ShowWindow(GetDlgItem(hDlg, ID_Combo6a), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Segate")) == 0)
				{
				//	MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT(""), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_ADDSTRING, 0, (LPARAM)(HardDiskTypesSegate + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_SETCURSEL, 0, 0);
				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo6a), SW_SHOW);
			}
///////////////////////////////For HardDisk Price//////////////////////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo6a))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("HardDiskTypes"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo6a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo6a, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("500GB")) == 0 )
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("500GB"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_RESETCONTENT, 0, 0);

					
				   SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_ADDSTRING, 0, (LPARAM)(HardDiskPrice[0]));
					

					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("1TB")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("1TB"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
				SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_RESETCONTENT, 0, 0);


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_ADDSTRING, 0, (LPARAM)(HardDiskPrice[1]));


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("2TB")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("2TB"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_RESETCONTENT, 0, 0);


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_ADDSTRING, 0, (LPARAM)(HardDiskPrice[2]));


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("4TB")) == 0)
				{
				//	MessageBox(NULL, TEXT("In ID_Combo6a"), TEXT("4TB"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
				SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_RESETCONTENT, 0, 0);


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_ADDSTRING, 0, (LPARAM)(HardDiskPrice[3]));


					SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_SETCURSEL, 0, 0);
					
				}
				ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				getHardDsikPrice = SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_GETLBTEXT, getHardDsikPrice, (LPARAM)myGetPrice->HardDiskPrice);
				gHardDiskPrice = 1;
			}

//////////////////////////////////////////////////For Mouse Type/////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo7))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo7"), TEXT("Mouse"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo7, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo7, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Logitech")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In ID_Combo7"), TEXT("Logitech"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_RESETCONTENT, 0, 0);


					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_ADDSTRING, 0, (LPARAM)(MouseType + i));
					}


					SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Dell")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo7"), TEXT("Dell"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_ADDSTRING, 0, (LPARAM)(MouseType + i));
					}


					SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				
				ShowWindow(GetDlgItem(hDlg, ID_Combo7a), SW_SHOW);
			}

////////////////////////////////////////////////For Mouse Price////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo7a))
			{
				//MessageBox(NULL, TEXT("ID_Combo7a"), TEXT("Message"), MB_OK);
				index = SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_GETLBTEXT, index, (LPARAM)buffer);
				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);
				//MessageBox(NULL, myGetPrice->Mouse, TEXT("Message"), MB_OK);
				//myGetPrice->Version
				if ((wcscmp(myGetPrice->Mouse, Mouse[1]) == 0))
				{
					wsprintf(Vadidation, myGetPrice->Mouse);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
				//	MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, MouseType[0]) == 0))
					{
						/*wsprintf(Vadidation, myGetPrice->MouseTypeW);
						wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
						MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);*/

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In MouseType1"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_ADDSTRING, 0, (LPARAM)(MousePriceLogitech[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, MouseType[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_RESETCONTENT, 0, 0);
					//	MessageBox(NULL, TEXT("In MouseType2"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_ADDSTRING, 0, (LPARAM)(MousePriceLogitech[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_SETCURSEL, 0, 0); //wparam ->index
																						  //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
						ShowWindow(GetDlgItem(hDlg, ID_Combo7b), SW_SHOW);
						getMousePrice = SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETCURSEL, 0, 0);
						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETLBTEXT, getMousePrice, (LPARAM)myGetPrice->MousePrice);
						gMousePrice = 1;

				}
				else if (wcscmp(myGetPrice->Mouse, Mouse[2]) == 0)
				{

					/*wsprintf(Vadidation, myGetPrice->MouseTypeW);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);
*/

					if ((wcscmp(buffer, MouseType[0]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Mouse 2 Type1"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_ADDSTRING, 0, (LPARAM)(MousePriceDell[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, MouseType[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Mouse 2 Type 2"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_ADDSTRING, 0, (LPARAM)(MousePriceDell[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					ShowWindow(GetDlgItem(hDlg, ID_Combo7b), SW_SHOW);
					getMousePrice = SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETLBTEXT, getMousePrice, (LPARAM)myGetPrice->MousePrice);
					gMousePrice = 1;

				}

			}
				

/////////////////////////////////////////////////For SMPS Types//////////////////////////////////////////////
			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo8))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo8"), TEXT("SMPS"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo8, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo8, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Corsair")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In ID_Combo8"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_RESETCONTENT, 0, 0);


					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_ADDSTRING, 0, (LPARAM)(SMPSCorsairTypes + i));
					}


					SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Antec")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo8"), TEXT("Antec"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_ADDSTRING, 0, (LPARAM)(SMPSAntecTypes + i));
					}


					SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}


				ShowWindow(GetDlgItem(hDlg, ID_Combo8a), SW_SHOW);
			}


	////////////////////////////////////For SMPS//////////////////////////////////////

			//TCHAR SMPSCorsairTypes[2][20] = { TEXT("Corsair RM650"), TEXT("Corsair RM750") };
			//TCHAR SMPSAntecTypes[2][20] = { TEXT("Antec HCG-900"), TEXT("Antec VP450P") };

	/////////////////////////////////////////////////For SMPS Types//////////////////////////////////////////////
			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo8a))
			{
				SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_RESETCONTENT, 0, 0);
	//			MessageBox(NULL, TEXT("In ID_Combo8a"), TEXT("SMPS"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo8a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo8a, CB_GETLBTEXT, index, (LPARAM)buffer);

		//		MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Corsair RM650")) == 0)
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
			//		MessageBox(NULL, TEXT("In ID_Combo8a"), TEXT("Corsair RM650"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_RESETCONTENT, 0, 0);


					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_ADDSTRING, 0, (LPARAM)(SMPSCorsairPrice[0]));
					


					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Corsair RM750")) == 0)
				{
				//	MessageBox(NULL, TEXT("In ID_Combo8a"), TEXT("Corsair RM750"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_ADDSTRING, 0, (LPARAM)(SMPSCorsairPrice[1]));
					}

					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}


				else if (wcscmp(buffer, TEXT("Antec HCG-900")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo8a"), TEXT("Antec HCG-900"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_ADDSTRING, 0, (LPARAM)(SMPSAntecPrice[0]));
					}

					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				else if (wcscmp(buffer, TEXT("Antec VP450P")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo8a"), TEXT("Antec VP450P"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_RESETCONTENT, 0, 0);

					for (int i = 0; i < 2; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_ADDSTRING, 0, (LPARAM)(SMPSAntecPrice[1]));
					}

					SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_SETCURSEL, 0, 0);
					//ShowWindow(GetDlgItem(hDlg, ID_Combo6b), SW_SHOW);
				}

				ShowWindow(GetDlgItem(hDlg, ID_Combo8b), SW_SHOW);
				getsmpsPrice = SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo8b), CB_GETLBTEXT, getsmpsPrice, (LPARAM)myGetPrice->SmpsPrice);
				gSmpsPrice = 1;

			}
			
/////////////////////////////////////// For Speaker//////////////////////////////////////////////////////////
			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo9))
			{
				//MessageBox(NULL, TEXT("In ID_Combo1"), TEXT("Message"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo9, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo9, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Jbl")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo1a));
					for (int i = 0; i < 3; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_ADDSTRING, 0, (LPARAM)(Speakerjbl + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_SETCURSEL, 0, 0); //wparam ->index


																				   //ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_SHOW);

																				   //SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0);


				}


				else if (lstrcmp(buffer, TEXT("Sony")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i < 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_ADDSTRING, 0, (LPARAM)(SpeakerSony + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_SETCURSEL, 0, 0); //wparam ->index
																				   //ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}


				else if (lstrcmp(buffer, TEXT("Panasonic")) == 0)
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_RESETCONTENT, 0, 0);
					for (int i = 0; i < 3; i++)
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_ADDSTRING, 0, (LPARAM)(SpeakerPanasonic + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_SETCURSEL, 0, 0); //wparam ->index
																				   //ShowWindow(GetDlgItem(hDlg, ID_ComboVer), SW_SHOW);
				}

				ShowWindow(GetDlgItem(hDlg, ID_Combo9a), SW_SHOW);
			}
		
///////////////////////////////////////For Speaker Price//////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo9a))
			{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("Price"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo9a, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo9a, CB_GETLBTEXT, index, (LPARAM)buffer);

				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if (wcscmp(buffer, TEXT("Arena 120")) == 0)
				{
					//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("Geforce 820M"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					//MessageBox(NULL, TEXT("In Intel"), TEXT("Message"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo1a));
					//for (int i = 0; i <= 3; i++)
					//{
					//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerjblPrice[0]));
					//}
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index


																				   //ShowWindow(GetDlgItem(hDlg, ID_Combo1a), SW_SHOW);

																				   //SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_SETCURSEL, 0, 0)

				}

				else if (wcscmp(buffer, TEXT("Arena 170")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("GTX 960M"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerjblPrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index


				}

				else if (wcscmp(buffer, TEXT("Arena 180")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("GTX 1050Ti"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerjblPrice[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("Sony XB20")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 470"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerSonyPrice[0]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("Sony XB10")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 560"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerSonyPrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("Sony CT290")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 570"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerSonyPrice[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				
				else if (wcscmp(buffer, TEXT("SC-HT31")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 570"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerPanasonicPrice[0]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("SC-HTB485")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 570"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerPanasonicPrice[1]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				else if (wcscmp(buffer, TEXT("SC-BTT785")) == 0)
				{
					//MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("RX 570"), MB_OK);
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_RESETCONTENT, 0, 0); 
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_ADDSTRING, 0, (LPARAM)(SpeakerPanasonicPrice[2]));
					SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_SETCURSEL, 0, 0); //wparam ->index

				}

				ShowWindow(GetDlgItem(hDlg, ID_Combo9b), SW_SHOW);
				getGpuPrice = SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo9b), CB_GETLBTEXT, getSpeakerPrice, (LPARAM)myGetPrice->SpeakerPrice);
				gSpeakerPrice = 1;
			}


////////////////////////////////////For PenDrive Size///////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo10))
			{
		//		SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Ram"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo10, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo10, CB_GETLBTEXT, index, (LPARAM)buffer);

			//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if ((wcscmp(buffer, TEXT("SandDisk")) == 0))
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
			//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					for (int i = 0; i < 2; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_ADDSTRING, 0, (LPARAM)(PendriveSize+i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo10a), SW_SHOW);
				}

				else if ((wcscmp(buffer, TEXT("HP")) == 0))
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_RESETCONTENT, 0, 0);
					//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					for (int i = 0; i < 2; i++)
					{
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
						SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_ADDSTRING, 0, (LPARAM)(PendriveSize + i));
					}
					SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo10a), SW_SHOW);
				}

				//else if (wcscmp(buffer, TEXT("G.Skill")) == 0)
				//{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("G.Skill"), MB_OK);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[2]));
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				//}
			}

///////////////////////////////////////////////For Penddrive Price/////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo10a))
			{
				//MessageBox(NULL, TEXT("ID_Combo7a"), TEXT("Message"), MB_OK);
				index = SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_GETLBTEXT, index, (LPARAM)buffer);
				//MessageBox(NULL, buffer, TEXT("Message"), MB_OK);
				//MessageBox(NULL, myGetPrice->Mouse, TEXT("Message"), MB_OK);
				//myGetPrice->Version
				if ((wcscmp(myGetPrice->Penddrive, Pendrive[1]) == 0))
				{
					wsprintf(Vadidation, myGetPrice->Mouse);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					//	MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);


					if ((wcscmp(buffer, PendriveSize[0]) == 0))
					{
						/*wsprintf(Vadidation, myGetPrice->MouseTypeW);
						wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
						MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);*/

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_RESETCONTENT, 0, 0);
						//	MessageBox(NULL, TEXT("In MouseType1"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_ADDSTRING, 0, (LPARAM)(PendriveSandDiskPrice[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, PendriveSize[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_RESETCONTENT, 0, 0);
						//	MessageBox(NULL, TEXT("In MouseType2"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_ADDSTRING, 0, (LPARAM)(PendriveSandDiskPrice[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					ShowWindow(GetDlgItem(hDlg, ID_Combo10b), SW_SHOW);
					getMousePrice = SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_GETLBTEXT, getPenddrivePrice, (LPARAM)myGetPrice->PendrivePrice);
					gPendrivePrice = 1;

				}
				else if (wcscmp(myGetPrice->Penddrive, Pendrive[2]) == 0)
				{

					/*wsprintf(Vadidation, myGetPrice->MouseTypeW);
					wsprintf(Vadidation, TEXT("THIS IS IN VALIDATION"));
					MessageBox(NULL, Vadidation, TEXT("ERROR"), MB_OK);
					*/

					if ((wcscmp(buffer, PendriveSize[0]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Mouse 2 Type1"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_ADDSTRING, 0, (LPARAM)(PendriveHPPrice[0]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					else if ((wcscmp(buffer, PendriveSize[1]) == 0))
					{
						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_RESETCONTENT, 0, 0);
						//MessageBox(NULL, TEXT("In Mouse 2 Type 2"), TEXT("Message"), MB_OK);
						//index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
						//SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)buffer

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_ADDSTRING, 0, (LPARAM)(PendriveHPPrice[1]));
						//SendMessage(GetDlgItem(hDlg, ID_ComboPrice), CB_SETCURSEL, 0, 0); //wparam ->index

						SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_SETCURSEL, 0, 0); //wparam ->index
																					   //ShowWindow(GetDlgItem(hDlg, ID_ComboPrice), SW_SHOW);
					}
					ShowWindow(GetDlgItem(hDlg, ID_Combo10b), SW_SHOW);
					getMousePrice = SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_GETCURSEL, 0, 0);
					SendMessage(GetDlgItem(hDlg, ID_Combo10b), CB_GETLBTEXT, getPenddrivePrice, (LPARAM)myGetPrice->PendrivePrice);
					gPendrivePrice = 1;

				}

			}

/////////////////////////////////////////For Cabinet Types////////////////////////////////////


			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo11))
			{
				//		SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Ram"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo11, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo11, CB_GETLBTEXT, index, (LPARAM)buffer);

				//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if ((wcscmp(buffer, TEXT("Zebronics")) == 0))
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					
					SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_ADDSTRING, 0, (LPARAM)(CabinetPrice[0]));
				
					SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo11a), SW_SHOW);
				}

				else if ((wcscmp(buffer, TEXT("Circle Desire")) == 0))
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_RESETCONTENT, 0, 0);
					//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
						//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
					SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_ADDSTRING, 0, (LPARAM)(CabinetPrice[1]));
					
					SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo11a), SW_SHOW);
				}

				//else if (wcscmp(buffer, TEXT("G.Skill")) == 0)
				//{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("G.Skill"), MB_OK);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[2]));
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				//}
				getCabinetPrice = SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_GETLBTEXT, getCabinetPrice, (LPARAM)myGetPrice->CabinetPrice);
				gCabinetPrice = 1;
			}

////////////////////////////////////////////For Fan Types/////////////////////////////////////////////

			if ((HWND)lParam == GetDlgItem(hDlg, ID_Combo12))
			{
				//		SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_RESETCONTENT, 0, 0);
				//MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Ram"), MB_OK);
				index = SendDlgItemMessage(hDlg, ID_Combo12, CB_GETCURSEL, 0, 0);
				(TCHAR*)SendDlgItemMessage(hDlg, ID_Combo12, CB_GETLBTEXT, index, (LPARAM)buffer);

				//	MessageBox(NULL, buffer, TEXT("Message"), MB_OK);

				if ((wcscmp(buffer, TEXT("Corsair")) == 0))
				{
					//SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_RESETCONTENT, 0, 0);
					//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));

					SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_ADDSTRING, 0, (LPARAM)(FanPrice[0]));

					SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo12a), SW_SHOW);
				}

				else if ((wcscmp(buffer, TEXT("Cooler Master")) == 0))
				{
					SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_RESETCONTENT, 0, 0);
					//		MessageBox(NULL, TEXT("In ID_Combo3"), TEXT("Corsair"), MB_OK);
					//SetFocus(GetDlgItem(hDlg, ID_Combo3));
					//TCHAR CpuTypeIntel[4][20] = { TEXT("----SELECT----"),TEXT("Core i3"),TEXT("Core i5"),TEXT("Core i7") };
					SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_ADDSTRING, 0, (LPARAM)(FanPrice[1]));

					SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_SETCURSEL, 0, 0); //wparam ->index
					ShowWindow(GetDlgItem(hDlg, ID_Combo12a), SW_SHOW);
				}

				//else if (wcscmp(buffer, TEXT("G.Skill")) == 0)
				//{
				//	MessageBox(NULL, TEXT("In ID_Combo2a"), TEXT("G.Skill"), MB_OK);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_RESETCONTENT, 0, 0);
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_ADDSTRING, 0, (LPARAM)(GpuPriceAmd[2]));
				//	SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_SETCURSEL, 0, 0); //wparam ->index

				//}
				getFanPrice = SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo12a), CB_GETLBTEXT, getFanPrice, (LPARAM)myGetPrice->FanPrice);
				gFanPrice = 1;
			}








			break;


		case CBN_KILLFOCUS:

			if (LOWORD(wParam) == ID_Combo1)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo1), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo1), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Processor);
				gProcessor = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo1a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo1a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->CoreGeneration);
				gCoreGeneration = 1;
				break;

			}
			if (LOWORD(wParam) == ID_ComboVer)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_ComboVer), CB_GETLBTEXT, index, (LPARAM)myGetPrice->WellVersion);
				gWellVersion = 1;
				break;

			}

			
/////////////////////change///////////////////////////
			if (LOWORD(wParam) == ID_Combo2)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo2), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo2), CB_GETLBTEXT, index, (LPARAM)myGetPrice->GraphicsCard);
				gGraphicsCard = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo2a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo2a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->GraphicsCardType);
				gGraphicsCardType = 1;
				break;

			}

			/*if (LOWORD(wParam) == ID_Combo2b)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo2b), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Ram);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo3)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo3), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo3), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Ram);
				gRam = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo3a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo3a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->RamSize);
				gRamSize = 1;
				break;

			}

			/*if (LOWORD(wParam) == ID_Combo3b)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo3b), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Mouse);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo4)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo4), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo4), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Motherboard);
				gMotherboard = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo4a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo4a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->MotherboardType);
				gMotherboardType = 1;
				break;

			}

		/*	if (LOWORD(wParam) == ID_Combo4b)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo4b), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Mouse);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo5)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo5), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo5), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Keyboard);
				gKeyboard = 1;
				break;

			}

			/*if (LOWORD(wParam) == ID_Combo5a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo5a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->KeyboardType);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo6)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo6), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo6), CB_GETLBTEXT, index, (LPARAM)myGetPrice->HardDisk);
				gHardDisk = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo6a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo6a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->HardDiskSize);
				gHardDiskSize = 1;
				break;

			}

			/*if (LOWORD(wParam) == ID_Combo6b)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo6b), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Mouse);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo7)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo7), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo7), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Mouse);
				gMouse = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo7a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo7a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->MouseType);
				gMouseType = 1;
				break;

			}

		/*	if (LOWORD(wParam) == ID_Combo7b)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo7b), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Mouse);
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo8)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo8), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo8), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Smps);
				gSmps = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo8a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo8a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->SmpsType);
				gSmpsType = 1;
				break;
				
			}

			if (LOWORD(wParam) == ID_Combo9)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo9), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo9), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Speaker);
				gSpeaker = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo9a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo9a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->SpeakerType);
				gSpeakerType = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo10)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo10), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo10), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Penddrive);
				gPendrive = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo10a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo10a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->PendriveSize);
				gPendriveSize = 1;
				break;

			}

			if (LOWORD(wParam) == ID_Combo11)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo11), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo11), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Cabinet);
				gCabinet = 1;
				break;

			}

			/*if (LOWORD(wParam) == ID_Combo11a)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo11a), CB_GETLBTEXT, index, (LPARAM)myGetPrice->CabinetType);
				gCabinetType = 1;
				break;

			}*/

			if (LOWORD(wParam) == ID_Combo12)
			{
				index = SendMessage(GetDlgItem(hDlg, ID_Combo12), CB_GETCURSEL, 0, 0);
				SendMessage(GetDlgItem(hDlg, ID_Combo12), CB_GETLBTEXT, index, (LPARAM)myGetPrice->Fan);
				gFan = 1;
				break;

			}

		break;
		}
		return(TRUE);
	}
	return(FALSE);
}


BOOL CALLBACK MyDlgProcName(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	switch (iMsg)
	{
	case WM_COMMAND:
		
		switch (LOWORD(wParam))
		{
		case IDCustomerName:
			GetDlgItemText(hDlg, ID_ETNAME, CustomerName, 50);
			EndDialog(hDlg, 0);
			break;
	
		}

		return(TRUE);
	}
	return(FALSE);
}





