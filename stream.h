#pragma once

#include <string>

namespace binstream {
	#define DECLARE_METHOD(T) \
		inline bool get(signed T &value) const { return getLittle(value); } \
		inline bool get(unsigned T &value) const { return getLittle(value); } \
		inline bool getLittle(signed T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getLittle(buffer); value = *((T *)buffer.c_str()); return success; } \
		inline bool getLittle(unsigned T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getLittle(buffer); value = *((T *)buffer.c_str()); return success; } \
		inline bool getBig(signed T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getBig(buffer); value = *((T *)buffer.c_str()); return success; } \
		inline bool getBig(unsigned T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getBig(buffer); value = *((T *)buffer.c_str()); return success; } \
		\
		inline void put(signed T value) { putLittle(value); } \
		inline void put(unsigned T value) { putLittle(value); } \
		inline void putLittle(signed T value) { putLittle({(char *)&value, sizeof(T)}); } \
		inline void putLittle(unsigned T value) { putLittle({(char *)&value, sizeof(T)}); } \
		inline void putBig(signed T value) { putBig({(char *)&value, sizeof(T)}); } \
		inline void putBig(unsigned T value) { putBig({(char *)&value, sizeof(T)}); }
	#define DECLARE_METHOD_NOSIGN(T) \
		inline bool get(T &value) const { return getLittle(value); } \
		inline bool getLittle(T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getLittle(buffer); value = *((T *)buffer.c_str()); return success; } \
		inline bool getBig(T &value) const { std::string buffer{(char *)&value, sizeof(T)}; bool success = getBig(buffer); value = *((T *)buffer.c_str()); return success; } \
		\
		inline void put(T value) { putLittle(value); } \
		inline void putLittle(T value) { putLittle({(char *)&value, sizeof(T)}); } \
		inline void putBig(T value) { putBig({(char *)&value, sizeof(T)}); }

	class stream {
	protected:
		std::string buffer_data;
		mutable unsigned long position_value;

	public:
		stream();
		stream(const std::string &buffer);
		stream(const char *buffer, unsigned long size);
		stream(unsigned long size);
		~stream();

		inline void skip(unsigned long count) const { position_value += count; }
		bool get(std::string &buffer) const;
		bool get(std::string &buffer, unsigned long size) const;
		bool getLittle(std::string &buffer) const;
		bool getLittle(std::string &buffer, unsigned long size) const;
		bool getBig(std::string &buffer) const;
		bool getBig(std::string &buffer, unsigned long size) const;

		void put(const std::string &buffer);
		void putLittle(const std::string &buffer);
		void putBig(const std::string &buffer);

		DECLARE_METHOD_NOSIGN(bool)
		DECLARE_METHOD(char)
		DECLARE_METHOD(short)
		DECLARE_METHOD(long)
		DECLARE_METHOD(long long)
		DECLARE_METHOD_NOSIGN(float)
		DECLARE_METHOD_NOSIGN(double)
		DECLARE_METHOD_NOSIGN(long double)

		bool getString(std::string &value) const;
		void putString(const std::string &value);

		unsigned long position() const;
		void position(unsigned long value);

		std::string buffer() const;
		void buffer(const std::string &value);
	};
	
	#undef DECLARE_METHOD
	#undef DECLARE_METHOD_NOSIGN
}
