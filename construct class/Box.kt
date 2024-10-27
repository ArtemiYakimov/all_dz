class Box(val width: Double, val height: Double, val depth: Double) {
    fun volume(): Double {
        return width * height * depth
    }
}