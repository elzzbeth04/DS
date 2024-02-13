import java.io.*;

class Main {
    public static void main(String args[]) throws IOException {
        String source = "Welcome to OOP class\n" + " Study well";
        
        // Allocate space equal to the length of the string
         FileWriter f1=null;
         FileReader f2=null;
         int c;
        // Create a FileWriter for "file1.txt" and write the content of the buffer into the file
        try{    
             f1 = new FileWriter("file1.txt");
        f1.write(source);
        }
        catch(IOException e)
        {
            System.out.println("not");
        }
         f1.close();
        try{
             f2=new FileReader("file1.txt");
           do{
               c=f2.read();
                if(c!=-1)
            {
                System.out.println((char)c);
            } 
           }while(c!=-1);
          
        }
        catch(IOException e)
        {
            System.out.println("nor");
        }
       

        // Close the FileWriter
       
        f2.close();
    }
}
