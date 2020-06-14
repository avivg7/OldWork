package server_side;

public interface CacheManager<T> {
               
		public boolean existSolution(T problem);
		public T loadSolution(T problem); //getSolution
		public void store(T problem, T solution); //saveSolution
}
