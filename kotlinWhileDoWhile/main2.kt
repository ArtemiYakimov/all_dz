fun main() {
    val N = 12345 // Задайте Ваше целое число больше 0
    printDigitsFromRight(N)

    println("задание 5")

    //задание 5
    for (i in 1..20) {
        // Если число нечетное, пропускаем его
        if (i % 2 != 0) {
            continue
        }

        // Если число равно 19, завершаем программу
        if (i == 19) {
            break
        }

        // Если число делится на 4 без остатка, умножаем его на 2
        val output = if (i % 4 == 0) i * 2 else i

        // Выводим результат
        println(output)
    }

    println("Задание 6")
    val initialSum = 350.0
    val months = 9
    val monthlyInterestRate = 7.0

    // Расчет конечной суммы вклада
    val finalSum = calculateDepositSum(initialSum, months, monthlyInterestRate)
    println("Конечная сумма вклада: ${String.format("%.2f", finalSum)}")
}

//задание 4
fun printDigitsFromRight(n: Int) {
    var number = n

    while (number > 0) {
        val digit = number % 10 // Получаем последнюю цифру
        println(digit) // Выводим цифру
        number /= 10 // Удаляем последнюю цифру
    }
}

//задание 6
fun calculateDepositSum(initialSum: Double, months: Int, monthlyInterestRate: Double): Double {
    var currentSum = initialSum
    for (month in 1..months) {
        // Начисление процентов за каждый месяц
        val interest = currentSum * monthlyInterestRate / 100
        currentSum += interest
        println("Месяц $month: сумма = ${String.format("%.2f", currentSum)}")
    }
    return currentSum
}