import java.util.HashSet;
import java.util.Set;

public class ColorSetComparison {

    public static void main(String[] args) {
        Set<String> set1 = new HashSet<>();
        set1.add("Red");
        set1.add("Green");
        set1.add("Blue");

        Set<String> set2 = new HashSet<>();
        set2.add("Blue");
        set2.add("Yellow");
        set2.add("Green");

        Set<String> commonColors = getCommonElements(set1, set2);

        System.out.println("Common colors: " + commonColors);
    }

    public static Set<String> getCommonElements(Set<String> setA, Set<String> setB) {
        Set<String> commonSet = new HashSet<>(setA);
        commonSet.retainAll(setB);  // Сохраняет только те элементы, которые есть в обоих наборах
        return commonSet;
    }
}
