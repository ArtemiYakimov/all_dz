class Fish implements Swimmable {
    private String name;
    private int age;

    public Fish(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public void swim() {
        System.out.println(name + " плавает свободно в воде.");
    }

    // Дополнительные методы
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}