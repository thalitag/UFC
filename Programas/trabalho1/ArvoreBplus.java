
package trabalho1;

/**
 *
 * @author thalita
 */
public class ArvoreBplus{

    private No raiz; 
    
    public ArvoreBplus(){
        raiz = new No();
        raiz.setRaiz(true);
        raiz.setFolha(true);
    }

    public No getRaiz() {
        return raiz;
    }

    public void setRaiz(No raiz) {
        this.raiz = raiz;
    }
    
    /**
     * Imprime os elementos das folhas 
    */
    public void imprimirDados(){
        
        No noAux = new No();
        
        if (this.raiz.isFolha()){
            
            System.out.print("[ ");
            for (int i = 0; i < this.raiz.getQuantElementos(); i++) {
                System.out.print(this.raiz.getChaves()[i] + " ");
            }
            System.out.println(']');
        } else {
            noAux = this.raiz;
            //buscando a folha que contem o menor elemento
            while(noAux.isFolha() == false){
                
                noAux = noAux.getFilhos()[0];   
            }
            while (noAux.getNoDireita() != null) {
                noAux.imprimirNo();
                noAux = noAux.getNoDireita();
            }
            noAux.imprimirNo();
        }  
    }
    
    /**
     * Procura um No na arvore de acordo com a chave
     * @param chave
     * @return caso 1 (retorna nulo): a arvore so tem a raiz e o elemento nao esta nela
     * caso 2 (retorna a folha mais proxima do elemento): a arvore tem mais nos do que so a raiz, mas a folha nao tem o elemento
     * case 3 (retorna a folha que contem o elemento): a arvore tem mais nos do que so a raiz e uma das folhas contem o elemento
     */
    public No buscarNo(int chave){
        
        No noAux = null;
        
        //A arvore so tem a raiz
        if (this.raiz.isFolha() && this.raiz.verificaElemento(chave)){
            noAux = this.raiz;
        }
        //Busca a folha mais proxima do elemento ou folha que contem o elemento
        else if (!this.raiz.isFolha()){
            noAux = this.raiz;
            while(!noAux.isFolha()){
                noAux = noAux.getFilhos()[noAux.buscarPosicaoFilho(chave)];
            }
        }
        
        return noAux;
        
    }
    
    /**
     * Busca por igualdade
     * Verifica se a arvore tem determinado elemento/chave
     * @param chave
     * @return 
     */
    public boolean buscar(int chave){
        
        No noAux = null;
        
        if (this.raiz.isFolha() && this.raiz.verificaElemento(chave)){
            noAux = this.raiz;
        }
        else if (this.raiz.isFolha() == false){
            noAux = this.raiz;
            while(noAux.isFolha() == false){
                noAux = noAux.getFilhos()[noAux.buscarPosicaoFilho(chave)];
            }
        }
        
        boolean temElemento = false;
        
        if (noAux != null && noAux.verificaElemento(chave))
            temElemento = true;
        
        return temElemento;
            
    }
    
    
    /**
     * Busca por intervalo
     * Verifica se a arvore tem determinado elemento/chave
     * @param chave1
     * @param chave2
     */
    public void buscarPorIntervalo(int chave1, int chave2){
        
        No noAux = new No();
        
        System.out.print("Busca por intervalo ("+chave1+", "+chave2+"): ");
        
        //imprimir em ordem crescente
        if (chave1 <= chave2){
            noAux = buscarNo(chave1);
            while(noAux.getNoDireita() != null){
                for (int i = 0; i < noAux.getQuantElementos(); i++) {
                    if (noAux.getChaves()[i] >= chave1 && noAux.getChaves()[i] <= chave2){
                        System.out.print(noAux.getChaves()[i] + " ");
                    }
                }
                noAux = noAux.getNoDireita(); 
            }
            for (int i = 0; i < noAux.getQuantElementos(); i++) {
                if (noAux.getChaves()[i] >= chave1 && noAux.getChaves()[i] <= chave2){
                    System.out.print(noAux.getChaves()[i] + " ");
                }
            }
            System.out.println();
        }
        
        //imprimir em ordem decrescente
        else {
            noAux = this.buscarNo(chave1);
            
            while (noAux.getNoEsquerda() != null){
                for (int i = (noAux.getQuantElementos()-1); i >= 0; i--) {
                    
                    //System.out.print(noAux.getChaves()[i] + " ");
                    if (noAux.getChaves()[i] <= chave1 && noAux.getChaves()[i] >= chave2){
                        System.out.print(noAux.getChaves()[i] + " ");
                    }
                }
                noAux = noAux.getNoEsquerda(); 
            }
            for (int i = (noAux.getQuantElementos()-1); i >= 0; i--) {
                if (noAux.getChaves()[i] <= chave1 && noAux.getChaves()[i] >= chave2){
                    System.out.print(noAux.getChaves()[i] + " ");
                }
            }
            System.out.println();
        }
        
    }
    
    
    /**
     * Insere todos os elementoos de um vetor
     * @param vetor
     */
    public void insercaoEmMassa(int[] vetor){
        for (int i = 0; i < vetor.length; i++) {
            this.inserir(vetor[i]);
        }
    }
    
    
    /**
     * Adiciona um elemento a arvore 
     * @param chave
     */
    public void inserir(int chave){
        
        //A arvore so tem a raiz e ela nao esta cheia
        if (this.raiz.isFolha() && this.raiz.getQuantElementos() < 9){
            this.raiz.addChave(chave);
            this.raiz.ordena();
        } 
        
        //a arvore so tem a raiz, mas a raiz esta cheia
        else if (this.raiz.isFolha() && this.raiz.getQuantElementos() == 9){
            
            //fazendo o split da raiz
            No nos[] = new No[2];
            nos = this.raiz.split(chave);

            this.raiz = new No();
            this.raiz.addChave(nos[1].getChaves()[0]);
            this.raiz.setFilhos(nos);
            this.raiz.setRaiz(true);
            this.raiz.setFolha(false);

            this.raiz.getFilhos()[0].setFolha(true);
            this.raiz.getFilhos()[0].setNoDireita(nos[1]);
            this.raiz.getFilhos()[0].setPai(this.raiz);
            this.raiz.getFilhos()[1].setFolha(true);
            this.raiz.getFilhos()[1].setNoEsquerda(nos[0]);
            this.raiz.getFilhos()[1].setPai(this.raiz);
            
        }
        
        //A arvore tem mais nos que somente a raiz
        else if (this.raiz.isFolha() == false){
            
            //noAux: no que contem a folha do elemento a ser inserido
            No noAux = new No();
            noAux = this.buscarNo(chave);
            
            //a folha nao esta cheia
            if (noAux.getQuantElementos() < 9){
                noAux.inserirFolha(chave);
            } 
            
            //a folha esta cheia
            else {
                //o no pai nao esta cheio
                if (noAux.getPai().getQuantElementos() < 9){
                    noAux.inserirFolha(chave);
                } 
                //o no pai tambem esta cheio 
                else {
                    while (noAux.getPai().getQuantElementos() == 9){
                        noAux.inserirFolha(chave);
                        noAux = noAux.getPai();
                        //.inserir(chave);
                    }
                }
            }
        }
    }
    
    public void remover(int chave){
               
        //remoção de chave no caso de só houver a raiz
        if (this.raiz.isFolha()){
            this.raiz.ordenaRemocao(chave);
        } 
        else{
           //se houver mais de uma chave no nó folha, fazer a remoção normalmente
            if(this.buscar(chave) && this.buscarNo(chave).getQuantElementos()> 1){
                this.buscarNo(chave).ordenaRemocao(chave);
            }
                      
        }

    }
    
       
}
