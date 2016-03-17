#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double valorAbsoluto(double x)
{
    return x < 0.0 ? -x : x;
}

double Erp(double xb, double xa)
{
    return valorAbsoluto((xb - xa)/xb)*100.0;
}

template<typename Func1, typename Func2>
double newtonRaphson(double x0, Func1 &f, Func2 &fp)
{
    return x0 - f(x0)/fp(x0);
}

int main()
{
    cout << setprecision(9) << fixed;

    int iteracion = 1;
    double xiAnterior = 0.0;
    double xi = 2; // AJUSTA VALOR DE INICIO
    double erp = 0.0;
    double evaluacion = 0.0;

    // AJUSTA FUNCIÓN Y DERIVADA DE LA FUNCIÓN
    auto f = [&](double x) {
        return x*x*x-7.0*x+7.0;
    };
    auto fPrima = [&](double x) {
        return 3.0*x*x-7.0;
    };

    do {
        evaluacion = newtonRaphson(xi, f, fPrima);
        erp = Erp(xi, xiAnterior);

        cout << iteracion << "|";
        cout << xi << "|";
        cout << evaluacion << "|";
        cout << erp << endl;

        ++iteracion;
        xiAnterior = xi;
        xi = evaluacion;
        system("pause>nul");
    } while (true);
    return 0;
}
