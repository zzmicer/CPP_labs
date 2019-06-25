// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Wrapper.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int GetN() {

}

TForm1 *Form1;

int n = 0;
Wrapper wrapper(n);

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (Edit1->Text != "" && Edit2->Text != "" &&
		(CheckBox1->Checked != false || CheckBox2->Checked != false)
		&& Edit4->Text != "" && Edit5->Text != "" && Edit3->Text != "") {

		wrapper.AddData(Edit1, Edit2, Edit3, Edit4, Edit5, CheckBox1,
			CheckBox2, n);
		n++;
		wrapper.ShowData(n, Memo1);
	}
	else
		ShowMessage("������! ��������� ����!");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	Memo1->Clear();

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) {
	wrapper.DelData(Edit7, n);
	n--;
	wrapper.ShowData(n, Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	wrapper.ShowStud(Memo1, n);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	wrapper.ShowData(n, Memo1);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	wrapper.SortData(CheckBox1, CheckBox2, n, Memo1);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	wrapper.DataRetrieval(Edit4->Text, Edit5->Text, n, Memo1, Edit6);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	if (OpenDialog1->Execute() == true) {
		Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
	}
	int count_string = 0;
	TStringList* list = new TStringList; // ��������� ������
	list->LoadFromFile(OpenDialog1->FileName); // ��������� ����
	count_string = list->Count / 6; // ���������� �����
	n += count_string;
	wrapper.SetData(Memo1, n);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender) {
	if (SaveDialog1->Execute() == true && SaveDialog1->FileName != "") {
		Memo1->Lines->SaveToFile(SaveDialog1->FileName);
	}
	else
		ShowMessage("Error!");

}
// ---------------------------------------------------------------------------
