#include <stdio.h>
#include <list>
#include <string>
#include "rapidjson/writer.h" /*JSON write*/
#include "rapidjson/reader.h" /*JSON read*/
#include "rapidjson/stringbuffer.h" /*JSON buffer*/
#include "rapidjson/document.h"

using namespace rapidjson;
using namespace std;

const char* json = "{\"hello\": \"world\",\"t\" : true,\"f\" : false,\"n\" : null,\"i\" : 123,\"pi\" : 3.1416,\"a\" : [1, 2, 3, 4]}";

int main() 
{
	//Document doc;
	//doc.Parse(json);
	printf(json);
	
	//assert(doc.isObject);
	//for (Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
	//	printf("%d ", itr->GetInt());
	return 0;
}