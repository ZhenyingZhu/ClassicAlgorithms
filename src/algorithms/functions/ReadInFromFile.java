package algorithms.functions; 

import java.util.*; 
import java.io.*; 

public class ReadInFromFile {
    /* Function: Read a file and print it on the screen. 
     * Solution: Use File, BufferedReader, FileReader and IOException. 
     */ 
    
    public void read(String path) {
        if (path == null || path.length() == 0) {
            return; 
        }
        
        try {
            File file = new File(path); // Without path, the file should be in the parent folder of the package. 
            BufferedReader reader = new BufferedReader(new FileReader(file)); 
            String line = null; 
            while ((line = reader.readLine()) != null) {
                System.out.println(line); 
            }
            
            reader.close(); 
        } catch (IOException ie) {
            ie.printStackTrace(); 
        }
    }
}