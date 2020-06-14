package Sortina;

public abstract class CommonSorter<T> implements Sorter<T> {
	@Override
	public long measureTime(Comparable<T>[] comparables) {
		long time0 = System.currentTimeMillis();
		sort(comparables);
		return System.currentTimeMillis() - time0;
		
	}

}
