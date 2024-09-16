package Destinatario;

import Sistema.Sistema;
import Observador.IObservador;

import java.time.LocalDate;

import ClassesSistema.*;
import Usuario.IUsuario;
import Console.Console1;

public class Facade {
	
	private static Facade singleton;
	
	private Facade() {};
	
	public static Facade AcessarSingleton() {
		if(singleton == null) {
			singleton = new Facade();
		}
		return singleton;
	}
	
	private boolean aux;
	
	public void Run() {
		this.aux = true;
		Console1 c = new Console1();
		Sistema.getBiblioteca().Inicializar();
		
		while(this.aux) {
			c.Executar();
		}
	}
	
	public String Emprestar(int CodUsuario, int CodLivro) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		Livro livro = Sistema.getBiblioteca().getLivro(CodLivro);
		
		//Pq nao foi poss�vel
		boolean var = usuario.Emprestimo(livro);
		if(var == true) {
			return "Sucesso, voce (" + usuario.getNome() + ") alugou " + livro.getTitulo();
		}
		return usuario.getNome() + " nao foi poss�vel alugar " + livro.getTitulo();
	}
	
	public String Devolver(int CodUsuario, int CodLivro) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		Livro livro = Sistema.getBiblioteca().getLivro(CodLivro);
		
		boolean var = usuario.Devolver(livro);
		String msg = "";
		if(var) {
			msg += livro.getTitulo() + " devolvido, obrigado " + usuario.getNome(); 
		}else {
			msg += usuario.getNome() + ", nao foi localizado o emprestimo de " + livro.getTitulo();
		}
		return msg;
	}
	
	//Pronto
	public String ConsultaLivro(int CodLivro) {
		Livro livro = Sistema.getBiblioteca().getLivro(CodLivro);
		String msg = livro.consulta();
		
		return msg;
	}
	
	//Pronto
	public String ConsultaAluno(int CodUsuario) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		String msg = usuario.Consulta();
		
		return msg;
	}
	
	//Pronto
	public String ConsultaProfessor(int CodUsuario) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		String msg = usuario.Consulta();
		
		return msg;
	}
	
	//Pronto
	public String Reservar(int CodUsuario, int CodLivro) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		Livro livro = Sistema.getBiblioteca().getLivro(CodLivro);
		
		boolean var = usuario.Reservar(livro);
		
		String msg;
		
		if(var) {
			msg = "Senhor(a), " + usuario.getNome() + " o livro " + livro.getTitulo() + " foi reservado.";
		}else {
			msg = "Senhor(a), " + usuario.getNome() + " nao foi possivel reservar o livro " + livro.getTitulo();
		}
		return msg;
	}
	
	//Pronto
	public String Observar(int CodUsuario, int CodLivro) {
		IUsuario usuario = Sistema.getBiblioteca().getUsuario(CodUsuario);
		Livro livro = Sistema.getBiblioteca().getLivro(CodLivro);
		
		livro.addObserver((IObservador) usuario);
		
		return "";
	}
	public String Sair() {
		this.aux = false;
		return "Saiu";
	}
}