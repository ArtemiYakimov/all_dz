class Magnit(location: String, openingHours: String) : Shop("Magnit", location, openingHours) {
    override fun sellProduct(product: String, price: Double) {
        totalSales += price
        numberOfCustomers++
        println("Продан продукт: $product за $price рублей в магазине $name.")
    }

    override fun getCustomerCount(): Int {
        return numberOfCustomers
    }
}