/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho3;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author thalita
 */
public class Arquivo {
    
    public String[] lerArquivo(String c, int tamanhoArq){
        Historia h = new Historia();
        File dir = new File(c);
        File arq = new File(dir, "dados.txt");
        String[] s = new String[tamanhoArq];
        ArrayList<String> array = new ArrayList<String>();
        Dado d;
        char p;
        
        try {
            //Indicamos o arquivo que será lido
            FileReader fileReader = new FileReader(arq);

            //Criamos o objeto bufferReader que nos
            // oferece o método de leitura readLine()
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            //String que irá receber cada linha do arquivo
            String linha = "";

            //Fazemos um loop linha a linha no arquivo,
            // enquanto ele seja diferente de null.
            //O método readLine() devolve a linha na
            // posicao do loop para a variavel linha.
            while ( ( linha = bufferedReader.readLine() ) != null) {
                s = linha.split(",");
            }
          
            //liberamos o fluxo dos objetos ou fechamos o arquivo
            fileReader.close();
            bufferedReader.close();
            } catch (IOException e) {
        }
        return s;
    }
    
   /**
    * @param c (caminho para o arquivo)
    * @return tamanho do vetor da String correspondente ao arquivo
    */
    public int contarStringArq(String c){
        File dir = new File(c);
        File arq = new File(dir, "dados.txt");//mome do arquivo
        String[] s;
        ArrayList<String> array = new ArrayList<String>();
        Dado d;
        int cont = 0;
     
        try {
            //Indicamos o arquivo que será lido
            FileReader fileReader = new FileReader(arq);
            BufferedReader bufferedReader = new BufferedReader(fileReader);           
            //String que irá receber cada linha do arquivo
            String linha = "";

            while ( ( linha = bufferedReader.readLine() ) != null) {
                s = linha.split(","); 
                cont = s.length;

            }
                        
            //liberamos o fluxo dos objetos ou fechamos o arquivo
            fileReader.close();
            bufferedReader.close();
            } catch (IOException e) {
        }
        return cont;
    }
    
      
}
