// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
int x1, y1, r1;
int x2, y2, a2;
double angle = 0;
int a;
circle A(x1, y1, r1);
square B(x2, y2, a2);

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	x1 = StrToInt(Edit5->Text);
	y1 = StrToInt(Edit6->Text);
	r1 = StrToInt(Edit4->Text);
	x1=x1*cos(angle)-y1*sin(angle);
		y1=x1*sin(angle)+y1*cos(angle);

	r1 *= (ScrollBar5->Position)*0.5;
	A.setX(x1);
	A.setY(y1);
	A.setR(r1);

	Label3->Caption = FloatToStr(A.getS());
	Label4->Caption = FloatToStr(A.getP());
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);

	A.draw(Image1->Canvas);
	Edit2->Text = "(" + IntToStr(A.getx0()) + "," + IntToStr(A.gety0()) + ")";
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender) {
	x2 = StrToInt(Edit3->Text);
	y2 = StrToInt(Edit7->Text);
	a2 = StrToInt(Edit1->Text);
		a2 *= (ScrollBar5->Position)*0.5;
		x2=x2*cos(angle)-y2*sin(angle);
		y2=x2*sin(angle)+y2*cos(angle);

	B.setA(a2);
	B.setX(x2);
	B.setY(y2);
	Label18->Caption = FloatToStr(B.getS());
	Label17->Caption = FloatToStr(B.getP());
	Image2->Canvas->Brush->Color = clWhite;
	Image2->Canvas->FillRect(Image2->Canvas->ClipRect);
	B.draw(Image2->Canvas);
    Edit8->Text = "(" + IntToStr(B.getx0()) + "," + IntToStr(B.gety0()) + ")";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
	a = (ScrollBar1->Position);

	angle = a / 57.2958;
}
//---------------------------------------------------------------------------


