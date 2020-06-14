package server_side;

public interface Server {

	public void open(int port, ClientHandler ch);
	public void start(ClientHandler ch);
	public void stop();
}
