#include "Student.h"
#include <sstream>
#include <numeric>
#include <iomanip>

Student::Student(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::string Student::getEmail() const { return email; }
const std::vector<double>& Student::getGrades() const { return grades; }

void Student::addGrade(double grade) {
    if (grade >= 1.0 && grade <= 10.0) {
        grades.push_back(grade);
    }
}

double Student::getAverageGrade() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

std::string Student::toString() const {
    std::stringstream ss;
    ss <<  id << " " << name << " (" << email << ") | Medie: "
       << std::fixed << std::setprecision(2) << getAverageGrade();
    return ss.str();
}

std::string Student::toCSV() const {
    std::stringstream ss;
    ss << id << "," << name << "," << email;
    for (double g : grades) {
        ss << "," << g;
    }
    return ss.str();
}

Student Student::fromCSV(const std::string& csvLine) {
    std::stringstream ss(csvLine);
    std::string item;

    std::getline(ss, item, ',');
    int id = std::stoi(item);

    std::getline(ss, item, ',');
    std::string name = item;

    std::getline(ss, item, ',');
    std::string email = item;

    Student s(id, name, email);
    while (std::getline(ss, item, ',')) {
        s.addGrade(std::stod(item));
    }
    return s;
}