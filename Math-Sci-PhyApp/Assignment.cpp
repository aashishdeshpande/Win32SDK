#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strsafe.h>
#include "Assignment.h"
#include "chemistry.tlh"
HWND ghwnd;

FILE *gpFile = NULL;

//For Mathematics
TCHAR firstReal[10];
TCHAR firstImg[10];
TCHAR secondReal[10];
TCHAR secondImg[10];

//For Physics
TCHAR KEMass[10];
TCHAR KEVolume[10];
TCHAR PEHeight[10];
int giKEMass;
int giKEVolume;
int giPEHeight;

//For Chemistry
TCHAR CEnergy[10];
TCHAR CMass[10];
TCHAR CDeltaTemp[10];
float gfCEnergy;
float gfCMass;
float gfCDeltaTemp;
float gfSpecificHeat;

TCHAR class_name[20];
TCHAR batch_name[20];
TCHAR my_name[500];
TCHAR group_name[50];

/**********FOR MATHEMATICS************/
typedef struct ComplexNumber
{
	int gNumReal;
	int gNumImg;
}complexNumberClient;

complexNumberClient Num1, Num2, Answer;

// variable declarations
static HMODULE hLib = NULL;
//typedef void(*pFunctionPointer)(void);
typedef complexNumberClient(*pfnResult)(ComplexNumber, ComplexNumber);
typedef complexNumberClient(*pfnResultFraction)(ComplexNumber, ComplexNumber, int *);
//pFunctionPointer pfn = NULL;
pfnResult pfnRes = NULL;
pfnResultFraction pfnResFraction = NULL;
//int n1, n2, n3;
TCHAR str[255];

/***************FOR PHYSICS**************/
static HMODULE hLibPhysics = NULL;
typedef void(*pFunctionPointer)(void);
typedef int(*pfnKE)(int, int);
typedef float(*pfnPE)(int, int);
pFunctionPointer pfn = NULL;
pfnKE pfnKineticEnergy = NULL;
pfnPE pfnPotentialEnergy = NULL;
int finalKE;
float finalPE;
int giKEResult;
int giPEResult;

/***************FOR CHEMISTRY**************/
static HMODULE hLibChemistry = NULL;
typedef float(*pfnCalculateSpecificHeat)(float, float, float);
pfnCalculateSpecificHeat pfnCSH = NULL;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	MSG msg;
	HWND hwnd;
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("MyApp");
	ZeroMemory(&Num1, sizeof(Num1));
	ZeroMemory(&Num2, sizeof(Num2));

	if (fopen_s(&gpFile, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Log File Can Not Be Created\nExitting ..."), TEXT("Error"), MB_OK | MB_TOPMOST | MB_ICONSTOP);
	}

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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassEx(&wndclass);

	int xPos = GetSystemMetrics(SM_CXSCREEN);
	int yPos = GetSystemMetrics(SM_CYSCREEN);

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

	if (gpFile)
	{
		fprintf(gpFile, "Log File Is Successfully Closed.\n");
		fclose(gpFile);
		gpFile = NULL;
	}

	return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = NULL;
	HDC hdc = NULL;
	HFONT hf;
	RECT rc;
	PAINTSTRUCT ps;
	long lfHeight;

	HBITMAP hImage = NULL;
	HDC hdcMem;
	HBITMAP hbmOld;
	BITMAP bm;
	HFONT hfOld;
	HFONT hfOld_className;

	/*******FOR MATHEMATICS*******/

	switch (iMsg)
	{
	case WM_CREATE:
		//Load the Library For Calculation
		hLib = LoadLibrary(TEXT("ServerForComplexNumber.dll"));
		if (hLib == NULL)
		{
			MessageBox(hwnd, TEXT("Can Not Load Dll.\nExitting."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
			return(-1);
		}

		hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_SPACE:
			DialogBox(hInst, TEXT("LAWS"), hwnd, MyDlgProc);
			break;

		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_PAINT:
		hImage = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_Image));
		if (hImage == NULL)
		{
			MessageBox(NULL, TEXT("Could not Load ID_Image"), TEXT("Error"), MB_OK);
		}
		hdc = BeginPaint(hwnd, &ps);
		lfHeight = -MulDiv(48, GetDeviceCaps(hdc, LOGPIXELSY), 144);
		hf = CreateFont(lfHeight, 0, 0, 0, FW_EXTRABOLD, TRUE, TRUE, 0, 0, 0, 0, 0, 0, TEXT("Times New Roman"));
		SetBkMode(hdc, TRANSPARENT);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(0, 0, 0));
	    hfOld = (HFONT)SelectObject(hdc, hf);
		hdcMem = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcMem, hImage);
		GetObject(hImage, sizeof(bm), &bm);
		BitBlt(hdc, 0, 0, bm.bmWidth + 200, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		GetClientRect(hwnd, &rc);
		DrawText(hdc, TEXT("PRESS SPACEBAR TO CONTINUE"), -1, &rc, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
		//DrawText(hdc, TEXT("Maths-Physics-Chemistry"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_RIGHT);
		wsprintf(class_name, TEXT("ASTROMEDICOMP"));
		lfHeight = -MulDiv(48, GetDeviceCaps(hdc, LOGPIXELSY), 144);
		hf = CreateFont(lfHeight, 0, 0, 0, FW_EXTRABOLD, TRUE, 0, 0, 0, 0, 0, 0, 0, TEXT("Times New Roman"));
		hfOld_className = (HFONT)SelectObject(hdc, hf);
		TextOut(hdc, 200, 200, class_name, lstrlen(class_name));
		wsprintf(batch_name, TEXT("WinRT 2018"));
		TextOut(hdc, 1000, 200, batch_name, lstrlen(batch_name));
		wsprintf(my_name, TEXT("Aashish Deshpande"));
		TextOut(hdc, 1000, 280, my_name, lstrlen(my_name));

		wsprintf(group_name, TEXT("-WM_SIZE"));
		TextOut(hdc, 1050, 415, group_name, lstrlen(group_name));

		SelectObject(hdcMem, hbmOld);
		SelectObject(hdc, hfOld_className);
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	bool print = false;
	int denominator;
	
	/******FOR MATHEMATICS******/
	int const arraySize = 100;
	LPCTSTR pszFormat = TEXT("%d + %d %s");
	LPCTSTR pszFormatKE = TEXT("%d");
	LPCTSTR pszFormatPE = TEXT("%f");
	LPCTSTR pszFormatSpecificHeat = TEXT("%f");
	LPCTSTR pszFormatFraction = TEXT("%d/%d + %d/%d %s");
	TCHAR pszDest[arraySize];
	size_t cbDest = arraySize * sizeof(TCHAR);
	TCHAR *pszText = TEXT("i");
	
	switch (iMsg)
	{
	case WM_INITDIALOG:

		//ExplicitServer Which will call ClassFactoryServer For Physics Functionality
		hLibPhysics = LoadLibrary(TEXT("ExplicitServer.dll"));
		if (hLibPhysics == NULL)
		{
			MessageBox(NULL, TEXT("Can Not Load Physics Dll.\nExitting."), TEXT("Error"), MB_OK);
			return(-1);
		}

		pfn = (pFunctionPointer)GetProcAddress(hLibPhysics, "initializeCom");
		if (pfn == NULL)
		{
			MessageBox(NULL, TEXT("Can Not Get Address Of initializeCom().\nExitting."), TEXT("Error"), MB_OK);
			return(-1);
		}

		pfn(); 

		ShowWindow(hDlg, SW_SHOW);
		SendDlgItemMessage(hDlg, ID_RBBOYLESLAW, BM_SETCHECK, 1, 0);

		//Initially keep Physics disabled
		EnableWindow(GetDlgItem(hDlg, ID_MASS), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_KE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_SELECTKE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_SELECTPE), FALSE);

		//Initially keep Chemistry disabled
		EnableWindow(GetDlgItem(hDlg, ID_CENERGY), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CMASS), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CDELTATEMP), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_RBCSPECIFICHEAT), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CSPECIFICHEAT), FALSE);
		break;

	case WM_PAINT:
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_RBBOYLESLAW:
			//Disable Chemistry
			EnableWindow(GetDlgItem(hDlg, ID_CENERGY), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CMASS), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CDELTATEMP), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_RBCSPECIFICHEAT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CSPECIFICHEAT), FALSE);

			SetDlgItemText(hDlg, ID_CENERGY, TEXT(""));
			SetDlgItemText(hDlg, ID_CMASS, TEXT(""));
			SetDlgItemText(hDlg, ID_CDELTATEMP, TEXT(""));
			SetDlgItemText(hDlg, ID_CSPECIFICHEAT, TEXT(""));

			//Disable Physics
			EnableWindow(GetDlgItem(hDlg, ID_MASS), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_KE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTKE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTPE), FALSE);

			SetDlgItemText(hDlg, ID_MASS, TEXT(""));
			SetDlgItemText(hDlg, ID_KEVOLUME, TEXT(""));
			SetDlgItemText(hDlg, ID_PEHEIGHT, TEXT(""));
			SetDlgItemText(hDlg, ID_KE, TEXT(""));

			//Enable Maths
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTREAL), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTIMG), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDREAL), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDIMG), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_ADD), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_SUB), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_MUL), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_DIV), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_RESULT), TRUE);

			SendDlgItemMessage(hDlg, ID_RBCHARLESLAW, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_RBCHEMISTRY, BM_SETCHECK, BST_UNCHECKED, 0);
			break;

		case ID_RBCHARLESLAW:

			//Disable Chemistry
			EnableWindow(GetDlgItem(hDlg, ID_CENERGY), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CMASS), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CDELTATEMP), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_RBCSPECIFICHEAT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CSPECIFICHEAT), FALSE);

			SetDlgItemText(hDlg, ID_CENERGY, TEXT(""));
			SetDlgItemText(hDlg, ID_CMASS, TEXT(""));
			SetDlgItemText(hDlg, ID_CDELTATEMP, TEXT(""));
			SetDlgItemText(hDlg, ID_CSPECIFICHEAT, TEXT(""));

			//Disable Maths
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTREAL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTIMG), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDREAL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDIMG), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_ADD), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SUB), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_MUL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_DIV), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_RESULT), FALSE);

			SetDlgItemText(hDlg, ID_FIRSTREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_FIRSTIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_RESULT, TEXT(""));

			//Enable Physics
			EnableWindow(GetDlgItem(hDlg, ID_MASS), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_KE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTKE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTPE), TRUE);

			SendDlgItemMessage(hDlg, ID_RBBOYLESLAW, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_RBCHEMISTRY, BM_SETCHECK, BST_UNCHECKED, 0);
			break;

		case ID_RBCHEMISTRY:

			//Disable Maths
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTREAL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_FIRSTIMG), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDREAL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SECONDIMG), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_ADD), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SUB), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_MUL), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_DIV), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_RESULT), FALSE);

			SetDlgItemText(hDlg, ID_FIRSTREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_FIRSTIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_RESULT, TEXT(""));
		
			//Disable Physics
			EnableWindow(GetDlgItem(hDlg, ID_MASS), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_KE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTKE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_SELECTPE), FALSE);

			SetDlgItemText(hDlg, ID_MASS, TEXT(""));
			SetDlgItemText(hDlg, ID_KEVOLUME, TEXT(""));
			SetDlgItemText(hDlg, ID_PEHEIGHT, TEXT(""));
			SetDlgItemText(hDlg, ID_KE, TEXT(""));

			//Enable Chemistry
			EnableWindow(GetDlgItem(hDlg, ID_CENERGY), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CMASS), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CDELTATEMP), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_RBCSPECIFICHEAT), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CSPECIFICHEAT), TRUE);

			SendDlgItemMessage(hDlg, ID_RBCHARLESLAW, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_RBBOYLESLAW, BM_SETCHECK, BST_UNCHECKED, 0);
			break;

		case ID_OK:
		
			break;

		case ID_FIRSTREAL:
			GetDlgItemText(hDlg, ID_FIRSTREAL, firstReal, 10); //Save the no. of moles
			Num1.gNumReal = _wtoi(firstReal);
			fprintf(gpFile, "First Number Real part is %d\n", Num1.gNumReal);
			break;
			
		case ID_FIRSTIMG:
			GetDlgItemText(hDlg, ID_FIRSTIMG, firstImg, 10); //Save the no. of moles
			Num1.gNumImg = _wtoi(firstImg);
			fprintf(gpFile, "First Number Img part is %d\n", Num1.gNumImg);
			break;

		case ID_SECONDREAL:
			GetDlgItemText(hDlg, ID_SECONDREAL, secondReal, 10); //Save the increment/decrement constant 
			Num2.gNumReal = _wtoi(secondReal);
			fprintf(gpFile, "Second Number Real part is %d\n", Num2.gNumReal);
			break;

		case ID_SECONDIMG:
			GetDlgItemText(hDlg, ID_SECONDIMG, secondImg, 10); //Save the no. of moles
			Num2.gNumImg = _wtoi(secondImg);
			fprintf(gpFile, "Second Number Img part is %d\n", Num2.gNumImg);
			break;

		case ID_ADD:
			ZeroMemory(&Answer, sizeof(Answer));
			pfnRes = (pfnResult)GetProcAddress(hLib, "SumOfTwoComplexNumbers");
			if (pfnRes == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of SumOfTwoComplexNumbers().\nExitting."), TEXT("Error"), MB_OK);
				DestroyWindow(NULL);
				return(-1);
			}
			Answer = pfnRes(Num1, Num2);
			StringCbPrintf(pszDest, cbDest, pszFormat, Answer.gNumReal, Answer.gNumImg, pszText);
			fprintf(gpFile, "Answer Real part is %d\n", Answer.gNumReal);
			fprintf(gpFile, "Answer Img part is %d\n", Answer.gNumImg);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_RESULT, pszDest);
			break;

		case ID_SUB:
			ZeroMemory(&Answer, sizeof(Answer));
			pfnRes = (pfnResult)GetProcAddress(hLib, "SubtractionOfTwoComplexNumbers");
			if (pfnRes == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of SubtractionOfTwoComplexNumbers().\nExitting."), TEXT("Error"), MB_OK);
				DestroyWindow(NULL);
				return(-1);
			}
			Answer = pfnRes(Num1, Num2);
			StringCbPrintf(pszDest, cbDest, pszFormat, Answer.gNumReal, Answer.gNumImg, pszText);
			fprintf(gpFile, "Answer Real part is %d\n", Answer.gNumReal);
			fprintf(gpFile, "Answer Img part is %d\n", Answer.gNumImg);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_RESULT, pszDest);
			break;

		case ID_MUL:
			ZeroMemory(&Answer, sizeof(Answer));
			pfnRes = (pfnResult)GetProcAddress(hLib, "MultiplicationOfTwoComplexNumbers");
			if (pfnRes == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of MultiplicationOfTwoComplexNumbers().\nExitting."), TEXT("Error"), MB_OK);
				DestroyWindow(NULL);
				return(-1);
			}
			Answer = pfnRes(Num1, Num2);
			StringCbPrintf(pszDest, cbDest, pszFormat, Answer.gNumReal, Answer.gNumImg, pszText);
			fprintf(gpFile, "Answer Real part is %d\n", Answer.gNumReal);
			fprintf(gpFile, "Answer Img part is %d\n", Answer.gNumImg);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_RESULT, pszDest);
			break;

		case ID_DIV:
			ZeroMemory(&Answer, sizeof(Answer));
			pfnResFraction = (pfnResultFraction)GetProcAddress(hLib, "DivisionOfTwoComplexNumbers");
			if (pfnResFraction == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of DivisionOfTwoComplexNumbers().\nExitting."), TEXT("Error"), MB_OK);
				DestroyWindow(NULL);
				return(-1);
			}
			Answer = pfnResFraction(Num1, Num2, &denominator);
			StringCbPrintf(pszDest, cbDest, pszFormatFraction, Answer.gNumReal, denominator, Answer.gNumImg, denominator, pszText);
			fprintf(gpFile, "Answer Real part is %d\n", Answer.gNumReal);
			fprintf(gpFile, "Answer Img part is %d\n", Answer.gNumImg);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_RESULT, pszDest);
			break;

		/*********************FOR PHYSICS***************************/
		case ID_SELECTPE:
			EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), TRUE);
			SetDlgItemText(hDlg, ID_KEVOLUME, TEXT(""));
			SetDlgItemText(hDlg, ID_KE, TEXT(""));
			SetDlgItemText(hDlg, ID_MASS, TEXT(""));
			break;

		case ID_SELECTKE:
			EnableWindow(GetDlgItem(hDlg, ID_PEHEIGHT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEPE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_KEVOLUME), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CALCULATEKE), TRUE);
			SetDlgItemText(hDlg, ID_PEHEIGHT, TEXT(""));
			SetDlgItemText(hDlg, ID_KE, TEXT(""));
			SetDlgItemText(hDlg, ID_MASS, TEXT(""));
			break;

		case ID_MASS:
			GetDlgItemText(hDlg, ID_MASS, KEMass, 10); 
			giKEMass = _wtoi(KEMass);
			fprintf(gpFile, "Phiysics KEMass is %d\n", giKEMass);
			break;

		case ID_KEVOLUME:
			GetDlgItemText(hDlg, ID_KEVOLUME, KEVolume, 10);
			giKEVolume = _wtoi(KEVolume);
			fprintf(gpFile, "Physics KEVolume is %d\n", giKEVolume);
			break;

		case ID_PEHEIGHT:
			GetDlgItemText(hDlg, ID_PEHEIGHT, PEHeight, 10);
			giPEHeight = _wtoi(PEHeight);
			fprintf(gpFile, "Physics PEHeight is %d\n", giPEHeight);
			break;
			

		case ID_CALCULATEKE:
			/*pfn = (pFunctionPointer)GetProcAddress(hLibPhysics, "initializeCom");
			if (pfn == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of initializeCom().\nExitting."), TEXT("Error"), MB_OK);
				return(-1);
			}

			pfn();*/

			pfnKineticEnergy = (pfnKE)GetProcAddress(hLibPhysics, "SumOfTwoIntegers");
			if (pfnKineticEnergy == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of SumOfTwoIntegers().\nExitting."), TEXT("Error"), MB_OK);
				return(-1);
			}
			finalKE = pfnKineticEnergy(giKEMass, giKEVolume);

			StringCbPrintf(pszDest, cbDest, pszFormatKE, finalKE);
			fprintf(gpFile, "Kinetic Energy is %d\n", finalKE);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_KE, pszDest);
			break;

		case ID_CALCULATEPE :
			pfnPotentialEnergy = (pfnPE)GetProcAddress(hLibPhysics, "CalculatePE");
			if (pfnPotentialEnergy == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of CalculatePE().\nExitting."), TEXT("Error"), MB_OK);
				return(-1);
			}
			finalPE = pfnPotentialEnergy(giKEMass, giPEHeight);

			StringCbPrintf(pszDest, cbDest, pszFormatPE, finalPE);
			fprintf(gpFile, "Potential Energy is %f\n", finalPE);
			//MessageBox(NULL, pszDest, TEXT("Error"), MB_ICONERROR);
			SetDlgItemText(hDlg, ID_KE, pszDest);
			break;

			/*********************FOR CHEMISTRY***************************/

		case ID_CENERGY:
			GetDlgItemText(hDlg, ID_CENERGY, CEnergy, 10);
			gfCEnergy = _wtof(CEnergy);
			fprintf(gpFile, "Chemistry CEnergy is %f\n", gfCEnergy);
			break;

		case ID_CMASS:
			GetDlgItemText(hDlg, ID_CMASS, CMass, 10);
			gfCMass = _wtof(CMass);
			fprintf(gpFile, "Chemistry CMass is %f\n", gfCMass);
			break;

		case ID_CDELTATEMP:
			GetDlgItemText(hDlg, ID_CDELTATEMP, CDeltaTemp, 10);
			gfCDeltaTemp = _wtof(CDeltaTemp);
			fprintf(gpFile, "Chemistry CDeltaTemp is %f\n", gfCDeltaTemp);
			break;

		case ID_RBCSPECIFICHEAT:
			hLibChemistry = LoadLibrary(TEXT("IntermediateDLLForSpecificHeatCCW.dll"));
			if (hLibChemistry == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Load Chemistry Dll.\nExitting."), TEXT("Error"), MB_OK);
				return(-1);
			}
			else
			{
				MessageBox(NULL, TEXT("Loaded Chemistry Dll.\nExitting."), TEXT("Error"), MB_OK);
			}

			pfnCSH = (pfnCalculateSpecificHeat)GetProcAddress(hLibChemistry, "initializeCCW");
			if (pfnCSH == NULL)
			{
				MessageBox(NULL, TEXT("Can Not Get Address Of initializeCCW().\nExitting."), TEXT("Error"), MB_OK);
				return(-1);
			}
			else
			{
				MessageBox(NULL, TEXT("Obtained Address Of initializeCCW().\nExitting."), TEXT("Error"), MB_OK);
			}

			gfSpecificHeat = pfnCSH(gfCEnergy, gfCMass, gfCDeltaTemp);

			StringCbPrintf(pszDest, cbDest, pszFormatSpecificHeat,gfSpecificHeat);
			fprintf(gpFile, "Specific Heat is %f\n", gfSpecificHeat);
			SetDlgItemText(hDlg, ID_CSPECIFICHEAT, pszDest);

			break;

		case ID_CANCEL:
			EndDialog(hDlg, 0);
			break;

		case ID_RESET:
			SetDlgItemText(hDlg, ID_MASS, TEXT(""));
			SetDlgItemText(hDlg, ID_KEVOLUME, TEXT(""));
			SetDlgItemText(hDlg, ID_PEHEIGHT, TEXT(""));
			SetDlgItemText(hDlg, ID_KE, TEXT(""));

			SetDlgItemText(hDlg, ID_FIRSTREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_FIRSTIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDREAL, TEXT(""));
			SetDlgItemText(hDlg, ID_SECONDIMG, TEXT(""));
			SetDlgItemText(hDlg, ID_RESULT, TEXT(""));

			SetDlgItemText(hDlg, ID_CENERGY, TEXT(""));
			SetDlgItemText(hDlg, ID_CMASS, TEXT(""));
			SetDlgItemText(hDlg, ID_CDELTATEMP, TEXT(""));
			SetDlgItemText(hDlg, ID_CSPECIFICHEAT, TEXT(""));

			SendDlgItemMessage(hDlg, ID_CALCULATEKE, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_CALCULATEPE, BM_SETCHECK, BST_UNCHECKED, 0);

			SendDlgItemMessage(hDlg, ID_RBCSPECIFICHEAT, BM_SETCHECK, BST_UNCHECKED, 0);
			
			SendDlgItemMessage(hDlg, ID_ADD, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_MUL, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_DIV, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(hDlg, ID_SUB, BM_SETCHECK, BST_UNCHECKED, 0);
			break;

		}//case WM_COMMAND

	}//case iMsg
	return(FALSE);
}//DlgProc