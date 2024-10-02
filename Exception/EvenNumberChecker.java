public class EvenNumberChecker {

    // Метод для проверки четности числа
    public static void checkEven(int number) throws IllegalArgumentException {
        if (number % 2 != 0) {
            throw new IllegalArgumentException("Число " + number + " нечетное!");
        }
    }

    public static void main(String[] args) {
        int[] testNumbers = {2, 3, 4, 5, 6}; // Массив для тестирования

        for (int number : testNumbers) {
            try {
                checkEven(number); // Проверка числа
                System.out.println("Число " + number + " является четным.");
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage()); // Обработка исключения
            }
        }
    }
}
