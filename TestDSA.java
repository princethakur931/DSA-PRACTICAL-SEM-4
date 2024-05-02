import java.util.*;

public class TestDSA {
    private static int size;

    public static void sort(int elements[]) {
        buildHeap(elements);
        for (int i = size; i > 0; i--) {
            swap(elements, 0, i);
            size = size - 1;
            heapify(elements, 0);
        }
    }

    public static void buildHeap(int elements[]) {
        size = elements.length - 1;
        for (int i = size / 2; i >= 0; i--)
            heapify(elements, i);
    }

    public static void heapify(int elements[], int i) {
        int left = 2 * i + 1; // Corrected left child index calculation
        int right = 2 * i + 2; // Corrected right child index calculation
        int max = i;
        if (left <= size && elements[left] > elements[i])
            max = left;
        if (right <= size && elements[right] > elements[max])
            max = right;
        if (max != i) {
            swap(elements, i, max);
            heapify(elements, max);
        }
    }

    public static void swap(int elements[], int i, int j) {
        int tmp = elements[i];
        elements[i] = elements[j];
        elements[j] = tmp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        System.out.println("Enter size: ");
        n = in.nextInt();
        int elements[] = new int[n];
        System.out.println("Enter " + n + " integer elements: ");
        for (int i = 0; i < n; i++)
            elements[i] = in.nextInt();
        sort(elements);
        System.out.println("Elements after sorting: ");
        for (int i = 0; i < n; i++)
            System.out.print(elements[i] + " "); // Print elements on the same line
    }
}
