#pragma once
#include "Repository.h"

class UniversityService {
private:
    Repository& repo;

public:
    UniversityService(Repository& repository);

    void addStudent(int id, const std::string& name, const std::string& email);
    void removeStudent(int id);
    void addGradeToStudent(int id, double grade);

    const std::vector<Student>& getAllStudents() const;
    std::vector<Student> getStudentsWithAverageAbove(double threshold) const;
};