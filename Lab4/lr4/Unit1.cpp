// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

// ---------------------------------------------------------------------------

#pragma resource "*.dfm"
TForm1 *Form1;
Stack<float>flstack(0);
Stack<char>sign(0);
TEdit* edit[10];
TLabel* label[10];

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	for (int i = 0; i < 10; i++) {
		edit[i] = new TEdit(Form1);
		label[i] = new TLabel(Form1);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	Edit2->Text = "";
	int num = 0;
	AnsiString form = Edit1->Text;
	char str[100];
	strcpy(str, form.c_str());

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			num++;
			Edit2->Text = Edit2->Text + str[i];
		}
		else if (sign.size == 0 || str[i] == '(') {
			sign.Push(str[i]);
		}
		else if (str[i] == ')') {
			char temp;
			while (true) {
				temp = sign.Top();
				if (temp == '(') {
					sign.Pop();
					break;
				}
				Edit2->Text = Edit2->Text + temp;
				sign.Pop();
			}
		}

		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
			str[i] == '/') {
			if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||
				str[i] == '/') && sign.Top() == '(') {
				sign.Push(str[i]);
			}

			else if (!((str[i] == '*' || str[i] == '/') && (sign.Top() == '+' ||
				sign.Top() == '-'))) {
				char temp = sign.Top();
				Edit2->Text = Edit2->Text + temp;
				sign.Pop();
				sign.Push(str[i]);
			}
			else {
				sign.Push(str[i]);
			}
		}

		else if (i == strlen(str)) {
			while (sign.Top()) {
				char temp = sign.Top();
				Edit2->Text = Edit2->Text + temp;
				sign.Pop();
			}
		}
		for (int i = 0; i < 10; i++) {
			edit[i]->Parent = Form1;
			edit[i]->Name = "Edi" + IntToStr(i + 1);
			edit[i]->Text = "";
			edit[i]->Top = 10000000;
			edit[i]->Left = 10000000;
			label[i]->Parent = Form1;
			label[i]->Name = "Labe" + IntToStr(i + 1);
			label[i]->Caption = "";
			label[i]->Top = 10000000;
			label[i]->Left = 10000000;
		}

		for (int i = 0; i < num; i++) {
			edit[i]->Name = "Edi" + IntToStr(i + 1);
			edit[i]->Text = "";
			edit[i]->Top = 280 + 32 * i;
			edit[i]->Left = 50;
			label[i]->Name = "Labe" + IntToStr(i + 1);
			label[i]->Caption = IntToStr(i + 1);
			label[i]->Top = 280 + 32 * i;
			label[i]->Left = 35;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	double n1, n2;
	int num = 0;
	Edit3->Text = "";
	AnsiString form = Edit2->Text;
	char str[100];
	strcpy(str, form.c_str());
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			flstack.Push(StrToFloat(edit[num]->Text));
			num++;
		}

		else if (str[i] == '+') {
			n1 = flstack.Top();
			flstack.Pop();
			n2 = flstack.Top();
			flstack.Pop();
			flstack.Push(n2 + n1);
		}

		else if (str[i] == '-') {
			n1 = flstack.Top();
			flstack.Pop();
			n2 = flstack.Top();
			flstack.Pop();
			flstack.Push(n2 - n1);
		}

		else if (str[i] == '/') {
			n1 = flstack.Top();
			flstack.Pop();
			n2 = flstack.Top();
			flstack.Pop();
			flstack.Push(n2 / n1);
		}

		else if (str[i] == '*') {
			n1 = flstack.Top();
			flstack.Pop();
			n2 = flstack.Top();
			flstack.Pop();
			flstack.Push(n2 * n1);
		}
	}
	Edit3->Text = flstack.Top();
}
// ---------------------------------------------------------------------------
