#Questão 1:
class Conta:  
  def __init__(self, codigo, saldo=0):
    self.codigo = codigo
    self.saldo = saldo
    
  def deposita(self, quantia):
    self.saldo += quantia
    '''
    Adiciona a quantia ao saldo da conta.
    :param quantia: quantia a ser depositada
    '''
  
  def retira(self, quantia):
    if quantia > self.saldo:
      return False
    else:
      self.saldo -= quantia
      return True
    '''
    Subtrai a quantia do saldo da conta, a menos que o saldo seja insuficiente
    (isto é, menor que a quantia).
    :param quantia: quantia a ser retirada
    :return: `True` se a quantia foi retirada, `False` caso contrário
    '''
  
  def transfere(self, quantia, beneficiario):
    if quantia > self.saldo or beneficiario == None:
      return False
    else:
      self.saldo -= quantia
      beneficiario.saldo += quantia
      return True
    '''
    Transfere a quantia da conta atual para a conta do beneficiário,
    a menos que o saldo da conta atual seja insuficiente (ou ainda se
    o parâmetro `beneficiario` for `None`). 
    :param quantia: quantia a ser retirada
    :param beneficiario: conta do beneficiário
    :return: `True` se a transferência foi realizada, `False` caso contrário
    '''

#Questão 2:
class Aluno:
    def __init__(self, mat, nome):
        self._matricula = mat
        self._nome = nome
  
    def __eq__(self, outro):
        if self.matricula == outro.matricula:
            return True
        else:
            return False

    @property
    def matricula(self):
        return self._matricula
    
  
    @property
    def nome(self): 
        return self._nome
  
    @nome.setter
    def nome(self, v):
        self._nome = v