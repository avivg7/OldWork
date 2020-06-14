package server_side;

public interface Solver<Problem,Solution> {
	Solution solve(Problem p);
}
