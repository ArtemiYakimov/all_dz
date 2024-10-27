fun main(){
    val myCard = BankCard("1234 5678 9012 3456", "123")
    println("Номер карты: ${myCard.getCardNumber()}")
    print("Введите пароль для доступа к коду карты: ")
    val password = readLine() ?: ""
    println(myCard.getCardCode(password))

    //задание 2
    var a: Int = 10
    a += 7
    a -= 4
    a *= 2
    val result = a % 3
    println("результат: $result")

    //задание 3
    val number = 75
    val tens = number / 10
    val units = number % 10

    val swappedNumber = units * 10 + tens
    println("Переставленное число: $swappedNumber")
}