class Guitar extends Instrument {
    @Override
    void play() {
        System.out.println("Играет на гитаре: Трели аккорда.");
    }

    @Override
    void tune() {
        System.out.println("Настраивает гитару: Проверка каждой струны.");
    }
}
