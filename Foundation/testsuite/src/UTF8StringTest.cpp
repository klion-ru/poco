//
// UTF8StringTest.cpp
//
// $Id: //poco/Main/Foundation/testsuite/src/UTF8StringTest.cpp#1 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "UTF8StringTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/UTF8String.h"


using Poco::UTF8;


UTF8StringTest::UTF8StringTest(const std::string& name): CppUnit::TestCase(name)
{
}


UTF8StringTest::~UTF8StringTest()
{
}


void UTF8StringTest::testCompare()
{
	std::string a1("aaaaa");
	std::string b1("bbbbb");
	
	assert (UTF8::icompare(a1, b1) < 0);

	std::string a2("aaaaa");
	std::string b2("BBBBB");
	
	assert (UTF8::icompare(a2, b2) < 0);

	std::string a3("AAAAA");
	std::string b3("bbbbb");
	
	assert (UTF8::icompare(a3, b3) < 0);

	std::string a4("aaaaa");
	std::string b4("AAAAA");
	
	assert (UTF8::icompare(a4, b4) == 0);
	
	std::string a5("AAAAA");
	std::string b5("bbbbb");
	
	assert (UTF8::icompare(a5, b5) < 0);

	std::string a6("\303\274\303\266\303\244"); // "u"a"o
	std::string b6("\303\234\303\226\303\204"); // "U"A"O
	
	assert (UTF8::icompare(a6, b6) == 0);
}


void UTF8StringTest::testTransform()
{
	std::string s1("abcde");
	UTF8::toUpperInPlace(s1);
	assert (s1 == "ABCDE");

	std::string s2("aBcDe123");
	UTF8::toUpperInPlace(s2);
	assert (s2 == "ABCDE123");

	std::string s3("\303\274\303\266\303\244"); // "u"a"o
	UTF8::toUpperInPlace(s3);	
	assert (s3 == "\303\234\303\226\303\204"); // "U"A"O
	UTF8::toLowerInPlace(s3);
	assert (s3 == "\303\274\303\266\303\244"); // "U"A"O
}


void UTF8StringTest::setUp()
{
}


void UTF8StringTest::tearDown()
{
}


CppUnit::Test* UTF8StringTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("UTF8StringTest");

	CppUnit_addTest(pSuite, UTF8StringTest, testCompare);
	CppUnit_addTest(pSuite, UTF8StringTest, testTransform);

	return pSuite;
}
