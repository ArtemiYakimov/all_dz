class Student(firstName: String, lastName: String, age: Int, val major: String) : Person(firstName, lastName, age) {
    override fun work(): String {
        return "$firstName $lastName учится на специальности $major."
    }

    override fun study(): String {
        return "$firstName $lastName изучает предметы по специальности $major."
    }
}
