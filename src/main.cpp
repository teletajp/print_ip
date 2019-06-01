#include "print_ip.h"
int main(int argc, char const *argv[])
{
    print_ip(char(-1));
	print_ip(short(0));
	print_ip(int(2130706433));
	print_ip(long(8875824491850138409));
	print_ip(std::string("127.0.0.10"));
	print_ip(std::vector<uint8_t>{127,0,0,20});
	print_ip(std::list<uint8_t>{127,0,0,30});
    return 0;
}
