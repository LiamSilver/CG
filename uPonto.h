//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Ponto{
	public:
		double x;
		double y;
        int cohen = 0;
	Ponto(double nx, double ny);
	Ponto();

	int xW2Vp(Janela mundo, Janela vp);
	int yW2Vp(Janela mundo, Janela vp);

    int calcularCohen(Janela clipping);
	int calcularCohenX(Janela clipping);
	int calcularCohenY(Janela clipping);
	AnsiString mostra();


    //TranslatarPontos
};
#endif
