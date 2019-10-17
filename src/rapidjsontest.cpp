#include <stdio>
#include <list>
#include "rapidjson/writer.h" /*JSON write*/
#include "rapidjson/reader.h" /*JSON read*/
#include "rapidjson/stringbuffer.h" /*JSON buffer*/

using namespace rapidjson;

const char* json = "{
"hello": "world",
"t" : true,
"f" : false,
"n" : null,
"i" : 123,
"pi" : 3.1416,
"a" : [1, 2, 3, 4]
}"

int main() 
{
	
	return 0;
}