#Questão 1:

class Cor:
  def __init__(self, r, g, b):
    self.r = r
    self.g = g
    self.b = b
  
  def __eq__(self, o):
    return self.r == o.r and self.g == o.g and self.b == o.b

class Paleta:
  AZUL = Cor(0, 0, 255)
  VERMELHA = Cor(255, 0, 0)
  AMARELA = Cor(255, 255, 0)

#Questão 2:

import math

class Vetor:
  def __init__(self, x, y):
    self.x = x
    self.y = y
  
  def __eq__(self, o):
    return abs(self.x - o.x) < 0.001 and abs(self.y - o.y) < 0.001
  @staticmethod
  def comAnguloETamanho(ang, tam):
    return Vetor(math.cos(ang)*tam, math.sin(ang)*tam)
  @staticmethod
  def vertical(tam):
    return Vetor(0, tam)
  @staticmethod
  def horizontal(tam):
    return Vetor(tam, 0)

#Questão 3

class Pedido:
  RECEBIDO = 0
  PAGO = 1
  ENVIADO = 2
  ENTREGUE = 3
  
  def __init__(self, valor=0):
    self.valor = valor
    self.status = 0

  def pagar(self, forma_de_pagamento):
    if self.status == Pedido.RECEBIDO:
      self.status = Pedido.PAGO
  
  def enviar(self, transportadora):
    if self.status == Pedido.PAGO:
      self.status = Pedido.ENVIADO
  
  def entregar(self):
    if self.status == Pedido.ENVIADO:
      self.status = Pedido.ENTREGUE
