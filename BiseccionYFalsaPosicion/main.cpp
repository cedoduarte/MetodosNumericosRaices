#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

enum
{
    BISECCION = 1,
    FALSA_POSICION = 2
};

double valorAbsoluto(double x)
{
    return x < 0.0 ? -x : x;
}

double calculaErp(double xrNuevo, double xrAnterior)
{
    return valorAbsoluto((xrNuevo - xrAnterior)/xrNuevo)*100.0;
}

template<typename Func>
double calculaXr(int metodo, Func &f, double xi, double xs)
{
    if (metodo == BISECCION) {
        return (xi + xs)/2.0;
    }
    return xs-(f(xs)*(xi-xs))/(f(xi)-f(xs));
}

template<class Func>
void realizaAjustesXi_Xs(Func &f, double &xi, double &xs, double xr)
{
    double evaluacion = f(xi)*f(xr);
    if (evaluacion < 0.0) {
        xs = xr;
    } else if (evaluacion > 0.0) {
        xi = xr;
    }
}

template<typename Func>
void muestraTabla(Func &f, double xi, double xs, double paso)
{
    if (xi > xs) {
        double tmp = xi;
        xi = xs;
        xs = tmp;
    }
    for (double xp = xi; xp <= xs; xp += paso) {
        cout << xp << "|" << f(xp) << endl;
    }
    cout << endl;
}

int main()
{
    cout << setprecision(9) << fixed;

    // PONER FUNCIÓN AQUÍ
    auto f = [&](double x) {
        return x*x*x-7.0*x+7.0;
    };

    int iteracion = 1;
    double xi, xs, xr;
    double xrAnterior = 0.0;
    double erp;
    double paso;
    int opcion;

    cout << "Introduce 1 para BISECCION, 2 para FALSA POSICION: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "BISECCION" << endl;
    } else if (opcion == 2) {
        cout << "FALSA POSICION" << endl;
    } else {
        cout << "INTRODUCE DE NUEVO" << endl;
        return -1;
    }
    cout << "MOSTRAR TABLA PARA BUSCAR CAMBIO DE SIGNO" << endl;
    cout << "xi? ";
    cin >> xi;
    cout << "xs? ";
    cin >> xs;
    cout << "paso? ";
    cin >> paso;
    muestraTabla(f, xi, xs, paso);
    cout << "inserte xi y xs para el metodo: ";
    cin >> xi >> xs;

    do {
        xr = calculaXr(opcion, f, xi, xs);
        erp = calculaErp(xr, xrAnterior);
        cout << iteracion << "|"
             << xi << "|"
             << xs << "|"
             << xr << "|"
             << erp << endl;

        ++iteracion;
        xrAnterior = xr;
        realizaAjustesXi_Xs(f, xi, xs, xr);
        system("pause>nul");
    } while (true);


    return 0;
}

