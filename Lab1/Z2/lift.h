// ---------------------------------------------------------------------------

#ifndef liftH
#define liftH
#include <vcl.h>
// ---------------------------------------------------------------------------

class Lift {
public:
	int x1, y1, x2, y2;

	Lift(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}

	void draw(TCanvas *Canvas) {
		Canvas->Pen->Color = clBlack;
		Canvas->Brush->Color=clWhite;
		Canvas->Rectangle(x1, y1, x2, y2);
	}

	void moveUp() {
		y1 -= 1;
		y2 -= 1;
	}

	void moveDown() {
		y1 += 1;
		y2 += 1;
	}

	void clear(TCanvas *Canvas) {
		Canvas->Pen->Color = clWhite;
        Canvas->Brush->Color=clWhite;
		Canvas->Rectangle(x1, y1, x2, y2);
	}
};

#endif
