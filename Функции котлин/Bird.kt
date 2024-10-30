open class Bird (
    val type: String, // Тип птицы
    val canFly: Boolean // Может ли птица летать
    ) {
        // Метод для описания птицы
        open fun describe() {
            println("Это птица типа $type. ${if (canFly) "Она может летать." else "Она не может летать."}")
        }
}