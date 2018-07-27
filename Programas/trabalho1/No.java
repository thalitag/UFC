/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho1;

/**
 *
 * @author thalita
 */
public class No {
    
    //private int idNo ;      
    private int chaves[];//9 chaves por nó
    private No filhos[]; //cada nó pai pode ter 10 filhos
    private No pai; //cada nó tem 1 pai
    private boolean folha; 
    private boolean raiz; 
    private int quantElementos;
    private No noEsquerda;
    private No noDireita;

    
    //Construtor
    public No(){
        this.chaves = new int[9];
        this.filhos = new No[10];
        this.pai = null;
        this.raiz = false;
        this.folha = false;
        this.quantElementos = 0;
        this.noEsquerda = null;
        this.noDireita = null;
    }
    
    //Getters e Setters
    public boolean isFolha() {
        return folha;
    }

    public void setFolha(boolean folha) {
        this.folha = folha;
    }

    public boolean isRaiz() {
        return raiz;
    }

    public void setRaiz(boolean raiz) {
        this.raiz = raiz;
    }
    
    public No getPai() {
        return pai;
    }

    public void setPai(No pai) {
        this.pai = pai;
    }

    public int[] getChaves() {
        return chaves;
    }

    public void setChaves(int[] chaves) {
        this.chaves = chaves;
    }

    public No[] getFilhos() {
        return filhos;
    }

    public void setFilhos(No[] filhos) {
        this.filhos = filhos;
    }

    public int getQuantElementos() {
        return quantElementos;
    }

    public void setQuantElementos(int quantElementos) {
        this.quantElementos = quantElementos;
    }

    public No getNoEsquerda() {
        return noEsquerda;
    }

    public void setNoEsquerda(No noEsquerda) {
        this.noEsquerda = noEsquerda;
    }

    public No getNoDireita() {
        return noDireita;
    }

    public void setNoDireita(No noDireita) {
        this.noDireita = noDireita;
    }
    
    
    
    /**
    * Insere uma chave em um No nao cheio
     * @param chave
    */
    public void addChave(int chave){
        
        if (this.quantElementos < 9){
            this.getChaves()[this.getQuantElementos()] = chave;
            this.setQuantElementos(this.getQuantElementos()+1);
        }
        
    }
    
    public void removerChave(int chave){
        this.getChaves()[this.getQuantElementos()] = 0;
        this.setQuantElementos(this.getQuantElementos()-1);
        
    }
    
    
    /**
    * Ordena as chaves de um No
    */
    public void ordena(){
        
        int aux;
        
        if(this.quantElementos > 1){
            for(int i = 0; i < this.quantElementos ; i++){
                for(int j = 0; j < this.quantElementos -1; j++){
                    if(this.chaves[j] > this.chaves[j+1]){
                        aux = this.chaves[j];
                        this.chaves[j] = this.chaves[j+1];
                        this.chaves[j+1] = aux;
                    }
                }
            }
        }
    }
    /**
     * Ordena as chaves depois de uma remoção
     * @param chave 
     */
    public void ordenaRemocao(int chave){
        
        //se a chave estiver na ultima posição
        if(this.chaves[8]==chave){
            this.chaves[8]=0;
        }
        else{
            for(int i = 0; i < this.quantElementos-1 ; i++){   
                if(this.chaves[i] == chave){
                    this.chaves[i] = this.chaves[i+1];
                    this.chaves[i+1] = 0;
                    chave = this.chaves[i+1];
                }
            }
        }
    }
    
    
    /**
    * Retorna a posicao do No filho a partir de uma chave
    * Sera usado para o metodo buscar
     * @param chave
     * @return 
    */
    public int buscarPosicaoFilho(int chave){
        
        int valor = 0;
        
        for (int i = 0; i < this.quantElementos ; i++) {
            if (this.chaves[i] <= chave)
                valor = i+1;
        }
        return valor;
    }
    
    /**
     * Verifica se um No tem determinado elemento/chave
     * @param chave
     * @return boolean
     */
    public boolean verificaElemento(int chave){
        
        boolean temElemento = false;
        
        for (int i = 0; i < this.quantElementos ; i++) {
            if (this.chaves[i] == chave)
                temElemento = true;
        }
        
        return temElemento;
    }
    
    /**
     * Imprime os elementos do No 
    */
    public void imprimirNo(){
        
        System.out.print("[ ");
        for (int i = 0; i < this.quantElementos ; i++) {
            System.out.print(this.chaves[i]+" ");
        }
        System.out.println(']');
    }
    
    /**
     * Divide um no em dois
     * @param chave
     * @return 
     */
    public No[] split(int chave){
        
        No nos[] = new No[2];
        No novoNo = new No();
        
        int vetorAux[] = new int[10];
        
        System.arraycopy(this.chaves, 0, vetorAux, 0, 9);
        
        vetorAux[9] = chave;
        
        int aux;
        
        //ordena vetor
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 9; j++){
                if(vetorAux[j] > vetorAux[j+1]){
                    aux = vetorAux[j];
                    vetorAux[j] = vetorAux[j+1];
                    vetorAux[j+1] = aux;
                }
            }
        }
        
        this.quantElementos = 5;
        System.arraycopy(vetorAux, 0, this.chaves, 0, 5);
        
        novoNo.quantElementos = 5;
        novoNo.chaves[0] = vetorAux[5];
        novoNo.chaves[1] = vetorAux[6];
        novoNo.chaves[2] = vetorAux[7];
        novoNo.chaves[3] = vetorAux[8];
        novoNo.chaves[4] = vetorAux[9];
        
        nos[0] = this;
        nos[1] = novoNo;
        
        return nos;
    }
    
    public void reorganizarChaves(){
        
        //bubble sort
        for(int i = 0; i < 9 ; i++){
           for(int j = 0; j < 8; j++){
                if(this.chaves[i]!=0){
                    int aux;
                    if(this.chaves[j] > this.chaves[j+1] && this.chaves[j+1]!= 0){
                        aux = this.chaves[j];
                        this.chaves[j] = this.chaves[j+1];
                        this.chaves[j+1] = aux;
                    }
                }
            }
        }
    }
  
    
    public void inserirFolha(int chave){ // SOMENTE PARA NÓS FOLHAS
        
       //1º caso - há espaço na folha
        int espacoLivre =  this.verificarNo();
        int espacoLivrePai =  this.pai.verificarNo();
        if(espacoLivre != -1){
            this.chaves[espacoLivre] = chave;
            this.reorganizarChaves();
            this.setQuantElementos(this.getQuantElementos()+1);
        }
        
        //2º caso - nó folha não possui espaço mas ainda há espaço no nó pai
        
        else if(espacoLivre == -1 && espacoLivrePai != -1){
            No novoNo = new No();
            
            int noAux[] = new int [10];
            System.arraycopy(this.chaves, 0, noAux, 0, 9);
            noAux[9] = chave;

            for(int i = 0; i < 10 ; i++){
                for(int j = 0; j < 9; j++){
                    if(noAux[i]!=0){
                        int aux;
                        if(noAux[j] > noAux[j+1] && noAux[j+1]!= 0){
                            aux = noAux[j];
                            noAux[j] = noAux[j+1];
                            noAux[j+1] = aux;
                        }
                    }
                }
            }
            int chaveSubir = noAux[5];
            for(int i = 0; i < 9; i++ ){
                if(i < 5){
                    this.chaves[i] = noAux[i];
                }
                this.chaves[i] = 0;
                novoNo.chaves[i-5] = noAux[i];
            }
        
            
            int posicaoInsercaoPai = 0;
            for(int i = 0; i < 9; i++){
                if(chaveSubir < this.pai.chaves[i]){
                    posicaoInsercaoPai = i; // guarda a posição que a nova chave será inserida no pai
                    break;
                }    
                posicaoInsercaoPai = 8;
            }
            
            
            int aux2 = chaveSubir;
            No noaux2 = new No();
            noaux2 = novoNo;
            No noaux3 = new No();
            int aux3;
            for(int l = posicaoInsercaoPai; l < 9; l++){
                aux3 = this.pai.chaves[l];
                noaux3 = this.pai.filhos[l+1];
                this.pai.chaves[l] = aux2;
                this.pai.filhos[l+1] = noaux2;
                aux2 = aux3;
                noaux2 = noaux3;
            }
            
        }
 
    
    }

    
    //TODO RECURSIVIDADE 
    /*1 - examinar se a folha esta cheia(outro metodo)
      2 - buscar recursivamente o pai que ainda possui espaço para nova chave  
        2.1 - fazer a divisão dos pais no processo e subir a chave   
        (se a chave que foi inserida na folha subiu novamente, não há necessidade de inseri-la novamente nos indices)
    */
        
    //verifica se possui espaço para nova chave e retorna o proximo espaço livre
    public int verificarNo(){
        int chaveLivre = -1;
        for(int i = 0; i<=8; i++){
            if(this.chaves[i] == 0){
                chaveLivre = i;
            return chaveLivre;
            }
        }
        return chaveLivre;
    }   
    
}