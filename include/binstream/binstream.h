#pragma once

#include <string>

namespace binstreamtemponarynamespace {
	class binstream {
	protected:
		std::string buffer_data;
		mutable unsigned long position_value;
	public:
		binstream();
		binstream(const std::string &buffer);
		binstream(const char *buffer, unsigned long size);
		binstream(unsigned long size);
		~binstream();

		inline void skip(unsigned long count) const {
			position_value += count;
		}

		bool get(std::string &buffer) const;
		bool get(std::string &buffer, unsigned long size) const;
		bool getLittle(std::string &buffer) const;
		bool getLittle(std::string &buffer, unsigned long size) const;
		bool getBig(std::string &buffer) const;
		bool getBig(std::string &buffer, unsigned long size) const;
		void put(const std::string &buffer);
		void putLittle(const std::string &buffer);
		void putBig(const std::string &buffer);

		inline bool get(bool &value) const {
			return getLittle(value);
		}

		inline bool getLittle(bool &value) const {
			std::string buffer{(char *)&value, sizeof(bool)};
			bool success = getLittle(buffer);
			value = *((bool *)buffer.c_str());
			return success;
		}

		inline bool getBig(bool &value) const {
			std::string buffer{(char *)&value, sizeof(bool)};
			bool success = getBig(buffer);
			value = *((bool *)buffer.c_str());
			return success;
		}

		inline void put(bool value) {
			putLittle(value);
		}

		inline void putLittle(bool value) {
			putLittle({(char *)&value, sizeof(bool)});
		}

		inline void putBig(bool value) {
			putBig({(char *)&value, sizeof(bool)});
		}

		inline bool get(signed char &value) const {
			return getLittle(value);
		}

		inline bool get(unsigned char &value) const {
			return getLittle(value);
		}

		inline bool getLittle(signed char &value) const {
			std::string buffer{(char *)&value, sizeof(char)};
			bool success = getLittle(buffer);
			value = *((char *)buffer.c_str());
			return success;
		}

		inline bool getLittle(unsigned char &value) const {
			std::string buffer{(char *)&value, sizeof(char)};
			bool success = getLittle(buffer);
			value = *((char *)buffer.c_str());
			return success;
		}

		inline bool getBig(signed char &value) const {
			std::string buffer{(char *)&value, sizeof(char)};
			bool success = getBig(buffer);
			value = *((char *)buffer.c_str());
			return success;
		}

		inline bool getBig(unsigned char &value) const {
			std::string buffer{(char *)&value, sizeof(char)};
			bool success = getBig(buffer);
			value = *((char *)buffer.c_str());
			return success;
		}

		inline void put(signed char value) {
			putLittle(value);
		}

		inline void put(unsigned char value) {
			putLittle(value);
		}

		inline void putLittle(signed char value) {
			putLittle({(char *)&value, sizeof(char)});
		}

		inline void putLittle(unsigned char value) {
			putLittle({(char *)&value, sizeof(char)});
		}

		inline void putBig(signed char value) {
			putBig({(char *)&value, sizeof(char)});
		}

		inline void putBig(unsigned char value) {
			putBig({(char *)&value, sizeof(char)});
		}

		inline bool get(signed short &value) const {
			return getLittle(value);
		}

		inline bool get(unsigned short &value) const {
			return getLittle(value);
		}

		inline bool getLittle(signed short &value) const {
			std::string buffer{(char *)&value, sizeof(short)};
			bool success = getLittle(buffer);
			value = *((short *)buffer.c_str());
			return success;
		}

		inline bool getLittle(unsigned short &value) const {
			std::string buffer{(char *)&value, sizeof(short)};
			bool success = getLittle(buffer);
			value = *((short *)buffer.c_str());
			return success;
		}

		inline bool getBig(signed short &value) const {
			std::string buffer{(char *)&value, sizeof(short)};
			bool success = getBig(buffer);
			value = *((short *)buffer.c_str());
			return success;
		}

		inline bool getBig(unsigned short &value) const {
			std::string buffer{(char *)&value, sizeof(short)};
			bool success = getBig(buffer);
			value = *((short *)buffer.c_str());
			return success;
		}

		inline void put(signed short value) {
			putLittle(value);
		}

		inline void put(unsigned short value) {
			putLittle(value);
		}

		inline void putLittle(signed short value) {
			putLittle({(char *)&value, sizeof(short)});
		}

		inline void putLittle(unsigned short value) {
			putLittle({(char *)&value, sizeof(short)});
		}

		inline void putBig(signed short value) {
			putBig({(char *)&value, sizeof(short)});
		}

		inline void putBig(unsigned short value) {
			putBig({(char *)&value, sizeof(short)});
		}

		inline bool get(signed long &value) const {
			return getLittle(value);
		}

		inline bool get(unsigned long &value) const {
			return getLittle(value);
		}

		inline bool getLittle(signed long &value) const {
			std::string buffer{(char *)&value, sizeof(long)};
			bool success = getLittle(buffer);
			value = *((long *)buffer.c_str());
			return success;
		}

		inline bool getLittle(unsigned long &value) const {
			std::string buffer{(char *)&value, sizeof(long)};
			bool success = getLittle(buffer);
			value = *((long *)buffer.c_str());
			return success;
		}

		inline bool getBig(signed long &value) const {
			std::string buffer{(char *)&value, sizeof(long)};
			bool success = getBig(buffer);
			value = *((long *)buffer.c_str());
			return success;
		}

		inline bool getBig(unsigned long &value) const {
			std::string buffer{(char *)&value, sizeof(long)};
			bool success = getBig(buffer);
			value = *((long *)buffer.c_str());
			return success;
		}

		inline void put(signed long value) {
			putLittle(value);
		}

		inline void put(unsigned long value) {
			putLittle(value);
		}

		inline void putLittle(signed long value) {
			putLittle({(char *)&value, sizeof(long)});
		}

		inline void putLittle(unsigned long value) {
			putLittle({(char *)&value, sizeof(long)});
		}

		inline void putBig(signed long value) {
			putBig({(char *)&value, sizeof(long)});
		}

		inline void putBig(unsigned long value) {
			putBig({(char *)&value, sizeof(long)});
		}

		inline bool get(signed long long &value) const {
			return getLittle(value);
		}

		inline bool get(unsigned long long &value) const {
			return getLittle(value);
		}

		inline bool getLittle(signed long long &value) const {
			std::string buffer{(char *)&value, sizeof(long long)};
			bool success = getLittle(buffer);
			value = *((long long *)buffer.c_str());
			return success;
		}

		inline bool getLittle(unsigned long long &value) const {
			std::string buffer{(char *)&value, sizeof(long long)};
			bool success = getLittle(buffer);
			value = *((long long *)buffer.c_str());
			return success;
		}

		inline bool getBig(signed long long &value) const {
			std::string buffer{(char *)&value, sizeof(long long)};
			bool success = getBig(buffer);
			value = *((long long *)buffer.c_str());
			return success;
		}

		inline bool getBig(unsigned long long &value) const {
			std::string buffer{(char *)&value, sizeof(long long)};
			bool success = getBig(buffer);
			value = *((long long *)buffer.c_str());
			return success;
		}

		inline void put(signed long long value) {
			putLittle(value);
		}

		inline void put(unsigned long long value) {
			putLittle(value);
		}

		inline void putLittle(signed long long value) {
			putLittle({(char *)&value, sizeof(long long)});
		}

		inline void putLittle(unsigned long long value) {
			putLittle({(char *)&value, sizeof(long long)});
		}

		inline void putBig(signed long long value) {
			putBig({(char *)&value, sizeof(long long)});
		}

		inline void putBig(unsigned long long value) {
			putBig({(char *)&value, sizeof(long long)});
		}

		inline bool get(float &value) const {
			return getLittle(value);
		}

		inline bool getLittle(float &value) const {
			std::string buffer{(char *)&value, sizeof(float)};
			bool success = getLittle(buffer);
			value = *((float *)buffer.c_str());
			return success;
		}

		inline bool getBig(float &value) const {
			std::string buffer{(char *)&value, sizeof(float)};
			bool success = getBig(buffer);
			value = *((float *)buffer.c_str());
			return success;
		}

		inline void put(float value) {
			putLittle(value);
		}

		inline void putLittle(float value) {
			putLittle({(char *)&value, sizeof(float)});
		}

		inline void putBig(float value) {
			putBig({(char *)&value, sizeof(float)});
		}

		inline bool get(double &value) const {
			return getLittle(value);
		}

		inline bool getLittle(double &value) const {
			std::string buffer{(char *)&value, sizeof(double)};
			bool success = getLittle(buffer);
			value = *((double *)buffer.c_str());
			return success;
		}

		inline bool getBig(double &value) const {
			std::string buffer{(char *)&value, sizeof(double)};
			bool success = getBig(buffer);
			value = *((double *)buffer.c_str());
			return success;
		}

		inline void put(double value) {
			putLittle(value);
		}

		inline void putLittle(double value) {
			putLittle({(char *)&value, sizeof(double)});
		}

		inline void putBig(double value) {
			putBig({(char *)&value, sizeof(double)});
		}

		inline bool get(long double &value) const {
			return getLittle(value);
		}

		inline bool getLittle(long double &value) const {
			std::string buffer{(char *)&value, sizeof(long double)};
			bool success = getLittle(buffer);
			value = *((long double *)buffer.c_str());
			return success;
		}

		inline bool getBig(long double &value) const {
			std::string buffer{(char *)&value, sizeof(long double)};
			bool success = getBig(buffer);
			value = *((long double *)buffer.c_str());
			return success;
		}

		inline void put(long double value) {
			putLittle(value);
		}

		inline void putLittle(long double value) {
			putLittle({(char *)&value, sizeof(long double)});
		}

		inline void putBig(long double value) {
			putBig({(char *)&value, sizeof(long double)});
		}

		bool getString(std::string &value) const;
		void putString(const std::string &value);

		unsigned long position() const;
		void position(unsigned long value);

		std::string buffer() const;
		void buffer(const std::string &value);

	private:
		enum class Endian { Little, Big };
		static Endian endian();
	};
}

using binstreamtemponarynamespace::binstream;
