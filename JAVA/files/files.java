import java.io.*;
class Main
{
public static void main(String arg[]) throws IOException
{

try
    {
        FileInputStream f= new FileInputStream("Sample.txt");
        int c;
        do	
        {
            c=f.read();
            if(c!=-1)
            {
                System.out.print((char)c);
                
            }
        } while(c!=-1);
}
catch(FileNotFoundException e)
{
System.out.println("File not found");
return;
}
f.close();
}
}
