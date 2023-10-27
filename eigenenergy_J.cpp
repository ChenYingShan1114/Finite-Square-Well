#include <iostream>
#include <math.h>
using namespace std;

const double eV = 1.60217662e-19;
const double Bohr_radius = 5.29e-11;
const double hbar = 1.054571817e-34;
const double m_e = 9.1093837e-31;
const double pi = 3.14159265359;
const double nor = Bohr_radius / hbar * sqrt(m_e * eV);

double V = -13.6 * eV;
double a = 20 * Bohr_radius;

double f_even(double E){
    double tmp1 = 0, tmp2 = 0, tmp3 = 0;
    tmp1 = sqrt(-E);
    tmp2 = sqrt(E - V);
    tmp3 = a / hbar * sqrt(2 * m_e * (E - V));
    return tmp1 - tmp2 * tan(tmp3);
}

double ff_even(double E){
    double tmp1 = 0, tmp2 = 0, tmp3 = 0;
    tmp1 = sqrt(-E);
    tmp2 = sqrt(E - V);
    tmp3 = a / hbar * sqrt(2 * m_e * (E - V));
    return -0.5 * (1 / tmp1 + 1 / tmp2 * tan(tmp3) + sqrt(2 * m_e) * a / hbar / cos(tmp3) / cos(tmp3));
}

double f_odd(double E){
    double tmp1 = 0, tmp2 = 0, tmp3 = 0;
    tmp1 = sqrt(-E);
    tmp2 = sqrt(E - V);
    tmp3 = a / hbar * sqrt(2 * m_e * (E - V));
    return tmp1 + tmp2 / tan(tmp3);
}

double ff_odd(double E){
    double tmp1 = 0, tmp2 = 0, tmp3 = 0;
    tmp1 = sqrt(-E);
    tmp2 = sqrt(E - V);
    tmp3 = a / hbar * sqrt(2 * m_e * (E - V));
    return -0.5 * (1 / tmp1 - 1 / tmp2 / tan(tmp3) + sqrt(2 * m_e) * a / hbar / sin(tmp3) / sin(tmp3));
}

int main(){
    int num = 10, iter = 1000;
    double E_initial[num];
    cout << "Use the eigenenergy of infinite square well to guess" << endl;
    for (int n = 1; n <= num; n++){
        E_initial[n-1] = n * n * hbar * hbar * pi * pi / 8 / m_e / 400 / Bohr_radius / Bohr_radius / eV - 13.6;
        //cout << "The eigenenergy of " << n << " is " << n * n * hbar * hbar * pi * pi / 8 / m_e / 400 / Bohr_radius / Bohr_radius / eV - 13.6 << endl;
    
        if (n % 2 == 0){
            double E_in = E_initial[n-1] * eV;
            double E_new = 0, E_old = E_in;
            for (int i = 0; i < iter; i++){
                E_new = E_old - f_even(E_old) / ff_even(E_old) * 0.1;
                if (fabs((E_new - E_old)/E_old) < 1e-12){
                    cout << n << " state initial energy guess: " << E_in << " (J)";
                    cout << " ---> eigenenergy of finite square well " << E_new << " (J)" << endl;
                    //cout << f_even(E_new) << endl;
                    break;
                }
                else{
                    E_old = E_new;
                }
            }
        }
        else{
            double E_in = E_initial[n-1] * eV;
            double E_new = 0, E_old = E_in;
            for (int i = 0; i < iter; i++){
                E_new = E_old - f_odd(E_old) / ff_odd(E_old) * 0.1;
                if (fabs((E_new - E_old)/E_old) < 1e-12){
                    cout << n << " state initial energy guess: " << E_in << " (J)";
                    cout << " ---> eigenenergy of finite square well " << E_new << " (J)" << endl;
                    //cout << f_odd(E_new) << endl;
                    break;
                }
                else{
                    E_old = E_new;
                }
            }
        }
    }
}
