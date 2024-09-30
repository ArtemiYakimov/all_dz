public class Main {
    public static void main(String[] args) {
        // Создаём экземпляры инструментов
        Instrument guitar = new Guitar();
        Instrument piano = new Piano();

        // Выполняем действия с каждым инструментом
        guitar.tune();
        guitar.play();

        piano.tune();
        piano.play();
    }
}
