import java.util.Arrays;
import java.util.List;

public class LongestWordFinder {
    public static void main(String[] args) {
        List<String> words = Arrays.asList("первое", "слово", "длинное", "программирование", "второе", "пример");

        String longestWord = words.stream()
                .reduce("", (currentLongest, word) -> word.length() > currentLongest.length() ? word : currentLongest);

        System.out.println("Самое длинное слово: " + longestWord);
    }
}
