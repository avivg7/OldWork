package server_side;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;

public class MyTestClientHandler implements ClientHandler {
	CacheManager cm;
	Solver<String,String> solver;
	
	public MyTestClientHandler() {
		cm = new FileCacheManager();
		
		// Using lambda expression instead of create the class StringReverse
		// now solver will contain the solution  
		solver = (s)->new StringBuilder(s).reverse().toString();
	}
	
	@Override
	public void handleClient(InputStream in, OutputStream out) {
		try {
			BufferedReader inFromClient = new BufferedReader(new InputStreamReader(in));
			PrintWriter outToClient = new PrintWriter(out);
			String line;
			while (!(line = inFromClient.readLine()).equals("end")) {
				String sol = (String) cm.loadSolution(line);
				if (sol == null) {
					sol = solver.solve( line);
					cm.store((String) line, (String) sol);
				}
				outToClient.println(sol);
				outToClient.flush();
			}
			inFromClient.close();
			outToClient.close();
			
		} catch (Exception e) {System.out.println("handle Exception from runServer Inside MyTestClientHandler");} 
		
	}
}
