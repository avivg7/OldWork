package Sortina;

public class main {

	public static void main(String[] args) {
		String[] str = "B,D,A,F,E,C,G".split(",");
		Sorter<String> sorter = new BubbleSort<>();
		sorter.sort(str);
		for (String s : str) 
			System.out.println(s);
		System.out.println("------------------\n");
		
		Integer[] arr = new Integer[]{4,5,2,1,6,8};
		Sorter<Integer> sorter1 = new MergeSort<>();
		sorter1.sort(arr);
		for (Integer i : arr) 
			System.out.println(i);
		System.out.println("------------------\n");
		
		Double[] arrd = new Double[]{0.4,0.5,0.2,0.1,0.6,0.8};
		Sorter<Double> sorter2 = new QuickSort<>();
		sorter2.sort(arrd);
		for (Double d : arrd) 
			System.out.println(d);
		
	}
}
