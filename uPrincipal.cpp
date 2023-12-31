//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "uJanela.h"
#include "uPrincipal.h"
#include "uPonto.h"
#include "uPoligono.h"
#include "displayFile.h"
#include <Dialogs.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal* frmPrincipal;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);
Janela clipping(mundo.xMin / 2, mundo.yMin / 2, mundo.xMax / 2, mundo.yMax / 2);

Ponto aux;
Poligono pol;
displayFile display;
bool inicia = false;
bool isCircunferencia = false;
int contId = 0;
int raio = 0;

double xVp2W(int x, Janela mundo, Janela vp)
{
    return ((x - vp.xMin) / (vp.xMax - vp.xMin)) * (mundo.xMax - mundo.xMin) +
           mundo.xMin;
}
double yVp2W(int y, Janela mundo, Janela vp)
{
    return (1 - (y - vp.xMin) / (vp.yMax - vp.yMin)) *
               (mundo.yMax - mundo.yMin) +
           mundo.yMin;
}
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    //Inserindo o eixo vertical
    pol.tipo = 'E';
    pol.id = contId++;
    pol.pontos.push_back(Ponto(0, mundo.yMax));
    //	Image1->Canvas->MoveTo(250,0);
    pol.pontos.push_back(Ponto(0, mundo.yMin));
    //	Image1->Canvas->LineTo(250,500);
    display.poligonos.push_back(pol);
    pol.pontos.clear();
    //Inserindo o eixo horizontal
    pol.tipo = 'E';
    pol.id = contId++;
    pol.pontos.push_back(Ponto(mundo.xMin, 0));
    //	Image1->Canvas->MoveTo(0,250);
    pol.pontos.push_back(Ponto(mundo.xMax, 0));
    //	Image1->Canvas->LineTo(500,250);
    display.poligonos.push_back(pol);
    pol.pontos.clear();

    pol.tipo = 'R';
    pol.id = contId++;

    pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMin));
    pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMax));
    pol.pontos.push_back(Ponto(clipping.xMax, clipping.yMax));
    pol.pontos.push_back(Ponto(clipping.xMax, clipping.yMin));
    pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMin));
    display.poligonos.push_back(pol);
    pol.pontos.clear();

    display.mostra(lbPoligonos);
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::Image1MouseMove(
    TObject* Sender, TShiftState Shift, int X, int Y)
{
    double xw, yw;
    xw = xVp2W(X, mundo, vp);
    yw = yVp2W(Y, mundo, vp);
    lbVp->Caption = "(" + IntToStr(X) + ", " + IntToStr(Y) + ")";
    lbW->Caption = "(" + FloatToStr(xw) + ", " + FloatToStr(yw) + ")";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Image1MouseDown(
    TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (isCircunferencia) {
        inicia = false;
        isCircunferencia = false;

        pol.id = contId++;
        pol.tipo = 'C';

        aux.x = xVp2W(X, mundo, vp);
        aux.y = yVp2W(Y, mundo, vp);
        pol.desenhaCircunferencia(
            Image1->Canvas, mundo, vp, aux.x, aux.y, raio);
        display.poligonos.push_back(pol);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        pol.pontos.clear();
    } else if (inicia) {
        if (Button == mbRight) {
            inicia = false;
            pol.id = contId++;
            pol.tipo = 'P';
            display.poligonos.push_back(pol);
            display.mostra(lbPoligonos);
            display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
            pol.pontos.clear();
        } else {
            aux.x = xVp2W(X, mundo, vp);
            aux.y = yVp2W(Y, mundo, vp);
            pol.pontos.push_back(aux);
            pol.mostra(lbxPontos);
            pol.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnPoligonoClick(TObject* Sender)
{
    inicia = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnAtualizaMundoClick(TObject* Sender)
{
    mundo.xMin = StrToFloat(edXmin->Text);
    mundo.xMax = StrToFloat(edXmax->Text);
    mundo.yMin = StrToFloat(edYmin->Text);
    mundo.yMax = StrToFloat(edYmax->Text);
    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::lbPoligonosClick(TObject* Sender)
{
    display.poligonos[lbPoligonos->ItemIndex].mostra(lbxPontos);
}

void atualizaEixos()
{
    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnEsquerdaClick(TObject* Sender)
{
    mundo.xMax -= 10;
    mundo.xMin -= 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnDireitaClick(TObject* Sender)
{
    mundo.xMax += 10;
    mundo.xMin += 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnCimaClick(TObject* Sender)
{
    mundo.yMax += 10;
    mundo.yMin += 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnBaixoClick(TObject* Sender)
{
    mundo.yMax -= 10;
    mundo.yMin -= 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnZoomInClick(TObject* Sender)
{
    mundo.xMax -= 10;
    mundo.xMin += 10;
    mundo.yMax -= 10;
    mundo.yMin += 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnZoomOutClick(TObject* Sender)
{
    mundo.xMax += 10;
    mundo.xMin -= 10;
    mundo.yMax += 10;
    mundo.yMin -= 10;
    atualizaEixos();
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::rgTipoRetaClick(TObject* Sender)
{
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnCircunferenciaClick(TObject* Sender)
{
    if (inicia) {
        UnicodeString sRaio;
        InputQuery("Digite o raio da circunfer�ncia", "Digite o raio: ", sRaio);

        raio = StrToInt(sRaio);

        isCircunferencia = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnTranslacao2DClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usNovoX, usNovoY;
        double x, y;

        InputQuery("Digite o movimento de x", "x: ", usNovoX);
        InputQuery("Digite o movimento de y", "y: ", usNovoY);

        x = StrToFloat(usNovoX);
        y = StrToFloat(usNovoY);

        display.poligonos[lbPoligonos->ItemIndex].translacao(x, y);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel transladar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnEscalonamentoClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usNovoX, usNovoY;
        double x, y;

        InputQuery("Digite o escalonamento de x", "x: ", usNovoX);
        InputQuery("Digite o escalonamento de y", "y: ", usNovoY);

        x = StrToFloat(usNovoX);
        y = StrToFloat(usNovoY);

        display.poligonos[lbPoligonos->ItemIndex].escalonamento(x, y);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel escalonar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnRotacaoClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usGrau;
        double grau;

        InputQuery("Digite o grau de rota��o", "grau: ", usGrau);

        grau = StrToFloat(usGrau);

        display.poligonos[lbPoligonos->ItemIndex].rotacao(grau);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel rotacionar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnReflexaoClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usReflexaoX, usReflexaoY;
        double x, y;

        InputQuery("Digite um n�mero",
            " Digite 1 se voc� quer reflex�o em x \n Digite qualquer outro n�mero se n�o quiser: ",
            usReflexaoX);
        InputQuery("Digite um n�mero",
            "Digite 1 se voc� quer reflex�o em y \n Digite qualquer outro n�mero se n�o quiser: ",
            usReflexaoY);

        x = StrToFloat(usReflexaoX);
        y = StrToFloat(usReflexaoY);

        display.poligonos[lbPoligonos->ItemIndex].reflexao(x, y);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel fazer reflex�o no eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnClippingClick(TObject* Sender)
{
    int* contador = &contId;
    display.clipping(clipping, &contador);
    display.mostra(lbPoligonos);
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnCasteljauClick(TObject* Sender)
{
    if (display.poligonos[lbPoligonos->ItemIndex].pontos.size() == 3 &&
        display.poligonos[lbPoligonos->ItemIndex].tipo != 'E')
    {
        Poligono* polAux = new Poligono();
        polAux = &display.poligonos[lbPoligonos->ItemIndex];
        pol.id = contId++;
        pol.tipo = 'A';
        pol.casteljau(&polAux);
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    } else {
        ShowMessage("Selecione um poligono com 3 pontos");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnHermiteClick(TObject* Sender)
{
    if (display.poligonos[lbPoligonos->ItemIndex].pontos.size() == 4 &&
        display.poligonos[lbPoligonos->ItemIndex].tipo != 'E')
    {
        Poligono* polAux = new Poligono();
        polAux = &display.poligonos[lbPoligonos->ItemIndex];
        pol.id = contId++;
        pol.tipo = 'H';
        pol.hermite(&polAux);
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    } else {
        ShowMessage("Selecione um poligono com 4 pontos");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnBezierClick(TObject* Sender)
{
    if (display.poligonos[lbPoligonos->ItemIndex].pontos.size() == 4 &&
        display.poligonos[lbPoligonos->ItemIndex].tipo != 'E')
    {
        Poligono* polAux = new Poligono();
        polAux = &display.poligonos[lbPoligonos->ItemIndex];
        pol.id = contId++;
        pol.tipo = 'B';
        pol.bezier(&polAux);
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    } else {
        ShowMessage("Selecione um poligono com 4 pontos");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnBsplineClick(TObject* Sender)
{
    if (display.poligonos[lbPoligonos->ItemIndex].pontos.size() == 4 &&
        display.poligonos[lbPoligonos->ItemIndex].tipo != 'E')
    {
        Poligono* polAux = new Poligono();
        polAux = &display.poligonos[lbPoligonos->ItemIndex];
        pol.id = contId++;
        pol.tipo = 'S';
        pol.bSpline(&polAux);
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    } else {
        ShowMessage("Selecione um poligono com 4 pontos");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnResetarPoligonosClick(TObject* Sender)
{
    contId = 3;
    display.poligonos.erase(
        display.poligonos.begin() + 3, display.poligonos.end());
    display.mostra(lbPoligonos);
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnLerCuboClick(TObject* Sender)
{
    double valor;
    std::ifstream arquivo("../../Cubo.txt");

    if (arquivo.is_open()) {
        while (arquivo >> valor) {
            aux.x = valor;

            arquivo >> valor;

            aux.y = valor;

            arquivo >> valor;
            aux.z = valor;

            pol.pontos.push_back(aux);
        }

        arquivo.close();
    }

    else
    {
        ShowMessage("N�o foi poss�vel abrir o arquivo");
    }

    pol.tipo = 'P';
    pol.id = contId++;

    display.poligonos.push_back(pol);
    display.mostra(lbPoligonos);
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    pol.pontos.clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnLerPiramideClick(TObject* Sender)
{
    double valor;
    std::ifstream arquivo("../../Piramide.txt");

    if (arquivo.is_open()) {
        while (arquivo >> valor) {
            aux.x = valor;

            arquivo >> valor;

            aux.y = valor;

            arquivo >> valor;
            aux.z = valor;

            pol.pontos.push_back(aux);
        }

        arquivo.close();
    }

    else
    {
        ShowMessage("N�o foi poss�vel abrir o arquivo");
    }

    pol.tipo = 'P';
    pol.id = contId++;

    display.poligonos.push_back(pol);
    display.mostra(lbPoligonos);
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    pol.pontos.clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnTranslacao3dClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usNovoX, usNovoY, usNovoZ;
        double x, y, z;

        InputQuery("Digite o movimento de x", "x: ", usNovoX);
        InputQuery("Digite o movimento de y", "y: ", usNovoY);
        InputQuery("Digite o movimento de z", "z: ", usNovoZ);

        x = StrToFloat(usNovoX);
        y = StrToFloat(usNovoY);
        z = StrToFloat(usNovoZ);

        display.poligonos[lbPoligonos->ItemIndex].translacao(x, y, z);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel transladar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnEscalonamento3dClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usNovoX, usNovoY, usNovoZ;
        double x, y, z;

        InputQuery("Digite o escalonamento de x", "x: ", usNovoX);
        InputQuery("Digite o escalonamento de y", "y: ", usNovoY);
        InputQuery("Digite o escalonamento de z", "z: ", usNovoZ);

        x = StrToFloat(usNovoX);
        y = StrToFloat(usNovoY);
        z = StrToFloat(usNovoZ);

        display.poligonos[lbPoligonos->ItemIndex].escalonamento(x, y, z);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel escalonar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnRotacaoXClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
        UnicodeString usGrau;
        double grau;

        InputQuery("Digite o grau de rota��o em X", "grau: ", usGrau);

        grau = StrToFloat(usGrau);

        display.poligonos[lbPoligonos->ItemIndex].rotacao(grau, 1);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel rotacionar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnRotacaoYClick(TObject* Sender)
{
    if (lbPoligonos->ItemIndex > 1) {
		UnicodeString usGrau;
        double grau;

        InputQuery("Digite o grau de rota��o em Y", "grau: ", usGrau);

        grau = StrToFloat(usGrau);

        display.poligonos[lbPoligonos->ItemIndex].rotacao(grau, 2);
        display.mostra(lbPoligonos);
        display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    } else if (lbPoligonos->ItemIndex == 0 || lbPoligonos->ItemIndex == 1) {
        ShowMessage("N�o � possivel rotacionar o eixo");
    } else {
        ShowMessage("Selecione um poligono primeiro");
    }
}
//---------------------------------------------------------------------------

