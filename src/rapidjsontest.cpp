#include <stdio.h>
#include <list>
#include <string>
#include "rapidjson/writer.h" /*JSON write*/
#include "rapidjson/reader.h" /*JSON read*/
#include "rapidjson/stringbuffer.h" /*JSON buffer*/
#include "rapidjson/document.h"

using namespace rapidjson;
using namespace std;

const char* json = "{\"a\" : [{\"b\":123, \"c\":\"asd\"}, {\"b\":123, \"c\":\"asd\"}, {\"b\":123, \"c\":\"asd\"}, {\"b\":123, \"c\":\"asd\"}]}";

struct idc {
	int b;
	int c;
};

int main() 
{
	printf(json);
	Document doc;
	doc.Parse(json);
	assert(doc.IsObject);
	const Value& a = doc["a"];
	assert(a.IsArray);

	for (Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
	{
		const Value& attribute = *itr;
		assert(attribute.IsObject()); // each attribute is an object
		for (Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
			printf(itr2->name.GetString());
			printf(itr2->value.GetString());
		} 
	}

	return 0;
}