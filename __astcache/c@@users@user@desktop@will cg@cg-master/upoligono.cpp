﻿//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPoligono.h"
#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define PI 3.14159265
#include <Dialogs.hpp>
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
    int xVp, yVp, xVp2, yVp2, length, dx, dy;
    double deltaX, deltaY, x, y;
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
    if (tipo != 'C') {
        if (tipoReta == 0) {
            moveToLineTo(canvas, mundo, vp);
        } else if (tipoReta == 1) {
            dda(canvas, mundo, vp);
        } else {
            bresenham(canvas, mundo, vp);
        }
    } else {
        for (int i = 0; i < pontos.size(); i++) {
            int xVp, yVp;
            xVp = pontos[i].xW2Vp(mundo, vp);
            yVp = pontos[i].yW2Vp(mundo, vp);
            //            canvas->Pixels[xVp][yVp] = clBlue;
            canvas->Brush->Color = clBlack;
            canvas->Ellipse(Rect(xVp - 4, yVp - 4, xVp + 4, yVp + 4));
        }
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
void Poligono::desenhaCircunferencia(TCanvas* canvas, Janela mundo, Janela vp,
    int xCentral, int yCentral, int raio)
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
void Poligono::translacao(double dx, double dy)
{
    for (int i = 0; i < pontos.size(); i++) {
        pontos[i].x += dx;
        pontos[i].y += dy;
    }
}
void Poligono::escalonamento(double sx, double sy)
{
    double dx = calcularCentroPoligonoX();
    double dy = calcularCentroPoligonoY();
    Poligono::translacao(-dx, -dy);
    for (int i = 0; i < pontos.size(); i++) {
        pontos[i].x *= sx;
        pontos[i].y *= sy;
    }
    Poligono::translacao(dx, dy);
}
void Poligono::rotacao(double grau)
{
    double dx = calcularCentroPoligonoX();
    double dy = calcularCentroPoligonoY();
    double x, y, radianos;
    radianos = (grau * PI) / 180;
    double translacaoAoCentro[3][3] = { { 1, 0, 0 }, { 0, 1, 0 },
        { -dx, -dy, 1 } };
    double rotacao[3][3] = { { cos(radianos), -sin(radianos), 0 },
        { sin(radianos), cos(radianos), 0 }, { 0, 0, 1 } };
    double translacaoAPosicaoOriginal[3][3] = { { 1, 0, 0 }, { 0, 1, 0 },
        { dx, dy, 1 } };

    for (int index = 0; index < pontos.size(); index++) {
        double matrizTranslacaoRotacao[3][3] = {};
        double matrizRotacaoTranslacao[3][3] = {};
        double arrayPonto[3] = { pontos[index].x, pontos[index].y, 1 };
        double arrayAux[3] = {};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrizTranslacaoRotacao[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    matrizTranslacaoRotacao[i][j] +=
                        translacaoAoCentro[i][k] * rotacao[k][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrizRotacaoTranslacao[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    matrizRotacaoTranslacao[i][j] +=
                        matrizTranslacaoRotacao[i][k] *
                        translacaoAPosicaoOriginal[k][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arrayAux[i] += matrizRotacaoTranslacao[j][i] * arrayPonto[j];
            }
        }
        pontos[index].x = arrayAux[0] / arrayAux[2];
        pontos[index].y = arrayAux[1] / arrayAux[2];
    }

    /*
				Poligono::translacao(-dx, -dy);
    			for (int i = 0; i < pontos.size(); i++) {
    				x = pontos[i].x;
    				y = pontos[i].y;
    				pontos[i].x = x * cos(radianos) - y * sin(radianos);
    				pontos[i].y = x * sin(radianos) + y * cos(radianos);
    			}
    				Poligono::translacao(dx, dy);

*/
}
void Poligono::reflexao(int x, int y)
{
    if (x == 1 && y == 1) {
        for (int i = 0; i < pontos.size(); i++) {
            pontos[i].x *= -1;
            pontos[i].y *= -1;
        }
    } else if (x == 1) {
        for (int i = 0; i < pontos.size(); i++) {
            pontos[i].x *= -1;
        }
    } else if (y == 1) {
        for (int i = 0; i < pontos.size(); i++) {
            pontos[i].y *= -1;
        }
    }
}
double Poligono::calcularCentroPoligonoX()
{
    double centroX = 0;
    for (int i = 0; i < pontos.size(); i++) {
        centroX += pontos[i].x;
    }
    return (centroX / pontos.size());
}
double Poligono::calcularCentroPoligonoY()
{
    double centroY = 0;
    for (int i = 0; i < pontos.size(); i++) {
        centroY += pontos[i].y;
    }
    return (centroY / pontos.size());
}
AnsiString Poligono::toString()
{
    return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()) +
           " pontos";
}


