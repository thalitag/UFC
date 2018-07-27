/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Trabalho2;

import java.util.ArrayList;

/**
 *
 * @author rvictor
 */
public class Main {
    
    public static void main(String[] args) {
        ArrayList< Registro > b = new ArrayList<  >();
        Tabela t = new Tabela();
        
        Tabela t2 = new Tabela();
        t.lerArquivo("C:/Users/thali/Documents/NetBeansProjects/SGBD/src/Trabalho2/");       
        //t.lerArquivo("/home/rvictor/Área de Trabalho/repositorios/sgbd/src/Trabalho2");
        //int i = t.paginas.size();
        //Pagina p = t.getPagina(i-2);
        
        //Pagina p = new Pagina();
        //p = t.paginas.get(0);
        //p.imprimirPagina();
        //System.out.println("quantidade de paginas na tabela: "+t.getPaginas().size());
        //System.out.println(i);
        int atributos[] = {1,2};
       // b = t.projetarIdade(30,40);
        //for(int i = 0; i < b.size(); i++){
          // b.get(i).imprimirRegistro();
        //}
        t2 = t.tabelaTemporaria(atributos);
        Hash h = new Hash(t,atributos);
       
        h.imprimirBucket(1);
       
        //t2.imprimirTabela();
        
        
    }
    
}
