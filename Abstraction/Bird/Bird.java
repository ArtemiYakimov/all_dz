abstract class Bird {
    private double flySpeed;

    public Bird(double flySpeed) {
        this.flySpeed = flySpeed;
    }

    public double getFlySpeed() {
        return flySpeed;
    }

    public abstract void fly();
    public abstract void makeSound();
}