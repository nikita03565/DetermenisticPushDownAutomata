#include "unittest1.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void DPDAtest::UnitTest1::testMethod0()
{
    Assert::AreEqual(true, _dpda.check("--"));
}

void DPDAtest::UnitTest1::testMethod1()
{
    Assert::AreEqual(true, _dpda.check("-1111-"));
}

void DPDAtest::UnitTest1::testMethod2()
{
    Assert::AreEqual(true, _dpda.check("-01100-"));
}

void DPDAtest::UnitTest1::testMethod3()
{
    Assert::AreEqual(false, _dpda.check("-011100-"));
}

void DPDAtest::UnitTest1::testMethod4()
{
    Assert::AreEqual(false, _dpda.check("0-00110000-"));
}

void DPDAtest::UnitTest1::testMethod5()
{
    Assert::AreEqual(true, _dpda.check("-000000-"));
}

void DPDAtest::UnitTest1::testMethod6()
{
    Assert::AreEqual(false, _dpda.check("-0000000-"));
}

void DPDAtest::UnitTest1::testMethod7()
{
    Assert::AreEqual(false, _dpda.check("-000-0"));
}

void DPDAtest::UnitTest1::testMethod8()
{
    Assert::AreEqual(false, _dpda.check("-000011-"));
}

void DPDAtest::UnitTest1::testMethod9()
{
    Assert::AreEqual(false, _dpda.check("-00000000000001100000000000000000000000000"));
}

void DPDAtest::UnitTest1::testMethod10()
{
    Assert::AreEqual(false, _dpda.check("0-0-0"));
}

void DPDAtest::UnitTest1::testMethod11()
{
    Assert::AreEqual(false, _dpda.check("--01100-"));
}

void DPDAtest::UnitTest1::testMethod12()
{
    Assert::AreEqual(false, _dpda.check("---"));
}

void DPDAtest::UnitTest1::testMethod13()
{
    Assert::AreEqual(false, _dpda.check("-001100002-"));
}

void DPDAtest::UnitTest1::testMethod14()
{
    Assert::AreEqual(true, _dpda.check("-00111111110000-"));
}

void DPDAtest::UnitTest1::testMethod15()
{
    Assert::AreEqual(false, _dpda.check("-00111111110000--"));
}

void DPDAtest::UnitTest1::testMethod16()
{
    Assert::AreEqual(false, _dpda.check("-0110-"));
}

void DPDAtest::UnitTest1::testMethod17()
{
    Assert::AreEqual(true, _dpda.check("-000000000000000000000000000000000000000000000000000000000000000000-"));
}

void DPDAtest::UnitTest1::testMethod18()
{
    Assert::AreEqual(true, _dpda.check("-111111111111111111111111111111111111111111111111-"));
}

void DPDAtest::UnitTest1::testMethod19()
{
    Assert::AreEqual(true, _dpda.check("-000000000000000111111111111111111111111111111111111111111111111000000000000000000000000000000-"));
}