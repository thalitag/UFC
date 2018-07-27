
package Trabalho2;

/**
 *
 * @author thalita
 */
public class Pagina {
    
    public final int quantMaxRegistros = 16; // numero maximo de registro que a pagina pode ter
    private Registro registros[] = new Registro[quantMaxRegistros]; 
    private int qntRegistros = 0; //quantidade de registros que a pagina esta no momento
    
    public Pagina(){
        
    }
    
    public Pagina(Registro registros[]){
        this.registros = registros;
    }

    public Registro[] getRegistros() {
        return registros;
    }
    
    public Registro getRegistro(int posicaoRegistro){
        return this.registros[posicaoRegistro];
    }

    public int getQntRegistros() {
        return qntRegistros;
    }

    public void adicionarRegistro(Registro r){
     
        if(this.qntRegistros > this.registros.length-1){
            System.out.println("Pagina cheia");          
        }
        else{
            this.registros[qntRegistros] = r;
            this.qntRegistros++; 
        }
        
    }
    
    /**
    *
    * Apaga todos os registros
    */
    public void apagarRegistros(){
        for(int i = 0; i < this.registros.length; i++){
            this.registros[i] = null;
        }
        this.qntRegistros = 0;
    }
    
    public void imprimirPagina(){
        for(int i = 0; i < registros.length; i++){
            if(registros[i]!=null){
                System.out.println("\n\nRegistro "+ i);
            this.registros[i].imprimirRegistro();    
            }
        }
    }

}
