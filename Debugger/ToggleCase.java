public class ToggleCase {
    public static void main(String[] args) {
        String input = "Привет, Александр, с праздником, с Новым Годом";
        StringBuilder result = new StringBuilder();

        for (char ch : input.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                result.append(Character.toUpperCase(ch)); // Меняем регистр на верхний
            } else if (Character.isUpperCase(ch)) {
                result.append(Character.toLowerCase(ch)); // Меняем регистр на нижний
            } else {
                result.append(ch); // Оставляем символ без изменений
            }
        }

        System.out.println(result.toString());
    }
}
