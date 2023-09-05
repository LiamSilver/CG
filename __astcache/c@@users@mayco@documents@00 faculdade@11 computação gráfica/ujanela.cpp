//---------------------------------------------------------------------------

#pragma hdrstop

#include "uJanela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	Janela::Janela (double nxMin, double nxMax, double nyMin, double nyMax) {
		xMin = nxMin;
		xMax = nxMax;
		yMin = nyMin;
		yMax = nyMax;
	}

	Janela::Janela (){
		xMin = yMin = xMax = yMax = 0;
	}
