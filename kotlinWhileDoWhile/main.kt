//задание 1
fun factorialIterative(n: Int): Long {
    if (n < 0) throw IllegalArgumentException("Факториал отрицательного числа не определён")
    var result = 1L
    for (i in 1..n) {
        result *= i
    }
    return result
}

fun main() {
    println("Введите число:")
    val userInput = readLine()
    val number = userInput?.toIntOrNull() ?: return println("Введите корректное число.")

    val factorial = factorialIterative(number)
    println("Факториал числа $number равен $factorial.")

    //задание 2
    println("Введите стоимость конфет: ")
    val pricePerKg = readLine()?.toDoubleOrNull()

    if (pricePerKg != null && pricePerKg >= 0) {
        println("Стоимость конфет от 1 до 10 кг:")
        for (kg in 1..10) {
            val totalCost = kg * pricePerKg
            println("$kg кг: $totalCost")
        }
    } else {
        println("Введите корректное число для цены.")
    }

    //задание 3
    val A = 5
    val B = 10

    if (A < B){
        var count = 0

        for (number in A..B){
            println(number)
            count++
        }

        println("Количество чисел: $count")
    } else {
        println("А должно быть меньше B")
    }
}
