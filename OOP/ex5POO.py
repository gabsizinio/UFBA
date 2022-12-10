#Questão 1:
class Usuario:
    '''Um usuário da rede social é unicamente identificado
    pelo seu número de telefone.'''
    def __init__(self, telefone, nome):
        self.nome = nome
        self.telefone = telefone
    
    def __eq__(self, o):
        if self.telefone == o.telefone:
            return True
        else:
            return False
        
  
class Grupo:
    '''Grupo de usuários na rede social.
    Um grupo possui um nome e um conjunto de membros.
    Além disso, ele possui exatamente um dono, que é um membro.
    Um grupo não pode estar vazio.
    '''
    def __init__(self, nome, dono):
        self.nome = nome
        self.dono = dono
        self.usuarios = []
        self.usuarios.append(dono)


    def adiciona(self, usuario):
        '''Adiciona usuário como membro do grupo'''
        self.usuarios.append(usuario)
  
    def remove(self, usuario):
        '''Remove um usuário do grupo, se possível.
        Em alguns casos NÃO é possível remover o usuário do grupo:
        * Se o usuário é o único membro do grupo
        * Se o usuário é dono do grupo
        * Se o usuário não pertence ao grupo
        :return: `True` se o usuário foi removido ou `False` caso contrário
        '''
        if len(self.usuarios) == 1:
            return False
        if self.dono.telefone == usuario.telefone:
            return False
        if usuario in self.usuarios:
            self.usuarios.pop(self.usuarios.index(usuario))
            return True
        else:
            return False

    def altera_dono(self, novo_dono):
        '''Destitui o dono atual e elege um novo dono.
        O dono deve ser membro do grupo.
        Retorna `True` se o usuário informado é o novo dono
        ou `False` caso contrário.
        '''
        if novo_dono in self.usuarios:
            self.dono = novo_dono
            return True
        return False

    def contem_membro(self, usuario):
        '''Indica se um usuário faz parte do grupo'''
        if usuario in self.usuarios:
            return True
        return False

    def membros(self):
        '''Retorna uma cópia da lista de membros'''
        return self.usuarios.copy()

    def tamanho(self):
        '''Retorna quantidade de membros'''
        return len(self.usuarios)
