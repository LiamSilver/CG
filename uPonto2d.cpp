//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto2d.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto2d::Ponto2d(double nx, double ny)
{
	x = nx;
	y = ny;
}

Ponto2d::Ponto2d()
{
	x = y = 0;
}

int Ponto2d::xW2Vp(Janela mundo, Janela vp)
{
	return ((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) * (vp.xMax - vp.xMin);
}

int Ponto2d::yW2Vp(Janela mundo, Janela vp)
{
	return (1 - (y - mundo.yMin) / (mundo.yMax - mundo.yMin)) *
		   (vp.yMax - vp.yMin);
}

int Ponto2d::calcularCohen(Janela clipping)
{
	if (x < clipping.xMin)
		cohen += 1;
	else if (x > clipping.xMax)
		cohen += 2;

	if (y < clipping.yMin)
		cohen += 4;
	else if (y > clipping.yMax)
		cohen += 8;

	return cohen;
}

AnsiString Ponto2d::mostra()
{
	return "(" + FloatToStr(x) + ", " + FloatToStr(y) + ")";
};

