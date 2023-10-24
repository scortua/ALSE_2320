/**
 * Project Untitled
 */

<<<<<<< HEAD
#ifndef _PENTAGONO_H
#define _PENTAGONO_H

#include <iostream>

using namespace std;

class Pentagono
{
public:
  Pentagono(float l, float x = 0., float y = 0.);
  float area();
  float perimetro();

  friend ostream &operator<<(ostream &stream, Pentagono &p);

  void setLado(float l) { _lado = l; };
  float getLado() { return _lado; }
  void setX(float x) { _xc = x; };
  float getX() { return _xc; }
  void setY(float y) { _yc = y; };
  float getY() { return _yc; }
  void setAngulo(float a) { _angulo = a; };
  float getAngulo() { return _angulo; }

private:
  float _lado;
  float _xc;
  float _yc;
  float _angulo;
  float _area;
  float _perimetro;

  Pentagono();
=======

#ifndef _PENTAGONO_H
#define _PENTAGONO_H

#include "Geometrica.h"


class Pentagono: public Geometrica {
  public:
    Pentagono(float l, float x, float y);
    Pentagono(string parametros);
  private:
	float _lado;
	
    Pentagono();
>>>>>>> origin/main
};

#endif //_PENTAGONO_H
