import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        // Создаём множество целых чисел
        Set<Integer> numbers = new HashSet<>();
        numbers.add(10);
        numbers.add(16);
        numbers.add(21);
        numbers.add(14);
        numbers.add(8);
        numbers.add(30);
        numbers.add(5);

        // Обрабатываем множество
        for (Integer number : numbers) {
            if (number > 15 && number % 2 == 0) {
                // Выводим элементы, которые больше 15 и являются четными
                System.out.println(number);
            } else {
                // Выводим остальные элементы, деля их на 2
                System.out.println(number / 2);
            }
        }
    }
}
