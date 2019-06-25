// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "tree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree tree;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	StringGrid1->Cells[1][0] = "Êëþ÷:";
	StringGrid1->Cells[2][0] = "Èìÿ:";
	StringGrid1->Cells[1][1] = "10";
	StringGrid1->Cells[2][1] = "Alex";
	StringGrid1->Cells[1][2] = "13";
	StringGrid1->Cells[2][2] = "Bob";
	StringGrid1->Cells[1][3] = "8";
	StringGrid1->Cells[2][3] = "Dima";
	StringGrid1->Cells[1][4] = "20";
	StringGrid1->Cells[2][4] = "Max";
	StringGrid1->Cells[1][5] = "5";
	StringGrid1->Cells[2][5] = "Keine";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	Form1->TreeView1->Items->Clear();
	tree.print(tree.root);
	tree.viewTree(tree.root, -1);
	TreeView1->FullExpand();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	tree.search(StrToInt(Edit1->Text), tree.root);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	tree.del(tree.root, StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	tree.add(StrToInt(Edit2->Text), Edit3->Text, &(tree.root), 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	tree.balance();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
int i = 1;
	while (StringGrid1->Cells[1][i] != "" || StringGrid1->Cells[2][i] != "" )
	{
		String data = StringGrid1->Cells[2][i];
		int key = StrToInt(StringGrid1->Cells[1][i]);
		tree.add(key,data,&(tree.root),0);
		i++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Edit4->Text = tree.NodeCount(tree.root);
}
//---------------------------------------------------------------------------

