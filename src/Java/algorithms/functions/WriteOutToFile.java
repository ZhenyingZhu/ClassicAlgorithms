package algorithms.functions; 

import java.util.*; 
import java.io.*; 

public class WriteOutToFile {
    /* Function: Write strings to file. 
     * Solution: file.exists(), file.createNewFile(), writer.write(), writer.newLine()
     */ 
    
    public void write(String path, String[] contents) {
        if (path == null || path.length() == 0) {
            return; 
        }
        
        try {
            File file = new File(path); 
            if (file.exists()) {
                System.out.println("File already exist"); 
                return; 
            } else if (!file.createNewFile()) {
                System.out.println("Cannot create file"); 
                return; 
            }
            
            if (contents == null) {
                return; 
            }
            
            BufferedWriter writer = new BufferedWriter(new FileWriter(file)); 
            for (String line : contents) {
                writer.write(line); 
                writer.newLine(); 
                writer.flush(); 
            }
            
            writer.close(); 
        } catch (IOException oe) {
            oe.printStackTrace(); 
        }
    }
}