/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho3;

import java.util.ArrayList;

/**
 *
 * @author thalita
 */
public class Recuperacao {
    String [] historia;
    int tamanhoHistoria;
    ArrayList <String> redo = new ArrayList<String>();
    ArrayList <String> undo = new ArrayList<String>();
    
    public Recuperacao(String h[]){
        this.historia = h;
        this.tamanhoHistoria = h.length;
        this.checarRedo();
        this.imprimirArray(redo);
        this.checarUndo();        
        this.imprimirArray(undo);
  
    }
    /**
     * 
     * @return posição do CHECKPOINT na historia 
     */
    public int posicaoCP(){

        for (int i = 0; i < tamanhoHistoria; i++) {
            if(this.historia[i].startsWith("CP")){
                return i;
            }
        }
        return -1;
    }
    
    public int posicaoCM(int transacao){
        for(int i = 0; i < tamanhoHistoria; i++ ){
            if(this.historia[i].startsWith("CM")){
                if(this.historia[i].charAt(this.historia[i].length()-2) == transacao){
                    return i;
                }
            }
        }
        return -1;
    }
    
    public int posicaoFalha(){
        for(int i = 0; i < tamanhoHistoria; i++ ){
            if(this.historia[i].startsWith("FL")){
               return i;              
            }
        }
        return -1;
    }
    
    public void checarRedo(){

        ArrayList<Character> transacoes = new ArrayList<Character>(); 
        char t;
        for (int i = this.posicaoCP(); i < this.posicaoFalha(); i++) {   //checar os commits antes da falha e depois do checkpoint       
            if(this.historia[i].startsWith("CM")){
                t = this.historia[i].charAt(this.historia[i].length()-2); 
                transacoes.add(t);    
                //System.out.println("Transação: "+ t);
            }        
        }
        
        for(int i = 0; i < transacoes.size();i++){

            t = transacoes.get(i);
            int c;
            c = transacoes.get(i);
            for(int j = 0; j < this.posicaoFalha();j++){
                if(this.historia[j].charAt(0)=='w'&& this.historia[j].charAt(1)== c){
                    redo.add(this.historia[j]);
                    
                }
            }
        }     
        System.out.println("Redo: ");
    }
    
    public void checarUndo(){
         ArrayList<Character> transacoes = new ArrayList<Character>();
         char t;
         //saber quas transações não terminaram antes da falha
         for (int i = this.posicaoFalha(); i < tamanhoHistoria; i++) {
            if(this.historia[i].startsWith("CM")){
                t = this.historia[i].charAt(this.historia[i].length()-2); 
                transacoes.add(t);    
                
            }     
        }
        
         for(int i = 0; i < transacoes.size();i++){
            int c;
            c = transacoes.get(i);
            for(int j = 0; j < this.posicaoFalha();j++){
                if(this.historia[j].charAt(0)=='w' && this.historia[j].charAt(1)== c){
                    undo.add(this.historia[j]);
                    //System.out.println("Operação redo: "+ this.historia[j]);
                }
            }
        } 
        
        System.out.println("Undo :");
    }
    
    
    
    public void imprimirArray(ArrayList<String> a){
        for (int i = 0; i < a.size(); i++) {
            System.out.println(a.get(i));
        }
        System.out.println("");
    }
}
