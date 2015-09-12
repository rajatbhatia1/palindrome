CXX = g++-4.8
CXXFLAGS = -pedantic --std=c++11 -Werror
TESTLIBS = -lgtest -lpthread -lgtest_main
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f palindrome
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f palindrome.report

palindrome: clean palindrome.cpp
	$(CXX) $(CXXFLAGS) -o palindrome palindrome.cpp

buildtest: palindrome.cpp
	$(CXX) $(CXXFLAGS)  $(GCOVFLAGS) -o palindrome -DTESTING palindrome.cpp $(TESTLIBS)

regress: clean buildtest
	./palindrome

regress_report: regress
	$(VALGRIND) ./palindrome
	$(GCOV) -b palindrome.cpp | grep -A 5 "File 'palindrome.cpp'" >> palindrome.report
	cat palindrome.report
