#include "DatabaseConnectionDialog"
#include "DatabaseConnectionDialog"

DatabaseConnectionDialog::DatabaseConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseConnectionDialog)
{
    ui->setupUi(this);
}

DatabaseConnectionDialog::~DatabaseConnectionDialog()
{
    delete ui;
}

QString DatabaseConnectionDialog::getHostName() const {
    return ui->hostLineEdit->text();
}

QString DatabaseConnectionDialog::getDatabaseName() const {
    return ui->databaseLineEdit->text();
}

QString DatabaseConnectionDialog::getUsername() const {
    return ui->usernameLineEdit->text();
}

QString DatabaseConnectionDialog::getPassword() const {
    return ui->passwordLineEdit->text();
}

uint DatabaseConnectionDialog::getProtocol() const {
    return ui->protocolSpinBox->value();
}
