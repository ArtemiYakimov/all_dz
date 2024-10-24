//задание 2
fun findEvenNumbers(array: Array<IntArray>): List<Int> {
    val evenNumbers = mutableListOf<Int>()

    for (i in array.indices) {
        for (j in array[i].indices) {
            if (array[i][j] % 2 == 0) {
                evenNumbers.add(array[i][j])
            }
        }
    }

    return evenNumbers
}

//задание 3
fun fillArrays(): Array<IntArray> {
    val arrays = Array(4) { IntArray(4) }
    var counter = 1

    for (i in arrays.indices) {
        for (j in arrays[i].indices) {
            arrays[i][j] = counter++
        }
    }

    return arrays
}

fun printArray(arrays: Array<IntArray>) {
    for (i in arrays.indices) {
        for (j in arrays[i].indices) {
            print("${arrays[i][j]} ")
        }
        println()
    }
}

//задание 4
fun printPositiveElements(array1: IntArray) {
    fun isPositive(number: Int): Boolean {
        return number > 0
    }
    println("Положительные элементы массива:")
    for (element in array1) {
        if (isPositive(element)) {
            println(element)
        }
    }
}

fun main(){
    //задание 1
    var registration = Registration("example@gmail.com", "123456")
    println(registration.email)
    registration.password = "123" //проверка на то, что пароль короткий
    registration.password = "123456"

    //задание 2
    val array = arrayOf(
        intArrayOf(1, 2, 3, 4),
        intArrayOf(5, 6, 7, 8),
        intArrayOf(9, 10, 11, 12),
        intArrayOf(13, 14, 15, 16)
    )
    val evenNumbers = findEvenNumbers(array)
    println("Четные числа: $evenNumbers")

    //задание 3
    val arrays = fillArrays()
    println("Заполненный массив:")
    printArray(array)

    //задание 4
    val array1 = intArrayOf(-5, 3, 0, 7, -2, 8, -1, 4)
    printPositiveElements(array1)
}