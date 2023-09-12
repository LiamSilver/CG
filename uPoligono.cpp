//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPoligono.h"
#define SIGN(x) ((x) < 0 ? (-1) : (1))
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::mostra(TListBox* lbx)
{
    lbx->Items->Clear();

    for (int x = 0; x < pontos.size(); x++) {
        lbx->Items->Add(pontos[x].mostra());
    }
}

void Poligono::moveToLineTo(TCanvas* canvas, Janela mundo, Janela vp)
{
    canvas->Pen->Color = clBlack;
    int xVp, yVp;
    for (int i = 0; i < pontos.size(); i++) {
        xVp = pontos[i].xW2Vp(mundo, vp);
        yVp = pontos[i].yW2Vp(mundo, vp);

        if (i == 0)
            canvas->MoveTo(xVp, yVp);
        else
            canvas->LineTo(xVp, yVp);
    }
}

void Poligono::dda(TCanvas* canvas, Janela mundo, Janela vp)
{
    int xVp, yVp, xVp2, yVp2, length, x, y, dx, dy;
    double deltaX, deltaY;

    for (int i = 0; i < pontos.size() - 1; i++) {
        xVp = pontos[i].xW2Vp(mundo, vp);
        yVp = pontos[i].yW2Vp(mundo, vp);
        xVp2 = pontos[i + 1].xW2Vp(mundo, vp);
        yVp2 = pontos[i + 1].yW2Vp(mundo, vp);

        dx = xVp2 - xVp;
        dy = yVp2 - yVp;

        if (abs(dx) >= abs(dy))
            length = abs(dx);
        else
            length = abs(dy);

        deltaX = (double)(dx) / (double)(length);
        deltaY = (double)(dy) / (double)(length);

        x = xVp + 0.5 * SIGN(deltaX);
        y = yVp + 0.5 * SIGN(deltaY);

        for (int j = 0; j < length; j++) {
            canvas->Pixels[floor(x)][floor(y)] = clRed;
            x += deltaX;
            y += deltaY;
        }
    }
}

void Poligono::bresenham(TCanvas* canvas, Janela mundo, Janela vp)
{
    int xVp, yVp, xVp2, yVp2, length, x, y, dx, dy, e;
    double deltaX, deltaY;

    for (int i = 0; i < pontos.size() - 1; i++) {
        xVp = pontos[i].xW2Vp(mundo, vp);
        yVp = pontos[i].yW2Vp(mundo, vp);
        xVp2 = pontos[i + 1].xW2Vp(mundo, vp);
        yVp2 = pontos[i + 1].yW2Vp(mundo, vp);

        dx = abs((xVp2 - xVp));
        dy = abs((yVp2 - yVp));
        int sx = SIGN((xVp2 - xVp));
        int sy = SIGN((yVp2 - yVp));
        x = xVp;
        y = yVp;

        e = dx - dy;

        while (true) {
            canvas->Pixels[xVp][yVp] = clBlue;

            if (xVp == xVp2 && yVp == yVp2)
                break;

            int e2 = 2 * e;

            if (e2 > -dy) {
                e -= dy;
                xVp += sx;
            }

            if (e2 < dx) {
                e += dx;
                yVp += sy;
            }
        }
    }
}
void Poligono::desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta)
{
    if (tipoReta == 0) {
        moveToLineTo(canvas, mundo, vp);
    }

    else if (tipoReta == 1)
    {
        dda(canvas, mundo, vp);

    } else {
        bresenham(canvas, mundo, vp);
    }
}

//Desenha Circunferencia
void Poligono::desenhaPontoCircunferencia(
    int xCentral, int yCentral, int x, int y)
{
	Ponto ponto1(xCentral + x, yCentral + y);
	Ponto ponto2(xCentral - x, yCentral + y);
	Ponto ponto3(xCentral + x, yCentral - y);
	Ponto ponto4(xCentral - x, yCentral - y);
	Ponto ponto5(xCentral + y, yCentral + x);
	Ponto ponto6(xCentral - y, yCentral + x);
	Ponto ponto7(xCentral + y, yCentral - x);
	Ponto ponto8(xCentral - y, yCentral - x);

	pontos.push_back(ponto1);
	pontos.push_back(ponto2);
	pontos.push_back(ponto3);
	pontos.push_back(ponto4);
	pontos.push_back(ponto5);
	pontos.push_back(ponto6);
	pontos.push_back(ponto7);
	pontos.push_back(ponto8);
}

void Poligono::desenhaCircunferencia(
	TCanvas* canvas, Janela mundo, Janela vp, int xCentral, int yCentral, int raio)
{
    int x = 0;
    int y = raio;

    desenhaPontoCircunferencia(xCentral, yCentral, x, y);
    int p = 1 - raio;

    while (x < y) {
        if (p < 0) {
            x++;
        } else {
            x++;
            y--;
        }

        if (p < 0) {
            p += 2 * x + 1;
        } else {
            p += 2 * (x - y) + 1;
            desenhaPontoCircunferencia(xCentral, yCentral, x, y);
        }
    }
}
AnsiString Poligono::toString()
{
    return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()) +
           " pontos";
}

