class Car (private val mass: Double, private var speed: Double) {
    fun move() {
        if (speed > 0) {
            println("Автомобиль движется со скоростью $speed м/с.")
        } else {
            println("Автомобиль стоит на месте.")
        }
    }
    fun stop() {
        speed = 0.0
        println("Автомобиль остановлен.")
    }
    fun setSpeed(newSpeed: Double) {
        speed = newSpeed
        println("Скорость автомобиля изменена на $speed м/с.")
    }
}