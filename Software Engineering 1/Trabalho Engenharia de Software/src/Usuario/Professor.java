package Usuario;

import java.time.LocalDate;

import java.util.ArrayList;
import java.util.List;

import ClassesSistema.Emprestimo;
import ClassesSistema.ExemplarLivro;
import ClassesSistema.FabricaClassesSistema;
import ClassesSistema.Livro;
import ClassesSistema.Reserva;
import Observador.IObservador;
import Verificadores.VerificadorEmprestimo;
import Verificadores.FabricaVerificadores;

public class Professor implements IUsuario, IObservador{
	private int Id;
	private String Nome;
	private ArrayList<Reserva> Reservas;
	private ArrayList<Emprestimo> Emprestimo;
	private VerificadorEmprestimo Verificador;
	
	public Professor(int Id, String Nome) {
		this.Id = Id;
		this.Nome = Nome;
		
		this.Emprestimo = new ArrayList<Emprestimo>();
		this.Reservas = new ArrayList<Reserva>();
		
		Verificador = FabricaVerificadores.criaVerificadorProfessor();
	}
	
	public void setVerificador(VerificadorEmprestimo NovoVerificador) {
		this.Verificador = NovoVerificador;
	}
	
	public int Notificacoes = 0;
	
	public int getId() {
		return this.Id;
	}
	public String getNome() {
		return this.Nome;
	}
	
	public List<Reserva> getReservas(){
		return this.Reservas;
	}
	public List<Emprestimo> getEmprestimos(){
		return this.Emprestimo;
	}
	
	public boolean TemReserva(Livro livro) {
		for(int i = 0; i < Reservas.size(); i++) {
			if(Reservas.get(i).getLivro().getTitulo() == livro.getTitulo()) {
				return true;
			}
		}
		return false;
	}
	
	public boolean TemEmprestimo(Livro livro) {
		for(int i = 0; i < this.Emprestimo.size(); i++) {
			if(this.Emprestimo.get(i).getLivro().getTitulo() == livro.getTitulo()) {
				return true;
			}
		}
		return false;
	}
	
	public void RemoveReserva(Livro livro) {
		for(int i = 0; i < Reservas.size(); i++) {
			if(Reservas.get(i).getLivro().getTitulo() == livro.getTitulo()) {
				Reservas.remove(i);
				livro.removeReserva(this);
			}
		}
	}
	
	public boolean Devedor() {
		LocalDate hoje = LocalDate.now();
		
		for(int i = 0; i < this.Emprestimo.size(); i++) {
			if(hoje.isAfter(this.Emprestimo.get(i).getDataDevolver())) {
				return true;
			}
		}
		return false;
	}
	
	public boolean Emprestimo(Livro livro) {
		//System.out.println("hey");
		if(Verificador.podePegar(this, livro, 0)) {
			ExemplarLivro exemplar = livro.getExemplarDisponivel();
			Emprestimo emp = FabricaClassesSistema.criarEmprestimo(this, exemplar, 3);
			exemplar.setEmprestimo(emp);
			Emprestimo.add(emp);
			this.RemoveReserva(livro);
			return true;
		}
		return false;
	}
	
	public boolean Devolver(Livro livro) {
		for(int i = 0; i < Emprestimo.size(); i++) {
			if(Emprestimo.get(i).getLivro() == livro) {
				Emprestimo.get(i).cancelEmprestimo();
				Emprestimo.remove(i);
				return true;
			}
		}
		return false;
	}
	
	public boolean Reservar(Livro livro) {
		Reserva reserva = FabricaClassesSistema.criarReserva(livro, this);
		if(Reservas.size() < 3) {
			Reservas.add(reserva);
			livro.addReserva(reserva);
			return true;	
		}
		return false;
	}
	public void Notificar() {
		Notificacoes++;
	}
	
	public String Consulta() {
		String msg = "";
		return msg + this.Notificacoes;
	}
}
