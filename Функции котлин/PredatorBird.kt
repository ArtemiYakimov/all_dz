class PredatorBird (
    type: String,
    canFly: Boolean,
    val huntingStyle: String // Стиль охоты
) : Bird(type, canFly) {
    // Переопределение метода describe
    override fun describe() {
        super.describe()
        println("Эта птица охотится с помощью: $huntingStyle.")
    }
}