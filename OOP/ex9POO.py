#Questão 1:
import re
from abc import ABC, abstractmethod

class Usuario(ABC):
  def __init__(self, matricula, nome):
    self._matricula = matricula
    self._nome = nome
    
  @abstractmethod
  def valida(self):
    pass
    
  def nome_normalizado(self):
    return self._nome.title()

class Aluno(Usuario):
  def valida(self):
    return re.match('^\\d{9}$', self._matricula)

class Servidor(Usuario):
  def valida(self):
    return re.match('^\\d{7}$', self._matricula)

#Questão 2:
class Contador:
    def __init__(self, inicial=10):
        self._inicial = inicial
        self._contagem = inicial
  
    def decrementa(self, qtd=1):
        self._contagem -= qtd
        if self._contagem < 0:
            self._contagem = 0
 
    def reseta(self):
        self._contagem = self._inicial
  
    @property
    def contagem(self):
        return self._contagem

class Guerreiro:
    def __init__(self):
        self._vida = Contador()

    def recebe_dano(self):
        self._vida.decrementa(4)
  
    def provoca_dano(self, outro_guerreiro):
        outro_guerreiro.recebe_dano()
  
    @property
    def vida(self):
        return self._vida._contagem

g = Guerreiro()