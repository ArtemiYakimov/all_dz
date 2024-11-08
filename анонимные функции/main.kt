fun checkArrayElement(array: Array<Int>, checkFunction: (Int) -> Boolean): List<Int> {
    return array.filter(checkFunction)
}

fun main(){
    val newYearGreeting: (String, Int) -> String = {name, year ->
        "С наступающим Новым годом, $name! Пусть $year принесет вам счастье и удачу!"
    }
    val greetingMessage = newYearGreeting("Дмитрий", 2024)
    println(greetingMessage)

    val numbers = arrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    val isEven: (Int) -> Boolean = { number -> number % 2 == 0 }
    val evenNumbers = checkArrayElement(numbers, isEven)
    println("Четные числа в массиве: ${evenNumbers.joinToString(", ")}")

    val concatenate: (String, String) -> String = {str1, str2 -> str1 + str2
    }
    val result = concatenate("Привет," , "мир!")
    println(result)
}
