#pragma once
#include "Student.h"
#include <vector>
#include <string>

class Repository {
private:
    std::vector<Student> students;
    std::string filename;

    void loadFromFile();
    void saveToFile();

public:
    Repository(const std::string& filename);
    ~Repository();

    void addStudent(const Student& s);
    void removeStudent(int id);
    Student* findStudent(int id);
    const std::vector<Student>& getAll() const;
    void updateStudent(int id, const std::string& newName, const std::string& newEmail);
};