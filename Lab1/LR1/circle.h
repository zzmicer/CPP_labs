// ---------------------------------------------------------------------------

#ifndef circleH
#define circleH
#include "shape.h"
#include "math.h"


// ---------------------------------------------------------------------------
#endif

class circle : public shape {
private:
	int r;

public:

	circle(int, int, int);
	circle();

	void setR(int);


	void draw(TCanvas *Canvas);
    void clear(TCanvas *Canvas);

};
