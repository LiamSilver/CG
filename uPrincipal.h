//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.NumberBox.hpp>
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
	TButton *btnEsquerda;
	TButton *btnDireita;
	TButton *btnCima;
	TButton *btnBaixo;
	TButton *btnZoomIn;
	TButton *btnZoomOut;
	TRadioGroup *rgTipoReta;
	TButton *btnCircunferencia;
	TButton *btnTranslacao2D;
	TButton *btnEscalonamento;
	TButton *btnRotacao;
	TButton *btnReflexao;
	TButton *btnClipping;
	TButton *btnBezier;
	TButton *btnCasteljau;
	TButton *btnHermite;
	TButton *btnBspline;
	TButton *btnResetarPoligonos;
	TButton *btnLerCubo;
	TButton *btnLerPiramide;
	TButton *btnTranslacao3d;
	TButton *btnEscalonamento3d;
	TButton *btnRotacaoX;
	TButton *btnRotacaoY;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btnPoligonoClick(TObject *Sender);
	void __fastcall btnAtualizaMundoClick(TObject *Sender);
	void __fastcall lbPoligonosClick(TObject *Sender);
	void __fastcall btnEsquerdaClick(TObject *Sender);
	void __fastcall btnDireitaClick(TObject *Sender);
	void __fastcall btnCimaClick(TObject *Sender);
	void __fastcall btnBaixoClick(TObject *Sender);
	void __fastcall btnZoomInClick(TObject *Sender);
	void __fastcall btnZoomOutClick(TObject *Sender);
	void __fastcall rgTipoRetaClick(TObject *Sender);
	void __fastcall btnCircunferenciaClick(TObject *Sender);
	void __fastcall btnTranslacao2DClick(TObject *Sender);
	void __fastcall btnEscalonamentoClick(TObject *Sender);
	void __fastcall btnRotacaoClick(TObject *Sender);
	void __fastcall btnReflexaoClick(TObject *Sender);
	void __fastcall btnClippingClick(TObject *Sender);
	void __fastcall btnCasteljauClick(TObject *Sender);
	void __fastcall btnHermiteClick(TObject *Sender);
	void __fastcall btnBezierClick(TObject *Sender);
	void __fastcall btnBsplineClick(TObject *Sender);
	void __fastcall btnResetarPoligonosClick(TObject *Sender);
	void __fastcall btnLerCuboClick(TObject *Sender);
	void __fastcall btnLerPiramideClick(TObject *Sender);
	void __fastcall btnTranslacao3dClick(TObject *Sender);
	void __fastcall btnEscalonamento3dClick(TObject *Sender);
	void __fastcall btnRotacaoXClick(TObject *Sender);
	void __fastcall btnRotacaoYClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
