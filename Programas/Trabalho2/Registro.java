/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Trabalho2;

/**
 *
 * @author thalita
 */
public class Registro {
    int id_func = -1;//inicializar cpm -1 para no caso do id ser 0
    String nome;
    String sobrenome;
    int idade;
    
    public Registro(){
        
    }
    
    public Registro(int id_func, String nome, String sobrenome, int idade){
        this.id_func = id_func;
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.idade = idade;
    }
    
    public Registro(String registros[]){
        this.id_func = Integer.parseInt(registros[0]);
        this.nome = registros[1];
        this.sobrenome = registros[2];
        this.idade = Integer.parseInt(registros[3]);
       
    }

    public int getId_func() {
        return id_func;
    }

    public void setId_func(int id_func) {
        this.id_func = id_func;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    
    /**
     * 
     * @param atributos 
     * @return registro  r com apenas os atributos desejados
     */
    
    public Registro atributosProjecao(int atributos[]){
        Registro r = new Registro();
        for(int i = 0; i< atributos.length;i++){
            if(atributos[i] == 0){
                r.id_func = this.id_func;             
            }
            
            if(atributos[i] == 1){
               r.nome = this.nome;
            }
        
            if(atributos[i] == 2){
               r.sobrenome = this.sobrenome;
            }
            
            if(atributos[i] == 3){
                r.idade = this.idade;
            }
        }       
        
        return r;
    }
    
    
    
    
    public int transformarBinario(int atributos[]){
        int a;
        String concatenacao ="";
        String aux = "";
        String r2 = "";
        char r ;
        

        for(int i = 0; i< atributos.length;i++){
            if(atributos[i] == 0){
                a = Integer.toString(this.id_func).hashCode();
                concatenacao = concatenacao + Integer.toString(a);
            }
            
            if(atributos[i] == 1){
                a = (this.nome).hashCode();
                concatenacao = concatenacao + Integer.toString(a);
            }
        
            if(atributos[i] == 2){
                a = (this.sobrenome).hashCode();
                concatenacao = concatenacao + Integer.toString(a);
            }
            
            if(atributos[i] == 3){
                a = Integer.toString(this.idade).hashCode();
                concatenacao = concatenacao + Integer.toString(a);
            }
        }
            
        a = concatenacao.hashCode();
        aux = Integer.toBinaryString(a);
        r = aux.charAt(aux.length()-2);
        r2 = r2+r;
        r2 = r2+aux.charAt(aux.length()-1);
        
        a = Integer.parseInt(r2);
       
        return a;
        
    }
    
    public void imprimirRegistro(){
        if(this.id_func != -1 ){
           System.out.println("\nId_func: "+this.id_func);
        }
         if(this.nome!=null ){
           System.out.println("\nNome: "+this.nome);
        }
        if(this.sobrenome!=null ){
           System.out.println("\nSobrenome: "+this.sobrenome);
        }
         if(this.idade != 0){
           System.out.println("\n\nIdade: "+this.idade);
        }
    }
    
     

}
