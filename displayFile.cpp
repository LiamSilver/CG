//---------------------------------------------------------------------------
#pragma hdrstop

#include "displayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void displayFile::mostra(TListBox* lbx)
{
    lbx->Items->Clear();

    for (int i = 0; i < poligonos.size(); i++) {
        lbx->Items->Add(poligonos[i].toString());
    }
}

void displayFile::desenha(
    TCanvas* canvas, Janela mundo, Janela vp, int tipoReta)
{
    canvas->Brush->Color = clSilver;
    canvas->FillRect(Rect(0, 0, 500, 500));

    canvas->Pen->Color = clBlack;
    canvas->Pen->Width = 2;

    for (int i = 0; i < poligonos.size(); i++) {
        poligonos[i].desenha(canvas, mundo, vp, tipoReta);
    }
}

void displayFile::clipping(Janela clipping, int** contId)
{
    int tamanho = poligonos.size();

    for (int i = 3; i < tamanho; i++) {
        Poligono* pol = new Poligono();

        if (poligonos[i].tipo != 'R')
            poligonos[i].clipping(clipping, &pol);

        if (pol->pontos.size() > 0) {
            pol->tipo = 'R';
            pol->id = (**contId)++;
            poligonos.push_back(*pol);
        }
        delete pol;
    }
}

