#include "Service.h"
#include <algorithm>
#include <stdexcept>

UniversityService::UniversityService(Repository& repository) : repo(repository) {}

void UniversityService::addStudent(int id, const std::string& name, const std::string& email) {
    if (name.empty() || email.empty()) {
        throw std::runtime_error("Numele si email-ul nu pot fi vide!");
    }
    Student s(id, name, email);
    repo.addStudent(s);
}

void UniversityService::removeStudent(int id) {
    repo.removeStudent(id);
}

void UniversityService::addGradeToStudent(int id, double grade) {
    if (grade < 1.0 || grade > 10.0) {
        throw std::runtime_error("Nota trebuie sa fie intre 1 si 10!");
    }
    Student* s = repo.findStudent(id);
    if (s == nullptr) {
        throw std::runtime_error("Studentul nu a fost gasit!");
    }
    s->addGrade(grade);
}

const std::vector<Student>& UniversityService::getAllStudents() const {
    return repo.getAll();
}

std::vector<Student> UniversityService::getStudentsWithAverageAbove(double threshold) const {
    std::vector<Student> result;
    const auto& all = repo.getAll();
    std::copy_if(all.begin(), all.end(), std::back_inserter(result), [threshold](const Student& s) {
        return s.getAverageGrade() > threshold;
    });
    return result;
}