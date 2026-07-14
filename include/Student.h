#pragma once
#include <string>
#include <vector>

class Student {
private:
    int id;
    std::string name;
    std::string email;
    std::vector<double> grades;

public:
    Student(int id, const std::string& name, const std::string& email);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    const std::vector<double>& getGrades() const;

    void addGrade(double grade);
    double getAverageGrade() const;
    std::string toString() const;
    std::string toCSV() const;
    static Student fromCSV(const std::string& csvLine);
};
