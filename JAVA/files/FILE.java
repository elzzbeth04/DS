import java.io.*;
import java.util.*;

public class FILE
{
	public static void main(String args[]) throws IOException
	{
		try{
			String data="NEW FILE IS CREATED";
			FileWriter mywriter=new FileWriter("text.txt");
			for(int i=0;i<data.length();i++)
			{
			mywriter.write(data.charAt(i));}
			System.out.println("success");
			mywriter.close();
			
			
			
}
		catch(IOException e)
		{ 
			System.out.println("ERROR");
		}
		try{
			
			FileReader f=new FileReader("text.txt");
			int c;
			while((c=f.read())!=-1)
			{System.out.print((char)c);}
			
			f.close();
			
		}
		catch(IOException e)
		{
			System.out.println("ERROR");
		}
	}
}
	
/*	}
		try{
			File f=new File("text.txt");
			Scanner obj=new Scanner(f);
			while(obj.hasNextLine())
			{
				String data=obj.nextLine();
				System.out.println(data);
			}
			obj.close();
	}*/
