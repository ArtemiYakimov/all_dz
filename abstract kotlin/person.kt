abstract class Person(
    val firstName: String,
    val lastName: String,
    val age: Int
) {
    // Абстрактные функции
    abstract fun work(): String
    abstract fun study(): String

    // Обычная функция
    fun displayInfo() {
        println("Имя: $firstName $lastName, Возраст: $age")
    }
}