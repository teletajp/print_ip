#include <gtest/gtest.h>
#include "print_ip.h"
//Печать адреса как char(-1)
TEST(print_ip_test, print_1)
{
	print_ip(char(-1));
	print_ip(short(0));
	print_ip(int(2130706433));
	print_ip(long(8875824491850138409));
	print_ip(std::string("127.0.0.10"));
	print_ip(std::vector<uint8_t>{127,0,0,20});
	print_ip(std::list<uint8_t>{127,0,0,30});
	ASSERT_TRUE(true);
}
//Печать адреса как short(0)
//Печать адреса как int(2130706433)
//Печать адреса как long(8875824491850138409)
//Печать адреса как std::string
//Печать адреса как std::vector
//Печать адреса как std::list
//Опционально. Печать адреса как std::tuple
TEST(print_ip_test, test)
{
	ASSERT_FALSE(false);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
