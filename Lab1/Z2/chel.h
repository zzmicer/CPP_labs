// ---------------------------------------------------------------------------

#ifndef chelH
#define chelH
#include "lift.h"
// ---------------------------------------------------------------------------

class Man : public Lift {
public:
	int x2, y2, x3, y3;


	Man(int a, int b, int c, int d):Lift(a,b,c,d) {
		x2=a;
		y2=b;
		x3=c;
		y3=d;

	}

	void draw(TCanvas *Canvas) {
		Canvas->Pen->Color = clBlack;
		Canvas->Brush->Color=clBlue;
		Canvas->Rectangle(x2, y2, x3, y3);

	}

	void moveUp() {
		y2 -= 1;
		y3 -= 1;
	}

	void moveDown() {
		y2 += 1;
		y3 += 1;
	}

	void clear(TCanvas *Canvas) {
		Canvas->Pen->Color = clWhite;
		Canvas->Brush->Color=clWhite;
		Canvas->Rectangle(x2, y2, x3, y3);
	}

};
#endif
