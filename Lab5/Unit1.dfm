object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 485
  ClientWidth = 497
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Gauge1: TGauge
    Left = 181
    Top = 182
    Width = 121
    Height = 115
    Kind = gkVerticalBar
    MaxValue = 9
    Progress = 0
  end
  object Label1: TLabel
    Left = 196
    Top = 94
    Width = 17
    Height = 64
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -53
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 74
    Top = 40
    Width = 326
    Height = 48
    Caption = #1058#1077#1082#1091#1097#1080#1081' '#1101#1083#1077#1084#1077#1085#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 325
    Top = 124
    Width = 75
    Height = 25
    Caption = '->'
    TabOrder = 0
    OnClick = BtNext
  end
  object Button2: TButton
    Left = 85
    Top = 124
    Width = 75
    Height = 25
    Caption = '<-'
    TabOrder = 1
    OnClick = BtPrev
  end
  object Button3: TButton
    Left = 74
    Top = 216
    Width = 86
    Height = 25
    Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 325
    Top = 216
    Width = 86
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 3
    OnClick = Button4Click
  end
  object ListBox1: TListBox
    Left = 181
    Top = 312
    Width = 121
    Height = 113
    ItemHeight = 13
    TabOrder = 4
  end
  object Button5: TButton
    Left = 325
    Top = 312
    Width = 116
    Height = 25
    Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1074' '#1082#1086#1085#1077#1094
    TabOrder = 5
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 325
    Top = 343
    Width = 116
    Height = 21
    TabOrder = 6
    TextHint = #1047#1085#1072#1095#1077#1085#1080#1077
  end
  object Button6: TButton
    Left = 44
    Top = 312
    Width = 116
    Height = 25
    Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1087#1086' '#1080#1085#1076#1077#1082#1089#1091
    TabOrder = 7
    OnClick = Button6Click
  end
  object Edit2: TEdit
    Left = 44
    Top = 343
    Width = 116
    Height = 21
    TabOrder = 8
    TextHint = #1048#1085#1076#1077#1082#1089
  end
  object Edit3: TEdit
    Left = 44
    Top = 370
    Width = 116
    Height = 21
    TabOrder = 9
    TextHint = #1047#1085#1072#1095#1077#1085#1080#1077
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 408
    Top = 400
  end
end