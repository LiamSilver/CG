//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uJanela.h"
#include "uPrincipal.h"
#include "uPonto.h"
#include "uPoligono.h"
#include "displayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);
Ponto aux;
Poligono pol;
displayFile display;

bool inicia = false;
int contId = 0;

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

    display.desenha(Image1->Canvas, mundo, vp);

	//Inserindo o eixo vertical

	pol.tipo = 'E';
	pol.id  = contId++;

	pol.pontos.push_back(Ponto(0,mundo.yMax));
	//	Image1->Canvas->MoveTo(250,0);
	pol.pontos.push_back(Ponto(0,mundo.yMin));
	//	Image1->Canvas->LineTo(250,500);

	display.poligonos.push_back(pol);
	pol.pontos.clear();

	//Inserindo o eixo horizontal

	pol.tipo = 'E';
	pol.id  = contId++;

	pol.pontos.push_back(Ponto(mundo.xMin,0));
	//	Image1->Canvas->MoveTo(0,250);
	pol.pontos.push_back(Ponto(mundo.xMax,0));
	//	Image1->Canvas->LineTo(500,250);

	display.poligonos.push_back(pol);
	pol.pontos.clear();





	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp);

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

	if(inicia){

		if(Button == mbRight){
			inicia=false;
			pol.id = contId++;
			pol.tipo = 'P';

			display.poligonos.push_back(pol);
			display.mostra(lbPoligonos);
			display.desenha(Image1->Canvas, mundo, vp);
			pol.pontos.clear();
		}

		else{
		aux.x = xVp2W(X, mundo, vp);
		aux.y = yVp2W(Y, mundo, vp);

		pol.pontos.push_back(aux);
		pol.mostra(lbxPontos);
		pol.desenha(Image1->Canvas, mundo, vp);
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TfrmPrincipal::btnPoligonoClick(TObject *Sender)
{
    inicia = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnAtualizaMundoClick(TObject *Sender)
{
	mundo.xMin = StrToFloat(edXmin->Text);
	mundo.xMax = StrToFloat(edXmax->Text);
	mundo.yMin = StrToFloat(edYmin->Text);
	mundo.yMax = StrToFloat(edYmax->Text);

	display.poligonos[0].pontos[0].y = mundo.yMax;
	display.poligonos[0].pontos[1].y = mundo.yMin;

	display.poligonos[1].pontos[0].x = mundo.xMin;
	display.poligonos[1].pontos[1].x = mundo.xMax;

	display.desenha(Image1->Canvas, mundo, vp);

}
//---------------------------------------------------------------------------



void __fastcall TfrmPrincipal::lbPoligonosClick(TObject *Sender)
{
   display.poligonos[lbPoligonos->ItemIndex].mostra(lbxPontos);
}
//---------------------------------------------------------------------------

