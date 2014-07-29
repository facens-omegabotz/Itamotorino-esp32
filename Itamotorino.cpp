/*
  Itamotorino.cpp - Library to control the motor shield the Itapêduino
  Created and developed by GELSON J.A. FILHO, July 26, 2014 (4:12 am).
  Released into the public domain

  Itamotorino.cpp - Biblioteca para comandar el controlador de motor de la Itapêduino
  Creado y desarrollado por GELSON J.A. FILHO, Julio 26, 2014 (4:12)
  Publicada en el dominio público
  
  Itamotorino.cpp - Biblioteca para comandar a controladora de motores da Itapêduino
  Criado e desenvolvido por GELSON J. A. FILHO, Julho 26, 2014 (4:12)
  Lançamentos para o domínio público
*/

#include "Arduino.h"
#include "Itamotorino.h"

Itamotorino::Itamotorino(int pinM1a, int pinM1b,
                         int pinM2a, int pinM2b,
                         int pinEnableM1, int pinEnableM2)
{
	pinMode(pinM1a, OUTPUT);
	pinMode(pinM1b, OUTPUT);
	pinMode(pinM2a, OUTPUT);
	pinMode(pinM2b, OUTPUT);
	pinMode(pinEnableM1, OUTPUT);
	pinMode(pinEnableM2, OUTPUT);
	_pinM1a = pinM1a;
	_pinM1b = pinM1b;
	_pinM2a = pinM2a;
	_pinM2b = pinM2b;
	_pinEnableM1 = pinEnableM1;
	_pinEnableM2 = pinEnableM2;
}

void Itamotorino::setSpeeds(int m1, int m2)
{
  if(m1 >= 0 && m2 >= 0)
  {
    _m1 = m1;
    _m2 = m2;

    digitalWrite(_pinM1a, HIGH);
    digitalWrite(_pinM1b, LOW);
    digitalWrite(_pinM2a, HIGH);
    digitalWrite(_pinM2b, LOW);
    analogWrite(_pinEnableM1,_m1);
    analogWrite(_pinEnableM2,_m2);
  }
  if(m1 >= 0 && m2 < 0)
  {
    _m1 = m1;
    _m2 = m2;

    _m2 = -_m2;

    digitalWrite(_pinM1a, HIGH);
    digitalWrite(_pinM1b, LOW);
    digitalWrite(_pinM2a, LOW);
    digitalWrite(_pinM2b, HIGH);
    analogWrite(_pinEnableM1,_m1);
    analogWrite(_pinEnableM2,_m2);
  }
  if(m1 < 0 && m2 >= 0)
  {
    _m1 = m1;
    _m2 = m2;

    _m1 = -_m1;

    digitalWrite(_pinM1a, LOW);
    digitalWrite(_pinM1b, HIGH);
    digitalWrite(_pinM2a, HIGH);
    digitalWrite(_pinM2b, LOW);
    analogWrite(_pinEnableM1,_m1);
    analogWrite(_pinEnableM2,_m2);
  }
  if(m1 < 0 && m2 < 0)
  {
    _m1 = m1;
    _m2 = m2;

    _m1 = -_m1;
    _m2 = -_m2;
    
    digitalWrite(_pinM1a, LOW);
    digitalWrite(_pinM1b, HIGH);
    digitalWrite(_pinM2a, LOW);
    digitalWrite(_pinM2b, HIGH);
    analogWrite(_pinEnableM1,_m1);
    analogWrite(_pinEnableM2,_m2);
  }
}

