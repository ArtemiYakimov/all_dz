fun main(){
    val pelican = WaterBird("Пеликан", true)
    pelican.describe()

    val ostrich = Bird("Страус", false)
    ostrich.describe()

    val eagle = PredatorBird("Орлан", true, "падение на жертву")
    eagle.describe()

    val words = arrayOf("яблоко", "банан", "груша", "арбуз", "киви", "мандарин")

    // Поиск самого длинного слова
    val longestWord = words.maxByOrNull { it.length }

    // Вывод результата
    if (longestWord != null) {
        println("Самое длинное слово: $longestWord")
        println("Количество букв в этом слове: ${longestWord.length}")
    } else {
        println("Массив пуст.")
    }

    val inputString = "ПриВет, кАк деЛа"

    // Находим символы в верхнем регистре
    val uppercaseLetters = inputString.filter { it.isUpperCase() }

    // Выводим найденные символы и их количество
    println("Символы в верхнем регистре: $uppercaseLetters")
    println("Количество символов в верхнем регистре: ${uppercaseLetters.length}")
}