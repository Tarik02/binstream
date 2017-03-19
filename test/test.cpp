#include <iostream>
#include <binstream.h>

using namespace std;

#define TEST(condition) { \
		++tests; \
		if (condition) { \
			++successTests; \
		} else { \
			cout \
				<< "Test failed on line " << __LINE__ \
				<< " [" << #condition << "]" << endl; \
			++failedTests; \
		} \
	}

int main() {
	binstream stream;

	unsigned long tests = 0, successTests = 0, failedTests = 0;

	signed char valueSignedChar = 10;
	unsigned char valueUnsignedChar = 10;
	signed short valueSignedShort = 1000;
	unsigned short valueUnsignedShort = 1000;
	signed long valueSignedLong = 1000;
	unsigned long valueUnsignedLong = 1000;
	signed long long valueSignedLongLong = 1000;
	unsigned long long valueUnsignedLongLong = 1000;
	float valueFloat = 1000;
	double valueDouble = 1000;
	long double valueLongDouble = 1000;
	std::string valueString = "Hello, BinStream!";

	stream.put(valueSignedChar);
	stream.put(valueUnsignedChar);
	stream.put(valueSignedShort);
	stream.put(valueUnsignedShort);
	stream.put(valueSignedLong);
	stream.put(valueUnsignedLong);
	stream.put(valueSignedLongLong);
	stream.put(valueUnsignedLongLong);
	stream.put(valueFloat);
	stream.put(valueDouble);
	stream.put(valueLongDouble);
	stream.put(valueString);

	TEST((stream.get(valueSignedChar)) &&       (valueSignedChar == 10))
	TEST((stream.get(valueUnsignedChar)) &&     (valueUnsignedChar == 10))
	TEST((stream.get(valueSignedShort)) &&      (valueSignedShort == 1000))
	TEST((stream.get(valueUnsignedShort)) &&    (valueUnsignedShort == 1000))
	TEST((stream.get(valueSignedLong)) &&       (valueSignedLong == 1000))
	TEST((stream.get(valueUnsignedLong)) &&     (valueUnsignedLong == 1000))
	TEST((stream.get(valueSignedLongLong)) &&   (valueSignedLongLong == 1000))
	TEST((stream.get(valueUnsignedLongLong)) && (valueUnsignedLongLong == 1000))
	TEST((stream.get(valueFloat)) &&            (valueFloat == 1000))
	TEST((stream.get(valueDouble)) &&           (valueDouble == 1000))
	TEST((stream.get(valueLongDouble)) &&       (valueLongDouble == 1000))
	TEST((stream.get(valueString)) &&           (valueString == "Hello, BinStream!"))
	
	cout
		<< "Unit test "
		<< (failedTests == 0 ? "PASSED" : "FAILED")
		<< " (total test: "
		<< tests
		<< ", failed tests: "
		<< failedTests
		<< ")"
		<< endl;

	return failedTests == 0 ? 0 : -1;
}
