object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'frmPrincipal'
  ClientHeight = 663
  ClientWidth = 1106
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
    Left = 560
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
    Left = 840
    Top = 210
    Width = 52
    Height = 15
    Caption = 'X Minimo'
  end
  object lblYmin: TLabel
    Left = 840
    Top = 281
    Width = 52
    Height = 15
    Caption = 'Y Minimo'
  end
  object lblXmax: TLabel
    Left = 988
    Top = 210
    Width = 54
    Height = 15
    Caption = 'X Maximo'
  end
  object lblYmax: TLabel
    Left = 988
    Top = 281
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
    Left = 560
    Top = 32
    Width = 241
    Height = 153
    ItemHeight = 15
    TabOrder = 1
  end
  object btnPoligono: TButton
    Left = 840
    Top = 371
    Width = 121
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
    Left = 840
    Top = 231
    Width = 105
    Height = 23
    TabOrder = 4
    Text = '-250'
  end
  object edXmax: TEdit
    Left = 988
    Top = 231
    Width = 93
    Height = 23
    TabOrder = 5
    Text = '250'
  end
  object edYmax: TEdit
    Left = 988
    Top = 302
    Width = 93
    Height = 23
    TabOrder = 6
    Text = '250'
  end
  object edYmin: TEdit
    Left = 840
    Top = 302
    Width = 105
    Height = 23
    TabOrder = 7
    Text = '-250'
  end
  object btnAtualizaMundo: TButton
    Left = 960
    Top = 371
    Width = 121
    Height = 41
    Caption = 'Atualiza Mundo'
    TabOrder = 8
    OnClick = btnAtualizaMundoClick
  end
  object btnEsquerda: TButton
    Left = 560
    Top = 409
    Width = 97
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '<'
    TabOrder = 9
    OnClick = btnEsquerdaClick
  end
  object btnDireita: TButton
    Left = 712
    Top = 409
    Width = 89
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '>'
    TabOrder = 10
    OnClick = btnDireitaClick
  end
  object btnCima: TButton
    Left = 650
    Top = 371
    Width = 63
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '^'
    TabOrder = 11
    OnClick = btnCimaClick
  end
  object btnBaixo: TButton
    Left = 650
    Top = 409
    Width = 63
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'v'
    TabOrder = 12
    OnClick = btnBaixoClick
  end
  object btnZoomIn: TButton
    Left = 560
    Top = 371
    Width = 97
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
    Left = 712
    Top = 371
    Width = 89
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
    Left = 560
    Top = 224
    Width = 241
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
  object btnCircunferencia: TButton
    Left = 840
    Top = 409
    Width = 121
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Criar Circunfer'#234'ncia'
    TabOrder = 16
    OnClick = btnCircunferenciaClick
  end
  object btnTranslacao2D: TButton
    Left = 960
    Top = 409
    Width = 121
    Height = 41
    Caption = 'Transla'#231#227'o 2D'
    TabOrder = 17
    OnClick = btnTranslacao2DClick
  end
  object btnEscalonamento: TButton
    Left = 840
    Top = 467
    Width = 121
    Height = 42
    Caption = 'Escalonamento'
    TabOrder = 18
    OnClick = btnEscalonamentoClick
  end
  object btnRotacao: TButton
    Left = 960
    Top = 467
    Width = 121
    Height = 42
    Caption = 'Rota'#231#227'o em Z'
    TabOrder = 19
    OnClick = btnRotacaoClick
  end
  object btnReflexao: TButton
    Left = 840
    Top = 503
    Width = 121
    Height = 42
    Caption = 'Reflexao'
    TabOrder = 20
    OnClick = btnReflexaoClick
  end
  object btnClipping: TButton
    Left = 960
    Top = 503
    Width = 121
    Height = 42
    Caption = 'Clipping'
    TabOrder = 21
    OnClick = btnClippingClick
  end
  object btnBezier: TButton
    Left = 560
    Top = 466
    Width = 129
    Height = 43
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'B'#233'zier'
    TabOrder = 22
    OnClick = btnBezierClick
  end
  object btnCasteljau: TButton
    Left = 680
    Top = 467
    Width = 121
    Height = 42
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Casteljau'
    TabOrder = 23
    OnClick = btnCasteljauClick
  end
  object btnHermite: TButton
    Left = 664
    Top = 505
    Width = 137
    Height = 40
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Hermite'
    TabOrder = 24
    OnClick = btnHermiteClick
  end
  object btnBspline: TButton
    Left = 560
    Top = 503
    Width = 112
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'B-Spline'
    TabOrder = 25
    OnClick = btnBsplineClick
  end
  object btnResetarPoligonos: TButton
    Left = 560
    Top = 607
    Width = 141
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Resetar Poligonos'
    TabOrder = 26
    OnClick = btnResetarPoligonosClick
  end
  object btnLerCubo: TButton
    Left = 9
    Top = 560
    Width = 136
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Ler Cubo'
    TabOrder = 27
    OnClick = btnLerCuboClick
  end
  object btnLerPiramide: TButton
    Left = 9
    Top = 607
    Width = 136
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Ler Piramide'
    TabOrder = 28
    OnClick = btnLerPiramideClick
  end
  object btnTranslacao3d: TButton
    Left = 180
    Top = 560
    Width = 149
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Transla'#231#227'o 3D'
    TabOrder = 29
    OnClick = btnTranslacao3dClick
  end
  object btnEscalonamento3d: TButton
    Left = 180
    Top = 607
    Width = 149
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Escalonamento 3D'
    TabOrder = 30
    OnClick = btnEscalonamento3dClick
  end
  object btnRotacaoX: TButton
    Left = 368
    Top = 560
    Width = 141
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rota'#231#227'o em X'
    TabOrder = 31
    OnClick = btnRotacaoXClick
  end
  object btnRotacaoY: TButton
    Left = 368
    Top = 607
    Width = 141
    Height = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rota'#231#227'o em Y'
    TabOrder = 32
    OnClick = btnRotacaoYClick
  end
end
