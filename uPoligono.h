//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <vector>
#include <uPonto.cpp>
#include <cmath>

class Poligono
{
  public:
    int id;
    char tipo;
    std::vector<Ponto> pontos;

    AnsiString toString();
    void mostra(TListBox* lbx);
	void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta);
	void desenhaCircunferencia(
		TCanvas* canvas, Janela mundo, Janela vp, int xCentral, int yCentral, int raio);
	void desenhaPontoCircunferencia(int xCentral, int yCentral, int x, int y);

	void moveToLineTo(TCanvas* canvas, Janela mundo, Janela vp);
	void dda(TCanvas* canvas, Janela mundo, Janela vp);
	void bresenham(TCanvas* canvas, Janela mundo, Janela vp);
	//TranslatarOsPontosDoPoligono
};
//---------------------------------------------------------------------------
#endif

