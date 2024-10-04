// Класс с методом для получения позиции буквы
public class AlphabetUtility {
    public static int getLetterPosition(char letter) {
        // Приводим букву к верхнему регистру
        letter = Character.toUpperCase(letter);
        try {
            // Получаем позицию через метод valueOf() enum
            return Alphabet.valueOf(String.valueOf(letter)).getPosition();
        } catch (IllegalArgumentException e) {
            // Если буква не является частью алфавита, выбрасываем исключение
            throw new IllegalArgumentException("Неверный символ: " + letter);
        }
    }

    public static void main(String[] args) {
        char letter = 'C';
        int position = getLetterPosition(letter);
        System.out.println("Позиция буквы " + letter + " в алфавите: " + position);
    }
}