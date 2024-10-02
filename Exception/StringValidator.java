public class StringValidator {
    public static void validateString(String input) throws IllegalArgumentException{
        if (input == null) {
            throw new IllegalArgumentException("Входная строка не должна быть null");
        }

        if (input.matches(".*\\d.*")) {
            throw new IllegalArgumentException("Строка не должна содержать цифры");
        }
    }

    public static void main(String[] args) {
        // Массив тестовых строк
        String[] testStrings = { "Hello", "World123", "Java", "Programming2023", "Test!" };

        for (String testString : testStrings) {
            try {
                validateString(testString);
                System.out.println("Строка \"" + testString + "\" валидная.");
            } catch (IllegalArgumentException e) {
                System.out.println("Ошибка для строки \"" + testString + "\": " + e.getMessage());
            }
        }
    }
}

