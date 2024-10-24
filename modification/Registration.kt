class Registration (private var _email: String, private var _password: String) {
    var email: String
        get() = _email.toUpperCase()
        private set(value) {
            _email = value
        }

    var password: String
        get() = _password
        set(value) {
            if (value.length < 6) {
                println("Пароль должен содержать не менее 6 символов.")
            } else {
                _password = value
            }
        }
}