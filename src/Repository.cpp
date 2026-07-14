#include "Repository.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

Repository::Repository(const std::string& filename) : filename(filename) {
    loadFromFile();
}

Repository::~Repository() {
    saveToFile();
}

void Repository::loadFromFile() {
    std::ifstream f(filename);
    if (!f.is_open()) return;
    std::string line;
    while (std::getline(f, line)) {
        if (!line.empty()) {
            students.push_back(Student::fromCSV(line));
        }
    }
    f.close();
}

void Repository::saveToFile() {
    std::ofstream f(filename);
    for (const auto& s : students) {
        f << s.toCSV() << "\n";
    }
    f.close();
}

void Repository::addStudent(const Student& s) {
    if (findStudent(s.getId()) != nullptr) {
        throw std::runtime_error("Studentul cu acest ID exista deja!");
    }
    students.push_back(s);
    saveToFile();
}

Student* Repository::findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

void Repository::removeStudent(int id) {
    auto it = std::remove_if(students.begin(), students.end(), [id](const Student& s) {
        return s.getId() == id;
    });
    if (it == students.end()) {
        throw std::runtime_error("Studentul nu a fost gasit!");
    }
    students.erase(it, students.end());
    saveToFile();
}

const std::vector<Student>& Repository::getAll() const {
    return students;
}

void Repository::updateStudent(int id, const std::string& newName, const std::string& newEmail) {
    Student* s = findStudent(id);
    if (s == nullptr) {
        throw std::runtime_error("Studentul nu a fost gasit pentru update!");
    }
    *s = Student(id, newName, newEmail);
    saveToFile();
}