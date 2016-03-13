CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall $(shell pkg-config --cflags libmongoc-1.0)
LDFLAGS=
LDLIBS=-luv $(shell pkg-config --libs libmongoc-1.0)

SRCS=dapps.cc \
	registry/RegistryServer.cc \
	registry/ClientSocket.cc \
	registry/RegistryRequestProcessor.cc \
	utilities/ArgsProcessor.cc \
	commons/json/JSON.cc \
	commons/containers/JSONTypes.cc \
	commons/utilities/StringUtils.cc \
	commons/utilities/LoggingUtil.cc \
	commons/exceptions/DappsException.cc \
	commons/exceptions/JSONParseException.cc \
	commons/exceptions/OutOfBoundsException.cc \
	commons/containers/DappsContext.cc \
	commons/containers/Buffer.cc \
	commons/http/HttpSocket.cc \
	commons/http/AbstractHttpClient.cc \
	commons/sockets/AbstractClientSocket.cc \
	commons/mongodb/MongoClient.cc \
	commons/containers/ServerSchema.cc

OBJS=$(subst .cc,.o,$(SRCS))

all: dapps

dapps: $(OBJS)
	$(CXX) $(LDFLAGS) -o dapps $(OBJS) $(LDLIBS)
	
depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .depend

-include .depend
