#Questão 1:
class Retangulo:
  '''Representa um retângulo, com base e altura'''
  def altera_dimensoes(self, b, a):
    self.altura = a
    self.base = b
    '''
    Altera base e altura para os
    valores fornecidos como parâmetro
    '''

#Questão 2:
class Retangulo:
  '''Representa um retângulo, com base e altura'''
  def area(self):
    area = self.base * self.altura
    return area

  def perimetro(self):
    perimetro = 2*self.base + 2*self.altura
    return perimetro
    '''
    Altera base e altura para os
    valores fornecidos como parâmetro
    '''

#Questão 3:
class Retangulo:
  '''Representa um retângulo, com base e altura'''
  def __init__(self, b, a):
    self.base = b
    self.altura = a
  
  def area(self):
    area = self.base * self.altura
    return area

  def perimetro(self):
    perimetro = 2*self.base + 2*self.altura
    return perimetro
    '''
    Altera base e altura para os
    valores fornecidos como parâmetro
    '''

#Questão 4:
class Retangulo:
  def __init__(self, base, altura):
    self.base = base
    self.altura = altura
  def aumenta(self, outro):
    self.base += outro.base
    self.altura += outro.altura
    '''
    Redimensiona este retângulo, cujas dimensões
    passam a ser a soma das suas dimensões originais
    com as dimensões de outro retângulo, passado
    como parâmetro
    '''

#Questão 5:
class Retangulo:
  def __init__(self, base, altura):
    self.base = base
    self.altura = altura
  def mais(self, outro):
    return Retangulo(self.base + outro.base, self.altura + outro.altura)
    '''
    Cria um novo retângulo, cujas dimensões são
    a soma das dimensões deste retângulo com as
    dimensões de outro retângulo, passado como
    parâmetro
    '''

#Questão 6:
class Retangulo:
  def __init__(self, base, altura):
    self._base = base
    self._altura = altura
    self._area = self.base * self.altura
	
  @property
  def area(self):
    return self._area
  
  @property
  def base(self):
    return self._base
  
  @base.setter
  def base(self, b):
    self._base = b
    
  @property
  def altura(self):
    return self._altura
  
  @altura.setter
  def altura(self, a):
    self._altura = a

#Questão 7:
class Retangulo:
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura
        self.razao = base/altura

    @property
    def razao(self):
        return self.razao
    
    @razao.setter
    def razao(self, v):
        self.razao = v
        self.altura = self.base / v