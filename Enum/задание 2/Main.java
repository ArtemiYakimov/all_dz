import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();

        // Создаем коллекцию объектов Person
        people.add(new Person("Alice", 30, Gender.FEMALE));
        people.add(new Person("Bob", 25, Gender.MALE));
        people.add(new Person("Carol", 22, Gender.FEMALE));
        people.add(new Person("Dave", 35, Gender.MALE));
        people.add(new Person("Eve", 28, Gender.FEMALE));
        people.add(new Person("Frank", 40, Gender.MALE));
        people.add(new Person("Grace", 27, Gender.FEMALE));
        people.add(new Person("Henry", 33, Gender.MALE));
        people.add(new Person("Ivy", 29, Gender.FEMALE));
        people.add(new Person("Jack", 31, Gender.MALE));

        // Генерируем списки мужчин и женщин
        List<Person> maleList = filterByGender(people, Gender.MALE);
        List<Person> femaleList = filterByGender(people, Gender.FEMALE);

        // Печатаем списки на экран
        System.out.println("Мужчины: " + maleList);
        System.out.println("Женщины: " + femaleList);
    }

    public static List<Person> filterByGender(List<Person> people, Gender gender) {
        return people.stream()
                .filter(person -> person.getGender() == gender)
                .collect(Collectors.toList());
    }
}
