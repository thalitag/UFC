/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Trabalho2;

import java.util.ArrayList;

/**
 *
 * @author thalita
 */
public class Hash {
    ArrayList< Registro > bucket_00 = new ArrayList<  >(); 
    ArrayList< Registro > bucket_01 = new ArrayList<  >(); 
    ArrayList< Registro > bucket_10 = new ArrayList<  >(); 
    ArrayList< Registro > bucket_11 = new ArrayList<  >(); 

    public Hash(){
        
    }
    /**
     * Particiona os registro de mesma terminação de bits em buckets
     * @param t
     * @param atributos 
     */
    public Hash(Tabela t, int atributos[]){
        int digitos = 0;
        Tabela taux = new Tabela ();
        taux = t.tabelaTemporaria(atributos);
        for(int i = 0 ; i < taux.paginas.size(); i++){
            for(int j = 0; j < taux.paginas.get(i).getQntRegistros();j++){
                digitos = t.paginas.get(i).getRegistro(j).transformarBinario(atributos);
                switch (digitos) {
                    case 0:
                        this.bucket_00.add(taux.paginas.get(i).getRegistro(j));
                        break;
                    case 1:
                        this.bucket_01.add(taux.paginas.get(i).getRegistro(j));
                        break;
                    case 10:
                        this.bucket_10.add(taux.paginas.get(i).getRegistro(j));
                        break;
                    case 11:
                        this.bucket_11.add(taux.paginas.get(i).getRegistro(j));
                        break;
                    default:
                        break;
                }                     
            }
        }
    }

    public void imprimirBucket(int bucket){
        switch (bucket) {
            case 0:
                System.out.println("\nBucket_00 possui "+(this.bucket_00.size())+" elementos");
                for(int i = 0; i < this.bucket_00.size(); i++){
                    this.bucket_00.get(i).imprimirRegistro();
                }
                break;
            case 1:
                System.out.println("\nBucket_01 possui "+(this.bucket_01.size())+" elementos");
                for(int i = 0; i < this.bucket_01.size(); i++){
                    this.bucket_01.get(i).imprimirRegistro();
                }
                break;
            case 10:
                System.out.println("\nBucket_10 possui "+(this.bucket_10.size())+" elementos");
                for(int i = 0; i < this.bucket_10.size(); i++){
                    this.bucket_10.get(i).imprimirRegistro();
                }
                break;
            case 11:
                System.out.println("\nBucket_11 possui "+(this.bucket_11.size())+" elementos");
                for(int i = 0; i < this.bucket_11.size(); i++){
                    this.bucket_11.get(i).imprimirRegistro();
                }
                break;
            default:
                break;
        }
    }
    
    public void imprimirBuckets(){
        for(int i = 0; i < this.bucket_00.size(); i++){
            this.bucket_00.get(i).imprimirRegistro();
        }    
        for(int i = 0; i < this.bucket_01.size(); i++){
            this.bucket_01.get(i).imprimirRegistro();
        }
        for(int i = 0; i < this.bucket_10.size(); i++){
            this.bucket_10.get(i).imprimirRegistro();
        }
        for(int i = 0; i < this.bucket_11.size(); i++){
            this.bucket_11.get(i).imprimirRegistro();
        }
    }
    
    /*public Hash ordenarIdade(){
        Hash h = new Hash();
        while()
            for(int i = 0; i < this.bucket_00.size(); i++){
                if(this.bucket_00.get(i).getIdade() > this.bucket_00.get(i+1).getIdade()){
                    Registro aux = this.bucket_00.get(i+1);
                    this.bucket_00.set(i+1,  this.bucket_00.get(i)); 

                    this.bucket_00.set(i,aux);
                }
            }  
        
        return h;
    }*/

    
}

