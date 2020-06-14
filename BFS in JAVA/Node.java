
public class Node implements Comparable<Node>{
	
	public Node(String _name, String _pi) {
		this._name = _name;
		this._pi = _pi;
		this._d = 1000;
	}
	private String _name;
	private String _pi;
	private double _d;
	
	
	public String get_name() {
		return _name;
	}
	public void set_name(String _name) {
		this._name = _name;
	}
	public String get_pi() {
		return _pi;
	}
	public void set_pi(String _pi) {
		this._pi = _pi;
	}
	public double get_d() {
		return _d;
	}
	public void set_d(double _d) {
		this._d = _d;
	}
	@Override
	public int compareTo(Node o) {
		return (int)(this.get_d() - o.get_d()); 
		
	}
	@Override
	public String toString() {
		return "Node [_name=" + _name + ", _pi=" + _pi + ", _d=" + _d + "]";
	} 
 
}
