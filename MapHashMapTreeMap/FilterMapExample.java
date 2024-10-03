import java.util.HashMap;
import java.util.Map;

public class FilterMapExample {

    public static void main(String[] args) {
        // Создаем исходный HashMap
        HashMap<Integer, String> originalMap = new HashMap<>();
        originalMap.put(1, "Red");
        originalMap.put(2, "Green");
        originalMap.put(3, "Black");

        // Получаем новый отфильтрованный HashMap
        Map<Integer, String> filteredMap = filterMap(originalMap);

        // Выводим результат
        System.out.println("Filtered Map: " + filteredMap);
    }

    public static Map<Integer, String> filterMap(Map<Integer, String> map) {
        // Создаем новый HashMap для хранения отфильтрованных значений
        HashMap<Integer, String> resultMap = new HashMap<>();

        // Проходим по всем элементам исходного map
        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            // Проверяем условие длины строки
            if (entry.getValue().length() > 3) {
                // Добавляем элемент в новый map
                resultMap.put(entry.getKey(), entry.getValue());
            }
        }

        return resultMap; // Возвращаем новый ассоциативный массив
    }
}
