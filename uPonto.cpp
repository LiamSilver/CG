//---------------------------------------------------------------------------

#pragma hdrstop
#include "uJanela.h"
#include "uPonto2d.h"
#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto() : Ponto2d()
{
    z = 0;
}

Ponto::Ponto(double dx, double dy) : Ponto2d(dx, dy)
{
    z = 0;
}

Ponto::Ponto(double dx, double dy, double dz) : Ponto2d(dx, dy)
{
    z = dz;
}

AnsiString Ponto::mostra()
{
    return "(" + FloatToStr(x) + ", " + FloatToStr(y) + ", " + FloatToStr(z) +
           ")";
};

