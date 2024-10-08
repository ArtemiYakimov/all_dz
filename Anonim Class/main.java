// Определяем функциональный интерфейс
@FunctionalInterface
interface Printable {
    void print();
}

// Основной класс с методом main
public class main {
    public static void main(String[] args) {
        // Создаем анонимный класс, реализующий Printable
        Printable printable1 = new Printable() {
            @Override
            public void print() {
                System.out.println("Hello from Printable 1!");
            }
        };

        // Создаем второй анонимный класс
        Printable printable2 = new Printable() {
            @Override
            public void print() {
                System.out.println("Hello from Printable 2!");
            }
        };

        // Создаем третий анонимный класс
        Printable printable3 = new Printable() {
            @Override
            public void print() {
                System.out.println("Hello from Printable 3!");
            }
        };

        // Вызываем методы print
        printable1.print();
        printable2.print();
        printable3.print();
    }
}
