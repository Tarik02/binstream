#include "stream.h"
#include "endian.h"
#include <algorithm>

namespace binstream {
	stream::stream() :
		buffer_data(), position_value(0) {}

	stream::stream(const std::string &buffer) :
		buffer_data(buffer), position_value(0) {}

	stream::stream(const char *buffer, unsigned long size) :
		buffer_data(buffer, size), position_value(0) {}

	stream::stream(unsigned long size) :
		buffer_data(size, '\0'), position_value(0) {}

	stream::~stream() {}

	bool stream::get(std::string &buffer) const {
		if (this->buffer_data.size() - position_value < buffer.size()) {
			return false;
		}
		
		buffer = this->buffer_data.substr(position_value, buffer.size());
		position_value += buffer.size();
		return true;
	}

	bool stream::get(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return get(buffer);
	}

	bool stream::getLittle(std::string &buffer) const {
#if ENDIAN == ENDIAN_LITTLE
		return get(buffer);
#elif ENDIAN == ENDIAN_BIG
		if (get(buffer_data)) {
			std::reverse(buffer_data.begin(), buffer_data.end());
			return true;
		}
		
		return false;
#endif
	}

	bool stream::getLittle(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return getLittle(buffer);
	}

	bool stream::getBig(std::string &buffer) const {
#if ENDIAN == ENDIAN_BIG
		return get(buffer_data);
#elif ENDIAN == ENDIAN_LITTLE
		if (get(buffer)) {
			std::reverse(buffer.begin(), buffer.end());
			return true;
		}
		
		return false;
#endif
	}

	bool stream::getBig(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return getBig(buffer);
	}

	void stream::put(const std::string &buffer) {
		this->buffer_data += buffer;
	}

	void stream::putLittle(const std::string &buffer) {
#if ENDIAN == ENDIAN_LITTLE
		put(buffer);
#elif ENDIAN == ENDIAN_BIG
		auto swappedBuffer = buffer_data;
		std::reverse(swappedBuffer.begin(), swappedBuffer.end());
		put(swappedBuffer);
#endif
	}

	void stream::putBig(const std::string &buffer) {
#if ENDIAN == ENDIAN_BIG
		put(buffer_data);
#elif ENDIAN == ENDIAN_LITTLE
		auto swappedBuffer = buffer;
		std::reverse(swappedBuffer.begin(), swappedBuffer.end());
		put(swappedBuffer);
#endif
	}

	bool stream::getString(std::string &value) const {
		unsigned long length;
		return (get(length)) && (get(value, length));
	}

	void stream::putString(const std::string &value) {
		unsigned long length = value.length();
		put(length);
		put(value);
	}

	unsigned long stream::position() const {
		return position_value;
	}

	void stream::position(unsigned long value) {
		position_value = value;
	}

	std::string stream::buffer() const {
		return buffer_data;
	}

	void stream::buffer(const std::string &value) {
		buffer_data = value;
		position_value = 0;
	}
}
