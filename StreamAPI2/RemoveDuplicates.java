import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class RemoveDuplicates {
    public static void main(String[] args) {
        // Исходный список с дублирующимися элементами
        List<Integer> numbers = Arrays.asList(1, 2, 3, 2, 4, 5, 5, 6, 1, 7, 8, 7);

        // Удаление дубликатов с использованием потоков
        List<Integer> uniqueNumbers = numbers.stream()
                .distinct() // Удаляем дубликаты
                .collect(Collectors.toList()); // Собираем результат в список

        // Выводим уникальные элементы
        System.out.println("Уникальные элементы: " + uniqueNumbers);
    }
}
