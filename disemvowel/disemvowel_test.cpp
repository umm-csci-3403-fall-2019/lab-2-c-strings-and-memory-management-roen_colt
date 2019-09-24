#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
	        char *str = disemvowel(((char*) ""));
  ASSERT_STREQ("", str);
  free(str);
}

TEST(Disemvowel, HandleNoVowels) {
	char *str = disemvowel(((char*) "pqrst"));
  ASSERT_STREQ("pqrst", str);
	free(str);
}

TEST(Disemvowel, HandleOnlyVowels) {
	char *str = disemvowel(((char*) "aeiouAEIOUOIEAuoiea"));
  ASSERT_STREQ("",str);
  free(str);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  ASSERT_STREQ("Mrrs, Mnnst",
		      disemvowel((char*) "Morris, Minnesota"));
}

TEST(Disemvowel, HandlePunctuation) {
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      disemvowel((char*) "An (Unexplained) Elephant!"));
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
 char *disemvowelstr = disemvowel((str)); 
  ASSERT_STREQ("xyz", disemvowelstr);
 free(disemvowelstr);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
