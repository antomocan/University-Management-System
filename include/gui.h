#pragma once
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "Service.h"

class UniversityGUI : public QWidget {
private:
    UniversityService& service;

    QListWidget* studentList;
    QLineEdit* idInput;
    QLineEdit* nameInput;
    QLineEdit* emailInput;
    QLineEdit* gradeInput;

    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* addGradeButton;

    void initGUI();
    void connectSignals();
    void populateList();

public:
    UniversityGUI(UniversityService& srv);
};