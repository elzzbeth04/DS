import java.io.*;
public class file2
{
        public static void main(String arg[])
        {
            try{
                FileOutputStream f=new FileOutputStream("text.txt");
                String str="done";
                f.write(str.getbytes());
                f.close;
            }
            
        }
}