package server_side;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class MySerialServer implements Server  {

	private int port;
	private volatile boolean stop;
	
	public MySerialServer(int port) {
		this.port = port;
		stop = false;
	}
	
	private void runServer(ClientHandler ch) {
		try {
			
			ServerSocket server = new ServerSocket(port);
			server.setSoTimeout(1000);
			
			while (!stop) {
				try {
					
					Socket aClient = server.accept(); //block call
					System.out.println("waiting for clients");
					
					try {
						
						ch.handleClient(aClient.getInputStream(), aClient.getOutputStream());
						aClient.close();
						
					} catch (Exception e) { System.out.println("handle Exception from runServer Inside MYserialServer");}
					
				} catch (Exception e) { System.out.println("accept Exception from runServer Inside MYserialServer");}		
			}
			
			server.close();
			
		} catch (IOException e) {System.out.println("IO Exception from runServer Inside MYserialServer");}
		
	}

	@Override
	public void start(ClientHandler ch) {
		new Thread(()->runServer(ch)).start();
	}
	
	@Override
	public void stop() {
		stop = true;
	}


	@Override
	public void open(int port, ClientHandler ch) {/*...*/}
}
