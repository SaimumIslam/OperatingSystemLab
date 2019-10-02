import javax.swing.*;
import java.util.Scanner;

public class Paging{
  
  public static void main(String[] args) {
    
    int procSize,memSize,unitSize,numProcAdd,numMemAdd,address,position,gap=60;
    int[] page=new int[1000];
    int[] frame=new int[1000];
    
    JFrame f=new JFrame("");
    JButton b;
    JLabel l;
    
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Enter process size or logical memory size in Killobites : ");
    procSize = sc.nextInt();
    
    System.out.println("Enter main memory size in Killobites : ");
    memSize = sc.nextInt();
    
    System.out.println("Enter main memory size in Killobites : ");
    unitSize = sc.nextInt();
    
    numProcAdd=procSize/unitSize;
    numMemAdd=memSize/unitSize;
    
    for(int i=0;i<numMemAdd;i++)
    {
      System.out.println("Enter Page and frame : ");
      page[i] = sc.nextInt();
      frame[page[i]]= sc.nextInt();
    }
    
    System.out.println("Enter an address you want to find positiion in frame : ");
    address = sc.nextInt();
    
    position=address/(unitSize*1024);
    
    System.out.println("Your given address is on frame : "+frame[page[position]]);
    
    l=new JLabel("Virtual Memory");
    l.setBounds(85,10,100,30);  
    f.add(l);
    
    for(int i=1;i<=numProcAdd;i++)
    {
      l=new JLabel((procSize-unitSize)+"k-"+procSize+"k");
      l.setBounds(10,gap,100,30);  
      f.add(l);
      
      b=new JButton("Page No "+(numProcAdd-i));
      b.setBounds(85,gap,100,30);  
      f.add(b);
      
      gap+=31;
      procSize-=unitSize;
    }          
    
    gap=60;
    l=new JLabel("Physical Memory");
    l.setBounds(250,10,100,30);  
    f.add(l);
    
    for(int i=1;i<=numMemAdd;i++)
    {
      b=new JButton("Frame No "+(numMemAdd-i));
      b.setBounds(250,gap,100,30);  
      f.add(b);
      
      l=new JLabel((memSize-unitSize)+"k-"+memSize+"k");
      l.setBounds(352,gap,100,30);  
      f.add(l);
      
      gap+=31;
      memSize-=unitSize;
    } 
    
    gap=60;
    l=new JLabel("Page Table");
    l.setBounds(600,10,100,30);  
    f.add(l);
    
    for(int i=0;i<numMemAdd;i++)
    {
      b=new JButton("Page No "+page[i]);
      b.setBounds(550,gap,100,30);  
      f.add(b);
      
      b=new JButton("Frame No "+frame[page[i]]);
      b.setBounds(651,gap,150,30);  
      f.add(b);
      
      gap+=31;
      memSize-=unitSize;
    } 
    
    f.setSize(50*numMemAdd,800);  
    f.setLayout(null);  
    f.setVisible(true);   
  }  
} 