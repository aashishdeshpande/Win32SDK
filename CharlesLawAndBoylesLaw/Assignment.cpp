#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strsafe.h>
#include "Assignment.h"

#define gasConstant 8.3144598
#define MAX_CONST_FILENAME 100000
HWND ghwnd;

FILE *gpFile = NULL;

//boyle's law variables
float gBoylePressure = 1.000000;
double gBoyleVolume = 1022.678555;
float gIncDecConst;
int gConstTemp;
int gNoOfMoles;
int flagNoOfMoles = 1;
bool gbIncFlag = FALSE;
float gSavedPressure;
float gSavedVolume;

//boyle's law variables
TCHAR noOfMoulesBuff[10];
TCHAR incdecConstBuff[10];
TCHAR constTempBuff[10];
TCHAR boylePressure[10];
TCHAR boyleVolume[10];

FILE *fp;
static int fileNameCount = 1;
TCHAR boylesLawFileName[16] = TEXT("BoylesLaw-State");
int gprevBoyleVolume;
int gprevBoylePressure;
int gprevValueBoyleVol = 1;
int gprevValueBoyleVoldec = 1;
int gprevValueBoylePre = 1;
int gprevValueBoylePredec = 1;
//TCHAR mbStringBoylesLaw[100] = TEXT("Current State Saved in BoylesLaw-State");


//charles' law variables
float gCharleVolume = 1.000000;
float gCharleTemperature = 0.002673;
float gIncDecConstC;
int gConstPressure;
int gNoOfMolesC;
int flagNoOfMolesC = 1;
float gSavedVolumeC;
float gSavedTemperatureC;

//charles' law variables
TCHAR noOfMolesBuffC[10];
TCHAR incdecConstBuffC[10];
TCHAR constPressureBuffC[10];
TCHAR charlesTemperature[10];
TCHAR charlesVolume[10];


FILE *fpC;
static int fileNameCountC = 1;
TCHAR charlesLawFileName[17] = TEXT("CharlesLaw-State");
float gprevCharlesVolume;
float gprevCharlesTemperature;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	MSG msg;
	HWND hwnd;
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("MyApp");

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
	//HBITMAP hImage = NULL;
	HDC hdc = NULL;
	HFONT hf;
	//HFONT hfOld_className;
	RECT rc;
	PAINTSTRUCT ps;
	long lfHeight;
	//TCHAR AssignmentName[20];

	HBITMAP hImage = NULL;
	HDC hdcMem;
	HBITMAP hbmOld;
	BITMAP bm;
	HFONT hfOld;

	switch (iMsg)
	{
	case WM_CREATE:
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
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		GetClientRect(hwnd, &rc);
		DrawText(hdc, TEXT("PRESS SPACEBAR TO CONTINUE"), -1, &rc, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
		DrawText(hdc, TEXT("BOYLE'S LAW AND CHARLES' LAW"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_RIGHT);
		SelectObject(hdcMem, hbmOld);
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
	LPCTSTR pszFormat = TEXT("%4.6f");
	bool print = false;
	TCHAR appendName[5];
	TCHAR appendNameC[5];

	/*HBITMAP hImage = NULL;
	HDC hdc;
	BITMAP bm;
	PAINTSTRUCT ps;
	HDC hdcMem = NULL;
	HBITMAP hbmOld;*/

	switch (iMsg)
	{
	case WM_INITDIALOG:
		ShowWindow(hDlg, SW_SHOW);
		SendDlgItemMessage(hDlg, ID_RBBOYLESLAW, BM_SETCHECK, 1, 0);

		//Initially keep boyle's controls enabled
		EnableWindow(GetDlgItem(hDlg, ID_CHARLETMOLES), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLETCONSTANT), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLETPRESSURE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLETVOLUME), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLETTEMPERATURE), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPINC), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPDEC), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEINC), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEDEC), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLRESET), FALSE);
		EnableWindow(GetDlgItem(hDlg, ID_CHARLSAVESTATE), FALSE);
		break;

	case WM_PAINT:
		/*hImage = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_ImageD));
		if (hImage == NULL)
		{
			MessageBox(NULL, TEXT("Could not Load ID_Image"), TEXT("Error"), MB_OK);
		}
		hdc = BeginPaint(hDlg, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcMem, hImage);
		GetObject(hImage, sizeof(bm), &bm);
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		SelectObject(hdcMem, hbmOld);
		EndPaint(hDlg, &ps);*/

		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_OK:
			GetDlgItemText(hDlg, ID_BOYLETTEMPERATURE, constTempBuff, 10);
			gConstTemp = _wtoi(constTempBuff);
			break;

			/*Initially when no. of moles are entered in the edit box, the pressure and volume edit box
			must get set*/
		case ID_BOYLETMOLES:
			GetDlgItemText(hDlg, ID_BOYLETMOLES, noOfMoulesBuff, 10); //Save the no. of moles
			gNoOfMoles = _wtoi(noOfMoulesBuff);
			flagNoOfMoles = 0;
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				gBoylePressure = (float)(1.0 * 1.0 * 1.0) / (float)1.0;
				StringCbPrintf(boylePressure, sizeof(boylePressure), pszFormat, gBoylePressure);
				SetDlgItemText(hDlg, ID_BOYLETPRESSURE, boylePressure);

				gBoyleVolume = (float)(gNoOfMoles * gasConstant * 1.0) / (float)1.0;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);
			}
			break;

		case ID_BOYLETCONSTANT:
			GetDlgItemText(hDlg, ID_BOYLETCONSTANT, incdecConstBuff, 10); //Save the increment/decrement constant 
			gIncDecConst = _wtof(incdecConstBuff);
			break;

			/*When temperature is entered initially, the volume should get calculated and the edit box for
			volume must show updated value*/
		case ID_BOYLETTEMPERATURE:
			GetDlgItemText(hDlg, ID_BOYLETTEMPERATURE, constTempBuff, 10);//Save the constant temperature
			gConstTemp = _wtoi(constTempBuff);
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				gBoyleVolume = (float)(gNoOfMoles * gasConstant * gConstTemp) / (float)gBoylePressure;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);
			}
			break;

			//--------------------------------------FOR PRESSURE--------------------------------------------------
			/*Decrease the volume when pressure increases and increase the volume when pressure decreases
			Hence it is done(volume manipulation) under the case of pressure because change in pressure drives the
			corresponding change in volume*/
			//Increase the pressure on '+' pushbutton
		case ID_BOYLEPRESSUREINC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMoles == 0)
			{
				gBoylePressure = gBoylePressure + gIncDecConst;
				StringCbPrintf(boylePressure, sizeof(boylePressure), pszFormat, gBoylePressure);
				SetDlgItemText(hDlg, ID_BOYLETPRESSURE, boylePressure);

				gBoyleVolume = (float)(gNoOfMoles * gasConstant * gConstTemp) / (float)gBoylePressure;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);	
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

			//Decrease the pressure on '-' pushbutton
		case ID_BOYLEPRESSUREDEC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMoles == 0)
			{
				gBoylePressure = gBoylePressure - gIncDecConst;
				StringCbPrintf(boylePressure, sizeof(boylePressure), pszFormat, gBoylePressure);
				SetDlgItemText(hDlg, ID_BOYLETPRESSURE, boylePressure);

				gBoyleVolume = (float)(gNoOfMoles * gasConstant * gConstTemp) / (float)gBoylePressure;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);			
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;


			//-------------------------------------FOR VOLUME----------------------------------------------------------
			/*Decrease the the pressure when voulme increases and increase the pressure when voulme decreases
			Hence it is done(pressure manipulation) under the case of volume because change in volume drives the
			corresponding change in pressure*/
			//Increase the volume on '+' pushbutton
		case ID_BOYLEVOLUMEINC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMoles == 0)
			{
				gBoyleVolume = gBoyleVolume + gIncDecConst;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);

				gBoylePressure = (float)(gNoOfMoles * gasConstant * gConstTemp) / (float)gBoyleVolume;
				StringCbPrintf(boylePressure, sizeof(boylePressure), pszFormat, gBoylePressure);
				SetDlgItemText(hDlg, ID_BOYLETPRESSURE, boylePressure);		
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

			//Decrease the volume on '-' pushbutton
		case ID_BOYLEVOLUMEDEC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMoles == 0)
			{
				gBoyleVolume = gBoyleVolume - gIncDecConst;
				StringCbPrintf(boyleVolume, sizeof(boyleVolume), pszFormat, gBoyleVolume);
				SetDlgItemText(hDlg, ID_BOYLETVOLUME, boyleVolume);

				gBoylePressure = (float)(gNoOfMoles * gasConstant * gConstTemp) / (float)gBoyleVolume;
				StringCbPrintf(boylePressure, sizeof(boylePressure), pszFormat, gBoylePressure);
				SetDlgItemText(hDlg, ID_BOYLETPRESSURE, boylePressure);
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

		/*case ID_BOYLETVOLUME:
			if (HIWORD(wParam) == EM_GETMODIFY)
			{
				gprevBoyleVolume = 0;
			}
			break;*/


		/*case ID_BOYLETPRESSURE:
			if (HIWORD(wParam) == EM_GETMODIFY)
			{
				gprevBoylePressure = 0;
			}
			break;*/

			//------------------------------CASES FOR CHARLES' LAW---------------------------------------

			/*Initially when no. of moles are entered in the edit box, the volume and temperature edit box
			must get set*/
		case ID_CHARLETMOLES:
			GetDlgItemText(hDlg, ID_CHARLETMOLES, noOfMolesBuffC, 10); //Save the no. of moles
			gNoOfMolesC = _wtoi(noOfMolesBuffC);
			flagNoOfMolesC = 0;
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				gCharleVolume = (float)(1.0 * 1.0 * 1.0) / (float)1.0;
				StringCbPrintf(charlesVolume, sizeof(charlesVolume), pszFormat, gCharleVolume);
				SetDlgItemText(hDlg, ID_CHARLETVOLUME, charlesVolume);

				gCharleTemperature = (float)(gCharleVolume * 1.0) / (float)(gNoOfMolesC * gasConstant * 1.0);
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);
			}
			break;

		case ID_CHARLETCONSTANT:
			GetDlgItemText(hDlg, ID_CHARLETCONSTANT, incdecConstBuffC, 10); //Save the increment/decrement constant 
			gIncDecConstC = _wtof(incdecConstBuffC);
			break;

			/*When pressure is entered initially, the temperature should get calculated and the edit box for
			temperature must show updated value*/
		case ID_CHARLETPRESSURE:
			GetDlgItemText(hDlg, ID_CHARLETPRESSURE, constPressureBuffC, 10);//Save the constant temperature
			gConstPressure = _wtoi(constPressureBuffC);
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				gCharleTemperature = (float)(gConstPressure * 1.0) / (float)(gNoOfMolesC * gasConstant);
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);
			}
			break;

			//--------------------------------------FOR VOLUME--------------------------------------------------
			/*Decrease the temperature when volume decreases and increase the temperature when volume increases
			Hence it is done(temperature manipulation) under the case of volume because change in volume drives the
			corresponding change in temperature*/
			//Increase the volume on '+' pushbutton
		case ID_CHARLVOLUMEINC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMolesC == 0)
			{
				gCharleVolume = gCharleVolume + gIncDecConstC;
				StringCbPrintf(charlesVolume, sizeof(charlesVolume), pszFormat, gCharleVolume);
				SetDlgItemText(hDlg, ID_CHARLETVOLUME, charlesVolume);

				gCharleTemperature = (float)(gConstPressure * gCharleVolume) / (float)(gNoOfMolesC * gasConstant);
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

			//Decrease the voulme on '-' pushbutton
		case ID_CHARLVOLUMEDEC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMolesC == 0)
			{
				gCharleVolume = gCharleVolume - gIncDecConstC;
				StringCbPrintf(charlesVolume, sizeof(charlesVolume), pszFormat, gCharleVolume);
				SetDlgItemText(hDlg, ID_CHARLETVOLUME, charlesVolume);

				gCharleTemperature = (float)(gConstPressure * gCharleVolume) / (float)(gNoOfMolesC * gasConstant);
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

			//-------------------------------------FOR TEMPERATURE----------------------------------------------------------
			/*Decrease the the volume when temperature decreases and increase the volume when temperature increases
			Hence it is done(volume manipulation) under the case of temperature because change in temperature drives the
			corresponding change in volume*/
			//Increase the temperature on '+' pushbutton
		case ID_CHARLTEMPINC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMolesC == 0)
			{
				gCharleTemperature = gCharleTemperature + gIncDecConstC;
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);

				gCharleVolume = (float)(gNoOfMolesC * gasConstant * gCharleTemperature) / (float)gConstPressure;
				StringCbPrintf(charlesVolume, sizeof(charlesVolume), pszFormat, gCharleVolume);
				SetDlgItemText(hDlg, ID_CHARLETVOLUME, charlesVolume);
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

			//Decrease the temperature on '-' pushbutton
		case ID_CHARLTEMPDEC:
			if (HIWORD(wParam) == BN_CLICKED && flagNoOfMolesC == 0)
			{
				gCharleTemperature = gCharleTemperature - gIncDecConstC;
				StringCbPrintf(charlesTemperature, sizeof(charlesTemperature), pszFormat, gCharleTemperature);
				SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, charlesTemperature);

				gCharleVolume = (float)(gNoOfMolesC * gasConstant * gCharleTemperature) / (float)gConstPressure;
				StringCbPrintf(charlesVolume, sizeof(charlesVolume), pszFormat, gCharleVolume);
				SetDlgItemText(hDlg, ID_CHARLETVOLUME, charlesVolume);
			}
			else
			{
				MessageBox(hDlg, TEXT("Please Enter the Number of Moles"), TEXT("Error"), MB_ICONERROR);
			}
			break;

		case ID_BOYLERESET:
			SetDlgItemText(hDlg, ID_BOYLETMOLES, TEXT(""));
			SetDlgItemText(hDlg, ID_BOYLETCONSTANT, TEXT(""));
			SetDlgItemText(hDlg, ID_BOYLETTEMPERATURE, TEXT(""));
			SetDlgItemText(hDlg, ID_BOYLETPRESSURE, TEXT(""));
			SetDlgItemText(hDlg, ID_BOYLETVOLUME, TEXT(""));
			break;

		case ID_CHARLRESET:
			SetDlgItemText(hDlg, ID_CHARLETMOLES, TEXT(""));
			SetDlgItemText(hDlg, ID_CHARLETCONSTANT, TEXT(""));
			SetDlgItemText(hDlg, ID_CHARLETTEMPERATURE, TEXT(""));
			SetDlgItemText(hDlg, ID_CHARLETPRESSURE, TEXT(""));
			SetDlgItemText(hDlg, ID_CHARLETVOLUME, TEXT(""));
			break;

		case ID_BOYLESAVESTATE:
			if (HIWORD(wParam) == BN_CLICKED)
			{
				if (gNoOfMoles != 0 && gConstTemp != 0)
				{
					wsprintf(appendName, TEXT("%d"), fileNameCount);
					lstrcat(boylesLawFileName, appendName);
					lstrcat(boylesLawFileName, TEXT(".txt"));
					if (gSavedPressure != gBoylePressure && gSavedVolume != gBoyleVolume)
					{
						_wfopen_s(&fp, boylesLawFileName, TEXT("w"));
						wsprintf(boylesLawFileName, TEXT("BoylesLaw-State"));
						//MessageBox(hDlg, TEXT("before error checking of fp"), TEXT("file error"), MB_ICONINFORMATION);

						if (fp == NULL)
						{
							MessageBox(hDlg, TEXT("file cannot be opened"), TEXT("file error"), MB_ICONINFORMATION);
							exit(0);
						}
						else
						{
							TCHAR mbStringBoylesLaw[200] = TEXT("The Current State Of Gas Under Study For Boyle's Law Has Been Saved In A File By The Name 'BoylesLaw-State");
							wsprintf(appendName, TEXT("%d"), fileNameCount);
							lstrcat(mbStringBoylesLaw, appendName);

							MessageBox(hDlg, mbStringBoylesLaw, TEXT("BOYLE'S LAW FILE SAVE MESSAGE"), MB_ICONINFORMATION);

							fwprintf_s(fp, TEXT("BOYLE'S LAW:-\n"));

							fwprintf_s(fp, TEXT("Number Of Moles[n]:"));
							fwprintf_s(fp, noOfMoulesBuff);
							fwprintf_s(fp, TEXT("\n"));

							fwprintf_s(fp, TEXT("Value of Incerement/Decrement Constant:"));
							fwprintf_s(fp, incdecConstBuff);
							fwprintf_s(fp, TEXT("\n"));

							fwprintf_s(fp, TEXT("Value of Constant Temperature[T]:"));
							fwprintf_s(fp, constTempBuff);
							fwprintf_s(fp, TEXT("\n"));

							fwprintf_s(fp, TEXT("Value of Pressure[P]:"));
							fwprintf_s(fp, boylePressure);
							fwprintf_s(fp, TEXT("\n"));

							fwprintf_s(fp, TEXT("Value of Volume[V]:"));
							fwprintf_s(fp, boyleVolume);
							fwprintf_s(fp, TEXT("\n\n\n"));

							fileNameCount++;
						}
						gSavedPressure = gBoylePressure;
						gSavedVolume = gBoyleVolume;
					}
					else
					{
						MessageBox(hDlg, TEXT("File With Current State Already Exists"), TEXT("ERROR"), MB_ICONERROR);
					}
				}
					else
					{
						MessageBox(hDlg, TEXT("Incomplete Data"), TEXT("BOYLE'S LAW FILE SAVE ERROR"), MB_ICONERROR);
					}
			}
					
			break;

		case ID_CHARLSAVESTATE: 
			if (HIWORD(wParam) == BN_CLICKED)
			{
				if (gNoOfMolesC != 0 && gConstPressure != 0)
				{
					wsprintf(appendNameC, TEXT("%d"), fileNameCountC);
					lstrcat(charlesLawFileName, appendNameC);
					lstrcat(charlesLawFileName, TEXT(".txt"));
					if (gSavedVolumeC != gCharleVolume && gSavedTemperatureC != gCharleTemperature)
					{
						_wfopen_s(&fpC, charlesLawFileName, TEXT("w"));
						wsprintf(charlesLawFileName, TEXT("CharlesLaw-State"));

						if (fpC == NULL)
						{
							MessageBox(hDlg, TEXT("file cannot be opened"), TEXT("file error"), MB_ICONINFORMATION);
							exit(0);
						}

						else
						{
							TCHAR mbStringCharlesLaw[200] = TEXT("The Current State Of Gas Under Study For Charles' Law Has Been Saved In A File By The Name 'CharlesLaw-State");
							wsprintf(appendNameC, TEXT("%d"), fileNameCountC);
							lstrcat(mbStringCharlesLaw, appendNameC);

							MessageBox(hDlg, mbStringCharlesLaw, TEXT("CHARLES' LAW FILE SAVE MESSAGE"), MB_ICONINFORMATION);

							fwprintf_s(fpC, TEXT("CHARLES' LAW:-\n"));

							fwprintf_s(fpC, TEXT("Number Of Moles[n]:"));
							fwprintf_s(fpC, noOfMolesBuffC);
							fwprintf_s(fpC, TEXT("\n"));

							fwprintf_s(fpC, TEXT("Value of Incerement/Decrement Constant:"));
							fwprintf_s(fpC, incdecConstBuffC);
							fwprintf_s(fpC, TEXT("\n"));

							fwprintf_s(fpC, TEXT("Value of Constant Pressure[T]:"));
							fwprintf_s(fpC, constPressureBuffC);
							fwprintf_s(fpC, TEXT("\n"));

							fwprintf_s(fpC, TEXT("Value of Volume[P]:"));
							fwprintf_s(fpC, charlesVolume);
							fwprintf_s(fpC, TEXT("\n"));

							fwprintf_s(fpC, TEXT("Value of Temperature[V]:"));
							fwprintf_s(fpC, charlesTemperature);
							fwprintf_s(fpC, TEXT("\n"));

							fileNameCountC++;

						}
						gSavedVolumeC = gCharleVolume;
						gSavedTemperatureC = gCharleTemperature;
					}
					else
					{
						MessageBox(hDlg, TEXT("File With Current State Already Exists"), TEXT("ERROR"), MB_ICONERROR);
					}
				}	
				else
				{
					MessageBox(hDlg, TEXT("Incomplete Data"), TEXT("CHARLES' LAW FILE SAVE ERROR"), MB_ICONERROR);
				}

			}
			break;

		case ID_CANCEL:
			if (fp)
			{
				fprintf(fp, "Log File for boyle's law Is Successfully Closed.\n");
				fclose(fp);
				fp = NULL;
			}

			if (fpC)
			{
				fprintf(fpC, "Log File for charles' law Is Successfully Closed.\n");
				fclose(fpC);
				fpC = NULL;
			}
			EndDialog(hDlg, 0);
			break;

		}//case WM_COMMAND



		if (IsDlgButtonChecked(hDlg, ID_RBBOYLESLAW) == BST_CHECKED)
		{
			//Enable boyle's control
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETMOLES), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETCONSTANT), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETPRESSURE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETVOLUME), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETTEMPERATURE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEVOLUMEINC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEVOLUMEDEC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEPRESSUREINC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEPRESSUREDEC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLESAVESTATE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLERESET), TRUE);

			//Disable charles' control
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETMOLES), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETCONSTANT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETPRESSURE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETVOLUME), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETTEMPERATURE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPINC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPDEC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEINC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEDEC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLRESET), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLSAVESTATE), FALSE);
		}

		else if (IsDlgButtonChecked(hDlg, ID_RBCHARLESLAW) == BST_CHECKED)
		{
			//Enable charles' control
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETMOLES), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETCONSTANT), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETPRESSURE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETVOLUME), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLETTEMPERATURE), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPINC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLTEMPDEC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEINC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLVOLUMEDEC), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLRESET), TRUE);
			EnableWindow(GetDlgItem(hDlg, ID_CHARLSAVESTATE), TRUE);

			//Disable boyle's control
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETMOLES), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETCONSTANT), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETPRESSURE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETVOLUME), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLETTEMPERATURE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEVOLUMEINC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEVOLUMEDEC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEPRESSUREINC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLEPRESSUREDEC), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLESAVESTATE), FALSE);
			EnableWindow(GetDlgItem(hDlg, ID_BOYLERESET), FALSE);
		}
		fprintf(gpFile, "No. of Moles are %d\n", gNoOfMoles);
		fprintf(gpFile, "Const Temp is %d\n", gConstTemp);
		fprintf(gpFile, "inc/dec const is %f\n", gIncDecConst);
		fprintf(gpFile, "pressure is %f\n", gBoylePressure);
		fprintf(gpFile, "Inc/dec constant is %f\n", gIncDecConst);
	}//case iMsg
	return(FALSE);
}//DlgProc