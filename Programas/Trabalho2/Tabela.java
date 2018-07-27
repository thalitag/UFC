package Trabalho2;
import java.io.*; 
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author thalita
 */
public class Tabela {
    
    ArrayList< Pagina > paginas = new ArrayList< Pagina >();        

    public ArrayList<Pagina> getPaginas() {
        return paginas;
    }
    
    public Pagina getPagina(int pagina){
        Pagina p;
        p = this.paginas.get(pagina);
        return p;
    } 
    
    public void lerArquivo(String c){
        File dir = new File(c);
        File arq = new File(dir, "Funcionario.txt");
        String s[];
        Registro r;
        Pagina p = new Pagina ();
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
                r = new Registro(s);
                p.adicionarRegistro(r);
                if(p.getQntRegistros() == p.quantMaxRegistros ){
                    this.paginas.add(p);
                    
                    //p.imprimirPagina();
                    p = new Pagina();
                }
            }
            this.paginas.add(p);
           
            //liberamos o fluxo dos objetos ou fechamos o arquivo
            fileReader.close();
            bufferedReader.close();
            } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public Tabela tabelaTemporaria(int atributos[]){
        Tabela t = new Tabela();
        Pagina p = new Pagina();
        Registro r = new Registro();
        for(int i = 0 ; i < this.paginas.size(); i++){
            for(int j = 0; j < this.paginas.get(i).getQntRegistros();j++){
                p.adicionarRegistro(this.paginas.get(i).getRegistro(j).atributosProjecao(atributos));
                    if(p.getQntRegistros() == p.quantMaxRegistros ){
                        t.paginas.add(p);
                    
                        //p.imprimirPagina();
                        p = new Pagina();
                }
            }
        }
        t.paginas.add(p);

        return t;
    }
    
    public void imprimirTabela(){
        for(int i = 0; i< this.paginas.size(); i++){
            this.paginas.get(i).imprimirPagina();
        }
    }
    
  
    
    public ArrayList OrdenarIdade(){
        ArrayList< Registro > bucket = new ArrayList<  >();
        for(int i = 0 ; i < this.paginas.size(); i++){
            for(int j = 0; j < this.paginas.get(i).getQntRegistros();j++){
                bucket.add(this.paginas.get(i).getRegistro(j));
                 
            }                     
        }
        boolean troca = true;
        while(troca){
            for(int i = 0; i < bucket.size()-1; i++){
                if(bucket.get(i).getIdade() > bucket.get(i+1).getIdade()){
                    Registro aux = bucket.get(i+1);
                    bucket.set(i+1, bucket.get(i)); 
                    bucket.set(i,aux);
                    troca = true;
                }
            }  
        }
        return bucket;
    }
    
    public ArrayList< Registro > projetarIdade (int idadeInicial, int idadeFinal){
        ArrayList< Registro > projecao = new ArrayList<  >();
        ArrayList< Registro > aux= new ArrayList<  >();
        aux = this.OrdenarIdade();
        for(int i = 0 ; i < aux.size(); i++ ){
            if(aux.get(i).idade >= idadeInicial && aux.get(i).idade <= idadeFinal ){
                projecao.add(aux.get(i));
            }           
        }
            
        return projecao;
    }
    
    

}
