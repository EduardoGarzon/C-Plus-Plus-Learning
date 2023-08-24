// Implementa a Sobrecarga de operadores usando fun��es friends

// Inclus�o de bibliotecas
#include <iostream>
using namespace std;

class Complexo
{
private:
    double real;
    double imaginario;

public:
    Complexo(double r = 0, double i = 0);
    void mostra();
    friend Complexo operator+(const Complexo &L, const Complexo &R);
    friend Complexo operator+(const Complexo &L, double R);
    friend Complexo operator+(double L, const Complexo &R);
};

// Defini��o dos m�todos da classe Complexo

Complexo::Complexo(double r, double i)
{
    real = r;
    imaginario = i;
}

void Complexo::mostra()
{
    cout << "(" << real << " + " << imaginario << "i)";
}

// Defini��o das fun��es friends

Complexo operator+(const Complexo &L, const Complexo &R)
{
    Complexo aux;
    aux.real = L.real + R.real;
    aux.imaginario = L.imaginario + R.imaginario;
    return aux;
}

Complexo operator+(const Complexo &L, double R)
{
    Complexo aux;
    aux.real = L.real + R;
    aux.imaginario = L.imaginario;
    return aux;
}

Complexo operator+(double L, const Complexo &R)
{
    Complexo aux;
    aux.real = L + R.real;
    aux.imaginario = R.imaginario;
    return aux;
}

int main()
{
    Complexo a(3.4, 4.5);
    Complexo b(5.6, 6.7);
    Complexo c, d, e;
    double f = 7.89;

    cout << "a = ";
    a.mostra();
    cout << endl;
  
    cout << "b = ";
    b.mostra();
    cout << endl;
  
    c = a + b;
    cout << "c = a + b > ";
    c.mostra();
    cout << endl;
  
    d = a + f;
    cout << "d = a + " << f << " > ";
    d.mostra();
    cout << endl;
  
    e = f + b;
    cout << "e = " << f << " + b > ";
    e.mostra();
    cout << endl;
  
    system("pause");
    
    return 0;
}
