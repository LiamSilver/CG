//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

#include "uPonto2d.h"
//---------------------------------------------------------------------------

class Ponto: public Ponto2d{
	public:
		double z;

		Ponto();
		Ponto(double nx, double ny);
        Ponto(double nx, double ny, double nz);
        AnsiString mostra();

};
#endif
