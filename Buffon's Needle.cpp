// Buffon's Needle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <windowsx.h>
#include <conio.h>

using std::cin;
using std::cout;

struct Out
{
	float x1;
	float y1;
	float x2;
	float y2;
	bool per;
};

struct Out Bros(float xn, float yn, float a, float l, float lines[15]);


void main()
{
	const float Pi = 3.14159265359;
	float a = 10.0;
	float l;
	l = 0.96*a;
	float Ptr = 2 * l / (a*Pi); // Expression for the theoretical definition of probability
	int m = 0, n = 0;
	float Ppr = 0.0;
	float x1, y1, x2, y2;
	struct Out Priem;
	float lines[15];
	float x = 0.0;
	float n1 = 0.0, m1 = 0.0; 

	HWND hwnd = GetConsoleWindow(); // Getting the window id
	HDC hdc = GetDC(hwnd); // The GetDC function retrieves a handle to a device context (DC) for the client area of a specified window or for the entire screen. 
	HPEN whitePen = GetStockPen(WHITE_PEN); // Creating the white brush
	SelectBrush(hdc, whitePen); // Selecting the white brush for drawing a "grid"

	// Drawing the 15 horizontal lines
	float xn = 10.0, yn = 10.0;
	MoveToEx(hdc, xn, yn, NULL);
	for (int i = 0; i <= 15; i++)
	{
		lines[i] = yn + i * 2 * a;
		MoveToEx(hdc, xn, yn + i * 2 * a, NULL);
		LineTo(hdc, xn + 340, yn + i * 2 * a);
	}
	
	// File for recording the difference between theoretical and practically calculated probability
	char* filename = "output.txt";
	FILE* fp;
	errno_t err;
	err	= fopen_s(&fp, filename, "w+"); 

	int i_input;
	
	do
	{
		i_input = _getch();

		switch (i_input)
		{
		case 32:

			Priem = Bros(xn, yn, a, l, lines);
			x1 = Priem.x1;
			y1 = Priem.y1;
			x2 = Priem.x2;
			y2 = Priem.y2;
			if (Priem.per == true) 
				{ n = n + Priem.per; }

			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2, y2);
			m++;
			n1 = n;
			m1 = m;
			Ppr = n1 / m1; // calculation of practical probability by division number of intersections on the number of experiments
			x = Ptr - Ppr;
			fprintf(fp, "%4f\r\n", x);//"%f"

			MoveToEx(hdc, xn, yn, NULL);
			for (int i = 0; i <= 15; i++)
			{
				MoveToEx(hdc, xn, yn + i * 2 * a, NULL);
				LineTo(hdc, xn + 340, yn + i * 2 * a);
			}

			::TextOut(hdc, xn + 360, yn, L"To throw, press the SPACE bar", 33);
			::TextOut(hdc, xn + 360, yn + 4 * a, L"Num of experiment=", 18);
			WCHAR  hah[3];
			wsprintf(hah, TEXT("%d"), m);
			TextOut(hdc, xn + 500, yn + 4 * a, hah, lstrlen(hah));

			::TextOut(hdc, xn + 360, yn + 6 * a, L"Num of intersect=", 18);
			WCHAR  hah1[3];
			wsprintf(hah1, TEXT("%d"), n);
			TextOut(hdc, xn + 500, yn + 6 * a, hah1, lstrlen(hah1));

			::TextOut(hdc, xn + 360, yn + 8 * a, L"Ppract=", 7);
			WCHAR  hah2[6];
			swprintf(hah2, 7, L"%f", Ppr);
			TextOut(hdc, xn + 420, yn + 8 * a, hah2, lstrlen(hah2));

			::TextOut(hdc, xn + 360, yn + 10 * a, L"Ptheor=", 7);
			WCHAR  hah3[6];
			swprintf(hah3, 7, L"%f", Ptr);
			TextOut(hdc, xn + 420, yn + 10 * a, hah3, lstrlen(hah3));
		
		case 27:  break;
		}

	} while (i_input != 27);

	fclose(fp);
	getchar();
}


struct Out Bros(float xn, float yn, float a, float l, float lines[15])
{
	const float Pi = 3.1415;
	float x0, y0;
	int alpha;
	int t, c;
	struct Out tmp;

	t = xn + 340 - a;
	c = xn + a;
	x0 = rand() % (t)+c;
	t = yn + 14 * a;
	c = yn + a;
	y0 = rand() % (t)+c;
	alpha = rand() % (180) + (-180);

	tmp.x1 = x0 - l*cos(alpha*Pi / 180);
	tmp.y1 = y0 + l*sin(alpha*Pi / 180);
	tmp.x2 = x0 + l*cos(alpha*Pi / 180);
	tmp.y2 = y0 - l*sin(alpha*Pi / 180);
	tmp.per = false;

	for (int i = 0; i <= 15; i++)
	{
		if (((tmp.y1 <= lines[i]) && (tmp.y2 >= lines[i])) || ((tmp.y2 <= lines[i]) && (tmp.y1 >= lines[i])))
		{
			tmp.per = true;
		}
	}

	return tmp;
}
