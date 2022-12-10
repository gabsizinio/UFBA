#Questão 1:
def calcula_area(base, altura):
  return base * altura

#Questão 2:
def esta_obesa(peso, altura):
  imc = peso / (altura * altura)
  if imc >= 30:
    return True
  return False

#Questão 3:
def faixa_etaria(idade):
  if idade >= 0 and idade <= 1:
    return "bebê"
  elif idade >= 2 and idade <= 11:
    return "criança"
  elif idade >= 12 and idade <= 17:
    return "adolescente"
  else:
    return "adulta"

#Questão 4:
def linha(c, n):
  s = c * n
  return s

#Questão 5:
def retangulo(c, base, altura):
  s = c * base
  s += "\n"
  for i in range(0, altura - 1):
    s += c * base
    s += "\n"
  return s

#Questão 6:
def sequencia(n):
	lista = []
	for i in range(1, n + 1):
		lista.append(i)
	return lista

#Questão 7:
def produtorio(lista):
  resultado = 1
  for i in lista:
    resultado *= i
  return resultado

