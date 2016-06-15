package kriptográfia;

import java.io.*;
import java.util.*;

/**
 *
 * @author Varsányi Károly
 */
public class kódolás {

    private final String Kezdo_abc;
    private final int abc_hossz;
    private char Kod_abc[][];
    private String Kodolando_Szoveg;
    private char Kodolando_Szöveg_Tomb[];
    private String Kodolt_Szoveg;
    private String Kulcs;
    private char Kulcs_tomb[];
    
    public kódolás(){
        Kezdo_abc = "abcdefghijklmnopqrstuvwxyz";
        abc_hossz = 26;
        Kod_abc = new char[abc_hossz][abc_hossz];
        Kodolt_Szoveg = "";
        Feltoltes();
        Kodolas();
        Dekodolas();
        
    }
    
    private void Feltoltes(){
        for (int i = 0; i < abc_hossz; i++){
            Kod_abc[0][i] = Kezdo_abc.charAt(i);
            
        }
        for (int i = 1; i < abc_hossz; i++){
            for (int j = 0,k = 1; j < abc_hossz; j++){
                if (k == abc_hossz){
                    k = 0;
                }
                Kod_abc[i][j] = Kod_abc[i-1][k];
                k++;
            }
        }
    }
    
    public void Szovegbeker(){
        System.out.print("Adja meg a kódolandó szöveget: ");
        BufferedReader reader = new BufferedReader(new InputStreamReader (System.in));
        try {
            Kodolando_Szoveg = reader.readLine();
        }catch(IOException e){ }
    }
    
    private void Szovegfeltolt(){
        for (int i = 0; i < Kodolando_Szoveg.length(); i++){
            Kodolando_Szöveg_Tomb[i] = Kodolando_Szoveg.charAt(i);
        }
    }
    
    public void Kulcsbeker(){
        System.out.print("Adja meg a kulcsot: ");
        BufferedReader reader = new BufferedReader(new InputStreamReader (System.in));
        try {
            Kulcs = reader.readLine();
        }catch(IOException e){ }
    }
    
    private void Kulcsfeltolt(){
        for (int i = 0; i < Kulcs.length(); i++){
            Kulcs_tomb[i] = Kulcs.charAt(i);
        }
    }
    
    private int Hosszu(int Hossz){
        for (int i = 0; i < abc_hossz; i++){
            if(Kodolando_Szöveg_Tomb[Hossz] == Kod_abc[0][i]){
            return i;   
            }
        }
        return -1;
    }
    
    private int Szeles(int Szeles){
        int tart = Szeles % Kulcs.length(); // ez itt még csak egy szám meg kell keresni hogy melyik betűhöz tartozik
        for (int i = 0; i < abc_hossz; i++){
            if(Kulcs_tomb[tart] == Kod_abc[i][0]){
            return i;   
            }
        }
        return -1;
    }
    
    public void Kodolas(){
        Szovegbeker();
        Kodolando_Szöveg_Tomb = new char[Kodolando_Szoveg.length()];
        Szovegfeltolt();
        Kulcsbeker();
        Kulcs_tomb = new char[Kulcs.length()];
        Kulcsfeltolt();
        for (int i = 0; i < Kodolando_Szoveg.length();i++){
            if (Hosszu(i) == -1){
            Kodolt_Szoveg  += " ";
            }else{
            Kodolt_Szoveg  +=  Kod_abc[Szeles(i)][Hosszu(i)];
            }
        }
        System.out.println(Kodolt_Szoveg);
    }
    
    private int Kulcsellenorzes(int kapott){
         int tart = kapott % Kulcs.length();
         for(int i = 0; i < abc_hossz; i++){
            if (Kod_abc[i][0] == Kulcs_tomb[tart]){
                for (int j = 0; j < abc_hossz; j++){
                    if (Kod_abc[i][j] == Kodolando_Szöveg_Tomb[kapott]){
                        return j;
                    }
                }
            }
        }
         return -1;
    }
    
    public void Dekodolas(){
        Kodolt_Szoveg = "";
        Szovegbeker();
        Kodolando_Szöveg_Tomb = new char[Kodolando_Szoveg.length()];
        Szovegfeltolt();
        Kulcsbeker();
        Kulcs_tomb = new char[Kulcs.length()];
        Kulcsfeltolt();
        for(int i = 0; i < Kodolando_Szoveg.length(); i++){
            if (Kulcsellenorzes(i) == -1){
            Kodolt_Szoveg  += " ";
            }else{
            Kodolt_Szoveg += Kod_abc[0][Kulcsellenorzes(i)];
            }
        }
        System.out.println(Kodolt_Szoveg);        
    }
}
