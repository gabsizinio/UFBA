#Questão 1:
def distancia(x1, y1, x2, y2):
  """
	Calcular a distância euclidiana entre 
  2 pontos
  """
  dis = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (1/2)
  return dis

#Questão 2:
def maior(lista):
  maior = 0
  if len(lista) == 0:
    return 0
  for i in lista:
    if i > maior:
      maior = i
  return maior

#Questão 3:
def media_justa(lista):
  if len(lista) == 1 or len(lista) == 0:
    return 0
  ma = maior(lista)
  som = 0
  con = 0
  for i in lista:
    if i != ma:
      con += 1
      som += i
  
  return som / con

#Questão 4:
def preco_final(preco_produto, desconto, valor_frete):
  return preco_com_frete(preco_com_desconto(preco_produto, desconto), valor_frete)

def preco_com_desconto(preco_produto, desconto):
  return preco_produto * (100 - desconto)/100

def preco_com_frete(preco, valor_frete):
  return preco + valor_frete

def segundo_grau(x, a, b=0, c=0):
  resultado = a * x**2 + b*x + c
  return resultado