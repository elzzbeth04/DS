import java.io.*;
import java.util.*;
class factorial
{
	
	public static void main (String args[])
	{
		int f,n;
		Scanner sc=new Scanner(System.in);
		System.out.println("input number");
		 n=sc.nextInt();
		 f=fact(n);
		System.out.println("FACTORIAL"+f);
	
	}
	public static int fact(int n)
	{
		int result=1;
		if(n==1||n==0)
		{
		return 1;
			}
		else 
		{
		result=n*fact(n-1);
		return result;
			}
	
	}

}
