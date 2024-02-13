// TO INPUT EMPLOYEE DETAILS(ELIZABETH MARIYA SHIBU 17)
import java.io.*;
import java.util.*;
class Employee
{
	int empId;
	int empAge;
	double empSalary;
	String empName;
	char empGender;
	String empDesignation;
	String empAddress;
	 
	 Employee(int empId,int empAge,double empSalary,String empName,char empGender,String empDesignation,String empAddress)
	{
		this.empId=empId;
		this.empAge=empAge;
		this.empSalary=empSalary;
		this.empName=empName;
		this.empGender=empGender;
		this.empDesignation=empDesignation;
		this.empAddress=empAddress;
	}
	void display(int empId,int empAge,double empSalary,String empName,char empGender,String empDesignation,String empAddress)
	{
	System.out.println("ID : "+empId);
	System.out.println("AGE : "+empAge);
	System.out.println("SALARY : "+empSalary);
	System.out.println("NAME : "+empName);
	System.out.println("GENDER : "+empGender);
	System.out.println("DESIGNATION : "+empDesignation);
	System.out.println("ADDRESS : "+empAddress);
	}
}


//CREATING THE MAIN FUNCTION
	class empoyee
	{
	public static void main(String args[])
	{
	int i;
	Scanner sc=new Scanner(System.in);
	System.out.println("input the number of employee");
	int n=sc.nextInt();	
	Employee e[]=new Employee[n];
	for(i=0;i<n;i++)
	{	
	 System.out.println("input id of the employee");
	 int empId=sc.nextInt();
	 System.out.println("input age of the employee");
	 int empAge=sc.nextInt();
	 System.out.println("input salary of the employee");
	 double empSalary=sc.nextDouble();
	 System.out.println("input name of the employee");
	 String empName=sc.next();
	 System.out.println("input gender of the employee");
	 char empGender=sc.next().charAt(0);
	 System.out.println("input designation of the employee");
	 String empDesignation=sc.next();
	 System.out.println("input ADDRESS of the employee");
	 String empAddress=sc.next();
	 e[i]=new Employee(empId,empAge,empSalary,empName,empGender,empDesignation,empAddress);
	 e[i].display(empId,empAge,empSalary,empName, empGender, empDesignation, empAddress);
	}
	
	System.out.println("input the choice");
	int c=sc.nextInt();
	for(i=0;i<n;i++)
	{
		if(c==e[i].empId)
		{
		
		e[i].display(e[i].empId,e[i].empAge,e[i].empSalary,e[i].empName, e[i].empGender, e[i].empDesignation, e[i].empAddress);
		}
		
	}
	
	
}
}