import java.util.HashMap;
import java.util.Set;

public class MainHomeWorkEX1 {

    // Создаем HashMap с Integer ключами и String значениями
    private HashMap<Integer, String> map = new HashMap<>();

    public MainHomeWorkEX1() {
        // Заполняем HashMap данными
        map.put(1, "One");
        map.put(2, "Two");
        map.put(3, "Three");
    }

    // Метод, который возвращает набор ключей
    public Set<Integer> getKeys() {
        return map.keySet();
    }

    public static void main(String[] args) {
        MainHomeWorkEX1 example = new MainHomeWorkEX1();

        // Получаем набор ключей и выводим его
        Set<Integer> keys = example.getKeys();

        System.out.println("Ключи в HashMap: " + keys);
    }
}
