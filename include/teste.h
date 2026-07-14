#pragma once

class Tests {
private:
    static void testDomain();
    static void testRepository();
    static void testService();

public:
    static void runAllTests();
};