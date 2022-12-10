#Questão 1:
class Conta:
  def __init__(self, numero, saldo):
    self.numero = numero
    self.saldo = saldo
  
  def deposita(self, quantia):
    self.saldo += quantia

class ContaPoupanca(Conta):
  def rende(self):
	  self.saldo = self.saldo * 1.01

#Questão 2:
class RoboBasico:
    DIRECOES = {'frente': (0, -1), 'tras': (0, 1),
      'esquerda': (-1, 0), 'direita': (1, 0)}
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def move(self, direcao):
        dx, dy = RoboBasico.DIRECOES[direcao]
        self.x += dx
        self.y += dy

class RoboPlus(RoboBasico):
    def explora(self):
        super().move('frente')
        super().move('direita')
        super().move('tras')
        super().move('esquerda')
        

class RoboSmart(RoboBasico):
    def __init__(self, x, y, bx, by):
        super().__init__(x,y)
        self.inx = bx
        self.iny = by

    def retorna_a_base(self):
        self.x = self.inx
        self.y = self.iny

#Questão 3:
class Conta:
    def __init__(self):
        self.saldo = 0

    def deposita(self, quantia):
        self.saldo += quantia

    def retira(self, quantia):
        if self.saldo >= quantia:
            self.saldo -= quantia

class ContaAuditada(Conta):
    def __init__(self):
        super().__init__()
        self.qtd_depositos = 0
        self.qtd_retiradas = 0
    
    def deposita(self, quantia):
        super().deposita(quantia)
        self.qtd_depositos += 1
    
    def retira(self, quantia):
        super().retira(quantia)
        self.qtd_retiradas += 1

    def quantidade_operacoes(self):
        return self.qtd_retiradas + self.qtd_depositos