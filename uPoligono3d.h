//---------------------------------------------------------------------------

#ifndef uPoligono3dH
#define uPoligono3dH

//---------------------------------------------------------------------------

class Poligono3d : public Poligono
{
  public:
    std::vector<Ponto3d> pontos;

    void translacao(double dx, double dy, double dz);
};
#endif

