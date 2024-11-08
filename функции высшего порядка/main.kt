fun action(color1: String, color2: String, mix: (String, String) -> String): String {
    return mix(color1, color2) // Возвращаем результат смешивания
}

fun increment(number: Int): Int {
    return number + 1
}

fun double(number: Int): Int {
    return number * 2
}

fun modifyArray(array: Array<Int>, modifyFunction: (Int) -> Int): Array<Int> {
    return array.map(modifyFunction).toTypedArray()
}

fun main() {
    val color1 = "красный"
    val color2 = "синий"

    // Определяем функцию смешивания
    val mixFunction: (String, String) -> String = { c1, c2 ->
        when {
            c1 == "красный" && c2 == "синий" -> "фиолетовый"
            c1 == "синий" && c2 == "красный" -> "фиолетовый"
            c1 == "красный" && c2 == "желтый" -> "оранжевый"
            c1 == "желтый" && c2 == "красный" -> "оранжевый"
            c1 == "синий" && c2 == "желтый" -> "зеленый"
            c1 == "желтый" && c2 == "синий" -> "зеленый"
            else -> "неизвестный цвет"
        }
    }
    val mixedColor = action(color1, color2, mixFunction)
    println("Смешанный цвет: $mixedColor")

    val numbers = arrayOf(1, 2, 3, 4, 5)
    val incrementedNumbers = modifyArray(numbers, ::increment)
    println("Увеличенные на единицу: ${incrementedNumbers.joinToString(", ")}")
    val doubledNumbers = modifyArray(numbers, ::double)
    println("Умноженные на два: ${doubledNumbers.joinToString(", ")}")
}

