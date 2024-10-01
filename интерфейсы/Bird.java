class Bird implements Swimmable, Flyable {
    private String name;
    private int age;

    public Bird(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public void swim() {
        System.out.println(name + " плавает, когда приземляется на воду.");
    }

    @Override
    public void fly() {
        System.out.println(name + " летит высоко в небе.");
    }

    // Дополнительные методы
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}