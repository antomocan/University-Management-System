#include <QApplication>
#include "Repository.h"
#include "Service.h"
#include "gui.h"
#include "teste.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Tests::runAllTests();
    Repository repo("students.csv");
    UniversityService service(repo);
    UniversityGUI gui(service);

    gui.show();

    return app.exec();
}