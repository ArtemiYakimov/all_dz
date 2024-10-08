
public class main2 {
    public static void main(String[] args) {
        // Анонимный класс: простое объединение
        Concatenable simpleConcat = new Concatenable() {
            @Override
            public String concat(String str1, String str2) {
                return str1 + str2;
            }
        };

        // Анонимный класс: объединение с пробелом
        Concatenable spaceConcat = new Concatenable() {
            @Override
            public String concat(String str1, String str2) {
                return str1 + " " + str2;
            }
        };

        // Анонимный класс: объединение с восклицательным знаком (для второго слова)
        Concatenable exclaimConcat = new Concatenable() {
            @Override
            public String concat(String str1, String str2) {
                return str1 + " " + str2 + "!";
            }
        };

        // Проверяем реализацию
        System.out.println(simpleConcat.concat("Hello", "World")); // HelloWorld
        System.out.println(spaceConcat.concat("Hello", "World"));  // Hello World
        System.out.println(exclaimConcat.concat("Hello", "World")); // Hello World!
    }
}
