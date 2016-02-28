CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall
LDFLAGS=
LDLIBS=-luv

SRCS=dapps.cc \
	utilities/ArgsProcessor.cc \
	commons/json/JSON.cc \
	commons/containers/JSONTypes.cc \
	registry/RegistryServer.cc \
	utilities/StringUtils.cc \
	utilities/LoggingUtil.cc \
	commons/exceptions/DappsException.cc \
	registry/ClientSocket.cc \
	commons/exceptions/JSONParseException.cc \
	commons/containers/DappsContext.cc \
	commons/containers/Buffer.cc \
	commons/http/HttpSocket.cc \
	commons/http/AbstractHttpClient.cc \
	commons/sockets/AbstractClientSocket.cc

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
