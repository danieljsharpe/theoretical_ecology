/*
Script to investigate the effect of perturbations on a system of ODEs representing
ecological competition between species (Lotka-Volterra model)

Compile with:
g++ -std=c++17 lv_response.cpp

Daniel J. Sharpe
July 2021
*/

#include <vector>
#include <string>
#include <iostream>
#include <boost/numeric/odeint.hpp>

using namespace std;

/* construct vector from basic array of passed values */
template<typename T, size_t N>
vector<T> make_vec(const T (&data)[N]) {
    return vector<T>(data,data+N);
}

/* construct 2D array from basic [1D] array of passed values */
template<typename T, size_t N>
array<T,

int main() {

    /* initialize parameters */
    int N; // number of species
    vector<double> r; // r[i] is intrinsic birth rate of i-th species
    array<double,2> A; // A[i,j] represents influence of j-th species on i-th species
    vector<double> x, xSS; // time-dependent population vector and its steady state

    /* SET MODEL PARAMETERS HERE */
    N = 3;
    const double rv[] = {1.,1.,1.};
    /*
    Av = { 0.5, -1.0, 0.6,
           1.8,  1.4, 0.3,
	   1.2, -0.3, 1.1 };
    */
    const double xv[] = {0.5,0.5,0.5};

    /* construct and check */
    r = make_vec(rv);
    x = make_vec(xv);
    if (r.size()!=N || x.size()!=N) throw runtime_error(string("r or x not right size")); 

    return 0;
}
