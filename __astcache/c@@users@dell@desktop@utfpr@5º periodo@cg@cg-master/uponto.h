﻿//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Ponto{
	public:
		double x;
		double y;

	Ponto(double nx, double ny);
	Ponto();

	int xW2Vp(Janela mundo, Janela vp);
	int yW2Vp(Janela mundo, Janela vp);

	AnsiString mostra();

    //TranslatarPontos
};
#endif
