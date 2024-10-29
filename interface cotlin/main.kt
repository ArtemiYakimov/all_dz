fun gcd(a: Int, b: Int): Int {
    var x = a
    var y = b
    while (y != 0) {
        val temp = y
        y = x % y
        x = temp
    }
    return x
}

fun findSecondMax(numbers: List<Int>): Int? {
    if (numbers.size < 2) {
        return null // Если элементов меньше двух, второго максимального нет
    }

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

    return if (secondMax == Int.MIN_VALUE) null else secondMax
}

fun main(){
    val fireDepartment = FireDepartment()
    println("${fireDepartment.name} - ${fireDepartment.phone}: ${fireDepartment.getDescription()}")
    fireDepartment.performService()

    val ambulance = Ambulance()
    println("${ambulance.name} - ${ambulance.phone}: ${ambulance.getDescription()}")
    ambulance.performService()

    val A = 56
    val B = 98
    val result = gcd(A, B)
    println("Наибольший общий делитель (НОД) чисел $A и $B равен: $result")

    val numbers = listOf(3, 5, 1, 4, 2, 5, 6)
    val secondMax = findSecondMax(numbers)

    if (secondMax != null) {
        println("Второе максимальное число: $secondMax")
    } else {
        println("Второе максимальное число не найдено.")
    }
}