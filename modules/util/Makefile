LIB_NAME = util
LIB_VERSION_X = 0
LIB_VERSION_Y = 0
LIB_VERSION_Z = 1

HEAD_FILES = \
	pid_file.h \
	string.h \
	fs.h \
	argument_parser.h \
	split_cmdline.h \
	serializer.h \
	time_counter.h \
	async_pipe.h \
	backtrace.h \
	timestamp.h \
	json.h \
	base64.h \
	checksum.h \
	crc.h \
	json_deep_loader.h \

CPP_SRC_FILES = \
	pid_file.cpp \
	string.cpp \
	fs.cpp \
	argument_parser.cpp \
	split_cmdline.cpp \
	serializer.cpp \
	time_counter.cpp \
	async_pipe.cpp \
	backtrace.cpp \
	timestamp.cpp \
	json.cpp \
	base64.cpp \
	checksum.cpp \
	crc.cpp \
	json_deep_loader.cpp \

CXXFLAGS := -DLOG_MODULE_ID='"util"' $(CXXFLAGS)

TEST_CPP_SRC_FILES = \
	pid_file_test.cpp \
	string_test.cpp \
	fs_test.cpp \
	argument_parser_test.cpp \
	split_cmdline_test.cpp \
	serializer_test.cpp \
	time_counter_test.cpp \
	async_pipe_test.cpp \
	json_test.cpp \
	base64_test.cpp \
	checksum_test.cpp \
	crc_test.cpp \

TEST_LDFLAGS := $(LDFLAGS) -ltbox_base -ldl

ENABLE_SHARED_LIB = no

include ../../tools/lib_common.mk
