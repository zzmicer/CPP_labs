//---------------------------------------------------------------------------

#pragma hdrstop

#include "square.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

square::square(int x1, int y1, int a1) {
	x0 = x1;
	y0 = y1;
	a = a1;
}

square::square() {
}

void square::draw(TCanvas *Canvas) {
	Canvas->Pen->Color = clBlack;
	Canvas->Rectangle(x0-a,y0-a,x0+a,y0+a);
	p=4*a;
	s=a*a;

}

void square::clear(TCanvas *Canvas) {
Canvas->Pen->Color = clWhite;
	Canvas->Rectangle(x0-a,y0-a,x0+a,y0+a);
}

void square::setA(int a0){
	 (*this).a = a0;
}

