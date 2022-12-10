#Questão 1:
def preco_ingresso(idade):
  '''
  Retorna o preço do ingresso para um comprador
  com determinada idade. Ingressos só podem ser
  vendidos para pessoas com idade entre 18 e 140
  anos. Caso uma idade fora dessa faixa seja
  passada, é lançada uma exceção ValueError.
  '''
  if idade >= 18 and idade <= 60:
    return 30.0
  elif idade > 60 and idade <= 140:
    return 15.0
  else:
    raise ValueError()

#Questão 2:
# não altere esta função
def le_arquivo(nome):
  '''Retorna uma lista de linhas de um arquivo.
  Se o arquivo não existir, lança a exceção
  FileNotFoundError.

  :param nome: nome do arquivo
  '''
  if nome == 'ajuda.txt':
    return ['ajuda', '===', '', 'fim']
  else:
    raise FileNotFoundError()

# Complete a implementação desta função
def resumo(nome_arquivo, n):
    '''Retorna as n primeiras linhas de um
    arquivo, se existir. Se o arquivo não
    existir, retorna a string "Não
    encontrado".

    :param nome_arquivo: nome do arquivo
    :param n: número de linhas
    '''
    linhas = []
    try:
  	    linhas = le_arquivo(nome_arquivo)
    except FileNotFoundError:
        return "Não encontrado"
    return linhas[0:n]
