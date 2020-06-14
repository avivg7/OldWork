package server_side;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;

public class FileCacheManager<T> implements CacheManager<T> {
	
	@Override // check if the problem's solution is in the Cache
	public boolean existSolution(T problem) {
		
		//Creates a new File instance by converting the given 
		//pathname string into an abstract pathname.
		File f = new File(problem.toString() + ".bin");
		return f.exists();	
	}

	@Override //getSolution
	public T loadSolution(T problem) {
		
		// if the problem's solution is in the Cache
		if(!existSolution(problem))
			return null;
		
		ObjectInputStream in;
		try {
			in = new ObjectInputStream(new FileInputStream(problem.toString() + ".bin"));
			T solution = (T)in.readObject();
			in.close();
			return solution;
			
		} catch (Exception e) {
			System.out.println("Exception: loadSolution - raeding the solution");
		}
		return null;
	}

	@Override // save solution
	public void store(T problem, T solution) {
		ObjectOutputStream out;
		try {
			out = new ObjectOutputStream(new FileOutputStream(problem.toString() + ".bin"));
			out.writeObject(solution);
			out.close();
		} catch (Exception e) {
			System.out.println("Exception: store - writing the solution");
		}
		
	}


}
