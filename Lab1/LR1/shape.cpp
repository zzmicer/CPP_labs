// ---------------------------------------------------------------------------

#pragma hdrstop

#include "shape.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int shape::getx0() {
	return x0;
}

int shape::gety0() {
	return y0;
}

float shape::getP() {
	return p;
}

float shape::getS() {
	return s;
}
void shape::setX(int x){
	 (*this).x0 = x;
}
void shape::setY(int y){
	 (*this).y0 = y;
}
