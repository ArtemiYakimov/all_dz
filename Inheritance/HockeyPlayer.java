class HockeyPlayer extends Sportsman {
    public HockeyPlayer(String name, String team, int age) {
        super(name, team, age);
    }

    public void scoringGoals() {
        System.out.println(getName() + " scored a goal in hockey!");
    }

    @Override
    public void action() {
        System.out.println(getName() + " is playing hockey.");
    }
}