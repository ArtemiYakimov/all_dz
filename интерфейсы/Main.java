public class Main {
    public static void main(String[] args) {
        Human human = new Human("Алексей", 30);
        Fish fish = new Fish("Немо", 2);
        Bird bird = new Bird("Синица", 1);

        human.swim();
        fish.swim();
        bird.swim();
        bird.fly();
    }
}