fun main() {
    // задание 1
    val box = Box(3.0, 4.0, 5.0)
    val boxVolume = box.volume()
    println("Объем коробки: $boxVolume")

    // Задание 2
    println("Введите количество чисел:")
    val n = readLine()?.toIntOrNull() ?: return println("Некорректный ввод")
    val numbers = mutableListOf<Int>()
    println("Введите $n чисел:")
    for (i in 1..n) {
        var number: Int?
        do {
            number = readLine()?.toIntOrNull()
            if (number == null) {
                println("Некорректный ввод. Пожалуйста, введите целое число.")
            }
        } while (number == null) // Повторяем ввод, пока не будет введено корректное число

        numbers.add(number)
    }
    val min = numbers.minOrNull()
    val max = numbers.maxOrNull()
    if (min != null && max != null) {
        println("Минимальное значение: $min")
        println("Максимальное значение: $max")
    } else {
        println("Список чисел пуст.")
    }

    //задание 3
    val number = arrayOf(3, 67, 1, 55, 65, 89, 23)
    println("Элементы массива: ${number.joinToString(", ")}")

    //задание 4
    val a = 34
    val description = when {
        a < 0 && a % 2 == 0 -> "отрицательное четное число"
        a < 0 && a % 2 != 0 -> "отрицательное нечетное число"
        a == 0 -> "нулевое число"
        a > 0 && a % 2 == 0 -> "положительное четное число"
        a > 0 && a % 2 != 0 -> "положительное нечетное число"
        else -> "неизвестное число"
    }
    println(description)

    //задание 5
    val myCar = Car(mass = 1200.0, speed = 0.0)
    myCar.move()
    myCar.setSpeed(60.0)
    myCar.move()
    myCar.stop()
    myCar.move()
}