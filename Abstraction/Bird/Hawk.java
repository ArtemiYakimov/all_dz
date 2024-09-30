class Hawk extends Bird {
    public Hawk(double flySpeed) {
        super(flySpeed);
    }

    @Override
    public void fly() {
        System.out.println("Hawk is flying at a speed of " + getFlySpeed() + " km/h.");
    }

    @Override
    public void makeSound() {
        System.out.println("Hawk makes a sharp cry.");
    }
}
