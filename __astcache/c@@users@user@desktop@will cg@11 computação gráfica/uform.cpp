﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uJanela.h"
#include "uForm.h"
#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);
Ponto aux;

double xVp2W(int x, Janela mundo, Janela vp){
	return ((x - vp.xMin) / (vp.xMax - vp.xMin)) * (mundo.xMax - mundo.xMin) + mundo.xMin;
}

double yVp2W(int y, Janela mundo, Janela vp){
	return (1 - (y - vp.xMin) / (vp.yMax - vp.yMin)) * (mundo.yMax - mundo.yMin) + mundo.yMin;
}
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
	: TForm(Owner)
{
	Image1->Canvas->Brush->Color = clSilver;
	Image1->Canvas->FillRect(Rect(0,0,500,500));

	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->Pen->Width = 2;

	Image1->Canvas->MoveTo(250,0);
	Image1->Canvas->LineTo(250,500);

	Image1->Canvas->MoveTo(0,250);
	Image1->Canvas->LineTo(500,250);
}
//---------------------------------------------------------------------------


void __fastcall TfrmPrincipal::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	double xw, yw;
	xw = xVp2W(X, mundo, vp);
    yw = yVp2W(Y, mundo, vp);
	lbVp->Caption = "(" + IntToStr(X) + ", " + IntToStr(Y) + ")";
    lbW->Caption = "(" + FloatToStr(xw) + ", " + FloatToStr(yw) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	aux.x = xVp2W(X, mundo, vp);
    aux.y = yVp2W(Y, mundo, vp);
}
//---------------------------------------------------------------------------

