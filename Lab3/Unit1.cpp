// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List lst;
List lst_w;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {

	Storage *data = new Storage();

		if (StrToInt(Edit2->Text) < 0 || StrToInt(Edit3->Text) < 0)
			throw MyException("������������ ����!");

		else {
			data->set_number(StrToInt(Edit2->Text));
			data->set_name(Edit4->Text);
			data->set_price(StrToInt(Edit3->Text));
		}

	catch (MyException *e) {

		ShowMessage(e->Message);
		Edit4->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";

	}
	catch (...) {
		ShowMessage("Error occured!");
		Edit4->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
	}

	if (data->get_number() != 0) {
		lst.push_back(data);
	}
	else
		lst_w.push_back(data);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {

	Memo1->Clear();
	Memo1->Lines->Add("������ ��������� �������:");
	for (int i = 0; i < lst.size; i++) {
		Memo1->Lines->Add(lst[i].get_name());
		Memo1->Lines->Add(lst[i].get_number());
		Memo1->Lines->Add(lst[i].get_price());
		Memo1->Lines->Add('\n');

	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	Memo1->Clear();
	for (int i = 0; i < lst.size; i++) {
		if (lst[i].get_name() == Edit1->Text) {
			Memo1->Lines->Add(lst[i].get_name());
			Memo1->Lines->Add(lst[i].get_number());
			Memo1->Lines->Add(lst[i].get_price());
			Memo1->Lines->Add('\n');
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	for (int i = 0; i < lst.size; i++) {
		if (lst[i].get_name() == Edit5->Text) {
			lst.pop_index(i);
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	Memo1->Clear();
	for (int i = 0; i < lst.size; i++) {
		if (lst[i].get_price() < Edit6->Text) {
			Memo1->Lines->Add(lst[i].get_name());
			Memo1->Lines->Add(lst[i].get_number());
			Memo1->Lines->Add(lst[i].get_price());
			Memo1->Lines->Add('\n');
		}

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) {

	Memo1->Clear();
	Memo1->Lines->Add("������ ��������� �������:");
	for (int i = 0; i < lst_w.size; i++) {
		Memo1->Lines->Add(lst_w[i].get_name());
		Memo1->Lines->Add(lst_w[i].get_number());
		Memo1->Lines->Add(lst_w[i].get_price());
		Memo1->Lines->Add('\n');

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	if (Edit4->Text == "" || Edit2->Text == "" || Edit3->Text == "")
		Button1->Enabled = false;
	else
		Button1->Enabled = true;
	if (Edit6->Text == "")
		Button5->Enabled = false;
	else
		Button5->Enabled = true;
	if (Edit1->Text == "")
		Button2->Enabled = false;
	else
		Button2->Enabled = true;
	if (Edit5->Text == "")
		Button3->Enabled = false;
	else
		Button3->Enabled = true;

}
// ---------------------------------------------------------------------------
