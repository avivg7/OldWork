package Sortina;

public class QuickSort<T> extends CommonSorter<T> {
	@Override
	public void sort(Comparable<T>[] comparables) {
		System.out.println("Using quick Sort on " + 
				comparables.getClass().getSimpleName()); 
		qsort(comparables, 0, comparables.length-1);
	}
	
	public void qsort(Comparable<T>[] arr, int a, int b) {
        if (a < b) {
            int i = a, j = b;
            Comparable<T> x = arr[(i + j) / 2];

            do {
                while (arr[i].compareTo((T) x) < 0) i++;
                while (x.compareTo((T) arr[j]) < 0) j--;

                if ( i <= j) {
                	Comparable<T> tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                }

            } while (i <= j);

            qsort(arr, a, j);
            qsort(arr, i, b);
        }
    }
}
