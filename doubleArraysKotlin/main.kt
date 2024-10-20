fun main(){
    //задание 1
    val array = arrayOf(
        intArrayOf(5, 2, 9),
        intArrayOf(1, 7, 3),
        intArrayOf(8, 4, 6)
    )
    var minElement = array[0][0]
    for (i in array.indices) {
        for (j in array[i].indices) {
            if (array[i][j] < minElement) {
                minElement = array[i][j]
            }
        }
    }
    println("Минимальный элемент в массиве: $minElement")

    //задание 2
    val matrix = arrayOf(
        intArrayOf(5, 2, 9, 1, 7),
        intArrayOf(3, 8, 4, 6, 0),
        intArrayOf(10, 12, 11, 14, 13)
    )
    val elements = mutableListOf<Int>()
    for (row in matrix) {
        for (element in row) {
            elements.add(element)
        }
    }
    elements.sort()
    val median: Double
    val size = elements.size
    if (size % 2 == 0) {
        median = (elements[size / 2 - 1] + elements[size / 2]) / 2.0
    } else {
        median = elements[size / 2].toDouble()
    }
    println("Медиана в матрице: $median")

    //задание 3
    val matrix1 = Array(5) { IntArray(5) }
    matrix1[2][2] = 1
    matrix1[3][1] = 1
    matrix1[3][2] = 1
    matrix1[3][3] = 1
    for (i in 0..4) {
        matrix1[4][i] = 1
    }
    for (row in matrix1) {
        println(row.joinToString(" "))
    }

    //задание 4
    val numbers = intArrayOf(5, 3, 9, 1, 7, 9, 4)
    var max = Int.MIN_VALUE
    var secondMax = Int.MIN_VALUE
    for (number in numbers) {
        if (number > max) {
            secondMax = max
            max = number
        } else if (number > secondMax && number < max) {
            secondMax = number
        }
    }
    if (secondMax == Int.MIN_VALUE) {
        println("Второе максимальное число не найдено.")
    } else {
        println("Второе максимальное число: $secondMax")
    }
}
