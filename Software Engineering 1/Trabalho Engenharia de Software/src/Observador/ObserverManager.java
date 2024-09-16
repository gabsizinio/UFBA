package Observador;
import java.util.List;
import java.util.ArrayList;

 public class ObserverManager {
	private List<IObservador> Observadores;
	
	public ObserverManager() {
		Observadores = new ArrayList<>();
	}
	
	public void Notificar() {
		if(Observadores != null) {
			for(int i = 0; i < Observadores.size(); i++) {
				Observadores.get(i).Notificar();
			}
		}
	}
	
	public void addObs(IObservador NovoObservador) {
		Observadores.add(NovoObservador);
	}
}
