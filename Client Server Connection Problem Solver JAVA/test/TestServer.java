package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.Random;

public class TestServer {
	
	
	public static void runClient(int port){
		Socket s=null;
		PrintWriter out=null;
		BufferedReader in=null;
		try{
			s=new Socket("127.0.0.1",port);
			s.setSoTimeout(3000);
			out=new PrintWriter(s.getOutputStream());
			in=new BufferedReader(new InputStreamReader(s.getInputStream()));
			
			Random r=new Random() ;
			 
			for(int i=0;i<5;i++){
				String problem =""+r.nextInt(Integer.MAX_VALUE);
				System.out.println("\tsending problem...");
				out.println(problem);
				out.flush();
				System.out.println("\tproblem sent, waiting for solution...");
				String sol=in.readLine();
				System.out.println("\tsolution received");
				String realSol=new StringBuilder(problem).reverse().toString();
				if(!realSol.equals(sol))
					System.out.println("\twrong answer from your server (-4)");
				
			}
			out.println("end");
			out.flush();
			
		}catch(SocketTimeoutException e){
			System.out.println("\tYour Server takes over 3 seconds to answer (-20)");
		}catch(IOException e){
			System.out.println("\tYour Server ran into some IOException (-20)");
		}finally{
			try {
				in.close();
				out.close();
				s.close();
			} catch (IOException e) {
				System.out.println("\tYour Server ran into some IOException (-20)");
			}
		}
		
	}

}
