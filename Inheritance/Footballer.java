class Footballer extends Sportsman {
    public Footballer(String name, String team, int age) {
        super(name, team, age);
    }

    public void scoringGoals() {
        System.out.println(getName() + " scored a goal!");
    }

    @Override
    public void action() {
        System.out.println(getName() + " is playing football.");
    }
}