#include "teste.h"
#include "Student.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
#include <fstream>
#include <iostream>

void Tests::testDomain() {
    Student s(1, "Popescu Ion", "ion@test.com");
    assert(s.getId() == 1);
    assert(s.getName() == "Popescu Ion");
    assert(s.getEmail() == "ion@test.com");
    assert(s.getAverageGrade() == 0.0);

    s.addGrade(9.5);
    s.addGrade(8.5);
    assert(s.getAverageGrade() == 9.0);

    s.addGrade(12.0); // Nota invalida, nu ar trebui sa se adauge
    assert(s.getAverageGrade() == 9.0);
}

void Tests::testRepository() {
    std::string testFile = "test_students.csv";

    // Ne asiguram ca pornim cu un fisier curat
    std::ofstream clearFile(testFile);
    clearFile.close();

    {
        Repository repo(testFile);
        Student s(1, "Ionescu Dan", "dan@test.com");
        repo.addStudent(s);
        assert(repo.getAll().size() == 1);

        Student* found = repo.findStudent(1);
        assert(found != nullptr);
        assert(found->getName() == "Ionescu Dan");

        try {
            repo.addStudent(s);
            assert(false); // Nu ar trebui sa ajunga aici (ID duplicat)
        } catch (const std::exception&) {
            assert(true);
        }
    } // Aici destructorul salveaza in fisier

    {
        // Reincarcam din fisier sa vedem daca persistenta functioneaza
        Repository repo(testFile);
        assert(repo.getAll().size() == 1);
        repo.removeStudent(1);
        assert(repo.getAll().empty());
    }

    std::remove(testFile.c_str());
}

void Tests::testService() {
    std::string testFile = "test_service.csv";
    std::ofstream clearFile(testFile);
    clearFile.close();

    Repository repo(testFile);
    UniversityService service(repo);

    service.addStudent(1, "Grigore Ana", "ana@test.com");
    assert(service.getAllStudents().size() == 1);

    try {
        service.addStudent(1, "", "ana@test.com");
        assert(false); // Nume gol, ar trebui sa arunce eroare
    } catch (const std::exception&) {
        assert(true);
    }

    service.addGradeToStudent(1, 10.0);
    service.addGradeToStudent(1, 8.0);
    assert(service.getAllStudents()[0].getAverageGrade() == 9.0);

    auto filtered = service.getStudentsWithAverageAbove(8.5);
    assert(filtered.size() == 1);

    auto filteredEmpty = service.getStudentsWithAverageAbove(9.5);
    assert(filteredEmpty.empty());

    std::remove(testFile.c_str());
}

void Tests::runAllTests() {
    testDomain();
    testRepository();
    testService();
    std::cout << "Toate testele au trecut cu succes!\n";
}