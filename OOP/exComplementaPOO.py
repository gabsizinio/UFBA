class aluno:
    def __init__(self, nome, num):
        self.nome = nome
        self.numeroMatricula = num

class disciplina:
    codigo = 0
    cargaHoraria = 0
    alunos = []
    def __init__(self, codigo, carga):
        self.codigo = codigo
        self.cargaHoraria = carga
    
    def adicionar_aluno(self, aluno):
        self.alunos.append(aluno)
    
    def lista_de_matriculados(self):
        for i in self.alunos:
            print(i.nome)


    