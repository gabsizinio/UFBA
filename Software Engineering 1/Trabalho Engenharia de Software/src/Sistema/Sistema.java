package Sistema;
import java.util.List;

import ClassesSistema.Emprestimo;
import ClassesSistema.Livro;
import ClassesSistema.Reserva;
import ClassesSistema.FabricaClassesSistema;
import Usuario.IUsuario;
import Usuario.FabricaUsuario;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Sistema {
	public ArrayList<IUsuario> Usuarios;
	public ArrayList<Livro> Livros;
	
	public ArrayList<Reserva> Reservas;
	public ArrayList<Emprestimo> Emprestimos;
	
	private Sistema() {};
	
	private static Sistema Biblioteca;
	
	public static Sistema getBiblioteca() {
		if(Biblioteca == null) {
			Biblioteca = new Sistema();
		}
		return Biblioteca;
	}
	
	public void Inicializar() {
		Usuarios = new ArrayList<>();
		Livros = new ArrayList<>();
		
		Usuarios.add(FabricaUsuario.criaAlunoGrad(123, "Joao da Silva"));
		Usuarios.add(FabricaUsuario.criaAlunoPos(456, "Luiz Fernando Rodrigues"));
		Usuarios.add(FabricaUsuario.criaAlunoGrad(789, "Pedro Paulo"));
		Usuarios.add(FabricaUsuario.criaProfessor(100, "Carlos Luccena"));
		
		String[] autores = {"Ian Sommerville"};
		Livro livro = FabricaClassesSistema.criarLivro(100, "Engenharia de Software", "Addison Wesley", Arrays.asList(autores), "Sexta", 2000);
		livro.addExemplares(FabricaClassesSistema.criarExemplar(1, livro));
		livro.addExemplares(FabricaClassesSistema.criarExemplar(2, livro));
		Livros.add(livro);
		
		String[] autores2 = {"Grady Booch", "James Rumbaugh", "Ivar Jacobson"};
		Livro livro2 = FabricaClassesSistema.criarLivro(101, "UML - Guia do Usuario", "Campus", Arrays.asList(autores2), "Setima", 2000);
		livro2.addExemplares(FabricaClassesSistema.criarExemplar(3, livro2));
		Livros.add(livro2);
		
		String[] autores3 = {"Steve McConnel"};
		Livro livro3 = FabricaClassesSistema.criarLivro(200, "Code Complete", "Microsoft Press", Arrays.asList(autores3), "Segunda", 2014);
		livro3.addExemplares(FabricaClassesSistema.criarExemplar(4, livro3));
		Livros.add(livro3);
		
		String[] autores4 = {"Robert Martin"};
		Livro livro4 = FabricaClassesSistema.criarLivro(201, "Agile Software Development, Principles, Patterns and Pratices", "Prentice Hall", Arrays.asList(autores4), "Primeira", 2002);
		livro4.addExemplares(FabricaClassesSistema.criarExemplar(5, livro4));
		Livros.add(livro4);
		
		String[] autores5 = {"Martin Fowler"};
		Livro livro5 = FabricaClassesSistema.criarLivro(300, "Refactoring: Improving the Design of Existing Code", "Addison Wesley Professional", Arrays.asList(autores5), "Primeira", 1999);
		livro5.addExemplares(FabricaClassesSistema.criarExemplar(6, livro5));
		livro5.addExemplares(FabricaClassesSistema.criarExemplar(7, livro5));
		Livros.add(livro5);
		
		String[] autores6 = {"Norman Fenton", "James Bieman"};
		Livro livro6 = FabricaClassesSistema.criarLivro(301, "Software Metrics: A Rigorous and Practical Approach", "CRC Press", Arrays.asList(autores6), "Terceira", 2014);
		Livros.add(livro6);
		
		String[] autores7 = {"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"};
		Livro livro7 = FabricaClassesSistema.criarLivro(400, "Design Patterns: Elements of Reusable Object-Oriented Software", "Addison Wesley Professional", Arrays.asList(autores7), "Primeira", 1994);
		livro7.addExemplares(FabricaClassesSistema.criarExemplar(8, livro7));
		livro7.addExemplares(FabricaClassesSistema.criarExemplar(9, livro7));
		Livros.add(livro7);
		
		String[] autores8 = {"Martin Fowler"};
		Livro livro8 = FabricaClassesSistema.criarLivro(401, "UML Distilled: A Brief Guide to the Standard Object Modeling Language", "Addison Wesley Professional", Arrays.asList(autores8), "Terceira", 2003);
		Livros.add(livro8);	
	}
	
	public IUsuario getUsuario(int id) {
		for(int i = 0; i < Usuarios.size(); i++) {
			if(Usuarios.get(i).getId() == id) {
				return Usuarios.get(i);
			}
		}
		return null;
	}
	public Livro getLivro(int id) {
		for(int i = 0; i < Livros.size(); i++) {
			if(Livros.get(i).getId() == id) {
				return Livros.get(i);
			}
		}
		return null;
	}
	
	public void addUsuario(IUsuario usuario) {
		Usuarios.add(usuario);
	}
	
	public void addLivro(Livro livro) {
		Livros.add(livro);
	}
	
	public void addReserva(Reserva reserva) {
		Reservas.add(reserva);
	}
	public void addEmprestimo(Emprestimo emprestimo) {
		Emprestimos.add(emprestimo);
	}
	
}
