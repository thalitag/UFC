
package trabalho3;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.time.LocalTime;


/**
 *
 * @author thalita
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Arquivo a = new Arquivo();
        String s[];
        
        s = a.lerArquivo("C:/Users/thali/Desktop",a.contarStringArq("C:/Users/thali/Desktop"));
        Historia h = new Historia(s);        
        h.setDados(s);
        
        h.imprimirHistoria();
        h.checarHistoria();
       // h.imprimirHistoria();
        Recuperacao r = new Recuperacao(s);
        
    }
    
      

  
      





}
