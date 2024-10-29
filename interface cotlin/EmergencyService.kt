abstract class EmergencyService(
    val name: String,
    val phone: String
) : Describable {
    abstract fun performService()
}

class FireDepartment : EmergencyService("Пожарная служба", "101") {
    override fun performService() {
        println("Гасим пожары и спасаем людей.")
    }
    override fun getDescription(): String {
        return "Служба, отвечающая за тушение пожаров и спасение людей."
    }
}
class Ambulance : EmergencyService("Скорая помощь", "103") {
    override fun performService() {
        println("Предоставляем медицинскую помощь на месте.")
    }

    override fun getDescription(): String {
        return "Служба, предоставляющая неотложную медицинскую помощь."
    }
}