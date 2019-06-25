// ---------------------------------------------------------------------------

#pragma hdrstop

#include "circle.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

circle::circle(int x, int y, int rad) {
	x0 = x;
	y0 = y;
	r = rad;
}

circle::circle() {
}

void circle::draw(TCanvas *Canvas) {
	Canvas->Pen->Color = clBlack;
	Canvas->Ellipse(x0 - r, y0 - r, x0 + r, y0 + r);
	p=2*M_PI*r;
    s=M_PI*r*r;

}

void circle::clear(TCanvas *Canvas) {
	Canvas->Pen->Color = clWhite;
	Canvas->Ellipse(x0 - r, y0 - r, x0 + r, y0 + r);
}

void circle::setR(int r0){
	 (*this).r = r0;
}

