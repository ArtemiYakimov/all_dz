public class Main {
    public static void main(String[] args) {
        // Создаем экземпляры Bird
        Bird eagle = new Eagle(160); // скорость полета 160 км/ч
        Bird hawk = new Hawk(120);   // скорость полета 120 км/ч

        // Вызываем методы
        eagle.fly();
        eagle.makeSound();

        hawk.fly();
        hawk.makeSound();
    }
}