﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPoligono.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::mostra(TListBox* lbx)
{
    lbx->Items->Clear();

    for (int x = 0; x < pontos.size(); x++) {
        lbx->Items->Add(pontos[x].mostra());
    }
}

void Poligono::desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta)
{
    int xVp, yVp, xVp2, yVp2;

    if (tipoReta == 0) {
        canvas->Pen->Color = clBlack;
        for (int i = 0; i < pontos.size(); i++) {
            xVp = pontos[i].xW2Vp(mundo, vp);
            yVp = pontos[i].yW2Vp(mundo, vp);

            if (i == 0)
                canvas->MoveTo(xVp, yVp);
            else
                canvas->LineTo(xVp, yVp);
        }

    }

    else if (tipoReta == 1)
    {
        canvas->Pen->Color = clRed;
        for (int i = 0; i < pontos.size() - 1; i++) {
            xVp = pontos[i].xW2Vp(mundo, vp);
            yVp = pontos[i].yW2Vp(mundo, vp);

            xVp2 = pontos[i + 1].xW2Vp(mundo, vp);
            yVp2 = pontos[i + 1].yW2Vp(mundo, vp);
            canvas->Pen->Color = clRed;
            //DDA
        }

    } else {
        canvas->Pen->Color = clBlue;
        //Brasenham
    }
}

AnsiString Poligono::toString()
{
    return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()) +
           " pontos";
}

