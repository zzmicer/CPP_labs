object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 495
  ClientWidth = 680
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 81
    Height = 19
    Caption = #1060#1072#1084#1080#1083#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 188
    Width = 110
    Height = 19
    Caption = #1052#1072#1090#1077#1084#1072#1090#1080#1082#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 228
    Width = 100
    Height = 19
    Caption = #1060#1080#1083#1086#1089#1086#1092#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 268
    Width = 170
    Height = 19
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 133
    Height = 19
    Caption = #1057#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 8
    Top = 85
    Width = 145
    Height = 19
    Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 8
    Top = 310
    Width = 121
    Height = 19
    Caption = #1053#1086#1084#1077#1088' '#1079#1072#1087#1080#1089#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 8
    Top = 339
    Width = 123
    Height = 19
    Caption = #1057#1088#1077#1076#1085#1080#1081' '#1073#1072#1083#1083':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 296
    Top = 8
    Width = 376
    Height = 249
    Lines.Strings = (
      '')
    ReadOnly = True
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 124
    Top = 190
    Width = 32
    Height = 21
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 114
    Top = 230
    Width = 32
    Height = 21
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 184
    Top = 270
    Width = 32
    Height = 21
    TabOrder = 3
  end
  object Button1: TButton
    Left = 296
    Top = 279
    Width = 185
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 487
    Top = 310
    Width = 185
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 296
    Top = 341
    Width = 185
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089#1087#1080#1089#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 296
    Top = 372
    Width = 185
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 487
    Top = 279
    Width = 185
    Height = 25
    Caption = #1057#1090#1091#1076#1077#1085#1090#1099' '#1086#1090#1083#1080#1095#1085#1080#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = Button5Click
  end
  object Edit4: TEdit
    Left = 95
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object Edit5: TEdit
    Left = 147
    Top = 50
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object Button6: TButton
    Left = 296
    Top = 310
    Width = 185
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 11
    OnClick = Button6Click
  end
  object Edit7: TEdit
    Left = 135
    Top = 312
    Width = 43
    Height = 21
    TabOrder = 12
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 123
    Width = 97
    Height = 17
    Caption = #1087#1083#1072#1090#1085#1072#1103
    TabOrder = 13
  end
  object CheckBox2: TCheckBox
    Left = 8
    Top = 154
    Width = 97
    Height = 17
    Caption = #1073#1102#1076#1078#1077#1090#1085#1072#1103
    TabOrder = 14
  end
  object Button7: TButton
    Left = 487
    Top = 341
    Width = 185
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 15
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 487
    Top = 372
    Width = 185
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 16
    OnClick = Button8Click
  end
  object Edit6: TEdit
    Left = 135
    Top = 339
    Width = 43
    Height = 21
    TabOrder = 17
  end
  object OpenDialog1: TOpenDialog
    Left = 472
    Top = 440
  end
  object SaveDialog1: TSaveDialog
    Left = 528
    Top = 432
  end
end
