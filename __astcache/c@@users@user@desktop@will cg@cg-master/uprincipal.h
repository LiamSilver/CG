﻿//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *lbVp;
	TLabel *lbW;
	TListBox *lbxPontos;
	TButton *btnPoligono;
	TLabel *lblPontos;
	TListBox *lbPoligonos;
	TLabel *lblPoligono;
	TEdit *edXmin;
	TEdit *edXmax;
	TEdit *edYmax;
	TEdit *edYmin;
	TLabel *lblXmin;
	TLabel *lblYmin;
	TLabel *lblXmax;
	TLabel *lblYmax;
	TButton *btnAtualizaMundo;
	TButton *btnPrimeiroQuadrante;
	TButton *btnSegundoQuadrante;
	TButton *btnTerceiroQuadrante;
	TButton *btnQuartoQuadrante;
	TButton *btnZoomIn;
	TButton *btnZoomOut;
	TRadioGroup *rgTipoReta;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btnPoligonoClick(TObject *Sender);
	void __fastcall btnAtualizaMundoClick(TObject *Sender);
	void __fastcall lbPoligonosClick(TObject *Sender);
	void __fastcall btnPrimeiroQuadranteClick(TObject *Sender);
	void __fastcall btnSegundoQuadranteClick(TObject *Sender);
	void __fastcall btnTerceiroQuadranteClick(TObject *Sender);
	void __fastcall btnQuartoQuadranteClick(TObject *Sender);
	void __fastcall btnZoomInClick(TObject *Sender);
	void __fastcall btnZoomOutClick(TObject *Sender);
	void __fastcall rgTipoRetaClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
