package Sortina;

public class BubbleSort<T> extends CommonSorter<T> {

	@Override
	public void sort(Comparable<T>[] comparables) {
		System.out.println("Using Bubble Sort on " + 
				comparables.getClass().getSimpleName());
		for (int i = 0; i < comparables.length; i++) {
			for (int j = 0; j < i; j++) {
				if (comparables[j].compareTo((T) comparables[j+1])>0) {
					Comparable temp = comparables[j];
					comparables[j] = comparables[j+1];
					comparables[j+1] = temp;
			}
			}
		}
	}



}
