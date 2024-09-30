class Piano extends Instrument {
    @Override
    void play() {
        System.out.println("Играет на пианино: Звучание мелодий.");
    }

    @Override
    void tune() {
        System.out.println("Настраивает пианино: Регулировка высоты звуков.");
    }
}
