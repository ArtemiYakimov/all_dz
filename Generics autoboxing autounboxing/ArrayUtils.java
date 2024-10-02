import java.util.Arrays;

public class ArrayUtils {

    public static <T> void swap(T[] array, int index1, int index2) {
        if (array == null) {
            throw new IllegalArgumentException("Array must not be null");
        }
        if (index1 < 0 || index1 >= array.length || index2 < 0 || index2 >= array.length) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        if (index1 == index2) {
            return; // Ничего не делаем, если индексы совпадают
        }

        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static void main(String[] args) {
        Integer[] arr = {1, 2, 3, 4, 5};
        System.out.println("Before swap: " + Arrays.toString(arr));

        swap(arr, 1, 3);

        System.out.println("After swap: " + Arrays.toString(arr));
    }
}
