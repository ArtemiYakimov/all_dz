class Pyaterochka(location: String, openingHours: String) : Shop("Pyaterochka", location, openingHours) {
    override fun sellProduct(product: String, price: Double) {
        totalSales += price
        numberOfCustomers++
        println("Продан продукт: $product за $price рублей в магазине $name.")
    }

    override fun getCustomerCount(): Int {
        return numberOfCustomers
    }
}
