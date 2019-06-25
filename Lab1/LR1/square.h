//---------------------------------------------------------------------------

#ifndef squareH
#define squareH
#include "shape.h"
#include "math.h"
//---------------------------------------------------------------------------
#endif
class square : public shape {
private:
	int a;

public:

	square(int, int, int);
	square();

	void setA(int);


	void draw(TCanvas *Canvas);
	void clear(TCanvas *Canvas);

};
