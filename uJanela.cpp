//---------------------------------------------------------------------------

#pragma hdrstop

#include "uJanela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	Janela::Janela (double nxMin, double nyMin, double nxMax, double nyMax) {
		xMin = nxMin;
		xMax = nxMax;
		yMin = nyMin;
		yMax = nyMax;
	}

	Janela::Janela (){
		xMin = yMin = xMax = yMax = 0;
	}
