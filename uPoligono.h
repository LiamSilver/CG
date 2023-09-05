//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <vector>
#include <uPonto.cpp>

class Poligono{
	public:
	  int id;
	  char tipo;
	  std::vector <Ponto> pontos;

      AnsiString toString();
	  void mostra(TListBox* lbx);
	  void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta);
};
//---------------------------------------------------------------------------
#endif
