fun main() {
    val magnit = Magnit("Москва, ул. Ленина", "09:00 - 21:00")
    magnit.sellProduct("Хлеб", 50.0)
    magnit.sellProduct("Молоко", 60.0)
    magnit.displayInfo()

    val pyaterochka = Pyaterochka("Санкт-Петербург, пр. Невский", "08:00 - 22:00")
    pyaterochka.sellProduct("Яблоки", 30.0)
    pyaterochka.displayInfo()

    //задание 2
    val student = Student("Иван", "Иванов", 20, "Программирование")
    student.displayInfo()
    println(student.work())
    println(student.study())

    val employee = Employee("Петр", "Петров", 30, "Менеджер")
    employee.displayInfo()
    println(employee.work())
    println(employee.study())

    //задание 3
    fun convertLength(unitNumber: Int, lengthInMeters: Double): Double {
        return when (unitNumber) {
            1 -> lengthInMeters * 10 // дециметры
            2 -> lengthInMeters / 1000 // километры
            3 -> lengthInMeters // метры
            4 -> lengthInMeters * 1000 // миллиметры
            5 -> lengthInMeters * 100 // сантиметры
            else -> throw IllegalArgumentException("Неверный номер единицы длины. Должен быть от 1 до 5.")
        }
    }

        // Пример использования
        val unitNumber = 3 // номер единицы длины (например, 3 - метры)
        val lengthInMeters = 5.0 // длина отрезка в метрах

        val convertedLength = convertLength(unitNumber, lengthInMeters)
        println("Длина отрезка в выбранной единице: $convertedLength")
}
