//---------------------------------------------------------------------------

#pragma hdrstop

#include "uJanela.h"
#include "uPonto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto(double nx, double ny){
	x = nx;
	y = ny;
}

Ponto::Ponto(){
    x = y = 0;
}

int Ponto::xW2Vp(Janela mundo, Janela vp){
	return ((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) * (vp.xMax - vp.xMin);
}

int Ponto::yW2Vp(Janela mundo, Janela vp){
	return (1 - (y - mundo.yMin) / (mundo.yMax - mundo.yMin)) * (vp.yMax - vp.yMin);
}

AnsiString Ponto::mostra(){
	return "(" + FloatToStr(x) + ", " + FloatToStr(y) + ")";
};
