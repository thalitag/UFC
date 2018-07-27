
package trabalho3;

import java.util.ArrayList;

/**
 *
 * @author thalita
 */
public class Dado {
    char id;
    int timestampRead = 0;
    int timestampWrite = 0;
    static ArrayList<Dado> dados = new ArrayList<Dado>();
    
    public Dado(){}
    
    public Dado(char id, int timeStamp){
        this.id = id;
    }
    /**
     * Verifica se um dado existe no array de dados
     * @param a
     * @return 
     */
    public boolean verificarDado(ArrayList<Dado> a){
        boolean existe = false;
        for(int i = 0 ; i< a.size(); i++){
            if(a.get(i).id == this.id){
                existe = true;
            }
        }
        return existe;
    }
    
    static void ImprimirDados(){
        System.out.println("\nDados: ");
        for (int i = 0; i < Dado.dados.size(); i++) {
            
            System.out.println("< "+Dado.dados.get(i).id+", "+Dado.dados.get(i).timestampRead+", "+Dado.dados.get(i).timestampWrite+" >");
        }
    }
    
    /**
     * zera os valores dos timestamps dos dados
     */
    static void reinicializarDados(){
        for (int i = 0; i < Dado.dados.size(); i++) {
            Dado.dados.get(i).timestampRead = 0;
            Dado.dados.get(i).timestampWrite = 0;
        }
    }
}
