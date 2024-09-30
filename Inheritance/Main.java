public class Main {
    public static void main(String[] args) {
        Sportsman[] sportsmen = new Sportsman[6];

        sportsmen[0] = new Footballer("Lionel Messi", "PSG", 34);
        sportsmen[1] = new Footballer("Cristiano Ronaldo", "Manchester United", 36);
        sportsmen[2] = new HockeyPlayer("Wayne Gretzky", "Oilers", 60);
        sportsmen[3] = new HockeyPlayer("Alexander Ovechkin", "Capitals", 35);
        sportsmen[4] = new Skier("Lindsey Vonn", "USA", 36);
        sportsmen[5] = new Skier("Marcel Hirscher", "Austria", 32);

        for (Sportsman sportsman : sportsmen) {
            System.out.println("Name: " + sportsman.getName() + ", Team: " + sportsman.getTeam() + ", Age: " + sportsman.getAge());
            sportsman.action();

            // Вызов дополнительных методов
            if (sportsman instanceof Footballer) {
                ((Footballer) sportsman).scoringGoals();
            } else if (sportsman instanceof HockeyPlayer) {
                ((HockeyPlayer) sportsman).scoringGoals();
            } else if (sportsman instanceof Skier) {
                ((Skier) sportsman).racing();
            }

            System.out.println();
        }
    }
}