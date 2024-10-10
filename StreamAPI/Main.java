import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

class Person {
    private String name;
    private int age;

    // Конструктор
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Геттеры
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    // Для удобства вывода
    @Override
    public String toString() {
        return "Person{name='" + name + '\'' + ", age=" + age + '}';
    }
}

public class Main {
    public static void main(String[] args) {
        // Создаем список с объектами Person
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 25));
        people.add(new Person("Bob", 35));
        people.add(new Person("Charlie", 30));
        people.add(new Person("David", 40));
        people.add(new Person("Eve", 29));
        people.add(new Person("Frank", 33));
        people.add(new Person("Grace", 21));
        people.add(new Person("Hannah", 42));
        people.add(new Person("Ian", 37));
        people.add(new Person("Julia", 28));

        // Фильтруем людей старше 30 лет
        List<Person> filteredPeople = people.stream()
                .filter(person -> person.getAge() > 30)
                .collect(Collectors.toList());

        // Выводим отфильтрованных людей
        System.out.println("People older than 30:");
        filteredPeople.forEach(System.out::println);
    }
}
