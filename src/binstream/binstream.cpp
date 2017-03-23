#include "binstream/binstream.h"
#include <iomanip>
#include <sstream>
#include <algorithm>

namespace binstreamtemponarynamespace {
	binstream::binstream() :
		buffer_data(), position_value(0) {}

	binstream::binstream(const std::string &buffer) :
		buffer_data(buffer), position_value(0) {}

	binstream::binstream(const char *buffer, unsigned long size) :
		buffer_data(buffer, size), position_value(0) {}

	binstream::binstream(unsigned long size) :
		buffer_data(size, '\0'), position_value(0) {}

	binstream::~binstream() {}

	bool binstream::get(std::string &buffer) const {
		if (this->buffer_data.size() - position_value < buffer.size()) {
			return false;
		}

		buffer = this->buffer_data.substr(position_value, buffer.size());
		position_value += buffer.size();
		return true;
	}

	bool binstream::get(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return get(buffer);
	}

	bool binstream::getLittle(std::string &buffer) const {
		switch (endian()) {
		case Endian::Little:
			return get(buffer);
		case Endian::Big:
			if (get(buffer)) {
				std::reverse(buffer.begin(), buffer.end());
				return true;
			}

			return false;
		}
	}

	bool binstream::getLittle(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return getLittle(buffer);
	}

	bool binstream::getBig(std::string &buffer) const {
		switch (endian()) {
		case Endian::Big:
			return get(buffer);
		case Endian::Little:
			if (get(buffer)) {
				std::reverse(buffer.begin(), buffer.end());
				return true;
			}

			return false;
		}
	}

	bool binstream::getBig(std::string &buffer, unsigned long size) const {
		buffer.resize(size);
		return getBig(buffer);
	}

	void binstream::put(const std::string &buffer) {
		this->buffer_data += buffer;
	}

	void binstream::putLittle(const std::string &buffer) {
		switch (endian()) {
		case Endian::Little:
			put(buffer);
			break;
		case Endian::Big:
			auto swappedBuffer = buffer;
			std::reverse(swappedBuffer.begin(), swappedBuffer.end());
			put(swappedBuffer);
			break;
		}
	}

	void binstream::putBig(const std::string &buffer) {
		switch (endian()) {
		case Endian::Big:
			put(buffer);
			break;
		case Endian::Little:
			auto swappedBuffer = buffer;
			std::reverse(swappedBuffer.begin(), swappedBuffer.end());
			put(swappedBuffer);
			break;
		}
	}

	bool binstream::getString(std::string &value) const {
		unsigned long length;
		return (get(length)) && (get(value, length));
	}

	void binstream::putString(const std::string &value) {
		unsigned long length = value.length();
		put(length);
		put(value);
	}

	unsigned long binstream::position() const {
		return position_value;
	}

	void binstream::position(unsigned long value) {
		position_value = value;
	}

	std::string binstream::buffer() const {
		return buffer_data;
	}

	void binstream::buffer(const std::string &value) {
		buffer_data = value;
		position_value = 0;
	}

	std::string binstream::dump() const {
		static char Hex[] = "0123456789ABCDEF";

		std::stringstream ss;

		auto length = buffer_data.size();
		auto width = 0;
		for (unsigned long temp = length; temp != 0; temp /= 10, ++width);

		unsigned long i = 0;
		auto it = buffer_data.begin();
		for (unsigned long row = 0;; ++row) {
			ss << std::setw(width) << i << ": ";

			auto si = i;
			auto sit = it;
			for (unsigned long col = 0; col < 8; ++col) {
				auto ch = *it;

				ss << Hex[(ch >> 4) & 0xF] << Hex[ch & 0xF] << " ";

				++i;
				++it;

				if (i >= length) {
					break;
				}
			}

			ss << "   ";
			for (unsigned long j = i; j < ((i + 7) / 8) * 8; ++j) {
				ss << "   ";
			}

			for (unsigned long col = 0; col < 8; ++col) {
				auto ch = *sit;

				if ((ch >= 0x20) && (ch <= 0x7E)) { // Hardcoded
					ss << ch;
				} else {
					ss << ".";
				}

				++si;
				++sit;

				if (si >= length) {
					break;
				}
			}

			if (i >= length) {
				goto done;
			}

			ss << std::endl;
		}

done:
		return ss.str();
	}

	binstream::Endian binstream::endian() {
		union {
			uint32_t i;
			char c[4];
		} k = {0x01020304};

		return (k.c[0] == 1) ? Endian::Big : Endian::Little;
	}
}
