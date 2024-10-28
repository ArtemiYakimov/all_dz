abstract class Shop(
    val name: String,
    val location: String,
    val openingHours: String
) {
    // Свойства класса
    var totalSales: Double = 0.0
    var numberOfCustomers: Int = 0

    // Абстрактные функции
    abstract fun sellProduct(product: String, price: Double)
    abstract fun getCustomerCount(): Int

    fun displayInfo() {
        println("Магазин: $name")
        println("Локация: $location")
        println("Часы работы: $openingHours")
        println("Общие продажи: $totalSales")
        println("Количество клиентов: $numberOfCustomers")
    }
}
