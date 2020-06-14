
public class Edge {
	
	private String _from;
	private String _to;
	private double _w;
	
	public Edge(String _from, String _to, double _w) {
		this._from = _from;
		this._to = _to;
		this._w = _w;
	}
	
	public String get_from() {
		return _from;
	}
	public void set_from(String _from) {
		this._from = _from;
	}
	public String get_to() {
		return _to;
	}
	public void set_to(String _to) {
		this._to = _to;
	}
	public double get_w() {
		return _w;
	}
	public void set_w(double _w) {
		this._w = _w;
	}
}
