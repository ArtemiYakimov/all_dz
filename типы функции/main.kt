fun factorial(n: Int): Int {
    return if (n == 0) {
        1
    } else {
        n * factorial(n - 1)
    }
}

fun powerOfTen(n: Int): Long {
    return if (n == 0) {
        1 // 10^0 = 1
    } else {
        10 * powerOfTen(n - 1)
    }
}

fun increaseEverySecondElement(array: Array<Int>) {
    for (i in array.indices) {
        if (i % 2 == 0) {
            array[i] += 1
        }
    }
}

fun main() {
    println("Введите неотрицательное число: ")
    val input = readLine()?.toIntOrNull()
    if (input != null && input >= 0){
        val factorialResult = factorial(input)
        println("факториал числа $input равен $factorialResult")
    } else {
        println("некорректный ввод!")
    }

    println("Введите целое число N для вычисления 10 в степени N:")
    val input1 = readLine()?.toIntOrNull()

    if (input1 != null) {
        val result = powerOfTen(input1)
        println("10 в степени $input равно $result")
    } else {
        println("Некорректный ввод. Пожалуйста, введите целое число.")
    }

    val array = arrayOf(1, 2, 3, 4, 5, 6, 7)
    println("Исходный массив: ${array.joinToString(", ")}")
    increaseEverySecondElement(array)
    println("Измененный массив: ${array.joinToString(", ")}")
}