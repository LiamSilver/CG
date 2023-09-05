//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPoligono.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Poligono::mostra(TListBox* lbx)
{

	lbx->Items->Clear();

	for(int x=0; x<pontos.size(); x++){
	   lbx->Items->Add(pontos[x].mostra());
	}
}

void Poligono::desenha(TCanvas* canvas, Janela mundo, Janela vp)
{

	int xVp, yVp;

	for(int i=0; i<pontos.size(); i++){

		xVp = pontos[i].xW2Vp(mundo, vp);
		yVp = pontos[i].yW2Vp(mundo, vp);

		if(i==0)
			canvas->MoveTo(xVp,yVp);
		else
			canvas->LineTo(xVp,yVp);
	}
}

AnsiString Poligono::toString(){

	return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()) + " pontos";
}
