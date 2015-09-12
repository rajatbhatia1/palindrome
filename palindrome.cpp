#include <iostream>
#include <string>

#ifdef TESTING
#include "gtest/gtest.h"
#endif

#ifndef TESTING
void palindrome(std::string &s);

int main() 
{
  std::string s;
  std::cin >> s;
  palindrome(s);
  std::cout << s << std::endl;
}
#endif

void palindrome(std::string &s)
{
    //    std::cout << s << " => ";
    const char *c=s.c_str();
    int length = s.length();

    const char *p = c;
    const char *q = c + length - 1;
    int count = 0;
    while ((*p==*q) && count<(length/2)) {
        ++p;
        --q;
        ++count;
    }
    if (*p==*q) {
        // palindrome
        s.insert(count, 1, *p);
	return;
    } 
    // p and q are pointing to start and end of string
    // which may be able to be made palindrome
    if (length-2*count==2) {
      s.insert(count, 1, *q);
      return;
    } else { 
      if (*p==*(q-1)) {
	char ins_c = *q;
        const char *p1 = p;
        const char *q1 = q;
	--q1;
	int pos = count;
	//possible palindrome
	while ((*p1==*q1) && count<(length/2)) {
	  ++p1;
	  --q1;
	  ++count;
	}
	if (*p1==*q1) {
	  s.insert(pos, 1, ins_c);
	  return;
	} 
        count = pos;
      } 
      if (*(p+1)==*(q)) {
	char ins_c = *p;
	++p;
	int pos = length - count;
	//possible palindrome
	while ((*p==*q) && count<(length/2)) {
	  ++p;
	  --q;
	  ++count;
	}
	if (*p==*q) {
	  s.insert(pos, 1, ins_c);
	  return;
	}
      } 
    }
    s = "NA";
}

#ifdef TESTING
TEST(PalindromeFixture, eval_1) {
  std::string teststring("kitayuta");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_2) {
  std::string teststring("evima");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_3) {
  std::string teststring("a");
  palindrome(teststring);
  ASSERT_EQ(teststring, "aa");
}

TEST(PalindromeFixture, eval_4) {
  std::string teststring("yutampo");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_5) {
  std::string teststring("fft");
  palindrome(teststring);
  ASSERT_EQ(teststring, "tfft");
}

TEST(PalindromeFixture, eval_6) {
  std::string teststring("shuseki");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_7) {
  std::string teststring("lsdijfjisl");
  palindrome(teststring);
  ASSERT_EQ(teststring, "lsdijfjidsl");
}
TEST(PalindromeFixture, eval_8) {
  std::string teststring("ewcdcwerp");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_9) {
  std::string teststring("noon");
  palindrome(teststring);
  ASSERT_EQ(teststring, "nooon");
}

TEST(PalindromeFixture, eval_10) {
  std::string teststring("add");
  palindrome(teststring);
  ASSERT_EQ(teststring, "adda");
}

TEST(PalindromeFixture, eval_11) {
  std::string teststring("iq");
  palindrome(teststring);
  ASSERT_EQ(teststring, "qiq");
}

TEST(PalindromeFixture, eval_12) {
  std::string teststring("hogloid");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_13) {
  std::string teststring("yosupo");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_14) {
  std::string teststring("stat");
  palindrome(teststring);
  ASSERT_EQ(teststring, "stats");
}

TEST(PalindromeFixture, eval_15) {
  std::string teststring("level");
  palindrome(teststring);
  ASSERT_EQ(teststring, "levvel");
}

TEST(PalindromeFixture, eval_16) {
  std::string teststring("iwiwi");
  palindrome(teststring);
  ASSERT_EQ(teststring, "iwiiwi");
}

TEST(PalindromeFixture, eval_17) {
  std::string teststring("racecar");
  palindrome(teststring);
  ASSERT_EQ(teststring, "raceecar");
}

TEST(PalindromeFixture, eval_18) {
  std::string teststring("dog");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_19) {
  std::string teststring("squirrel");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_20) {
  std::string teststring("slime");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_21) {
  std::string teststring("palindrome");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_22) {
  std::string teststring("nqwcvcwqn");
  palindrome(teststring);
  ASSERT_EQ(teststring, "nqwcvvcwqn");
}



TEST(PalindromeFixture, eval_23) {
  std::string teststring("lsdijfjisl");
  palindrome(teststring);
  ASSERT_EQ(teststring, "lsdijfjidsl");
}

TEST(PalindromeFixture, eval_24) {
  std::string teststring("jewiiwefj");
  palindrome(teststring);
  ASSERT_EQ(teststring, "jfewiiwefj");
}

TEST(PalindromeFixture, eval_25) {
  std::string teststring("vnwmvmonv");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_26) {
  std::string teststring("zennyuu");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_27) {
  std::string teststring("mrtoudai");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_28) {
  std::string teststring("z");
  palindrome(teststring);
  ASSERT_EQ(teststring, "zz");
}

TEST(PalindromeFixture, eval_29) {
  std::string teststring("babccba");
  palindrome(teststring);
  ASSERT_EQ(teststring, "babccbab");
}

TEST(PalindromeFixture, eval_30) {
  std::string teststring("revive");
  palindrome(teststring);
  ASSERT_EQ(teststring, "reviver");
}

TEST(PalindromeFixture, eval_31) {
  std::string teststring("ee");
  palindrome(teststring);
  ASSERT_EQ(teststring, "eee");
}

TEST(PalindromeFixture, eval_32) {
  std::string teststring("battaba");
  palindrome(teststring);
  ASSERT_EQ(teststring, "abattaba");
}

TEST(PalindromeFixture, eval_33) {
  std::string teststring("bbb");
  palindrome(teststring);
  ASSERT_EQ(teststring, "bbbb");
}

TEST(PalindromeFixture, eval_34) {
  std::string teststring("zaa");
  palindrome(teststring);
  ASSERT_EQ(teststring, "zaaz");
}

TEST(PalindromeFixture, eval_35) {
  std::string teststring("abbabab");
  palindrome(teststring);
  ASSERT_EQ(teststring, "NA");
}

TEST(PalindromeFixture, eval_36) {
  std::string teststring("racecar");
  palindrome(teststring);
  ASSERT_EQ(teststring, "raceecar");
}

TEST(PalindromeFixture, eval_37) {
  std::string teststring("zzz");
  palindrome(teststring);
  ASSERT_EQ(teststring, "zzzz");
}
TEST(PalindromeFixture, eval_38) {
  std::string teststring("eviver");
  palindrome(teststring);
  ASSERT_EQ(teststring, "reviver");
}

TEST(PalindromeFixture, eval_39) {
  std::string teststring("aaaaa");
  palindrome(teststring);
  ASSERT_EQ(teststring, "aaaaaa");
}

TEST(PalindromeFixture, eval_40) {
  std::string teststring("eee");
  palindrome(teststring);
  ASSERT_EQ(teststring, "eeee");
}

#endif
