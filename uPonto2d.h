//---------------------------------------------------------------------------

#ifndef uPonto2dH
#define uPonto2dH
#include "uJanela.h"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Ponto2d{
	public:
		double x;
		double y;
		int cohen = 0;
	Ponto2d(double nx, double ny);
	Ponto2d();

	int xW2Vp(Janela mundo, Janela vp);
	int yW2Vp(Janela mundo, Janela vp);

    int calcularCohen(Janela clipping);
	int calcularCohenX(Janela clipping);
	int calcularCohenY(Janela clipping);
	AnsiString mostra();



};
#endif
