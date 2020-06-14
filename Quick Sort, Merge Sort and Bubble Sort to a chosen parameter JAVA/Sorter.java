package Sortina;

public interface Sorter<T> {
	void sort(Comparable<T>[] comparables);
	long measureTime(Comparable<T>[] comparables);

}
