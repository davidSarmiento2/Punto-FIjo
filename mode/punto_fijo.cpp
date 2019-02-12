#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

#define epsilon0 10e-8
#define epsilon1 10e-4
#define epsilon2 10e-2

const double EulerConstant = std::exp(1.0);
const double pi = M_PI;


double funct(double x);
double newFunct( double x );


int main(int argc, char* argv[])
{
  //intervalo [ 0,1 ]
  double a,b;
  a = 0;
  b = 1;
  if( newFunct( a ) > a && newFunct( b ) < b)
  {
    std::cout << "Hay por lo menos una raiz real" << std::endl;

    double actual = 0;
    double prev = newFunct ( 0.6 );
    double aux = 1;
    int iteration = 0;
    while ( aux > epsilon1 )
    {
      actual = newFunct( prev );
      aux = prev - actual;
      std::cout << " Previo: "<< prev << "  | Actual "<< actual << "  |Diferencia " << aux << std::endl;
      prev = actual;
      ++iteration;
    }
    std::cout << actual << " iteraciones: " <<iteration <<std::endl;
  }
  else
  {
      std::cout << "En este intervalo no se encontro nada." << std::endl;
  }
  return( 0 );
}


double funct(double x)
{
  return ( pow( EulerConstant, x ) ) - (pi * x);
}

double newFunct( double x )
{
  return( ( (pow( EulerConstant, x )) / pi));
}
