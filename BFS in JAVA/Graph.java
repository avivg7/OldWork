import java.util.*;
import java.util.Map.Entry;

public class Graph {
	
	public PriorityQueue<Node> _open;
	public Set<Node> _close;
	public HashMap<String,Node> _nodes;
	public HashMap<String,Edge> _edges;
	
	public Graph(Node n) {
		this._open = new PriorityQueue<Node>(10, new PathComparator());
		this._open.add(n);
		this._close = new HashSet<>();
		this._nodes = new HashMap<>();
		this._edges = new HashMap<>();
	}
	
	public String BestFirstSearch() {
		String bestPath = "G";
		Node n = null;
		while (!(this._open.isEmpty())) {
			n = _open.poll();
			_close.add(n);
			
			if (n.get_name() == "G") {
				while (n.get_pi() != null) {
					n = this._nodes.get(n.get_pi());
					bestPath = bestPath.concat("<-"+n.get_name());
				}
				return bestPath;
			}	
			
			for(Entry<String,Edge> e : _edges.entrySet()) {
				String from = e.getValue().get_from();
				String to = e.getValue().get_to();
				if (from == n.get_name()) {
					Successors(n, _nodes.get(to), e.getValue().get_w());
				}			
			}
		}	
		return null;
	}

	private void Successors(Node n, Node s, double w) {
		if (!(this._open.contains(s)) && !(this._close.contains(s))) {
			if(s.get_d() > n.get_d() + w) {
				s.set_pi(n.get_name());
				s.set_d(n.get_d() + w);
			}
			_open.add(s);
		}
		else {
			if(s.get_d() > n.get_d() + w)  {
				s.set_pi(n.get_name());
				s.set_d(n.get_d() + w);
			}
			else {
				if (!(this._open.contains(s))) {
					s.set_pi(n.get_name());
					_open.add(s);
				}
				else {
					Node tmp = _open.poll();
					_open.add(tmp);
				}
			}
		}
	}
}