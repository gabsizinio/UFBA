from typing import Protocol

class Item(Protocol):
   qtd: int
   preco: float

class Produto(Item):
   def __init__(self, qtd, preco):
       self.qtd = qtd
       self.preco = preco

def preco_final(item: Item) -> float:
   return item.qtd * item.preco

p = Produto(5, 3.14)
print(preco_final(p))