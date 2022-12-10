#Questão 1

from enum import Enum

class Componente(Enum):
    RED = 0
    BLUE = 1
    GREEN = 2

class Cor:
    def __init__(self, r, g, b):
        self.r = r
        self.g = g
        self.b = b
    
    def altera(self, componente, valor):
        if componente == Componente.RED:
            self.r = valor
        elif componente == Componente.BLUE:
            self.b = valor
        elif componente == Componente.GREEN:
            self.g = valor
    
    def __eq__(self, o):
        return self.r == o.r and self.g == o.g and self.b == o.b

#Questão 2

from enum import Enum

class Status(Enum):
    RECEBIDO = 0
    PAGO = 1
    ENVIADO = 2
    ENTREGUE = 3

class Pedido:
    def __init__(self, status=Status.RECEBIDO, valor=0.0):
        self.valor = valor
        self.status = Status.RECEBIDO

    def pagar(self, forma_de_pagamento):
        if self.status == Status.RECEBIDO:
            self.status = Status.PAGO
  
    def enviar(self, transportadora):
        if self.status == Status.PAGO:
            self.status = Status.ENVIADO
  
    def entregar(self):
        if self.status == Status.ENVIADO:
            self.status = Status.ENTREGUE
  
    def situacao(self):
        if self.status == Status.PAGO:
          return 'pago'
        elif self.status == Status.ENVIADO:
          return 'enviado'
        elif self.status == Status.ENTREGUE:
          return 'entregue'
        else:
          return 'recebido'
