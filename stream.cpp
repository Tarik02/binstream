#include "stream.h"
#include "endian.h"
#include <algorithm>

namespace binstream {
	stream::stream() :
		buffer(), position(0) {}

	stream::stream(const std::string &buffer) :
		buffer(buffer), position(0) {}

	stream::stream(const char *buffer, unsigned long size) :
		buffer(buffer, size), position(0) {}

	stream::stream(unsigned long size) :
		buffer(size, '\0'), position(0) {}

	stream::~stream() {}

	bool stream::get(std::string &buffer) const {
		if (this->buffer.size() - position < buffer.size()) {
			return false;
		}
		
		buffer = this->buffer.substr(position, buffer.size());
		position += buffer.size();
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
		if (get(buffer)) {
			std::reverse(buffer.begin(), buffer.end());
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
		return get(buffer);
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
		this->buffer += buffer;
	}

	void stream::putLittle(const std::string &buffer) {
#if ENDIAN == ENDIAN_LITTLE
		put(buffer);
#elif ENDIAN == ENDIAN_BIG
		auto swappedBuffer = buffer;
		std::reverse(swappedBuffer.begin(), swappedBuffer.end());
		put(swappedBuffer);
#endif
	}

	void stream::putBig(const std::string &buffer) {
#if ENDIAN == ENDIAN_BIG
		put(buffer);
#elif ENDIAN == ENDIAN_LITTLE
		auto swappedBuffer = buffer;
		std::reverse(swappedBuffer.begin(), swappedBuffer.end());
		put(swappedBuffer);
#endif
	}

	bool stream::getString(std::string &value) {
		unsigned long length;
		return (get(length)) && (get(value, length));
	}

	void stream::putString(const std::string &value) {
		unsigned long length = value.length();
		put(length);
		put(value);
	}
}
