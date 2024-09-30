class Skier extends Sportsman {
    public Skier(String name, String team, int age) {
        super(name, team, age);
    }

    public void racing() {
        System.out.println(getName() + " is racing down the slope!");
    }

    @Override
    public void action() {
        System.out.println(getName() + " is skiing.");
    }
}