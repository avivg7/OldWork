import java.util.Comparator;

public class PathComparator implements Comparator<Node> {

	@Override
	public int compare(Node n1, Node n2) {
		return (int)(n1.get_d()-n2.get_d());
	}

}
