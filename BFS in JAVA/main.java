
public class main {
	public static void main(String[] args) {
	
		Node A = new Node("A",null);
		A.set_d(0);
		Node B = new Node("B",null);
		Node C = new Node("C",null);
		Node D = new Node("D",null);
		Node E = new Node("E",null);
		Node G = new Node("G",null);
		
		Edge AB = new Edge("A", "B", 10);
		Edge AC = new Edge("A", "C", 20);
		Edge BD = new Edge("B", "D", 10);
		Edge BC = new Edge("B", "C", 5);
		Edge CE = new Edge("C", "E", 10);
		Edge DG = new Edge("D", "G", 100);
		Edge EG = new Edge("E", "G", 10);
		
		Graph g = new Graph(A);
		g._nodes.put("A", A);
		g._nodes.put("B", B);
		g._nodes.put("C", C);
		g._nodes.put("D", D);
		g._nodes.put("E", E);
		g._nodes.put("G", G);
		
		g._edges.put("AB",AB);
		g._edges.put("AC",AC);
		g._edges.put("AD",BD);
		g._edges.put("BC",BC);
		g._edges.put("CE",CE);
		g._edges.put("DG",DG);
		g._edges.put("EG",EG);
		
		System.out.println(g.BestFirstSearch());
		g._nodes.values().forEach(n->System.out.println(n));
	
	}
}
