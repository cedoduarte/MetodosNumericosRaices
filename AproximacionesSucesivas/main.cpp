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

int main()
{
    cout << setprecision(9) << fixed;

    // despejando x en modo de raíces, etc...
    // PONER FUNCIÓN AQUÍ
    auto xFunc = [&](double x0) {
        return pow(7.0*x0-7.0, 1.0/3.0);
    };

    int iteracion = 1;
    double xiAnterior = 0.0;
    double xi = 2.0; // AJUSTA VALOR DE INICIO
    double erp = 0.0;
    double evaluacion = 0.0;
    do {
        evaluacion = xFunc(xi);
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
