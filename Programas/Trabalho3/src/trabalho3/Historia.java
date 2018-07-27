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
public class Historia {
    String [] historia;
    int tamanhoHistoria;
    
    Historia(){ 
      this.historia = null;
    }
    
    Historia(String h[]){
        this.historia = h;
        this.tamanhoHistoria = h.length;
    }
    /**
     * Checa se a historia é válida 
     */
    public void checarHistoria(){
        Dado d;
        boolean erro= false;
        String transacao = "";//guarda o valor da transação(para saber ql transação está realizando a operação)
        int transacaoInt, posicaoTroca,posicaoTroca2,ultimaTransacaoR, ultimaTransacaoW;
        String ultimaTR ="",ultimaTw="";
        for (int i = 0; i <tamanhoHistoria ; i++) {
        if(this.historia[i].charAt(0)=='r'||this.historia[i].charAt(0)=='w'){    
                transacao += this.historia[i].charAt(1);
                transacaoInt = Integer.parseInt(transacao);
               
                d = this.getDado(Dado.dados,this.historia[i].charAt(this.historia[i].length()-2));
                
                //se a operação for read
                if(this.historia[i].charAt(0)=='r'){
                    if(d.timestampWrite>0 && transacaoInt < d.timestampWrite){

                    this.TratarErroOperaçãoRead(d, i, this.historia[i]);
                    erro = true;
                    //break;
                    this.checarHistoria();
                    }
                    else{
                        d.timestampRead = transacaoInt;
                        Dado.ImprimirDados();
                        
                    }
                }
 
                //se a operação for write
               
                if (this.historia[i].charAt(0)=='w'){
                 
                    if(d.timestampWrite>0 &&transacaoInt < d.timestampWrite ){
                     
                        this.TratarErroOperacaoWrite(d, i, this.historia[i], transacaoInt);
                        erro = true;
                        break;                   
                        
                    }
                    else if(d.timestampRead>0 && transacaoInt< d.timestampRead){
                       
                        this.TratarErroOperacaoWrite(d, i, this.historia[i], transacaoInt);
                        erro = true;
                        break;  
                    }
                    else{
                         d.timestampWrite = transacaoInt;
                         Dado.ImprimirDados();
                    }
                }                                              
            }    
          transacao = ""; 
        }//endfor
               
        if(!erro){
            System.out.println("\nResultado:");
            this.imprimirHistoria();
        }
        else{
            Dado.reinicializarDados();
            Dado.ImprimirDados();
            this.checarHistoria();
        }
       
    }    
    /**
     * Imprime a história
     */
    public void imprimirHistoria(){
        //System.out.println("\n");
        for (int i = 0; i < tamanhoHistoria; i++) {
            System.out.print(this.historia[i]+" ,");
        }
        System.out.println("\n");
    }
    public Dado getDado(ArrayList<Dado> a, char id){
        Dado d = new Dado(); 
        for (int i = 0; i < a.size(); i++) {
            if(id == a.get(i).id){
                d = a.get(i);
            }
        }
        return d;
    }
    /**
     * Reorganiza a historia trocando uma operação de lugar e reposicionando a frente da operação que já tinha realizado operação no dado
     * @param posicaoOperacao recebe a posição da operação atual que vai ser reposicionada
     * @param posicaoTroca recebe a posição da operação que ja tinha realizado operação no dado
     */
    public void trocarOperacoes(int posicaoOperacao, int posicaoTroca){
        String aux,aux2; 
       
        aux = this.historia[posicaoOperacao];
             
        for (int i = posicaoOperacao; i > posicaoTroca; i--) {
            this.historia[i]=this.historia[i-1];        
        }
        this.historia[posicaoTroca] = aux;
    }
    /**
     * Percorre a historia e cria objetos relacionados aos dados existentes
     * @param s (string que representa a historia)
     */
    public void setDados(String[] s){
        Dado d;
        for (int i = 0; i<s.length; i++) {
              if(!(s[i].startsWith("BT")||
                 s[i].startsWith("CM")||     
                 s[i].startsWith("FL")||
                 s[i].startsWith("CP")))
                {

               
                d = new Dado();
                 //checa se o dado ja está no array caso contrario o adiciona em dados
                 for(int j = 0; j <s[i].length();j++){                            
                    if(s[i].charAt(j)=='('){
                        d.id = s[i].charAt(j+1);
                        if(!d.verificarDado(Dado.dados)){
                             Dado.dados.add(d);
                        }
                    }
                }    
            }
        }
    }

    /**
     * Busca a posição de uma operação na historia
     * @param dado
     * @param transacao
     * @param operacao
     * @return posição
     */
    public int buscarOperacao(char dado, String transacao, String operacao){
     
        String op =operacao+transacao+"("+dado+")";
       // System.out.println("Metodo buscarOperacao op: "+ op);
        for (int i = 0; i < this.tamanhoHistoria; i++) {
            if(op.equals(this.historia[i])){
                return i;
            }
        }
        return -1;
    }
    
    /**
     * Trata erro na operação read
     * @param d
     * @param posicaoHistoria
     * @param operacao 
     */
    public void TratarErroOperaçãoRead(Dado d, int posicaoHistoria, String operacao){
        int posicaoTroca;
        System.out.println("\nProblema encontrado na operação: "+ operacao);
        posicaoTroca = this.buscarOperacao(d.id,String.valueOf(d.timestampWrite),"w");

        this.trocarOperacoes(posicaoHistoria, posicaoTroca);
        System.out.println("História para nova tentativa: ");
        this.imprimirHistoria();    
    }
    /**
     * Trata erro na operação write
     * @param d
     * @param posicaoHistoria
     * @param operacao
     * @param transacao 
     */
    public void TratarErroOperacaoWrite(Dado d, int posicaoHistoria, String operacao, int transacao){
        int posicaoTroca;
        System.out.println("\nProblema encontrado na operação: "+ operacao);
        
        //se o TSR e o TSW do dao forem iguais e o TS da transação for menor que os TS do dado 
        if(d.timestampRead==d.timestampWrite && transacao<d.timestampRead){
            System.out.println("Transação "+d.timestampRead+" já leu e escreveu o dado "+d.id);
            posicaoTroca = this.buscarOperacao(d.id,String.valueOf(d.timestampRead),"r");
            this.trocarOperacoes(posicaoHistoria, posicaoTroca);
        }
        
        //se o TS da transação for menor que o TSR do dado 
        if(transacao< d.timestampRead){
            posicaoTroca = this.buscarOperacao(d.id,String.valueOf(d.timestampRead),"r");
            System.out.println("Transação "+d.timestampRead+" já leu o dado "+d.id);
            //System.out.println("2 : posicaoTroca: "+posicaoTroca);
            this.trocarOperacoes(posicaoHistoria, posicaoTroca);
        }
        
        //se o TS da transação for menor que o TSW do dado  
        if(transacao < d.timestampWrite){
            System.out.println("Transação "+d.timestampWrite+" já escreveu o dado "+d.id);
            posicaoTroca = this.buscarOperacao(d.id,String.valueOf(d.timestampRead),"w");
            //System.out.println("3 : posicaoTroca: "+posicaoTroca);
            this.trocarOperacoes(posicaoHistoria, posicaoTroca);
        }


        System.out.println("História para nova tentativa: ");
        this.imprimirHistoria();

    }
}
