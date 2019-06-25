// ---------------------------------------------------------------------------
#pragma once
#ifndef shapeH
#define shapeH
#include <vcl.h>


// ---------------------------------------------------------------------------
#endif

class shape {
protected:
	int x0, y0;
	float p, s;

public:
	int getx0();
	int gety0();
	float getP();
	float getS();
    void setX(int);
	void setY(int);
};
