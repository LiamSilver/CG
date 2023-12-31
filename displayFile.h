//---------------------------------------------------------------------------

#ifndef displayFileH
#define displayFileH
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <vector>
#include "uPoligono.cpp"
#include <Dialogs.hpp>

class displayFile{
	public:
		std::vector <Poligono> poligonos;

		 void mostra(TListBox* lbx);
		 void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta);
         void clipping(Janela clipping, int** contId);

};
//---------------------------------------------------------------------------
#endif
