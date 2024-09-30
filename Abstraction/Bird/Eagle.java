class Eagle extends Bird {
    public Eagle(double flySpeed) {
        super(flySpeed);
    }

    @Override
    public void fly() {
        System.out.println("Eagle is flying at a speed of " + getFlySpeed() + " km/h.");
    }

    @Override
    public void makeSound() {
        System.out.println("Eagle makes a screeching sound.");
    }
}