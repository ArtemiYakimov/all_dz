public class arraysEqual {

    public static <T> boolean areArraysEqual(T[] array1, T[] array2) {
        // Сначала проверяем, равны ли длины массивов
        if (array1.length != array2.length) {
            return false;
        }

        // Затем сравниваем каждый элемент по индексам
        for (int i = 0; i < array1.length; i++) {
            if (!array1[i].equals(array2[i])) {
                return false; // Если хотя бы один элемент не совпадает, возвращаем false
            }
        }

        return true; // Если все элементы совпадают, возвращаем true
    }

    public static void main(String[] args) {
        Integer[] array1 = {1, 2, 3, 4};
        Integer[] array2 = {1, 2, 3, 4};
        Integer[] array3 = {1, 2, 3, 5};

        System.out.println(areArraysEqual(array1, array2)); // Вывод: true
        System.out.println(areArraysEqual(array1, array3)); // Вывод: false
    }
}
