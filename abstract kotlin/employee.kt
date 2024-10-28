class Employee(firstName: String, lastName: String, age: Int, val position: String) : Person(firstName, lastName, age) {
    override fun work(): String {
        return "$firstName $lastName работает на должности $position."
    }

    override fun study(): String {
        return "$firstName $lastName проходит обучение для повышения квалификации."
    }
}