//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uForm.h"
#include "uJanela.h"
#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ShowMessage(FloatToStr(mundo.xMin));
}
//---------------------------------------------------------------------------
