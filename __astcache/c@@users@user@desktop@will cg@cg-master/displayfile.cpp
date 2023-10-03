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

void displayFile::clipping(Janela clipping, int contId)
{
    for (int i = 0; i < poligonos.size() - 1; i++) {
        //	ShowMessage("teste");
        for (int j = 0; j < poligonos[i].pontos.size() - 1; j++) {
            if (poligonos[i].pontos[j].calcularCohen(clipping) == 0 &&
                poligonos[i].pontos[j + 1].calcularCohen(clipping) == 0)
            {
                Poligono pol;

                pol.tipo = 'R';
                pol.id = ++contId;

                pol.pontos.push_back(poligonos[i].pontos[j]);
                pol.pontos.push_back(poligonos[i].pontos[j + 1]);

                poligonos.push_back(pol);
            }
        }
    }
}

