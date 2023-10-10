//---------------------------------------------------------------------------
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

void Poligono::clipping(Janela clipping, Poligono** pol)
{
    Poligono* aux = *pol;
    Ponto pontoAux;
    for (int i = 0; i < pontos.size() - 1; i++) {
        int cohen1 = pontos[i].calcularCohen(clipping);
        int cohen2 = pontos[i + 1].calcularCohen(clipping);

        if (cohen1 == 0 && cohen2 == 0) {
            aux->pontos.push_back(pontos[i]);
            aux->pontos.push_back(pontos[i + 1]);
        } else if ((cohen1 & cohen2) == 0) {
            double m = (pontos[i + 1].y - pontos[i].y) /
                       (pontos[i + 1].x - pontos[i].x);
            double xInterseccao, yInterseccao;

            if (cohen1 == 0) {
                aux->pontos.push_back(pontos[i]);
            } else {
                pontoAux = calculaInterseccao(
                    clipping, cohen1, pontos[i].x, pontos[i].y, m);
                //				if (pontoAux.calcularCohen(clipping) == 0)
                aux->pontos.push_back(pontoAux);
            }

            if (cohen2 == 0) {
                aux->pontos.push_back(pontos[i + 1]);
            } else {
                pontoAux = calculaInterseccao(
                    clipping, cohen2, pontos[i + 1].x, pontos[i + 1].y, m);

                //                if (pontoAux.calcularCohen(clipping) == 0)
                aux->pontos.push_back(pontoAux);
            }
        }
    }
}

Ponto Poligono::calculaInterseccao(
    Janela clipping, int cohen, int x, int y, double m)
{
    Ponto pontoAux;
    if (cohen & 8) {
        pontoAux.x = x + pow(m, -1) * (clipping.yMax - y);
        pontoAux.y = clipping.yMax;
    } else if (cohen & 4) {
        pontoAux.x = x + pow(m, -1) * (clipping.yMin - y);
        pontoAux.y = clipping.yMin;
    } else if (cohen & 1) {
        pontoAux.x = clipping.xMin;
        pontoAux.y = y + m * (clipping.xMin - x);
    } else if (cohen & 2) {
        pontoAux.x = clipping.xMax;
        pontoAux.y = y + m * (clipping.xMax - x);
    }

    return pontoAux;
}

void Poligono::casteljau(Poligono** pol)
{
    Ponto p0 = (*pol)->pontos[0], p1 = (*pol)->pontos[1],
          p2 = (*pol)->pontos[2];

    pontos.push_back(p0);

    casteljauRecursivo(p0, p1, p2);
}

void Poligono::casteljauRecursivo(Ponto p0, Ponto p1, Ponto p2)
{
    double dx, dy, diferenca;
    dx = pow((p2.x - p0.x), 2);
    dy = pow((p2.y - p0.y), 2);
    diferenca = sqrt(dx + dy);

    if (diferenca < 1) {
        pontos.push_back(p2);
    }

    else
    {
        Ponto a, b, c;
        a = calculaPontoMedio(p0, p1);
        b = calculaPontoMedio(p1, p2);
        c = calculaPontoMedio(a, b);

        casteljauRecursivo(p0, a, c);
        casteljauRecursivo(c, b, p2);
    }
}

void Poligono::hermite(Poligono** pol)
{
    Ponto aux;
    double matrizHermite[4][4] = { { 2, -2, 1, 1 }, { -3, 3, -2, -1 },
        { 0, 0, 1, 0 }, { 1, 0, 0, 0 } };

    double vetorGeometriaX[4] = { 0, 0, 0, 0 };
    vetorGeometriaX[0] = (*pol)->pontos[0].x;
    vetorGeometriaX[1] = (*pol)->pontos[3].x;
	vetorGeometriaX[2] = 3*((*pol)->pontos[1].x - (*pol)->pontos[0].x);
	vetorGeometriaX[3] = 3*((*pol)->pontos[3].x - (*pol)->pontos[2].x);

	double vetorGeometriaY[4] = { 0, 0, 0, 0 };
	vetorGeometriaY[0] = (*pol)->pontos[0].y;
	vetorGeometriaY[1] = (*pol)->pontos[3].y;
	vetorGeometriaY[2] = 3*((*pol)->pontos[1].y - (*pol)->pontos[0].y);
	vetorGeometriaY[3] = 3*((*pol)->pontos[3].y - (*pol)->pontos[2].y);

	double coeficienteX[4];
	double coeficienteY[4];

	for (int i = 0; i < 4; i++) {
		coeficienteX[i] = 0;
		coeficienteY[i] = 0;
		for (int j = 0; j < 4; j++) {
			coeficienteX[i] += matrizHermite[i][j] * vetorGeometriaX[j];
			coeficienteY[i] += matrizHermite[i][j] * vetorGeometriaY[j];
		}
	}

	for (double t = 0; t <= 1; t += 0.01) {
		double array[4] = { pow(t, 3), pow(t, 2), t, 1 };

		aux.x = 0;
		aux.y = 0;
		//       double p1, p2, p3, p4;
		//       p1 = 2 * array[0] - 3 * array[1] + 1;
		//       p2 = -2 * array[0] + 3 * array[1];
		//       p3 = array[0] - 2 * array[1] + array[2];
		//      p4 = array[0] - array[2];

		for (int i = 0; i < 4; i++) {
			aux.x += coeficienteX[i] * array[i];
			aux.y += coeficienteY[i] * array[i];
		}

		//		aux.x = p1 * vetorGeometriaX[0] + p2 * vetorGeometriaX[1] +
		//				p3 * vetorGeometriaX[2] + p4 * vetorGeometriaX[3];
		//       aux.y = p1 * vetorGeometriaY[0] + p2 * vetorGeometriaY[1] +
		//               p3 * vetorGeometriaY[2] + p4 * vetorGeometriaY[3];
		pontos.push_back(aux);
	}
}

void Poligono::bezier(Poligono** pol)
{
	Ponto aux;

	double vetorGeometriaX[4] = { 0, 0, 0, 0 };
	vetorGeometriaX[0] = (*pol)->pontos[0].x;
	vetorGeometriaX[1] = (*pol)->pontos[1].x;
	vetorGeometriaX[2] = (*pol)->pontos[2].x;
	vetorGeometriaX[3] = (*pol)->pontos[3].x;

	double vetorGeometriaY[4] = { 0, 0, 0, 0 };
	vetorGeometriaY[0] = (*pol)->pontos[0].y;
	vetorGeometriaY[1] = (*pol)->pontos[1].y;
	vetorGeometriaY[2] = (*pol)->pontos[2].y;
	vetorGeometriaY[3] = (*pol)->pontos[3].y;

	for (double t = 0; t <= 1; t += 0.01) {
		double p1, p2, p3, p4;
		p1 = pow((1 - t), 3);
		p2 = 3 * t * pow((1 - t), 2);
		p3 = 3 * pow(t, 2) * (1 - t);
		p4 = pow(t, 3);

		aux.x = p1 * vetorGeometriaX[0] + p2 * vetorGeometriaX[1] +
				p3 * vetorGeometriaX[2] + p4 * vetorGeometriaX[3];
		aux.y = p1 * vetorGeometriaY[0] + p2 * vetorGeometriaY[1] +
				p3 * vetorGeometriaY[2] + p4 * vetorGeometriaY[3];
		pontos.push_back(aux);
	}
}

void Poligono::bSpline(Poligono** pol)
{
	Ponto aux;
	double coeficienteX[4], coeficienteY[4];

	double vetorGeometriaX[4] = { 0, 0, 0, 0 };
	vetorGeometriaX[0] = (*pol)->pontos[0].x;
	vetorGeometriaX[1] = (*pol)->pontos[1].x;
	vetorGeometriaX[2] = (*pol)->pontos[2].x;
	vetorGeometriaX[3] = (*pol)->pontos[3].x;

	double vetorGeometriaY[4] = { 0, 0, 0, 0 };
	vetorGeometriaY[0] = (*pol)->pontos[0].y;
	vetorGeometriaY[1] = (*pol)->pontos[1].y;
	vetorGeometriaY[2] = (*pol)->pontos[2].y;
	vetorGeometriaY[3] = (*pol)->pontos[3].y;

	double matrizBspline[4][4] = { { -1, 3, -3, 1 }, { 3, -6, 3, 0 },
		{ -3, 0, 3, 0 }, { 1, 4, 1, 0 } };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrizBspline[i][j] /= 6;
		}
	}

	for (int i = 0; i < 4; i++) {
		coeficienteX[i] = 0;
		coeficienteY[i] = 0;

		for (int j = 0; j < 4; j++) {
			coeficienteX[i] += vetorGeometriaX[j] * matrizBspline[i][j];
			coeficienteY[i] += vetorGeometriaX[j] * matrizBspline[i][j];
		}
	}

	for (double t = 0; t <= 1; t += 0.01) {
		double array[4] = { pow(1 - t, 3), 3 * pow(1 - t, 2) * t,
			3 * (1 - t) * pow(t, 2), pow(t, 3) };
		aux.x = 0;
		aux.y = 0;

		for (int i = 0; i < 4; i++) {
            aux.x += vetorGeometriaX[i] * array[i];
            aux.y += vetorGeometriaY[i] * array[i];
        }

        pontos.push_back(aux);
    }
}
Ponto Poligono::calculaPontoMedio(Ponto a, Ponto b)
{
    return Ponto((a.x + b.x) / 2, (a.y + b.y) / 2);
}

AnsiString Poligono::toString()
{
    return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()) +
           " pontos";
}

