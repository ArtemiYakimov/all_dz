public class MaxEvenFinder {
    public static void main(String[] args) {
        int[] numbers = {3, 5, 2, 8, 10, 7, 12, 15}; // Пример массива
        int maxEven = Integer.MIN_VALUE; // Инициализируем минимально возможное значение

        for (int number : numbers) {
            if (number % 2 == 0) { // Проверяем, четное ли число
                if (number > maxEven) { // Сравниваем с текущим максимальным четным
                    maxEven = number;
                }
            }
        }

        if (maxEven != Integer.MIN_VALUE) {
            System.out.println("Максимальное четное число: " + maxEven);
        } else {
            System.out.println("Четные числа в массиве отсутствуют.");
        }
    }
}
