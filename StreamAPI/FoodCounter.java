import java.util.Arrays;
import java.util.List;

public class FoodCounter {
 static public void main(String[] args){
     List<String> foodItems = Arrays.asList(
             "Яблоко", "Апельсин", "Арбуз",
             "Банан", "Груша", "Киви",
             "Мандарин", "Грейпфрут", "Манго"
     );

     char startingLetter = 'А';

     long count = foodItems.stream()
             .filter(item -> item.charAt(0) == startingLetter)
             .count();

     System.out.println("Количество названий, начинающихся с '" + startingLetter + "': " + count);
 }
}
