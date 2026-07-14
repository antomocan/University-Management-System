#include "gui.h"
#include "Service.h"
#include <QMessageBox>

UniversityGUI::UniversityGUI(UniversityService& srv) : service(srv) {
    initGUI();
    connectSignals();
    populateList();
}

void UniversityGUI::initGUI() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    studentList = new QListWidget();
    mainLayout->addWidget(studentList);

    QVBoxLayout* rightLayout = new QVBoxLayout();
    QFormLayout* formLayout = new QFormLayout();

    idInput = new QLineEdit();
    nameInput = new QLineEdit();
    emailInput = new QLineEdit();
    gradeInput = new QLineEdit();

    formLayout->addRow("ID:", idInput);
    formLayout->addRow("Nume:", nameInput);
    formLayout->addRow("Email:", emailInput);
    formLayout->addRow("Nota:", gradeInput);

    rightLayout->addLayout(formLayout);

    addButton = new QPushButton("Adauga Student");
    deleteButton = new QPushButton("Sterge Student");
    addGradeButton = new QPushButton("Adauga Nota");

    rightLayout->addWidget(addButton);
    rightLayout->addWidget(deleteButton);
    rightLayout->addWidget(addGradeButton);

    mainLayout->addLayout(rightLayout);
}

void UniversityGUI::connectSignals() {
    QObject::connect(addButton, &QPushButton::clicked, [this]() {
        try {
            int id = idInput->text().toInt();
            std::string name = nameInput->text().toStdString();
            std::string email = emailInput->text().toStdString();
            service.addStudent(id, name, email);
            populateList();
            idInput->clear();
            nameInput->clear();
            emailInput->clear();
        } catch (const std::exception& e) {
            QMessageBox::warning(this, "Eroare", e.what());
        }
    });

    QObject::connect(deleteButton, &QPushButton::clicked, [this]() {
        try {
            QListWidgetItem* selected = studentList->currentItem();
            if (!selected) {
                throw std::runtime_error("Selecteaza un student din lista!");
            }
            std::string text = selected->text().toStdString();
            int id = std::stoi(text.substr(text.find('[') + 1, text.find(']') - 1));
            service.removeStudent(id);
            populateList();
        } catch (const std::exception& e) {
            QMessageBox::warning(this, "Eroare", e.what());
        }
    });

    QObject::connect(addGradeButton, &QPushButton::clicked, [this]() {
        try {
            QListWidgetItem* selected = studentList->currentItem();
            if (!selected) {
                throw std::runtime_error("Selecteaza un student din lista!");
            }
            std::string text = selected->text().toStdString();
            int id = std::stoi(text.substr(text.find('[') + 1, text.find(']') - 1));
            double grade = gradeInput->text().toDouble();
            service.addGradeToStudent(id, grade);
            populateList();
            gradeInput->clear();
        } catch (const std::exception& e) {
            QMessageBox::warning(this, "Eroare", e.what());
        }
    });
}

void UniversityGUI::populateList() {
    studentList->clear();
    for (const auto& s : service.getAllStudents()) {
        studentList->addItem(QString::fromStdString(s.toString()));
    }
}