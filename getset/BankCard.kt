class BankCard(private val cardNumber: String, private val cardCode: String) {
    fun getCardNumber(): String {
        return cardNumber
    }

    fun getCardCode(password: String): String {
        return if (password == "123456789") {
            cardCode
        } else {
            "Неверный пароль. Доступ к коду карты запрещен."
        }
    }
}