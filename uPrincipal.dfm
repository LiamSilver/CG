object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'frmPrincipal'
  ClientHeight = 686
  ClientWidth = 1101
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Scaled = False
  TextHeight = 15
  object lbVp: TLabel
    Left = 8
    Top = 515
    Width = 17
    Height = 15
    Caption = '( , )'
  end
  object lbW: TLabel
    Left = 475
    Top = 515
    Width = 17
    Height = 15
    Caption = '( , )'
  end
  object lblPontos: TLabel
    Left = 536
    Top = 11
    Width = 37
    Height = 15
    Caption = 'Pontos'
  end
  object lblPoligono: TLabel
    Left = 840
    Top = 11
    Width = 53
    Height = 15
    Caption = 'Poligonos'
  end
  object lblXmin: TLabel
    Left = 536
    Top = 434
    Width = 52
    Height = 15
    Caption = 'X Minimo'
  end
  object lblYmin: TLabel
    Left = 536
    Top = 521
    Width = 52
    Height = 15
    Caption = 'Y Minimo'
  end
  object lblXmax: TLabel
    Left = 720
    Top = 434
    Width = 54
    Height = 15
    Caption = 'X Maximo'
  end
  object lblYmax: TLabel
    Left = 720
    Top = 521
    Width = 54
    Height = 15
    Caption = 'Y Maximo'
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 502
    Height = 502
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = 0
    end
  end
  object lbxPontos: TListBox
    Left = 536
    Top = 32
    Width = 241
    Height = 153
    ItemHeight = 15
    TabOrder = 1
  end
  object btnPoligono: TButton
    Left = 536
    Top = 368
    Width = 96
    Height = 41
    Caption = 'Inicia Poligono'
    TabOrder = 2
    OnClick = btnPoligonoClick
  end
  object lbPoligonos: TListBox
    Left = 840
    Top = 32
    Width = 241
    Height = 153
    ItemHeight = 15
    TabOrder = 3
    OnClick = lbPoligonosClick
  end
  object edXmin: TEdit
    Left = 536
    Top = 455
    Width = 121
    Height = 23
    TabOrder = 4
    Text = '-250'
  end
  object edXmax: TEdit
    Left = 720
    Top = 455
    Width = 121
    Height = 23
    TabOrder = 5
    Text = '250'
  end
  object edYmax: TEdit
    Left = 720
    Top = 542
    Width = 121
    Height = 23
    TabOrder = 6
    Text = '250'
  end
  object edYmin: TEdit
    Left = 536
    Top = 542
    Width = 121
    Height = 23
    TabOrder = 7
    Text = '-250'
  end
  object btnAtualizaMundo: TButton
    Left = 720
    Top = 368
    Width = 99
    Height = 41
    Caption = 'Atualiza Mundo'
    TabOrder = 8
    OnClick = btnAtualizaMundoClick
  end
  object btnPrimeiroQuadrante: TButton
    Left = 864
    Top = 446
    Width = 96
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '1'#186' Quadrante'
    TabOrder = 9
    OnClick = btnPrimeiroQuadranteClick
  end
  object btnSegundoQuadrante: TButton
    Left = 988
    Top = 446
    Width = 93
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '2'#186' Quadrante'
    TabOrder = 10
    OnClick = btnSegundoQuadranteClick
  end
  object btnTerceiroQuadrante: TButton
    Left = 864
    Top = 533
    Width = 96
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '3'#186' Quadrante'
    TabOrder = 11
    OnClick = btnTerceiroQuadranteClick
  end
  object btnQuartoQuadrante: TButton
    Left = 988
    Top = 533
    Width = 93
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '4'#186' Quadrante'
    TabOrder = 12
    OnClick = btnQuartoQuadranteClick
  end
  object btnZoomIn: TButton
    Left = 865
    Top = 368
    Width = 95
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Zoom In'
    TabOrder = 13
    OnClick = btnZoomInClick
  end
  object btnZoomOut: TButton
    Left = 988
    Top = 368
    Width = 93
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Zoom Out'
    TabOrder = 14
    OnClick = btnZoomOutClick
  end
  object rgTipoReta: TRadioGroup
    Left = 536
    Top = 224
    Width = 501
    Height = 105
    Caption = 'Tipo de Reta'
    ItemIndex = 0
    Items.Strings = (
      'MoveTo -  LineTo'
      'DDA'
      'Bresenham')
    TabOrder = 15
    OnClick = rgTipoRetaClick
  end
end
