//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <vector>
#include <uPonto.cpp>
#include <cmath>

class Poligono
{
  public:
    int id;
    char tipo;
    std::vector<Ponto> pontos;

    AnsiString toString();
    void mostra(TListBox* lbx);
    void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta);
    void desenhaCircunferencia(TCanvas* canvas, Janela mundo, Janela vp,
        int xCentral, int yCentral, int raio);
    void desenhaPontoCircunferencia(int xCentral, int yCentral, int x, int y);

    void moveToLineTo(TCanvas* canvas, Janela mundo, Janela vp);
    void dda(TCanvas* canvas, Janela mundo, Janela vp);
    void bresenham(TCanvas* canvas, Janela mundo, Janela vp);

    void translacao(double dx, double dy);
	void translacao(double dx, double dy, double dz);

	void escalonamento(double sx, double sy);
	void escalonamento(double sx, double sy, double dz);

	void rotacao(double grau);
	void rotacao(double grau, int op);


	void reflexao(int x, int y);

	double calcularCentroPoligonoX();
	double calcularCentroPoligonoY();
    double calcularCentroPoligonoZ();

	void casteljau(Poligono** pol);
    void casteljauRecursivo(Ponto p0, Ponto p1, Ponto p2);

    void hermite(Poligono** pol);
	void bezier(Poligono** pol);
	void bSpline(Poligono** pol);

    Ponto calculaPontoMedio(Ponto a, Ponto b);
    void clipping(Janela clipping, Poligono** pol);
    Ponto calculaInterseccao(
		Janela clipping, int cohen, int x, int y, double m);

	bool verificaPonto(Ponto aux, Poligono* pol);
};
//---------------------------------------------------------------------------
#endif

