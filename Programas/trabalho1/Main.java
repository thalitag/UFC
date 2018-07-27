/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho1;

/**
 *
 * @author rvictor
 */
public class Main {
    
    public static void main(String[] args) {
        
        ArvoreBplus bpt = new ArvoreBplus();
        
        /*
        bpt.imprimirDados();
        bpt.inserir(2);
        bpt.inserir(8);
        bpt.inserir(8);
        bpt.inserir(5);
        bpt.inserir(4);

        //bpt.inserir(1);
        bpt.imprimirDados();
        bpt.remover(6);

        bpt.inserir(1);
        bpt.inserir(10);
        bpt.inserir(11);
        bpt.inserir(12);
        bpt.inserir(7);
>>>>>>> 8d22915175eb2fe5417c37235acc05c81c3c7e8a
        bpt.imprimirDados();
       
        
        //exemplo imprimindo na ordem crescente
        bpt.buscarPorIntervalo(4, 7);
        //exemplo imprimindo na ordem decrescente
        bpt.buscarPorIntervalo(7, 4);
        
      
       
        //exemplo: imprimindo o No que contem o elemento 1
        //se nao tiver retorna null ou a folha mais proxima
        if(bpt.buscarNo(1) != null){
            System.out.print("No do elemento 1: ");
            bpt.buscarNo(1).imprimirNo();
        } else {
            System.out.println("A arvore nao possui o elemeto 1");
        }
        
        //exemplo: imprimindo o No que contem o elemento 3
        //se nao tiver retorna null ou a folha mais proxima
        if(bpt.buscarNo(3) != null){
            System.out.print("No do elemento 3: ");
            bpt.buscarNo(3).imprimirNo();
        } else {
            System.out.println("A arvore nao possui o elemeto 3:");
        }
        
        //exemplo: imprimindo o No que contem o elemento 7
        //se nao tiver retorna null ou a folha mais proxima
        if(bpt.buscarNo(7) != null){
            System.out.print("No do elemento 7: ");
            bpt.buscarNo(7).imprimirNo();
        } else {
            System.out.println("A arvore nao possui o elemeto 7:");
        }
        
        if(bpt.buscar(1))
            System.out.println("a arvore contem o elemento 1");
        else
            System.out.println("a arvore nao contem o elemento 1");
        
        if(bpt.buscar(4))
            System.out.println("a arvore contem o elemento 4");
        else
            System.out.println("a arvore nao contem o elemento 4");
        
        if(bpt.buscar(7))
            System.out.println("a arvore contem o elemento 7");
        else
            System.out.println("a arvore nao contem o elemento 7");
        */
        
        bpt.imprimirDados();
        
        int[] vetor = new int[10];
        vetor[0] = 20;
        vetor[1] = 40;
        vetor[2] = 50;
        vetor[3] = 10;
        vetor[4] = 60;
        vetor[5] = 100;
        vetor[6] = 90;
        vetor[7] = 30;
        vetor[8] = 70;
        vetor[9] = 80;
        bpt.insercaoEmMassa(vetor);
        /*
        bpt.inserir(20);
        bpt.inserir(40);
        bpt.inserir(50);
        bpt.inserir(10);
        bpt.inserir(60);
        bpt.inserir(100);
        bpt.inserir(90);
        bpt.inserir(30);
        bpt.inserir(70);
        bpt.inserir(80);
        */
        bpt.getRaiz().imprimirNo();
        bpt.imprimirDados();
        

        System.out.println(bpt.buscar(80) ? "true" : "false");
        System.out.println(bpt.buscar(85) ? "true" : "false");

        System.out.println(bpt.getRaiz().isFolha() ? "true" : "false");

        bpt.buscarPorIntervalo(25, 60);
        bpt.buscarPorIntervalo(60, 20);
        bpt.buscarNo(60).imprimirNo();
        
        bpt.remover(60);
        bpt.getRaiz().imprimirNo();
        bpt.buscarNo(60).imprimirNo();


    }
}
