import kotlin.math.pow

fun main(){
    //задание 1
    val numbers = doubleArrayOf(1.5, 2.3, 3.7, 4.1, 5.6, 6.2, 7.8, 8.0, 9.4, 10.1)
    var product = 1.0
    for (number in numbers) {
        product *= number
    }
    println("произведение массива: $product")

    println(" ")

    //задание 2
    val number = arrayOf(12, 45, 7, 23, 56, 89, 34, 21)
    val sumNumbers = number.sum()
    val countNumbers = number.size
    val average = sumNumbers.toDouble() / countNumbers

    println("Среднее арифметическое: $average")

    println(" ")

    //задание 3
    val number1 = arrayOf(12, 45, 7, 23, 56, 89, 34, 21)
    val evenNumbers = number1.filter { it % 2 == 0 }
    val countK = evenNumbers.size
    println("Четные числа: $evenNumbers")
    println("Количество четных чисел: $countK")

    println(" ")

    //задание 4
    val n = 10
    val array = IntArray(n)
    for (i in 0 until n) {
        array[i] = 2.0.pow(i + 1).toInt()
    }
    println("Массив степеней двойки:")
    println(array.joinToString(", "))
}