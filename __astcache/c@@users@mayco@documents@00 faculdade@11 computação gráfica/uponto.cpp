//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto.h"
#include "uJanela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto(double nx, double ny){
	x = nx;
	y = ny;
}

Ponto::Ponto(){
    x = y = 0;
}
