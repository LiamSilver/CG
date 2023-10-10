//---------------------------------------------------------------------------
#ifndef uPonto3dH
#define uPonto3dH
#include "uPonto.h"
//---------------------------------------------------------------------------
class Ponto3d : public Ponto
{
  public:
    double z;

    Ponto3d(double nx, double ny, double nz);
    Ponto3d();
    AnsiString mostra();
};
#endif

