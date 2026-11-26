
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

#define PASS "\033[1;32m[PASS]\033[0m"
#define FAIL "\033[1;31m[FAIL]\033[0m"

static int testsPassed = 0;
static int testsFailed = 0;

void test_price(const std::string &name, float actual, float expected)
{
    std::cout << "[";

    if (std::fabs(actual - expected) < 0.001f)
    {
        std::cout << PASS;
        testsPassed++;
    }
    else
    {
        std::cout << FAIL;
        testsFailed++;
    }

    std::cout << "] " << name
              << " | Expected: " << expected
              << " | Got: " << actual << std::endl;
}

void print_section(const std::string &name)
{
    std::cout << "\n========== " << name << " ==========\n";
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // ARTICLES
    std::vector<Article> articles;
    articles.push_back({"Keyboard", 80.0f, 1});
    articles.push_back({"Mouse", 40.0f, 2});
    articles.push_back({"Headset", 60.0f, 1});

    // TOTAL = 220 €

    print_section("STANDARD COMMAND");

    Command standard(1, Day::Monday, "Alice", articles);

    test_price("Standard command total",
               standard.get_total_price(), 220.0f);

    print_section("TUESDAY DISCOUNT");

    ThuesdayDiscountCommand tuesday(
        2, Day::Tuesday, "Bob", articles
    );

    test_price("Tuesday discount (10%)",
               tuesday.get_total_price(), 198.0f);

    ThuesdayDiscountCommand monday(
        3, Day::Monday, "Charlie", articles
    );

    test_price("Monday - no discount",
               monday.get_total_price(), 220.0f);

    print_section("PACKAGE REDUCTION");

    PackageReductionDiscountCommand package(
        4, Day::Monday, "David", articles
    );

    test_price("Above 150 euros (-10 euros)",
               package.get_total_price(), 210.0f);

    std::vector<Article> articles150;
    articles150.push_back({"Monitor", 150.0f, 1});

    PackageReductionDiscountCommand package150(
        5, Day::Monday, "Eve", articles150
    );

    test_price("Exactly 150 euros - no discount",
               package150.get_total_price(), 150.0f);

    std::vector<Article> articles100;
    articles100.push_back({"Keyboard", 50.0f, 2});

    PackageReductionDiscountCommand package100(
        6, Day::Monday, "Frank", articles100
    );

    test_price("Below 150 euros - no discount",
               package100.get_total_price(), 100.0f);

    print_section("ARTICLE QUANTITIES");

    std::vector<Article> quantityArticles;
    quantityArticles.push_back({"USB Cable", 5.0f, 4});
    quantityArticles.push_back({"Adapter", 10.0f, 3});

    Command quantityCommand(
        7, Day::Wednesday, "Grace", quantityArticles
    );

    test_price("Multiple articles and quantities",
               quantityCommand.get_total_price(), 50.0f);

    print_section("POLYMORPHISM");

    Command *commands[3];

    commands[0] = new Command(8, Day::Monday, "Henry", articles);
    commands[1] = new ThuesdayDiscountCommand(
        9, Day::Tuesday, "Iris", articles
    );
    commands[2] = new PackageReductionDiscountCommand(
        10, Day::Monday, "Jack", articles
    );

    test_price("Polymorphism - standard",
               commands[0]->get_total_price(), 220.0f);

    test_price("Polymorphism - Tuesday",
               commands[1]->get_total_price(), 198.0f);

    test_price("Polymorphism - package",
               commands[2]->get_total_price(), 210.0f);

    for (int i = 0; i < 3; i++)
        delete commands[i];

    print_section("TEST SUMMARY");

    std::cout << "Passed: " << testsPassed << std::endl;
    std::cout << "Failed: " << testsFailed << std::endl;
    std::cout << "Total:  " << testsPassed + testsFailed << std::endl;

    if (testsFailed == 0)
        std::cout << "\n\033[1;32mALL TESTS PASSED!\033[0m" << std::endl;
    else
        std::cout << "\n\033[1;31mSOME TESTS FAILED!\033[0m" << std::endl;

    return (testsFailed == 0 ? 0 : 1);
}
