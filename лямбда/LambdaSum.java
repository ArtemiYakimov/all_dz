import java.util.Arrays;
import java.util.List;

public class LambdaSum {

    public static void main(String[] args) {

        // Шаг 3: Создаем список целых чисел
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        // Шаг 4: Вычисляем сумму чётных элементов с помощью лямбда-выражения
        int sumOfEvens = numbers.stream()
                .filter(n -> n % 2 == 0) // Фильтруем чётные числа
                .mapToInt(Integer::intValue) // Преобразуем в IntStream
                .sum(); // Суммируем

        // Шаг 5: Выводим результат
        System.out.println("Сумма четных элементов: " + sumOfEvens);
    }
}
